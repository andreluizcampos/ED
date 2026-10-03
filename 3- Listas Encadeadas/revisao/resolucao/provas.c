#include <stdio.h>
#include <string.h>
#include "provas.h"
#include <stdlib.h>
#include "lista.h"

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
    p->Questoes = CriaLista();
    int len = strlen(name) + 1;
    p->Nome = malloc(sizeof(char) * len);
    strcpy(p->Nome, name);

    return p;
}

tQuestao *CriaQuest(char *name, int id)
{

    tQuestao *q = malloc(sizeof(tQuestao));
    int len = strlen(name) + 1;
    q->enunciado = malloc(sizeof(char) * len);
    strcpy(q->enunciado, name);
    q->ID = id;

    return q;
}

void LiberaQuest(tQuestao *Q)
{

    free(Q->enunciado);
    free(Q);
}

void LiberaProva(tProva *P)
{

    LiberaLista(P->Questoes);
    free(P->Nome);
    free(P);
}

void ImprimeQuestao(tQuestao *Q, FILE *f)
{

    fprintf(f, "ID: Q%d, Enunciado: %s\n", Q->ID, Q->enunciado);
}

void ImprimeProva(tProva *P, FILE *f)
{

    fprintf(f, "Prova: %s\n", P->Nome);
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
