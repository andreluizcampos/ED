#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main()
{

    tMatriz *m = LeMatriz();
    tMatriz *C = CopiaMatriz(m);
    SuavizaMatriz(C, m);
    PrintaMatriz(m);
    printf("\n");

    printf("A matriz suavizada eh:\n");
    PrintaMatriz(C);

    DestroiMatriz(m);
    DestroiMatriz(C);
}