#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "aluno.h"
#include "professor.h"

struct No
{

    tNo *ant;
    tNo *prox;
    void *dado;
    LiberaElemento libera;
    ImprimeElemento imprime;
    GetClasseElemento getClasse;
    GetInfo gINFO;
};

tNo *CriaNo()
{

    tNo *n = malloc(sizeof(tNo));
    n->dado = NULL;
    n->ant = NULL;
    n->prox = NULL;
    n->getClasse = NULL;
    return n;
}

void LiberaNo(tNo *n)
{

    n->libera(n->dado);
    free(n);
}
void InsereElemento(tNo *dest, void *dado, tNo *sent, GetClasseElemento getClasse, GetInfo ginfo)
{

    dest->dado = dado;
    dest->getClasse = getClasse;
    dest->gINFO = ginfo;
    char c = dest->getClasse(dado);

    if (sent->ant == NULL && sent->prox == NULL)
    {

        sent->ant = dest;
        sent->prox = dest;
        dest->prox = sent;
        dest->ant = sent;

        if (c == 'A')
        {

            dest->imprime = ImprimeAluno;
            dest->libera = LiberaAluno;
        }

        else
        {

            dest->imprime = ImprimeProfessor;
            dest->libera = LiberaAluno;
        }

        return;
    }

    tNo *ult = sent->ant;
    ult->prox = dest;
    dest->ant = ult;
    dest->prox = sent;
    sent->ant = dest;

    if (c == 'A')
    {

        dest->imprime = ImprimeAluno;
        dest->libera = LiberaAluno;
    }

    else
    {

        dest->imprime = ImprimeProfessor;
        dest->libera = LiberaProfessor;
    }

    return;
}
char GetClasseNo(tNo *n)
{
    return n->getClasse(n->dado);
}

void ImprimeLista(tNo *sent, FILE *f)
{
    tNo *ult = sent->ant;
    tNo *atual = sent->prox;

    do
    {

        atual->imprime(atual->dado, f);
        atual = atual->prox;
    } while (atual != ult);
}

void LiberaLista(tNo *sent)
{
    tNo *p = sent->prox;

    while (p != sent && p != NULL)
    {

        tNo *tchau = p;
        p = p->prox;
        LiberaNo(tchau);
    }

    free(sent);
}

void CalculaMediaElementos(float *MCR, float *MSAL, int *Q1, int *Q2, tNo *sent)

{

    tNo *p = sent->prox;

    *MCR = 0;
    *MSAL = 0;

    int count_prof = 0, count_aluno = 0;
    char c = 'N';

    while (p != sent && p != NULL)
    {
        c = p->getClasse(p->dado);

        if (c == 'A')
        {

            count_aluno++;
            *MCR += p->gINFO(p->dado);
        }
        else
        {

            count_prof++;
            *MSAL += p->gINFO(p->dado);
        }
        p = p->prox;
    }

    *MSAL = *MSAL / count_prof;
    *MCR = *MCR / count_aluno;
    *Q1 = count_aluno;
    *Q2 = count_prof;
}

void PrintClass(tNo *n, char key, FILE *f)
{

    tNo *p = n->prox;

    while (p != n && p != NULL)
    {

        if (p->getClasse(p->dado) == key)
        {

            p->imprime((p->dado), f);
        }
        p = p->prox;
    }

    return;
}
