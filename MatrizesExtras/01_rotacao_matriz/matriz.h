#ifndef _MATRIZ_H
#define _MATRIZ_H

#include<stdio.h>
#include<string.h>

typedef struct Matriz tMatriz;


tMatriz *LeMatriz();

void LiberaMatriz(tMatriz *m);

tMatriz *TranspoeMatriz(tMatriz *m);

tMatriz *RecalculaMatriz(tMatriz *m);

void ImprimeMatriz(tMatriz *m);

void LiberaMatrizParcial(tMatriz *m);


#endif