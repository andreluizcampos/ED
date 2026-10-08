#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"

struct Professor
{

    char *nome;
    int CPF;
    float salario;
    char classe;
};

tProfessor *CriaProfessor(char *nome, int CPF, float salario)
{

    tProfessor *p = malloc(sizeof(tProfessor));

    int len = strlen(nome) + 1;

    p->salario = salario;
    p->CPF = CPF;
    p->nome = malloc(sizeof(char) * len);
    strcpy(p->nome, nome);
    p->classe = 'P';

    return p;
}

void ImprimeProfessor(void *dado, FILE *f)
{
    tProfessor *p = (tProfessor *)dado;

    fprintf(f, "%s, CPF: %d e Salário:%.2f\n", p->nome, p->CPF, p->salario);
}
void LiberaProfessor(void *dado)
{
    tProfessor *p = (tProfessor *)dado;

    free(p->nome);
    free(p);
}

char GetClasseProfessor(void *dado)
{
    tProfessor *p = (tProfessor *)dado;

    return p->classe;
}

float GetSalario(void *p)
{

    tProfessor *P = (tProfessor *)p;

    return P->salario;
}
