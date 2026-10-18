#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct aluno
{
    char *nome;
    int matricula;
};

typedef struct celula TCelula;

struct celula
{
    TAluno *aluno;
    TCelula *prox;
};

/* Sentinela: guarda ponteiros para a primeira e a ultima celula */
struct lista
{
    TCelula *prim;
    TCelula *ult;
};

TLista *CriaLista()
{
    TLista *lista = malloc(sizeof(TLista));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

TAluno *InicializaAluno(char *nome, int matricula)
{
    TAluno *aluno = malloc(sizeof(TAluno));
    aluno->nome = strdup(nome);
    aluno->matricula = matricula;
    return aluno;
}

void InsereAluno(TLista *lista, TAluno *aluno)
{
    TCelula *nova = malloc(sizeof(TCelula));
    nova->aluno = aluno;
    nova->prox = lista->prim;

    lista->prim = nova;
    if (lista->ult == NULL) // lista estava vazia
        lista->ult = nova;
}

/* Insere no final - usada pelo Merge para preservar a ordem */
static void InsereCelulaFinal(TLista *lista, TCelula *cel)
{
    cel->prox = NULL;
    if (lista->ult == NULL)
        lista->prim = cel;
    else
        lista->ult->prox = cel;
    lista->ult = cel;
}

/* Remove da lista a celula p, cujo anterior eh ant (NULL se p for a primeira) */
static void DesencadeiaCelula(TLista *lista, TCelula *ant, TCelula *p)
{
    if (ant == NULL)
        lista->prim = p->prox;
    else
        ant->prox = p->prox;

    if (p == lista->ult)
        lista->ult = ant;
}

TAluno *Retira(TLista *lista, int mat)
{
    TCelula *ant = NULL;
    TCelula *p = lista->prim;

    while (p != NULL && p->aluno->matricula != mat)
    {
        ant = p;
        p = p->prox;
    }

    if (p == NULL) // nao encontrou
        return NULL;

    DesencadeiaCelula(lista, ant, p);
    TAluno *aluno = p->aluno;
    free(p);
    return aluno;
}

void RetiraRepetidos(TLista *lista)
{
    for (TCelula *atual = lista->prim; atual != NULL; atual = atual->prox)
    {
        TCelula *ant = atual;
        TCelula *p = atual->prox;

        // remove TODAS as ocorrencias posteriores do mesmo aluno
        while (p != NULL)
        {
            if (p->aluno->matricula == atual->aluno->matricula)
            {
                TCelula *dup = p;
                DesencadeiaCelula(lista, ant, dup);
                p = dup->prox;

                // se for outro TAluno com a mesma matricula, libera-o tambem;
                // se for a mesma referencia, so a celula eh liberada
                if (dup->aluno != atual->aluno)
                    LiberaAluno(dup->aluno);
                free(dup);
            }
            else
            {
                ant = p;
                p = p->prox;
            }
        }
    }
}

TLista *Merge(TLista *turma1, TLista *turma2)
{
    TLista *nova = CriaLista();
    TCelula *p1 = turma1->prim;
    TCelula *p2 = turma2->prim;

    while (p1 != NULL || p2 != NULL)
    {
        if (p1 != NULL)
        {
            TCelula *prox = p1->prox;
            InsereCelulaFinal(nova, p1);
            p1 = prox;
        }
        if (p2 != NULL)
        {
            TCelula *prox = p2->prox;
            InsereCelulaFinal(nova, p2);
            p2 = prox;
        }
    }

    // as celulas foram transferidas: listas originais ficam vazias
    turma1->prim = turma1->ult = NULL;
    turma2->prim = turma2->ult = NULL;

    return nova;
}

void LiberaAluno(TAluno *aluno)
{
    free(aluno->nome);
    free(aluno);
}

void Imprime(TLista *lista)
{
    for (TCelula *p = lista->prim; p != NULL; p = p->prox)
        printf("Nome: %s Matricula: %d\n", p->aluno->nome, p->aluno->matricula);
}

void LiberaLista(TLista *lista)
{
    TCelula *p = lista->prim;
    while (p != NULL)
    {
        TCelula *prox = p->prox;
        LiberaAluno(p->aluno);
        free(p);
        p = prox;
    }
    free(lista); // libera o sentinela
}
