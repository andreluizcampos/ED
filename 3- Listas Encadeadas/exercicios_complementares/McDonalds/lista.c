#include <stdio.h>
#include "pedido.h"
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct No
{

    tNo *next;
    void *dado;
};

tNo *CriaNo()
{

    tNo *node = malloc(sizeof(tNo));
    node->next = NULL;
    node->dado = NULL;

    return node;
}

void RemoveElemento(tNo *Sent, char *nome)
{

    if (Sent->next == NULL)
    {

        return;
    }

    tNo *I = Sent->next;

    tNo *B = Sent;

    while (I != NULL)
    {

        TProduto *P = (TProduto *)I->dado;

        char *name = RetornaNome(P);

        if ((strcmp(name, nome) == 0))
        {

            B->next = I->next;
            free(I);
            return;
        }
        B = I;
        I = I->next;
    }
}

void InsereElemento(tNo *Sent, TProduto *P)
{

    tNo *new = CriaNo();
    new->dado = P;

    if (Sent->next == NULL)
    {

        Sent->next = new;
        return;
    }

    tNo *I = Sent->next;

    while (1)
    {

        if (I->next == NULL)
        {

            I->next = new;
            return;
        }
        I = I->next;
    }
}
void ImprimeLista(tNo *Sent)
{

    if (Sent->next == NULL)
    {

        return;
    }

    tNo *I = Sent->next;

    while (I != NULL)
    {

        TProduto *P = (TProduto *)I->dado;

        ImprimeIngredientes(P);
        I = I->next;
    }
}

int CalculaCalorias(tNo *Sent)
{

    if (Sent->next == NULL)
    {

        return 0;
    }

    tNo *I = Sent->next;

    int v = 0;

    while (I != NULL)
    {

        TProduto *P = (TProduto *)I->dado;

        v += Calorias(P);

        I = I->next;
    }

    return v;
}

int Restricao(tNo *Sent, char *lalala)
{

    if (Sent->next == NULL)
    {

        return -1;
    }

    tNo *I = Sent->next;

    while (I != NULL)
    {

        TProduto *P = (TProduto *)I->dado;

        char *name = RetornaNome(P);

        if (VerificaIngrediente(P, lalala))
        {

            return 1;
        }

        I = I->next;
    }

    return 0;
}
