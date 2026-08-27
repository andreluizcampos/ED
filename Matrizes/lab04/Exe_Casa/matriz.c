#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

#define MAX_STR 50

struct Matriz
{
    int linhas;
    int col;
    char **conteudo;
};

int getLinhas(tMatriz *m)
{

    return m->linhas;
}
int getColunas(tMatriz *m)
{

    return m->col;
}

tMatriz *BuildaMatriz()
{

    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));
    scanf("%d %d", &m->linhas, &m->col);
    m->conteudo = (char **)malloc(sizeof(char *) * m->linhas * m->col);

    for (int i = 0; i < m->linhas; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            m->conteudo[i * m->col + j] = (char *)malloc(sizeof(char) * MAX_STR);
            scanf("%s", m->conteudo[i * m->col + j]);
        }
    }

    return m;
}
void LiberaMatriz(tMatriz *m)
{

    for (int i = 0; i < m->linhas * m->col; i++)
    {

        free(m->conteudo[i]);
    }
    free(m->conteudo);
    free(m);
}
tMatriz *TranpostaMatriz(tMatriz *m)
{

    tMatriz *T = (tMatriz *)malloc(sizeof(tMatriz));
    T->linhas = m->col;
    T->col = m->linhas;
    T->conteudo = (char **)malloc(sizeof(char *) * T->linhas * T->col);

    for (int i = 0; i < m->linhas; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            T->conteudo[j * T->col + i] = m->conteudo[i * m->col + j];
        }
    }

    return T;
}

tMatriz *OrdenaAlfa(tMatriz *m)
{
    tMatriz *M = (tMatriz *)malloc(sizeof(tMatriz));
    M->linhas = m->linhas;
    M->col = m->col;
    M->conteudo = (char **)malloc(sizeof(char *) * m->linhas * m->col);

    for (int i = 0; i < m->linhas * m->col; i++)
    {

        M->conteudo[i] = m->conteudo[i];
    }

    int flag = 1;

    while (flag)
    {

        flag = 0;

        for (int n = 0; n < (m->linhas * m->col) - 1; n++)
        {

            if (strcmp(M->conteudo[n], M->conteudo[n + 1]) > 0)
            {

                char *temp = M->conteudo[n];
                M->conteudo[n] = M->conteudo[n + 1];
                M->conteudo[n + 1] = temp;
                flag = 1;
            }
        }
    }

    return M;
}
void FreeParcial(tMatriz *m)
{

    free(m->conteudo);
    free(m);
}

void PrintMatriz(tMatriz *m)
{

    for (int i = 0; i < m->linhas; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            printf("%s ", m->conteudo[i * m->col + j]);
        }

        printf("\n");
    }
}

void TotalFree(tMatriz *m)
{

    for (int i = 0; i < m->linhas * m->col; i++)
    {

        free(m->conteudo[i]);
    }

    free(m->conteudo);
    free(m);
}
