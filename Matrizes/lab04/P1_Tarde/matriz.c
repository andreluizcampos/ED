#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#define MAX_STR 150

struct matriz
{
    char ***dados;
    int col;
    int lin;
};

tMatriz *LeMatriz()
{
    // Dados(***) -> Linha(**) -> String(*) (Precisa ser alocada)
    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));
    scanf("%d %d", &m->lin, &m->col);

    m->dados = (char ***)malloc(sizeof(char **) * m->lin);

    for (int i = 0; i < m->lin; i++)
    {

        m->dados[i] = malloc(sizeof(char *) * m->col);

        for (int j = 0; j < m->col; j++)
        {

            m->dados[i][j] = (char *)malloc(sizeof(char) * MAX_STR);
            scanf("%s", m->dados[i][j]);
        }
    }

    return m;
}
void DestroiMatriz(tMatriz *m)
{

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            free(m->dados[i][j]);
        }
    }

    for (int i = 0; i < m->lin; i++)
    {

        free(m->dados[i]);
    }

    free(m->dados);
    free(m);
}
void ImprimeMatriz(tMatriz *m)
{

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            printf("%s ", m->dados[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void LocalizaPalavra(tMatriz *m)
{
    char word[150];

    while (1)
    {
        int flag = 0;
        printf("==> Digite a palavra para o caça-palavras ou 0, caso queira sair: \n");
        if (scanf("%[]", word) != 1)
        {

            break;
        }

        if (strcmp(word, "0") == 0)
        {

            printf("Program ended with exit code: %s\n", word);
            break;
        }

        else
        {
            for (int i = 0; i < m->lin; i++)
            {

                for (int j = 0; j < m->col; j++)
                {

                    if (strcmp(word, m->dados[i][j]) == 0)
                    {

                        printf("%s\n", word);
                        printf("Palavra encontrada na posicao [%d][%d] :)!\n", i, j);
                        flag = 1;
                    }
                }
            }

            if (!flag)
            {

                printf("%s\n", word);
                printf("Plavara não encontrada :(...\n");
            }
        }
    }
}