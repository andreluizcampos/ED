#ifndef _MATRIZ_H
#define _MATRIZ_H

typedef struct Matriz tMatriz;

tMatriz *CriaMatriz(int l, int c);
tMatriz *CopiaMatriz(tMatriz *M);
void LiberaMatriz(tMatriz *m);
void PrintaMatriz( tMatriz *m);
void OrdenaMatriz(tMatriz *m);
void PrintaPosicao(tMatriz *m, char *Nome);
void InsereElemeneto( tMatriz *m, int lin, int col, char *nome);



#endif