#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matriz.h"

int main()
{
    tMatriz *m = CriaMatriz();
    tMatriz *c = CopiaMatriz(m);

    printf("\nMatriz Original:\n");
    printf("\n");
    ImprimeMatriz(m);
    printf("\nMatriz com filtro de mediana:\n\n");
    AplicaMediana(c, m);
    LiberaMatriz(c);
    LiberaMatriz(m);
}