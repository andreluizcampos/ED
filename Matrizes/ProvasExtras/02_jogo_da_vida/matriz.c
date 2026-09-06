#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct Matriz
{

    int col;
    int lin;
    int **dados;
    int qtd;
};

// Função que lê e retorna uma matriz
tMatriz *LeMatriz()
{

    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));

    int qntd = 0;

    scanf("%d %d %d", &m->lin, &m->col, &m->qtd);

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

tMatriz *DuplicaMatriz(tMatriz *m)
{

    tMatriz *C = (tMatriz *)malloc(sizeof(tMatriz));
    C->col = m->col;
    C->lin = m->lin;
    C->qtd = m->qtd;

    C->dados = (int **)malloc(sizeof(int *) * C->lin);

    for (int i = 0; i < C->lin; i++)
    {

        C->dados[i] = (int *)malloc(sizeof(int *)*C->col);
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

void CopiaMatriz(tMatriz *m, tMatriz *C)
{

    for (int i = 0; i < C->lin; i++)
    {

        for (int j = 0; j < C->col; j++)
        {

            C->dados[i][j] = m->dados[i][j];
        }
    }
}

void AlteraMatriz(tMatriz *m, tMatriz *d)
{

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            int count = 0;

            if (i == 0)
            {

                if (j == 0)
                {
                    count += m->dados[i + 1][j] == 1;
                    count += m->dados[i][j + 1] == 1;
                    count += m->dados[i + 1][j + 1] == 1;
                }
                else if (j == m->col - 1)
                {

                    count += m->dados[i + 1][j] == 1;
                    count += m->dados[i][j - 1] == 1;
                    count += m->dados[i + 1][j - 1] == 1;
                }

                else
                {

                    count += m->dados[i + 1][j] == 1;
                    count += m->dados[i][j + 1] == 1;
                    count += m->dados[i + 1][j + 1] == 1;
                    count += m->dados[i][j - 1] == 1;
                    count += m->dados[i + 1][j - 1] == 1;
                }
            }

            else if (i == m->lin - 1)
            {

                if (j == 0)
                {
                    count += m->dados[i - 1][j] == 1;
                    count += m->dados[i][j + 1] == 1;
                    count += m->dados[i - 1][j + 1] == 1;
                }
                else if (j == m->col - 1)
                {

                    count += m->dados[i - 1][j] == 1;
                    count += m->dados[i][j - 1] == 1;
                    count += m->dados[i - 1][j - 1] == 1;
                }

                else
                {

                    count += m->dados[i - 1][j] == 1;
                    count += m->dados[i][j + 1] == 1;
                    count += m->dados[i - 1][j + 1] == 1;
                    count += m->dados[i][j - 1] == 1;
                    count += m->dados[i - 1][j - 1] == 1;
                }
            }

            else
            {

                if (j == 0)
                {
                    count += m->dados[i - 1][j] == 1;     // Acima
                    count += m->dados[i][j + 1] == 1;     // Direita
                    count += m->dados[i - 1][j + 1] == 1; // D DireitaA
                    count += m->dados[i + 1][j] == 1;
                    count += m->dados[i + 1][j + 1] == 1;
                }

                else if (j == m->col - 1)
                {

                    count += m->dados[i - 1][j] == 1;
                    count += m->dados[i][j - 1] == 1;
                    count += m->dados[i - 1][j - 1] == 1;
                    count += m->dados[i + 1][j] == 1;
                    count += m->dados[i + 1][j - 1] == 1;
                }

                else
                {

                    count += m->dados[i - 1][j] == 1;
                    count += m->dados[i][j - 1] == 1;
                    count += m->dados[i - 1][j - 1] == 1;
                    count += m->dados[i + 1][j] == 1;
                    count += m->dados[i + 1][j - 1] == 1;
                    count += m->dados[i + 1][j + 1] == 1;
                    count += m->dados[i - 1][j + 1] == 1;
                    count += m->dados[i][j + 1] == 1;
                }
            }

            if (count < 2 || count > 3)
            {

                if (m->dados[i][j] == 1)
                {
                    d->dados[i][j] = 0;
                }
            }

            if (count == 3)
            {

                if (m->dados[i][j] == 0)
                {

                    d->dados[i][j] = 1;
                }
            }
        }
    }
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

    printf("\n");
}

void Loop(tMatriz *m, tMatriz *c)
{

    for (int i = 0; i < m->qtd + 1; i++)
    {

        PrintaMatriz(m);
        AlteraMatriz(m, c);
        CopiaMatriz(c, m);
    }
}
