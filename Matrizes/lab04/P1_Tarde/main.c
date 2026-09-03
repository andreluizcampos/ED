#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

int main()
{

    tMatriz *m = LeMatriz();
    ImprimeMatriz(m);
    LocalizaPalavra(m);
    DestroiMatriz(m);

    return 0;
}