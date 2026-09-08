#ifndef _MATRIZ_H
#define _MATRZ_H

typedef struct Matriz tMatriz;

tMatriz *CriaMatriz();
void LiberaMatriz(tMatriz *m);
void ImprimeMatriz(tMatriz *m);
void AplicaMediana(tMatriz *m, tMatriz *Dest);
tMatriz *CopiaMatriz(tMatriz *S);
void OrdenaVetor(int *v);

#endif