/* Andre Luiz Campos */
#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>

/* TAD Matriz de inteiros (tipo opaco) */
typedef struct matriz tMatriz;

/* Cria uma matriz nlin x ncol com todos os elementos zerados.
 * pre: nlin > 0 e ncol > 0
 * pos: matriz alocada dinamicamente */
tMatriz *criaMatriz(int nlin, int ncol);

/* Escreve o valor v na posicao [i][j] */
void defineElemento(tMatriz *m, int i, int j, int v);

/* Retorna o valor da posicao [i][j] */
int pegaElemento(tMatriz *m, int i, int j);

int pegaNLinhas(tMatriz *m);
int pegaNColunas(tMatriz *m);

/* Retorna uma NOVA matriz, de mesmas dimensoes, em que cada pixel interno eh
 * a mediana da janela 3x3 centrada nele. Os pixels de borda sao copiados. */
tMatriz *filtroMediana(tMatriz *m);

/* Conta quantas posicoes diferem entre duas matrizes de mesma dimensao */
int contaDiferencas(tMatriz *a, tMatriz *b);

/* Imprime a matriz no arquivo out, um elemento por espaco, uma linha por linha */
void imprimeMatriz(FILE *out, tMatriz *m);

void liberaMatriz(tMatriz *m);

#endif
