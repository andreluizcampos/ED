/* Andre Luiz Campos */
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz {
    int **dados;   /* vetor de ponteiros para linhas */
    int nlin;
    int ncol;
};

tMatriz *criaMatriz(int nlin, int ncol)
{
    int i, j;
    tMatriz *m = (tMatriz *) malloc(sizeof(tMatriz));
    m->nlin = nlin;
    m->ncol = ncol;
    m->dados = (int **) malloc(sizeof(int *) * nlin);
    for (i = 0; i < nlin; i++) {
        m->dados[i] = (int *) malloc(sizeof(int) * ncol);
        for (j = 0; j < ncol; j++)
            m->dados[i][j] = 0;
    }
    return m;
}

void defineElemento(tMatriz *m, int i, int j, int v)
{
    m->dados[i][j] = v;
}

int pegaElemento(tMatriz *m, int i, int j)
{
    return m->dados[i][j];
}

int pegaNLinhas(tMatriz *m) { return m->nlin; }
int pegaNColunas(tMatriz *m) { return m->ncol; }

/* ordena um vetor pequeno por insercao */
static void ordenaVetor(int *v, int n)
{
    int i, j, chave;
    for (i = 1; i < n; i++) {
        chave = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

tMatriz *filtroMediana(tMatriz *m)
{
    int i, j, x, y, k;
    int janela[9];
    tMatriz *nova = criaMatriz(m->nlin, m->ncol);

    for (i = 0; i < m->nlin; i++) {
        for (j = 0; j < m->ncol; j++) {
            if (i == 0 || j == 0 || i == m->nlin - 1 || j == m->ncol - 1) {
                nova->dados[i][j] = m->dados[i][j];   /* borda: inalterado */
            } else {
                k = 0;
                for (x = i - 1; x <= i + 1; x++)
                    for (y = j - 1; y <= j + 1; y++)
                        janela[k++] = m->dados[x][y];
                ordenaVetor(janela, 9);
                nova->dados[i][j] = janela[4];        /* mediana de 9 valores */
            }
        }
    }
    return nova;
}

int contaDiferencas(tMatriz *a, tMatriz *b)
{
    int i, j, cont = 0;
    for (i = 0; i < a->nlin; i++)
        for (j = 0; j < a->ncol; j++)
            if (a->dados[i][j] != b->dados[i][j])
                cont++;
    return cont;
}

void imprimeMatriz(FILE *out, tMatriz *m)
{
    int i, j;
    for (i = 0; i < m->nlin; i++) {
        for (j = 0; j < m->ncol; j++)
            fprintf(out, "%d%s", m->dados[i][j], (j == m->ncol - 1) ? "" : " ");
        fprintf(out, "\n");
    }
}

void liberaMatriz(tMatriz *m)
{
    int i;
    for (i = 0; i < m->nlin; i++)
        free(m->dados[i]);
    free(m->dados);
    free(m);
}
