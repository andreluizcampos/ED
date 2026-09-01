#include "matriz.h"
#include <stdlib.h>

struct Matriz
{
    int *dados;
    int col;
    int linhas;
};

tMatriz *LeMatriz()
{

    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));
    scanf(" %d %d", &m->linhas, &m->col);

    m->dados = malloc(sizeof(int) * m->linhas * m->col);

    for (int i = 0; i < m->linhas; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            scanf(" %d", &m->dados[i * m->col + j]);
        }
    }

    return m;
}

void LiberaMatriz(tMatriz *m)
{

    free(m->dados);
    free(m);
}

tMatriz *TranspoeMatriz(tMatriz *m)
{

    tMatriz *R = (tMatriz *)malloc(sizeof(tMatriz));
    R->col = m->linhas;
    R->linhas = m->col;
    R->dados = malloc(sizeof(int) * R->linhas * R->col);

    for (int i = 0; i < R->linhas; i++)
    {

        for (int j = 0; j < R->col; j++)
        {

            R->dados[i * R->col + j] = m->dados[j * m->col + i];
        }
    }

    for (int i = 0; i < R->linhas; i++)
    {

        for (int j = 0; j < (R->col / 2); j++)
        {
            int temp = R->dados[i * R->col + ((R->col - 1) - j)];
            R->dados[i * R->col + ((R->col - 1) - j)] = R->dados[i * R->col + j];
            R->dados[i * R->col + j] = temp;
        }
    }

    return R;
}

void ImprimeMatriz(tMatriz *m)
{

    for (int i = 0; i < m->linhas; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            printf("%d ", m->dados[i * m->col + j]);
        }

        printf("\n");
    }
}
