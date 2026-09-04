#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

struct Matriz
{
    int c;
    int l;
    int **dados;
};

tMatriz *LeMatriz()
{

    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));
    scanf("%d %d", &m->l, &m->c);

    m->dados = (int **)malloc(sizeof(int *) * m->l);

    for (int i = 0; i < m->l; i++)
    {

        m->dados[i] = (int *)malloc(sizeof(int) * m->c);
    }

    for (int i = 0; i < m->l; i++)
    {

        for (int j = 0; j < m->c; j++)
        {

            scanf(" %d", &m->dados[i][j]);
        }
    }

    return m;
}

void LiberaMatriz(tMatriz *m)
{

    for (int i = 0; i < m->l; i++)
    {

        free(m->dados[i]);
    }
    free(m->dados);
    free(m);
}

void ProcuraMatriz(tMatriz *m1, tMatriz *m2)
{
    int count = 0;
    int x = 0, y = 0;

    for (int i = 0; i < m1->l; i++)
    {

        int p1 = 0, p2 = 0, cond = 1;

        for (int j = 0; j < m1->c; j++)
        {
            cond = 1;
            p1 = i, p2 = j;

            if ((i + m2->l <= m1->l) && (j + m2->c) <= m1->c)
            {

                for (int k = i; k < i + m2->l; k++)
                {
                    y = 0;

                    for (int m = j; m < j + m2->c; m++)
                    {

                        if (m2->dados[x][y] != m1->dados[k][m])
                        {
                           // printf("%d %d\n", p1, p2);
                            cond = 0;
                            break;
                        }

                        y++;
                    }

                    x++;
                }
                x = 0;

                if (cond)
                {
                    printf("Matriz encontrada em [%d][%d]\n", p1, p2);
                    count++;
                    cond = 0;
                }

                cond = 0;
            }
        }
    }

    if (count == 0)
    {

        printf("Matriz nao encontrada :(\n");
    }
}
void PrintaMatriz(tMatriz *m);
