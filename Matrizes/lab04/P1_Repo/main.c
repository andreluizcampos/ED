#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matriz.h"

int main()
{

    tMatriz *m = LeMatriz();
    Printa(m);
    printf("\n");
    OrdenaMatriz(m);
    Printa(m);
    LiberaMatriz(m);


    return 0;
}