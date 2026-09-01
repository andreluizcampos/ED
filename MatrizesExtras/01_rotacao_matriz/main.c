#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matriz.h"

int main()
{

    tMatriz *M = LeMatriz();
    tMatriz *T = TranspoeMatriz(M);
    ImprimeMatriz(T);
    LiberaMatriz(M);
    LiberaMatriz(T);

    return 0;
}
