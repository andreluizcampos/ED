#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include <string.h>

struct Matriz
{

    int col;
    int lin;
    int **dados;
};

tMatriz *CriaMatriz()
{

    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));

    scanf(" %d %d", &m->lin, &m->col);

    m->dados = (int **)malloc(sizeof(int *) * m->lin);

    for (int i = 0; i < m->lin; i++)
    {

        m->dados[i] = (int *)malloc(sizeof(int *) * m->col);
    }

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            scanf(" %d", &m->dados[i][j]);
        }
    }

    return m;
}

void LiberaMatriz(tMatriz *m)
{

    for (int i = 0; i < m->lin; i++)
    {

        free(m->dados[i]);
    }

    free(m->dados);
    free(m);
}

void PrintaMatriz(tMatriz *m)
{

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->lin; j++)
        {

            printf("%d ", m->dados[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

void ExibeTODAS(tMatriz *m)
{

    int mC = 0, mL = 0, mT = 0;

    for (int i = 0; i < m->lin; i++)
    {

        mL = m->lin - i;

        for (int j = 0; j < m->col; j++)
        {
            mC = m->col - j;
            mT = mC > mL ? mL : mC;

            printf("Submatrizes possiveis em [%d,%d]\n", i, j);

            for (int k = 0; k < mT; k++)
            {

                tMatriz *M = CriaSub(m, i, i + k, j, j + k);
                PrintaMatriz(M);
                LiberaSub(M);
            }
        }
    }
}

tMatriz *CriaSub(tMatriz *M, int LI, int LF, int CI, int CF)
{

    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));

    m->col = CF - CI + 1;
    m->lin = LF - LI + 1;

    m->dados = (int **)malloc(sizeof(int *) * m->lin);

    int a = 0;
    for (int i = LI; i <= LF; i++)
    {

        m->dados[a] = M->dados[i] + CI;
        a++;
    }

    return m;
}

void LiberaSub(tMatriz *M)
{

    free(M->dados);
    free(M);
}
