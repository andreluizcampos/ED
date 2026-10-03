#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "provas.h"

struct No
{

    tNo *next;
    tQuestao *Q;
};

struct Lista
{

    tNo *ini;
    tNo *fim;
};

tLista *CriaLista()
{

    tLista *L = malloc(sizeof(tLista));
    L->fim = NULL;
    L->ini = NULL;

    return L;
}

void ImprimeLista(tLista *l, FILE *f)
{

    tNo *p = l->ini;

    while (p != NULL)
    {

        ImprimeQuestao(getQuestao(p), f);
        p = p->next;
    }
}

void AdicionaElemento(tLista *l, tQuestao *Q)
{

    tNo *New = malloc(sizeof(tNo));
    New->Q = Q;
    New->next = NULL;

    if (l->ini == NULL && l->fim == NULL)
    {
        l->ini = New;
        l->fim = New;

        return;
    }
    else
    {

        l->fim->next = New;
        New->next = NULL;
        l->fim = New;
    }
}

void RemoveElemento(tNo *n1, tLista *L)
{

    tNo *p = L->ini;

    int id = getID(n1->Q);

    if (L->fim == NULL && L->ini == NULL)
    {

        return;
    }

    if (L->fim == L->ini)
    {

        free(p);
        return;
    }

    if (getID(n1->Q) == getID(L->ini->Q))
    {

        L->ini = L->ini->next;
        free(n1);
        return;
    }

    tNo *ant = p;

    while (p != NULL)
    {

        if (id == getID(p->Q))
        {
            ant->next = p->next;
            free(n1);
        }
        tNo *ant = p;
        p = p->next;
    }
}

void LiberaLista(tLista *l)
{

    if (l->fim == NULL && l->ini == NULL)
    {

        free(l);
        return;
    }

    if (l->fim == l->ini)
    {
        free(l->fim);
        free(l);

        return;
    }

    tNo *m = l->ini;

    tNo *tchau = m;

    while (m != NULL)
    {
        tchau = m;
        m = m->next;
        free(tchau);
    }
    free(l);
}

tLista *Merge(tLista *l1, tLista *l2)
{
    tLista *Merged = CriaLista();

    tNo *a = l1->ini;
    tNo *b = l2->ini;

    while (1)
    {

        if (a != NULL)
        {
            AdicionaElemento(Merged, getQuestao(a));
            a = a->next;
        }

        if (b != NULL)
        {

            AdicionaElemento(Merged, getQuestao(b));
            b = b->next;
        }

        if (a == NULL && b == NULL)
        {

            return Merged;
        }
    }

    return Merged;
}

void FiltraMerge(tLista *merged)
{

    tNo *I = merged->ini;
    tNo *L = merged->ini;

    while (I != NULL)
    {

        tNo *C = I->next;

        while (C != NULL)
        {
            int id1 = getID(getQuestao(I));
            int id2 = getID(getQuestao(C));

            if (id1 == id2)
            {
                L->next = C->next;
                tNo *ByeBye = C;
                C = C->next;
                free(ByeBye);
            }

            if (C == NULL)
            {

                return;
            }

            L = C;
            C = C->next;
        }
        I = I->next;
    }
}

void AdicionaQuest(tLista *L1, tLista *L2, int num)
{

    tNo *p = L1->ini;

    while (p != NULL)
    {
        if (num == getID(getQuestao(p)))
        {

            tQuestao *Q = getQuestao(p);
            AdicionaElemento(L2, Q);
            return;
        }
        p = p->next;
    }
}

void LiberaBancoDeQuestoes(tLista *BQ)
{
    tNo *p = BQ->ini;

    while (p != NULL)
    {

        tNo *tchau = p;
        p = p->next;
        tQuestao *Q = getQuestao(tchau);
        LiberaQuest(Q);
        free(tchau);
    }

    free(BQ);
}

tQuestao *getQuestao(tNo *N)
{

    return N->Q;
}
