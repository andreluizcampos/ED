#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

int main()
{

    tMatriz *m = LeMatriz();
    tMatriz *C = DuplicaMatriz(m);
    Loop(m, C);
    LiberaMatriz(m);
    LiberaMatriz(C);
}
