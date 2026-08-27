#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

int main()
{

    tMatriz *M = BuildaMatriz();
    tMatriz *T = TranpostaMatriz(M);
    tMatriz *A = OrdenaAlfa(M);

    printf("\n");
    PrintMatriz(M);
    printf("\n");
    PrintMatriz(T);
    printf("\n");
    PrintMatriz(A);
    printf("\n");

    FreeParcial(T);
    FreeParcial(A);
    TotalFree(M);

    return 0;
}