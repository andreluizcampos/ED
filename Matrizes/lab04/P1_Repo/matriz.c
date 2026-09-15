#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

struct Matriz
{
    int lin;
    int col;
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

tMatriz *CopiaMatriz(tMatriz *M)
{

    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));
    m->lin = M->col;
    m->col = M->lin;

    m->nomes = (char ***)malloc(sizeof(char **) * m->lin);

    for (int i = 0; i < m->lin; i++)
    {

        m->nomes[i] = (char **)malloc(sizeof(char *) * m->col);
    }

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            InsereElemeneto(m, i, j, M->nomes[j][i]);
        }
    }

   

    return m;
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

    int total = m->col * m->lin;

    int c = m->col;
    int l = m->lin;

    for (int i = 0; i < total - 1; i++)
    {

        for (int j = i + 1; j < total; j++)
        {

            char *n1 = m->nomes[i / c][i % c];
            char *n2 = m->nomes[j / c][j % c];

            if (strcmp(n1, n2) > 0)
            {

                char *temp = m->nomes[i / c][i % c];
                m->nomes[i / c][i % c] = m->nomes[j / c][j % c];
                m->nomes[j / c][j % c] = temp;
            }
        }
    }
}

void PrintaPosicao(tMatriz *m, char *Nome)
{

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            if (strcmp(Nome, m->nomes[i][j]) == 0)
            {

                printf("PALAVRADA ACHADA! [%d, %d]\n", i, j);

                return;
            }
        }
    }

    printf("NAO ACHEI :(\n");
}

void InsereElemeneto(tMatriz *m, int lin, int col, char *nome)
{
    int len = strlen(nome) + 1;
    m->nomes[lin][col] = (char *)malloc(sizeof(char) * len);
    strcpy(m->nomes[lin][col], nome);
}
