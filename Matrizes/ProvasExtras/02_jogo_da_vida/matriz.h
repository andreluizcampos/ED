#ifndef _MATRIZ_H
#define _MATRIZ_H

typedef struct Matriz tMatriz;

// Função que lê e retorna uma matriz
tMatriz *LeMatriz();
tMatriz *DuplicaMatriz(tMatriz *m);
void CopiaMatriz(tMatriz *m, tMatriz *C);
void LiberaMatriz(tMatriz *m);
void AlteraMatriz(tMatriz *m, tMatriz *d);
void PrintaMatriz(tMatriz *m);
void Loop(tMatriz *m, tMatriz *c);

#endif