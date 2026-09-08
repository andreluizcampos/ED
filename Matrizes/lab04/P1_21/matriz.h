#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct Matriz tMatriz;

tMatriz *CriaMatriz();
void LiberaMatriz(tMatriz *m);
void PrintaMatriz(tMatriz *m);
void ExibeSubMatriz(tMatriz *m, int LI, int LF, int CI, int CF);
void ExibeTODAS(tMatriz *m);
tMatriz *CriaSub(tMatriz *M, int LI, int LF, int CI, int CF);
void ImprimeSubs(tMatriz *M);
void LiberaSub(tMatriz *M);


#endif