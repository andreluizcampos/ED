#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matriz.h"

struct Matriz
{
    int col;
    int lin;
    char ***nomes;
};

tMatriz *CriaMatriz(int l, int c)
{

    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));
    m->lin = l;
    m->col = c;
    m->nomes = (char ***)malloc(sizeof(char **) * m->lin);

    for (int i = 0; i < m->lin; i++)
    {

        m->nomes[i] = (char **)malloc(sizeof(char *) * m->col);
    }

    return m;
}

void SetaElemento(char *nome, tMatriz *m, int l, int c)
{

    m->nomes[l][c] = (char *)malloc(sizeof(char) * (strlen(nome) + 1));
    strcpy(m->nomes[l][c], nome);
    free(nome);
}

void LiberaMatriz(tMatriz *m)
{

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            free(m->nomes[i][j]);
        }
        free(m->nomes[i]);
    }

    free(m->nomes);
    free(m);
}
void PrintaMatriz(tMatriz *m)
{

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            printf("%s ", m->nomes[i][j]);
        }

        printf("\n");
    }
}

void OrdenaMatriz(tMatriz *m)
{

    int flag = 1;

    int total = m->lin * m->col;

    for (int i = 0; i < total - 1; i++)
    {

        for (int j = i + 1; j < total; j++)
        {

            char *nome1 = m->nomes[i / m->col][i % m->col];
            char *nome2 = m->nomes[j / m->col][j % m->col];

            if (strcmp(nome1, nome2) > 0)
            {

                char *temp = m->nomes[i / m->col][i % m->col];
                m->nomes[i / m->col][i % m->col] = m->nomes[j / m->col][j % m->col];
                m->nomes[j / m->col][j % m->col] = temp;
            }
        }
    }
}

tMatriz *Tranposta(tMatriz *m)
{

    tMatriz *Mat = (tMatriz *)malloc(sizeof(tMatriz));
    Mat->lin = m->col;
    Mat->col = m->lin;

    Mat->nomes = (char ***)malloc(sizeof(char **) * Mat->lin);

    for (int i = 0; i < Mat->lin; i++)
    {

        Mat->nomes[i] = (char **)malloc(sizeof(char *) * Mat->col);
    }

    for (int i = 0; i < Mat->lin; i++)
    {

        for (int j = 0; j < Mat->col; j++)
        {

            int size = strlen(m->nomes[j][i]);
            Mat->nomes[i][j] = (char *)malloc(sizeof(char) * (size + 1));
        }
    }

    for (int i = 0; i < Mat->lin; i++)
    {

        for (int j = 0; j < Mat->col; j++)
        {

            strcpy(Mat->nomes[i][j], m->nomes[j][i]);
        }
    }

    return Mat;
}
