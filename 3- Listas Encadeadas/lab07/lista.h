#ifndef _LISTA_H
#define _LISTA_H

#include<stdio.h>

typedef struct No tNo;

typedef void (*ImprimeElemento)(void *dado, FILE *f);
typedef void (*LiberaElemento)(void *dado);
typedef char (*GetClasseElemento)(void *dado);
typedef float (*GetInfo)(void *dado);

tNo *CriaNo();
void LiberaNo(tNo *n);
void InsereElemento(tNo *dest, void *dado, tNo *sent, GetClasseElemento getClasse, GetInfo ginfo);
char GetClasseNo(tNo *n);
void LiberaLista(tNo *sent);
void ImprimeLista(tNo *sent, FILE *f);
void PrintClass(tNo *n, char key, FILE *f);

void CalculaMediaElementos(float *MCR, float *MSAL, int *Q1, int *Q2,tNo *sent);





#endif