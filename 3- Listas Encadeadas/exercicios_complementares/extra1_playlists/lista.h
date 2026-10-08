#ifndef _LISTA_H
#define _LISTA_H

#include "musica.h"

typedef struct Lista tLista;
typedef struct No tNo;

tLista *CriaLista();
void InsereElemento(tMusica *m, tLista *L);
void RemoveElemento(int id, tLista *L);
void ImprimeLista(tLista *L, FILE *f);
tLista *Filtrada(tLista *L1, tLista *L2);
void LiberaBancoMusicas(tLista *BM);
void LiberaLista(tLista *L);
void SelecionaMusica(int id, tLista *Src, tLista *Dest);

#endif
