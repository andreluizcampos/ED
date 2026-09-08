#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "matriz.h"

int main()
{

    tMatriz *m = CriaMatriz();
    int p = 0;

    scanf("%d", &p);

    tMatriz *col = CriaSubMatriz(m, p);
    ImprimeMatriz(col);

    ContabilizaColunas(m);

    LiberaMatrizt(m);
    LiberaSub(col);

    return 0;
}