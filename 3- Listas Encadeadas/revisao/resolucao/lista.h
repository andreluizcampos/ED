#ifndef _LISTA_H
#define _LISTA_H

#include <stdio.h>

typedef struct Lista tLista;
typedef struct No tNo;

#include "provas.h"

tLista *CriaLista();
void ImprimeLista(tLista *l, FILE *f);
void AdicionaElemento(tLista *l, tQuestao *Q);
void RemoveElemento(tNo *n1);
void LiberaLista(tLista *l);
tLista *Merge(tLista *l1, tLista *l2);
void FiltraMerge(tLista *merged);
void AdicionaQuest(tLista *L1, tLista *L2, int num);
void LiberaBancoDeQuestoes(tLista *BQ);
tQuestao *getQuestao(tNo *N);

#endif
