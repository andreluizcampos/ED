#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "matriz.h"

struct Matriz
{
    int **d;
    int c;
    int l;
};

tMatriz *CriaMatriz()
{

    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));

    scanf(" %d %d", &m->l, &m->c);

    m->d = (int **)malloc(sizeof(int *) * m->l);

    for (int i = 0; i < m->l; i++)
    {
        m->d[i] = (int *)malloc(sizeof(int) * m->c);
    }

    for (int i = 0; i < m->l; i++)
    {

        for (int j = 0; j < m->c; j++)
        {

            scanf(" %d", &m->d[i][j]);
        }
    }

    return m;
}

void LiberaMatriz(tMatriz *m)
{

    for (int i = 0; i < m->l; i++)
    {
        free(m->d[i]);
    }
    free(m->d);
    free(m);
}

void ImprimeMatriz(tMatriz *m)
{

    for (int i = 0; i < m->l; i++)
    {

        for (int j = 0; j < m->c; j++)
        {

            printf(" %d", m->d[i][j]);
        }

        printf("\n");
    }
}

void AplicaMediana(tMatriz *m, tMatriz *Dest)
{

    int *v = (int *)malloc(sizeof(int) * 9);

    int Med = 0;

    for (int i = 0; i < m->l; i++)
    {

        for (int j = 0; j < m->c; j++)
        {

            if (i == 0 || i == m->l - 1 || j == 0 || j == m->c - 1)
            {

                continue;
            }

            else
            {

                v[0] = m->d[i][j];
                v[1] = m->d[i][j + 1];
                v[2] = m->d[i][j - 1];
                v[3] = m->d[i - 1][j];
                v[4] = m->d[i - 1][j - 1];
                v[5] = m->d[i - 1][j + 1];
                v[6] = m->d[i + 1][j];
                v[7] = m->d[i + 1][j + 1];
                v[8] = m->d[i + 1][j - 1];
                OrdenaVetor(v);
                if (v[4] != m->d[i][j])
                {
                    m->d[i][j] = v[4];
                    Med++;
                }
            }
        }
    }
    ImprimeMatriz(m);
    printf("\nPixels alterados: %d\n", Med);
    free(v);
}

tMatriz *CopiaMatriz(tMatriz *S)
{

    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));
    m->c = S->c;
    m->l = S->l;

    m->d = (int **)malloc(sizeof(int *) * m->l);

    for (int i = 0; i < m->l; i++)
    {
        m->d[i] = (int *)malloc(sizeof(int) * m->c);
    }

    for (int i = 0; i < m->l; i++)
    {

        for (int j = 0; j < m->c; j++)
        {

            m->d[i][j] = S->d[i][j];
        }
    }

    return m;
}

void OrdenaVetor(int *v)
{

    int flag = 1;

    while (flag)
    {

        flag = 0;

        for (int i = 0; i < 8; i++)
        {

            if (v[i] > v[i + 1])
            {

                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                flag = 1;
            }
        }
    }
}
