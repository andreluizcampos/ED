#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

int main()
{

    int LI, LF, CI, CF, P;

    tMatriz *m = CriaMatriz();
    scanf(" %d %d %d %d %d", &LI, &LF, &P, &CI, &CF);

    tMatriz *s = CriaSubMatriz(m, LI, LF, CI, CF, P);
    ImprimeMatriz(s);
    LiberaMatrizt(m);
    LiberaSub(s);

        return 0;
}