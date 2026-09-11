#ifndef _MATRIZ_H
#define _MATRIZ_

typedef struct Matriz tMatriz;

tMatriz *CriaMatriz(int l, int c);
void SetaElemento(char *nome, tMatriz *m, int l, int c);
void LiberaMatriz(tMatriz *m);
void PrintaMatriz(tMatriz *m);
void OrdenaMatriz(tMatriz *m);
tMatriz *Tranposta(tMatriz *m);

#endif