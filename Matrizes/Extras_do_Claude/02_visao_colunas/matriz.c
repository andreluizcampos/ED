#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include <string.h>
#include <limits.h>

struct Matriz
{
    int **dados;
    int col;
    int lin;
};

tMatriz *CriaMatriz()
{

    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));
    scanf("%d %d", &m->lin, &m->col);

    m->dados = (int **)malloc(sizeof(int *) * m->lin);

    for (int i = 0; i < m->lin; i++)
    {

        m->dados[i] = (int *)malloc(sizeof(int) * m->col);
    }

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            scanf("%d", &m->dados[i][j]);
        }
    }

    return m;
}
void LiberaMatrizt(tMatriz *m)
{

    for (int i = 0; i < m->lin; i++)
    {

        free(m->dados[i]);
    }

    free(m->dados);
    free(m);
}

void ImprimeMatriz(tMatriz *m)
{

    int maior = INT_MIN;
    int menor = INT_MAX;
    int sum = 0;
    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            printf("%d ", m->dados[i][j]);
            sum += m->dados[i][0];
            maior = m->dados[i][0] > maior ? m->dados[i][0] : maior;
            menor = m->dados[i][0] < menor ? m->dados[i][0] : menor;
        }

        printf("\n");
    }

    printf("\n Min: %d | Max: %d | Soma: %d\n", menor, maior, sum);
}

tMatriz *CriaSubMatriz(tMatriz *M, int L)
{

    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));
    m->dados = (int **)malloc(sizeof(int *) * M->lin);
    m->col = 1;
    m->lin = M->lin;

    for (int i = 0; i < M->lin; i++)
    {
        m->dados[i] = M->dados[i] + L;
    }

    return m;
}

void ContabilizaColunas(tMatriz *M)
{

    int maior = INT_MIN;
    int menor = INT_MAX;

    printf("\n Estatisticas de todas as colunas\n");

    for (int k = 0; k < M->lin; k++)
    {
        int sum = 0;
        tMatriz *m = CriaSubMatriz(M, k);

        for (int i = 0; i < m->lin; i++)
        {

            sum += m->dados[i][0];
            maior = m->dados[i][0] > maior ? m->dados[i][0] : maior;
            menor = m->dados[i][0] < menor ? m->dados[i][0] : menor;
        }

        printf("Coluna %d -> Min: %d | Max: %d | Soma: %d\n", k, menor, maior, sum); // Coluna 0 -> Min: 1 | Max: 21 | Soma: 55

        LiberaSub(m);
    }
}

void LiberaSub(tMatriz *m)
{

    free(m->dados);
    free(m);
}