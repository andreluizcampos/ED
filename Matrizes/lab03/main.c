
#include "matriz.h"

int main()
{

  int n1, n2;

  scanf("%d %d ", &n1, &n2);
  Matriz *m = inicializaMatriz(n1, n2);

  imprimeMatriz(m);

  Matriz *t = transposta(m);

  imprimeMatriz(t);

  Matriz *mult = multiplicacao(m, m);
  imprimeMatriz(mult);

  destroiMatriz(m);
  destroiMatriz(t);
  destroiMatriz(mult);

  int m = 1, n = 7, p = 11, b = 3;

  int A[3][3];
  int B[3][3];
  int C[m][p];
  int k = 0;

  for (int i = 0; i < m; i++)
  {

    for (int j = 0; j < p; j++)
    {

      C[i][j] = 0;

      for (int k = 0; k < n)
    }
  }
}
