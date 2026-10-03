#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "provas.h"

struct Prova
{
    tLista *Questoes;
    char *Nome;
};

struct Questao
{
    int ID;
    char *enunciado;
};

tProva *CriaProva(char *name)
{

    tProva *p = malloc(sizeof(tProva));
    int len = strlen(name) + 1;
    p->Nome = malloc(sizeof(char) * len);
    strcpy(p->Nome, name);
    p->Questoes = CriaLista();
    return p;
}

tQuestao *CriaQuest(char *name, int id)
{

    tQuestao *Q = malloc(sizeof(tQuestao));
    Q->ID = id;
    int len = strlen(name) + 1;
    Q->enunciado = malloc(sizeof(char) * len);
    strcpy(Q->enunciado, name);

    return Q;
}

void LiberaQuest(tQuestao *Q)
{

    free(Q->enunciado);
    free(Q);
}

void LiberaProva(tProva *P)
{

    free(P->Nome);
    LiberaLista(P->Questoes);
    free(P);
}

void ImprimeQuestao(tQuestao *Q, FILE *f)
{

    fprintf(f, "ID:Q%d, Enunciado: %s\n", Q->ID, Q->enunciado);
}

void ImprimeProva(tProva *P, FILE *f)
{

    fprintf(f, "%s\n", P->Nome);
    ImprimeLista(P->Questoes, f);
}

int getID(tQuestao *Q)
{

    return Q->ID;
}

tLista *getLista(tProva *P)
{

    return P->Questoes;
}

void SetLista(tLista *L, tProva *P)
{

    P->Questoes = L;
}