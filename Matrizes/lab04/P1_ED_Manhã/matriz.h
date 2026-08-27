#ifndef MATRIZ_H
#define MATRIZ_H


typedef struct Matriz tMat;


tMat *LeMatriz();

void LiberaMatrizFull(tMat *m);

tMat *MatrizSuavaizada(tMat *m);

void printMat(tMat *m);

#endif
