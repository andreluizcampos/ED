#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "lista.h"
#include "professor.h"

int main()
{

    FILE *f1 = fopen("entrada.txt", "r");
    FILE *f2 = fopen("saida.txt", "w");

    int n = 0;

    fscanf(f1, "%d", &n);

    tNo *sent = CriaNo();

    for (int i = 0; i < n; i++)
    {

        char c;
        void *dado;
        GetClasseElemento getClasse;
        GetInfo Ginfo;

        char *nome;
        float info;
        int cpf;

        fscanf(f1, " %c", &c);
        fscanf(f1, "%ms %d %f", &nome, &cpf, &info);
        if (c == 'A')
        {

            dado = CriaAluno(nome, cpf, info);
            getClasse = GetClasseAluno;
            Ginfo = GetCR;
        }
        else
        {
            dado = CriaProfessor(nome, cpf, info);
            getClasse = GetClasseProfessor;
            Ginfo = GetSalario;
        }

        tNo *novo = CriaNo();
        InsereElemento(novo, dado, sent, getClasse, Ginfo);
        free(nome);
    }

    fprintf(f2, "PROFESSORES\n");
    PrintClass(sent, 'P', f2);

    float MSAL = 0;
    float MCR = 0;
    int Q1 = 0, Q2 = 0;
    CalculaMediaElementos(&MCR, &MSAL, &Q1, &Q2, sent);

    fprintf(f2, "\n Media de salario dos %d professores:%.2f", Q2, MSAL);

    fprintf(f2, "\nALUNOS\n");
    PrintClass(sent, 'A', f2);
    fprintf(f2, "\n Media de CR dos %d alunos:%.2f\n", Q1, MCR);
    fclose(f1);
    fclose(f2);
    LiberaLista(sent);

    return 0;
}