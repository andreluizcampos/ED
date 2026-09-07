#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

struct Matriz
{
    int **dados;
    int col;
    int lin;
};

tMatriz *CriaMatriz()
{

    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));
    scanf(" %d %d", &m->lin, &m->col);

    m->dados = (int **)malloc(sizeof(int *) * m->lin);

    for (int i = 0; i < m->lin; i++)
    {

        m->dados[i] = (int *)malloc(sizeof(int) * m->col);
    }

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            scanf("%d", &m->dados[i][j]);
        }
    }

    return m;
}

void LiberaMatrizt(tMatriz *m)
{

    for (int i = 0; i < m->lin; i++)
    {

        free(m->dados[i]);
    }

    free(m->dados);
    free(m);
}
void ImprimeMatriz(tMatriz *m)
{

    int a = 0;

    for (int i = 0; i < m->lin; i++)
    {

        for (int j = 0; j < m->col; j++)
        {

            printf("%d ", m->dados[i][j]);
            a += m->dados[i][j];
        }

        printf("\n");
    }

    printf("\nSomatorio: %d", a);
}

tMatriz *CriaSubMatriz(tMatriz *M, int LI, int LF, int CI, int CF, int P)
{

    tMatriz *m = (tMatriz *)malloc(sizeof(tMatriz));
    m->col = CF - CI + 1;
    m->lin = (LF - LI) / P + 1;

    m->dados = (int **)malloc(sizeof(int *) * m->lin);

    int a = 0;
    int p = 0;

    for (int i = LI; i <= LF; i += P)
    {

        if (i < M->lin)
        {
            m->dados[a] = M->dados[i] + CI;
            a++;
            p += P - 1;
        }
    }

    return m;
}

void LiberaSub(tMatriz *m)
{

    free(m->dados);
    free(m);
}
