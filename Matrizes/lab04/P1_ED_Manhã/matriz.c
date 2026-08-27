#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Matriz
{
    int col, lin;
    int *elementos;
};

tMat *LeMatriz()
{

    tMat *m = (tMat *)malloc(sizeof(tMat));

    scanf("%d %d ", &m->lin, &m->col);

    m->elementos = malloc(sizeof(int) * m->col * m->lin);

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {
            scanf("%d ", &m->elementos[i * m->col + j]);
        }
    }

    return m;
}

void LiberaMatrizFull(tMat *m)
{

    free(m->elementos);
    free(m);
}

tMat *MatrizSuavaizada(tMat *m)
{

    tMat *s = (tMat *)malloc(sizeof(tMat));
    s->col = m->col;
    s->lin = m->lin;
    s->elementos = (int *)malloc(sizeof(int) * s->col * s->lin);

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {
            if (j == 0 || j == m->col - 1 || i == 0 || i == m->lin - 1)
            {

                s->elementos[s->col * i + j] = (m->elementos[i * m->col + j]);
                continue;
            }

            else
            {

                for (int k = i - 1; k <= i + 1; k++)
                {

                    int sum = 0;
                    int contador = 0;

                    for (int l = j - 1; l <= j + 1; l++)
                    {

                        sum += m->elementos[m->col * k + l];
                        contador++;
                    }

                    s->elementos[i * m->col + j] = sum / contador;
                }
            }
        }
    }

    return s;
}

void printMat(tMat *m)
{

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            printf("%d ", m->elementos[i * m->col + j]);
        }

        printf("\n");
    }
    printf("\n");
}