
#ifndef matriz_h
#define matriz_h


#define MAX_NOME_STRING 145

typedef struct  Matriz tMatriz;


int getLinhas(tMatriz *m);
int getColunas(tMatriz *m);
tMatriz* BuildaMatriz();
void LiberaMatriz(tMatriz *m);
tMatriz* TranpostaMatriz(tMatriz *m);
tMatriz* OrdenaAlfa(tMatriz *m);
void FreeParcial(tMatriz *m);
void PrintMatriz(tMatriz *m);
void TotalFree(tMatriz *m);

#endif