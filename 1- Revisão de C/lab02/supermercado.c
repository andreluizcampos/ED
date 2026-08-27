#include <stdio.h>
#include <stdlib.h>
#include "supermercado.h"

#define MAX_STR 100
struct Produto
{
    char *nome;
    int codigo;
    float valor;
};

struct Supermercado
{
    char *nome;
    int qtd_produtos;
    tProduto **produtos;
    float estoque;
};

struct Franquias
{
    char *nome;
    int *Quantidades;
    float v_estoque;
    int Qtd_produtos;
};

tProduto *LeProduto()
{

    tProduto *p = (tProduto *)malloc(sizeof(tProduto));
    p->nome = (char *)malloc(sizeof(char) * MAX_STR);

    scanf("%d %s %f ", &p->codigo, p->nome, &p->valor);

    return p;
}

tSupermercado *CriaMercado()
{

    int n = 0;
    scanf("%d ", &n);
    tSupermercado *M = (tSupermercado *)malloc(sizeof(tSupermercado));
    M->produtos = (tProduto **)malloc(sizeof(tProduto *));
    M->qtd_produtos = n;
    M->estoque = 0;

    for (int i = 0; i < n; i++)
    {
        M->produtos[i] = LeProduto();
        M->produtos = (tProduto **)realloc(M->produtos, sizeof(tProduto *) * (i + 2));
        }

        M->nome = (char*)malloc(sizeof(char)*MAX_STR);
        scanf("%s",M->nome);
    return M;
}

tFranquia *LeFranquia(int qtd_produtos_mercado)
{

    char *nome;
    int qtd_entradas = 0;

    scanf("%ms", &nome);
    tFranquia *f = (tFranquia *)malloc(sizeof(tFranquia));
    scanf(" %d", &qtd_entradas);
    f->Quantidades = (int *)calloc(qtd_produtos_mercado, sizeof(int));

    for (int i = 0; i < qtd_entradas; i++)
    {
        int pos = 0, qtd = 0;

        scanf(" %d %d", &pos, &qtd);
        pos = pos - 1;
        f->Quantidades[pos] = qtd;
    }

    f->nome = nome;
    f->Qtd_produtos = qtd_produtos_mercado;
    f->v_estoque = 0;

    return f;
}

int getQtdProdutosMercado(tSupermercado *M)
{

    return M->qtd_produtos;
}

int getQtdPosFranquia(tFranquia *f, int pos)
{

    return f->Quantidades[pos];
}

void PrintaProduto(tProduto *p, int qtd)
{

    printf("Item: %s, valor unitário: %.2f, quantidade: %d\n", p->nome, p->valor, qtd);
}

void PrintaMercado(tSupermercado *M, tFranquia **Franquias, int n)
{

    printf("Nome do Supermercado: %s\n", M->nome);

    for (int i = 0; i < n; i++)
    {

        PrintaFilial(Franquias[i], M);
    }
}

void PrintaFilial(tFranquia *f, tSupermercado *M)
{
    CalculaEtoque(f,M);
    printf("Filial: %s\n", f->nome);
    printf("Estoque: %.2f\n", f->v_estoque);

    for (int i = 0; i < f->Qtd_produtos; i++)
    {

        if (f->Quantidades[i] > 0)
            PrintaProduto(M->produtos[i], f->Quantidades[i]);
    }
}

void CalculaEtoque(tFranquia *f, tSupermercado *M)
{

    for (int i = 0; i < f->Qtd_produtos; i++)
    {

        float valor = M->produtos[i]->valor;

        f->v_estoque += valor * f->Quantidades[i];
    }
}

tFranquia **CriaFranquias(int n, int qtd_produtos_mercado)
{

    int q_franquias = n;

    tFranquia **F = (tFranquia **)malloc(sizeof(tFranquia *));

    for (int i = 0; i < q_franquias; i++)
    {
        F[i] = LeFranquia(qtd_produtos_mercado);
        F = realloc(F, sizeof(tFranquia *) * (i + 2));
    }

    return F;
}

void LiberaFranquia(tFranquia *f)
{

    free(f->Quantidades);
    free(f->nome);
    free(f);
}

void LiberaFRANQUIAS(tFranquia **f, int n)
{

    for (int i = 0; i < n; i++)
    {

        LiberaFranquia(f[i]);
    }

    free(f);
}

void LiberaProduto(tProduto *p){

    free(p->nome);
    free(p);

}

void LiberaMercado(tSupermercado *M){


    for( int i  = 0;i<M->qtd_produtos;i++){

        LiberaProduto(M->produtos[i]);
    }

    free(M->nome);
    free(M->produtos);
    free(M);
}
