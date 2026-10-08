#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aluno.h"

struct Aluno
{

    char *nome;
    int CPF;
    float CR;
    char classe;
};

tAluno *CriaAluno(char *nome, int CPF, float CR)
{

    tAluno *a = malloc(sizeof(tAluno));
    a->CR = CR;
    a->CPF = CPF;

    int len = strlen(nome) + 1;

    a->nome = malloc(sizeof(char) * len);

    strcpy(a->nome, nome);

    a->classe = 'A';

    return a;
}

void LiberaAluno(void *dado)
{
    tAluno *a = (tAluno *)dado;

    free(a->nome);
    free(a);
}
void ImprimeAluno(void *dado, FILE *f)
{
    tAluno *a = (tAluno *)dado;

    fprintf(f, "%s , CPF: %d e CR: %.2f\n", a->nome, a->CPF, a->CR);
}

char GetClasseAluno(void *dado)
{
    tAluno *a = (tAluno *)dado;

    return a->classe;
}

float GetCR(void *a){

    tAluno *A = (tAluno*)a;

    return A->CR;
}
