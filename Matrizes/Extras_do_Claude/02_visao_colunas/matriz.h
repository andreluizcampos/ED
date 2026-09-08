#ifndef _MATRIZ_H
#define _MATRIZ_H

typedef struct Matriz tMatriz;

tMatriz *CriaMatriz();
void LiberaMatrizt(tMatriz *m);
void ImprimeMatriz(tMatriz *m);
tMatriz *CriaSubMatriz(tMatriz *M, int LI);
void LiberaSub(tMatriz *m);
void ContabilizaColunas(tMatriz *M);

#endif