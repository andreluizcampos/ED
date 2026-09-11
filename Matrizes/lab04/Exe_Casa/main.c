#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

int main()
{

    int col, lin;

    scanf(" %d %d", &lin, &col);

    tMatriz *m = CriaMatriz(lin, col);

    for (int i = 0; i < lin; i++)
    {

        for (int j = 0; j < col; j++)
        {

            char *nome;
            scanf("%ms", &nome);
            SetaElemento(nome, m, i, j);
        }
    }

    PrintaMatriz(m);
    tMatriz *T = Tranposta(m);

    printf("\n== Primeiro experimento:\n");
    PrintaMatriz(T);
    printf("\n== Segundo experimento:\n");
    OrdenaMatriz(m);
    PrintaMatriz(m);

    LiberaMatriz(m);
    LiberaMatriz(T);
}