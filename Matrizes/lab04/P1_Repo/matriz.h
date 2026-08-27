#ifndef MAT_H
#define MAT_H

typedef struct  Matriz tMatriz;


tMatriz *LeMatriz();
void LiberaMatriz(tMatriz *m);
void Printa(tMatriz *m);
int BuscaPalavra(tMatriz *m, char *word);
void OrdenaMatriz(tMatriz *m);


#endif