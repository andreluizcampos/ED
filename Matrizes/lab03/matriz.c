#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

struct matriz
{
    int linhas;
    int colunas;
    int *elementos;
};

Matriz *inicializaMatriz(int nlinhas, int ncolunas)
{

    Matriz *m = (Matriz *)malloc(sizeof(Matriz));
    m->colunas = ncolunas;
    m->linhas = nlinhas;
    m->elementos = (int *)malloc(sizeof(int) * m->colunas * m->linhas);

    for (int i = 0; i < nlinhas; i++)
    {

        for (int j = 0; j < ncolunas; j++)
        {

            scanf("%d ", &m->elementos[i * ncolunas + j]);
        }
    }

    return m;
}


void modificaElemento(Matriz *mat, int linha, int coluna, int elem)
{

    if ((linha >= 0 && coluna >= 0) && (linha < mat->linhas && coluna < mat->colunas))
    {

        mat->elementos[(linha * mat->colunas) + coluna] = elem;
    }
}

int recuperaElemento(Matriz *mat, int linha, int coluna)
{

    if ((linha >= 0 && coluna >= 0) && (linha < mat->linhas && coluna < mat->colunas))
    {

        return mat->elementos[(linha * mat->colunas) + coluna];
    }
}

int recuperaNColunas(Matriz *mat)
{

    return mat->colunas;
}


int recuperaNLinhas(Matriz *mat)
{

    return mat->linhas;
}


Matriz *transposta(Matriz *mat)
{

    Matriz *t = (Matriz *)malloc(sizeof(Matriz));
    t->colunas = mat->linhas;
    t->linhas = mat->colunas;
    t->elementos = (int *)malloc(sizeof(int) * t->colunas * t->linhas);

    for (int i = 0; i < mat->linhas; i++)
    {

        for (int j = 0; j < mat->colunas; j++)
        {

            t->elementos[j * t->colunas + i] = mat->elementos[i * mat->colunas + j];
        }
    }

    return t;
}


Matriz *multiplicacao(Matriz *mat1, Matriz *mat2)
{

    Matriz *m = (Matriz *)malloc(sizeof(Matriz));
    m->colunas = mat2->colunas;
    m->linhas = mat1->linhas;
    m->elementos = (int *)malloc(sizeof(int) * m->colunas * m->linhas);

    for (int i = 0; i < mat1->linhas; i++)
    {
        int acc = 0;
        for (int j = 0; j < mat2->colunas; j++)
        {

            for (int k = 0; k < mat2->colunas; k++)
            {

                acc += mat1->elementos[i * mat1->colunas + k] * mat2->elementos[i + mat2->colunas * k];
            }

            m->elementos[i * m->colunas + j] = acc;
        }
    }

    return m;
}


void imprimeMatriz(Matriz *mat)
{

    for (int i = 0; i < mat->linhas; i++)
    {

        for (int j = 0; j < mat->colunas; j++)
        {

            printf("%d ", mat->elementos[i * mat->colunas + j]);
        }

        printf("\n");
    }

    printf("\n");
}

void imprimeLinha(Matriz *mat, int indice)
{

    for (int i = 0; i < mat->colunas; i++)
    {

        printf("%d ", mat->elementos[indice + i]);
    }
}


void destroiMatriz(Matriz *mat)
{

    free(mat->elementos);
    free(mat);
}
