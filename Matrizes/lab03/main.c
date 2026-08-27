
#include "matriz.h"

int main()
{

    int n1, n2;

    scanf("%d %d ", &n1, &n2);
    Matriz *m = inicializaMatriz(n1, n2);

    imprimeMatriz(m);

    Matriz *t = transposta(m);

      imprimeMatriz(t);

    Matriz *mult = multiplicacao(m,m);
      imprimeMatriz(mult);

      destroiMatriz(m);
      destroiMatriz(t);
      destroiMatriz(mult);

}