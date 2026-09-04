#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

#define MAX_STR 90

struct Matriz
{
    char **words;
    int col;
    int lin;
};

tMatriz *LeMatriz()
{

    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));
    scanf(" %d %d", &m->lin, &m->col);

    m->words = (char **)malloc(sizeof(char *) * m->lin * m->col);

    for (int i = 0; i < m->lin * m->col; i++)
    {

        m->words[i] = (char *) malloc(sizeof(char) * MAX_STR);
    }

    for (int i = 0; i < m->lin * m->col; i++)
    {

        scanf("%s", m->words[i]);
    }

    return m;
}

void LiberaMatriz(tMatriz *m)
{

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            free(m->words[i * m->col + j]);
        }
    }

    free(m->words);

    free(m);
}

void Printa(tMatriz *m)
{

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            printf("%s ", m->words[i * m->col + j]);
        }

        printf("\n");
    }
}

int BuscaPalavra(tMatriz *m, char *word);

void OrdenaMatriz(tMatriz *m)
{

    int flag = 1;

    while (flag)
    {

        flag = 0;

        int max = m->col * m->lin;

        for (int i = 0; i < max - 1; i++)
        {

            if (strcmp(m->words[i], m->words[i + 1]) > 0)
            {

                char temp[70];
                strcpy(temp, m->words[i]);
                strcpy(m->words[i], m->words[i + 1]);
                strcpy(m->words[i + 1], temp);
                flag = 1;
            }
        }
    }
}
