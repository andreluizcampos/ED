#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include <string.h>

struct Matriz
{
    char **nomes;
    int col;
    int lin;
};

tMatriz *LeMatriz()
{

    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));

    scanf(" %d %d", &m->lin, &m->col);

    m->nomes = malloc(sizeof(char *) * m->col * m->lin);
    char nome[80];

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            scanf("%s", nome);

            int mult = strlen(nome) + 1;

            m->nomes[i * m->col + j] = (char *)malloc(sizeof(char) * mult);
            strcpy(m->nomes[m->col * i + j], nome);
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

            free(m->nomes[i * m->col + j]);
        }
    }
    free(m->nomes);
    free(m);
}
void Printa(tMatriz *m)
{

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            printf("%s ", m->nomes[i * m->col + j]);
        }

        printf("\n");
    }
}

int BuscaPalavra(tMatriz *m, char *word)
{

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            if (strcmp(m->nomes[i * m->col + j], word) == 0)
            {

                printf("Palavra encontrada na posicao [%d][%d]!\n", i, j);
                return 1;
            }
        }
    }

    printf("Palavra não encontrada :(\n)");

    return 0;
}

void OrdenaMatriz(tMatriz *m)
{

    int flag = 1;

    while (flag)
    {

        flag = 0;

        for (int i = 0; i < (m->lin * m->col) - 1; i++)
        {

            char *temp = m->nomes[i];

            if (strcmp(m->nomes[i + 1], m->nomes[i]) < 0)
            {

                m->nomes[i] = m->nomes[i + 1];
                m->nomes[i + 1] = temp;
                flag = 1;
            }
        }
    }
}
