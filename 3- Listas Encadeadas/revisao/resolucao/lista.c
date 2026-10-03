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
    tNo *final;
};

tLista *CriaLista()
{
    tLista *l = malloc(sizeof(tLista));
    l->final = NULL;
    l->ini = NULL;

    return l;
}

void ImprimeLista(tLista *l, FILE *f)
{

    tNo *p = l->ini;

    while (p != NULL)
    {

        ImprimeQuestao(p->Q, f);
        p = p->next;
    }
}

void AdicionaElemento(tLista *l, tQuestao *q)
{

    tNo *new = malloc(sizeof(tNo));
    new->Q = q;

    if (l->ini == NULL)
    {
        new->next = NULL;
        l->ini = new;
        l->final = new;
        return;
    }

    else
    {
        l->final->next = new;
        new->next = NULL;
        l->final = new;
        return;
    }
}

void AdicionaQuest(tLista *L1, tLista *L2, int num)
{

    tNo *p = L2->ini;

    // L1 -> Lista para inserir as questoes advindas da terceira.
    // L2 -> Banco de Questoes 

    while (p != NULL)
    {

        if (getID(p->Q) == num)
        {

            if (L1->ini == NULL)
            {

                tNo *n = malloc(sizeof(tNo));
                n->Q = getQuestao(p);
                L1->final = n;
                L1->ini = n;
                n->next = NULL;
            }

            else
            {
                tNo *n = malloc(sizeof(tNo));
                n->Q = getQuestao(p);
                n->next = L1->ini;
                L1->ini = n;
            }

            return;
        }

        p = p->next;
    }
}

void RemoveElemento(tNo *n1)
{

    free(n1);
}

tLista *Merge(tLista *l1, tLista *l2)
{

    tNo *L1, *L2;

    tLista *l = CriaLista();

    L1 = l1->ini;
    L2 = l2->ini;

    while (1)
    {

        if (L1 != NULL)
        {

            AdicionaElemento(l, L1->Q);
        }
        if (L2 != NULL)
        {

            AdicionaElemento(l, L2->Q);
        }

        if (L1 == NULL && L2 == NULL)
        {

            return l;
        }

        if (L1 != NULL)
        {
            L1 = L1->next;
        }

        if (L2 != NULL)
        {

            L2 = L2->next;
        }
    }

    return l;
}

void FiltraMerge(tLista *merged)
{

    if (merged->ini == NULL)
    {

        return;
    }

    tNo *ant = merged->ini;
    tNo *BACK = NULL;

    while (ant != NULL)
    {

        int ID1 = getID(ant->Q);
        int flag = 0;

        tNo *comp = ant->next;

        while (comp != NULL)
        {

            int ID2 = getID(comp->Q);

            if (ID2 == ID1)
            {
                flag = 1;
                break;
            }

            comp = comp->next;
        }

        if (flag)
        {
            tNo *morrido = ant;
            ant = ant->next;

            if (BACK == NULL)
            {
                merged->ini = ant;
            }

            else
            {
                BACK->next = ant;
            }

            RemoveElemento(morrido);
        }

        else
        {
            BACK = ant;
            ant = ant->next;
        }
    }
}

void LiberaBancoDeQuestoes(tLista *BQ)
{

    tNo *p = BQ->ini;

    while (p != NULL)
    {
        LiberaQuest(p->Q);
        tNo *morrido = p;
        p = p->next;
        free(morrido);
    }

    free(BQ);
}

void LiberaLista(tLista *l)
{

    tNo *p = l->ini;

    while (p != NULL)
    {
        tNo *morrido = p;
        p = p->next;
        free(morrido);
    }

    free(l);
}

tQuestao *getQuestao(tNo *N)
{

    return N->Q;
}
