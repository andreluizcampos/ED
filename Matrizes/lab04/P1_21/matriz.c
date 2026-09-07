#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

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

        for (int j = 0; j < m->col; j++)
        {

            printf("%d ", *(m->dados[i] + j));
        }
        printf("\n");
    }
}

tMatriz *CriaSub(tMatriz *M, int LI, int LF, int CI, int CF)
{

    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));
    m->col = CF - CI + 1;
    m->lin = LF - LI + 1;
    m->dados = (int **)malloc(sizeof(int *) * m->lin);
    int a = 0, b = 0;

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

void ImprimeSubs(tMatriz *M)
{

    for (int i = 0; i < M->lin; i++)
    {

        for (int j = 0; j < M->col; j++)
        {

            int m_c, m_l, mt;

            m_c = M->col - j;
            m_l = M->lin - i;

            mt = m_c > m_l ? m_l : m_c;

            for (int k = 0; k < mt; k++)
            {
                printf("Submatriz Quadrada %dx%d em [%d, %d]\n", k + 1, k + 1, i, j);
                tMatriz *sub = CriaSub(M, i, i + k, j, j + k);
                PrintaMatriz(sub);
                printf("\n");
                free(sub->dados);
                free(sub);
            }
        }
    }
}