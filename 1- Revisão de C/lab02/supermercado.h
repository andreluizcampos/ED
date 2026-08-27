#ifndef _SUPERMERCADO_H
#define _SUPERMERCADO_H

typedef struct Produto tProduto;
typedef struct Supermercado tSupermercado;
typedef struct Franquias tFranquia;

tSupermercado *CriaMercado();
int getQtdProdutosMercado(tSupermercado *M);

tProduto *LeProduto();

void LiberaProduto(tProduto *p);
void LiberaMercado(tSupermercado *M);
tFranquia *LeFranquia(int qtd_produtos_mercado);
tFranquia **CriaFranquias(int n, int qtd_produtos_mercado);
int getQtdPosFranquia(tFranquia *f, int pos);
void PrintaProduto(tProduto *p, int qtd);
void CalculaEtoque(tFranquia *f, tSupermercado *M);
void LiberaFranquia(tFranquia *f);
void LiberaFRANQUIAS(tFranquia **f, int n);
void PrintaMercado(tSupermercado *M, tFranquia **Franquias, int n);
void PrintaFilial(tFranquia *f, tSupermercado *M);


#endif