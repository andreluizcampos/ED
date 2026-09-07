#ifndef _MATRIZ_H
#define _MATRZ_H

typedef struct Matriz tMatriz;

tMatriz *CriaMatriz();
void LiberaMatrizt(tMatriz *m);
void ImprimeMatriz(tMatriz *m);
tMatriz *CriaSubMatriz(tMatriz *M, int LI, int LF, int CI, int CF, int P);
void LiberaSub(tMatriz *m);

#endif