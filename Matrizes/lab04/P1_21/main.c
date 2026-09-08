#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main()
{

    tMatriz *m = CriaMatriz();

    int LI, LF, CI, CF;

    scanf(" %d %d %d %d", &LI, &LF, &CI, &CF);
    tMatriz *s = CriaSub(m, LI, LF, CI, CF);
    PrintaMatriz(s);
    printf("\n");
   ExibeTODAS(m);
    LiberaMatriz(m);
    LiberaSub(s);
}
