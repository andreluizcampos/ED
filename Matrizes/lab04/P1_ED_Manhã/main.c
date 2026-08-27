#include<stdlib.h>
#include<stdio.h>
#include"matriz.h"

int main (){

    tMat *m = LeMatriz();
    tMat *s = MatrizSuavaizada(m);
    
    printMat(m);
    printMat(s);
    printf("\n\n");
    LiberaMatrizFull(m);
    LiberaMatrizFull(s);

    return 0;

}