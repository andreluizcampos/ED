#ifndef _MATRIZ_H
#define _MATRIZ_H

typedef struct matriz tMatriz;

tMatriz *LeMatriz();
void DestroiMatriz(tMatriz *m);
void ImprimeMatriz(tMatriz *m);
void LocalizaPalavra(tMatriz *m);

#endif