#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct aluno
{

    int mat;
    char *nome;
};

struct lista
{

    TLista *next;
    TAluno *aluno;
};

TLista *CriaLista()
{

    TLista *l = malloc(sizeof(TLista));
    l->aluno = NULL;
    l->next = NULL;
    return l;
}

/*Inicializa um TipoItem aluno
 * inputs: o nome e a matricula do aluno
 * output: um ponteiro para o tipo TAluno criado
 * pre-condicao: nome e matricula validos
 * pos-condicao: tipo TAluno criado, com os campos nome e matricula COPIADOS */
TAluno *InicializaAluno(char *nome, int matricula)
{

    TAluno *A = malloc(sizeof(TAluno));
    A->nome = strdup(nome);
    A->mat = matricula;

    return A;
}

/*Insere um aluno na primeira posicao da lista de alunos
 * inputs: aluno a ser inserido na lista (do tipo TAluno) e a lista
 * output: nenhum
 * pre-condicao: aluno n�o NULL e lista n�o NULL (mas, a lista pode estar vazia)
 * pos-condicao: lista contem o aluno inserido na primeira posicao */
void InsereAluno(TLista *lista, TAluno *aluno)
{
    TLista *New = CriaLista();
    New->aluno = aluno;

    if (lista->next == NULL)
    {

        lista->next = New;
        return;
    }

    else
    {

        TLista *temp = lista->next;
        lista->next = New;
        New->next = temp;
        return;
    }
}

/*Retira a primeira ocorrencia de um aluno de matricula mat da lista de alunos
 * inputs: a lista e a matricula do aluno a ser retirado da lista
 * output: o aluno (do tipo TAluno) retirado da lista ou NULL, se o aluno nao se encontrar na lista
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: lista nao contem a primeira ocorrencia do aluno de matricula mat */
TAluno *Retira(TLista *lista, int mat)
{

    TLista *I = lista->next;
    TLista *B = NULL;

    while (I != NULL)
    {

        int M_I = I->aluno->mat;

        if (M_I == mat)
        {

            if (B == NULL)
            {

                TLista *R = lista->next;
                TAluno *A = R->aluno;
                lista->next = lista->next->next;
                I = lista->next;
                free(R);
                return A;
            }
            else
            {
                B->next = I->next;
                TLista *R = I;
                TAluno *A = R->aluno;
                I = I->next;
                free(R);

                return A;
            }
        }

        else
        {

            B = I;
            I = I->next;
        }
    }

    return NULL;
}

/* Retira as repeticoes na lista. Ou seja, deixa apenas uma referencia para cada aluno na lista
 * inputs: a lista
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: lista nao contem repeticoes de alunos - APENAS UMA OCORRENCIA DE CADA ALUNO */
void RetiraRepetidos(TLista *lista)
{

    if (lista->next == NULL)
    {

        return;
    }

    TLista *I = lista->next;

    while (I != NULL)
    {

        int mat = I->aluno->mat;
        I = I->next;
        TAluno *B = Retira(lista, mat);
        TAluno *K = Retira(lista, mat);

        while (1)
        {

            if (K == NULL)
            {

                InsereAluno(lista, B);
                break;
            }
            else
            {

                K = Retira(lista, mat);
            }
        }
    }
}

/* Intercala os alunos das turmas 1 e 2 em uma nova lista. Por exemplo, se a turma 1 tiver (a1->a2->a3) e a turma 2 tiver (b1->b2->b3->b4->b5), a funcao deve retornar uma nova lista formada pelos elementos (a1->b1->a2->b2->a3->b3->b4->b5). Se uma das  listas tiver mais elementos que a outra, os elementos excedentes s�o transferidos na mesma ordem para a nova lista. As listas originais devem ficar vazias (com sentila prim e ult apontando para NULL).
 * inputs: duas listas n�o nulas (por�m, podem estar vazias)
 * output: uma nova lista com os elementos intercalados
 * pre-condicao: listas turma1 e turma2 nao sao NULL (mas podem estar vazias)
 * pos-condicao: lista retornada contem os elementos intercalados. As listas de entrada vazias (apenas com sentinela). */
TLista *Merge(TLista *turma1, TLista *turma2)
{

    TLista *Mix = CriaLista();

    TLista *Aux1 = turma1;
    TLista *Aux2 = turma2;

    Aux1 = Aux1->next;
    Aux2 = Aux2->next;

    while (Aux2 != NULL || Aux1 != NULL)
    {

        if (Aux1 != NULL)
        {

            InsereAluno(Mix, Aux1->aluno);
            TLista *B = Aux1;
            Aux1 = Aux1->next;
            free(B);
        }
        if (Aux2 != NULL)
        {

            InsereAluno(Mix, Aux2->aluno);
            TLista *B = Aux2;
            Aux2 = Aux2->next;
             free(B);
        }
    }

    turma1->next = NULL;
    turma2->next = NULL;
    return Mix;
}

/* Libera a memoria alocada para o aluno
 * inputs: o aluno do tipo TAluno*
 * output: nenhum
 * pre-condicao: aluno n�o NULL
 * pos-condicao: toda a memoria alocada para o aluno foi liberada (inclusive para o nome) */
void LiberaAluno(TAluno *aluno)
{

    free(aluno->nome);
    free(aluno);
}

/*Imprime os dados de todos os alunos da lista
 * inputs: a lista de alunos
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas, pode estar vazia)
 * pos-condicao: dados dos alunos impressos na saida padrao */
void Imprime(TLista *lista)
{

    TLista *I = lista->next;

    while (I != NULL)
    {

        printf("%s %d\n", I->aluno->nome, I->aluno->mat);

        I = I->next;
    }
}

/*Libera toda a memoria alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
 * inputs: a lista encadeada de alunos
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: toda memoria alocada eh liberada (use valgrind!) */
void LiberaLista(TLista *lista)
{

    if ( lista->next == NULL)
    {

        free(lista);
        return;
    }

    else
    {

        TLista *I = lista->next;

        while (I != NULL)
        {
            TAluno *A = I->aluno;
            TLista *B = I;
            I = I->next;

            LiberaAluno(A);
            free(B);
        }
    }
    free(lista);
}