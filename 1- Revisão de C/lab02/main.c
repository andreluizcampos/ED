#include <stdio.h>
#include <stdlib.h>
#include "supermercado.h"

int main()
{

    tSupermercado *M = CriaMercado();

    int n = 0;

    scanf("%d ", &n);

    tFranquia **filiais = CriaFranquias(n, getQtdProdutosMercado(M));
    PrintaMercado(M,filiais,n);
    LiberaMercado(M);
    LiberaFRANQUIAS(filiais,n);
    

}