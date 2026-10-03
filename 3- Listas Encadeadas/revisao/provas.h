#ifndef _PROVAS_H
#define _PROVAS_H

#include <stdio.h>

typedef struct Questao tQuestao;
typedef struct Prova tProva;
#include"lista.h"

tProva *CriaProva(char *name);
tQuestao *CriaQuest(char *name, int id);
void LiberaQuest(tQuestao *Q);
void LiberaProva(tProva *P);
void ImprimeQuestao(tQuestao *Q, FILE *f);
void ImprimeProva(tProva *P, FILE *f);
int getID(tQuestao *Q);
tLista *getLista(tProva *P);
void SetLista(tLista *L, tProva *P);


#endif
