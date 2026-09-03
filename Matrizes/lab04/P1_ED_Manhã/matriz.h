#ifndef _MATRIZ_H
#define _MARTIZ_H

typedef struct matriz tMatriz;

tMatriz *LeMatriz();

void DestroiMatriz(tMatriz *m);

void PrintaMatriz(tMatriz *m);

void SuavizaMatriz(tMatriz *C, tMatriz *m);

tMatriz *CopiaMatriz(tMatriz *m);
 
#endif