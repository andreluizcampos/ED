#ifndef _MATRIZ_H
#define _MATRIZ_H

typedef struct Matriz tMatriz;


tMatriz *LeMatriz();
void LiberaMatriz(tMatriz *m);
void ProcuraMatriz(tMatriz *m1, tMatriz *m2);
void PrintaMatriz(tMatriz *m);



#endif