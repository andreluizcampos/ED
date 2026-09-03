#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz
{
    int col;
    int lin;
    int **dados;
};

tMatriz *LeMatriz()
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

void DestroiMatriz(tMatriz *m)
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

            printf("%d ", m->dados[i][j]);
        }
        printf("\n");
    }
}

tMatriz *CopiaMatriz(tMatriz *m)
{

    tMatriz *C = (tMatriz *)malloc(sizeof(tMatriz));
    C->dados = (int **)malloc(sizeof(int *) * m->lin);
    C->lin = m->lin;
    C->col = m->col;

    for (int i = 0; i < C->lin; i++)
    {

        C->dados[i] = (int *)malloc(sizeof(int) * C->col);
    }

    for (int i = 0; i < C->lin; i++)
    {

        for (int j = 0; j < C->col; j++)
        {

            C->dados[i][j] = m->dados[i][j];
        }
    }

    return C;
}

void SuavizaMatriz(tMatriz *C, tMatriz *m)
{

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            if ((i == 0 || i == m->lin - 1) || (j == 0 || j == m->col - 1))
            {

                continue;
            }

            else
            {

                int counter = 0;
                int acc = 0;

                for (int x = i - 1; x <= i + 1; x++)
                {

                    for (int y = j - 1; y <= j + 1; y++)
                    {

                        counter += m->dados[x][y];
                        acc++;
                    }
                }

                C->dados[i][j] = counter / acc;
            }
        }
    }
}
