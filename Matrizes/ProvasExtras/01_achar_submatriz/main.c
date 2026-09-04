#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

int main()
{

    tMatriz *m1 = LeMatriz();
    tMatriz *m2 = LeMatriz();

    ProcuraMatriz(m1, m2);

    LiberaMatriz(m1);
    LiberaMatriz(m2);
}