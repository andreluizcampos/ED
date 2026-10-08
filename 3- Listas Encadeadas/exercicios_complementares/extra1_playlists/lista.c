#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "musica.h"
#include "lista.h"

struct Lista
{

    tNo *ini;
    tNo *fim;
};

struct No
{

    tMusica *Mus;
    tNo *Next;
};

tLista *CriaLista()
{

    tLista *L = malloc(sizeof(tLista));
    L->fim = NULL;
    L->ini = NULL;

    return L;
}

void InsereElemento(tMusica *m, tLista *L)
{

    tNo *new = malloc(sizeof(tNo));

    if (L->fim == NULL && L->ini == NULL)
    {

        L->fim = new;
        L->ini = new;
        new->Next = NULL;
        new->Mus = m;
    }
    else
    {

        L->fim->Next = new;
        L->fim = new;
        new->Next = NULL;
        new->Mus = m;
    }
}

void RemoveElemento(int id, tLista *L)
{

    if (L->ini == NULL && L->fim == NULL)
    {

        return;
    }

    if (getID(L->ini->Mus) == id)
    {
        tNo *Bye = L->ini;
        L->ini = L->ini->Next;
        free(Bye);
        return;
    }

    tNo *ant = L->ini;
    tNo *p = L->ini;

    while (p != NULL)
    {

        if (getID(p->Mus) == id)
        {

            ant->Next = p->Next;
            free(p);
            return;
        }
        ant = p;
        p = p->Next;
    }
}

void ImprimeLista(tLista *L, FILE *f)
{

    tNo *p = L->ini;

    while (p != NULL)
    {

        PrintaMusica(p->Mus, f);
        p = p->Next;
    }

    return;
}

void LiberaBancoMusicas(tLista *BM)
{

    tNo *p = BM->ini;

    while (p != NULL)
    {
        tNo *ant = p;
        p = p->Next;
        LiberaMusica(ant->Mus);
        free(ant);
    }

    free(BM);
}

void LiberaLista(tLista *L)
{

    tNo *P = L->ini;

    while (P != NULL)
    {

        tNo *ant = P;
        P = P->Next;
        free(ant);
    }

    free(L);
}

void SelecionaMusica(int id, tLista *Src, tLista *Dest)
{

    tNo *p = Src->ini;

    while (p != NULL)
    {
        if (id == getID(p->Mus))
        {

            InsereElemento(p->Mus, Dest);
            return;
        }
        p = p->Next;
    }
}
