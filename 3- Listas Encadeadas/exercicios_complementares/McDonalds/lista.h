#ifndef _LISTA_H
#define _LISTA_H

typedef struct No tNo;

#include"produto.h"


tNo *CriaNo();
void RemoveElemento(tNo *Sent, char *nome);
void InsereElemento(tNo *Sent, TProduto *P);
void ImprimeLista(tNo *Sent);
int CalculaCalorias(tNo *Sent);
int Restricao(tNo *Sent, char *lalala);

#endif