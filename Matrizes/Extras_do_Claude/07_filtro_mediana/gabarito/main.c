/* Andre Luiz Campos */
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(void)
{
    int nlin, ncol, i, j, v;
    FILE *in, *out;
    tMatriz *original, *mediana;

    in = fopen("entrada.txt", "r");
    if (in == NULL) {
        printf("Erro ao abrir entrada.txt\n");
        return 1;
    }

    fscanf(in, "%d %d", &nlin, &ncol);
    original = criaMatriz(nlin, ncol);
    for (i = 0; i < nlin; i++)
        for (j = 0; j < ncol; j++) {
            fscanf(in, "%d", &v);
            defineElemento(original, i, j, v);
        }
    fclose(in);

    mediana = filtroMediana(original);

    out = fopen("saida.txt", "w");
    fprintf(out, "Matriz Original:\n");
    imprimeMatriz(out, original);
    fprintf(out, "\nMatriz com filtro de mediana:\n");
    imprimeMatriz(out, mediana);
    fprintf(out, "\nPixels alterados: %d\n", contaDiferencas(original, mediana));
    fclose(out);

    liberaMatriz(original);
    liberaMatriz(mediana);
    return 0;
}
