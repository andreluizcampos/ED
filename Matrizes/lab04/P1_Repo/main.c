#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

int main()
{

    char *nome;

    int l = 0, c = 0;

    scanf("%d %d", &l, &c);

    tMatriz *M = CriaMatriz(l, c);

    for (int i = 0; i < l; i++)
    {

        for (int j = 0; j < c; j++)
        {

            scanf("%ms", &nome);
            InsereElemeneto(M, i, j, nome);
            free(nome);
        }
    }

    PrintaMatriz(M);
    printf("\n");
    tMatriz *T = CopiaMatriz(M);

    PrintaMatriz(T);
    printf("\n");
    printf("\n");

    OrdenaMatriz(T);
    printf("\n");
    printf("\n");

    PrintaMatriz(T);
    LiberaMatriz(T);
    LiberaMatriz(M);
}