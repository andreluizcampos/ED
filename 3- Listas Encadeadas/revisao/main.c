#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "provas.h"
#include "lista.h"

int main()
{

    FILE *f = fopen("entrada.txt", "r");
    int n = 0;
    fscanf(f, "%d ", &n);

    tLista *BQ = CriaLista();

    for (int i = 0; i < n; i++)
    {
        char *name;
        int number;
        fscanf(f, " Q%d  \n%m[^\n]", &number, &name);
        tQuestao *Q = CriaQuest(name, number);
        AdicionaElemento(BQ, Q);
        free(name);
    }

    char *p1_nome;
    char *p2_nome;
    int nQP1, nQP2;
    fscanf(f, "%ms %d", &p1_nome, &nQP1);

    tProva *P1 = CriaProva(p1_nome);
    tLista *Quests_P1 = getLista(P1);

    for (int i = 0; i < nQP1; i++)
    {

        int ID = 0;

        fscanf(f, " Q%d", &ID);

        AdicionaQuest(BQ, Quests_P1, ID);
    }

    free(p1_nome);

    fscanf(f, "%ms %d", &p2_nome, &nQP2);

    tProva *P2 = CriaProva(p2_nome);
    free(p2_nome);

    tLista *Quests_P2 = getLista(P2);

    for (int i = 0; i < nQP2; i++)
    {

        int ID;
        fscanf(f, " Q%d", &ID);
        AdicionaQuest(BQ, Quests_P2, ID);
    }

    tProva *Merged = CriaProva("Merge");
    tLista *Q_Merged = getLista(Merged);
    tLista *Merged_Lista = Merge(Quests_P1, Quests_P2);
    SetLista(Merged_Lista, Merged);
    LiberaLista(Q_Merged);

    fclose(f);

    f = fopen("saida.txt", "w");

    ImprimeProva(P1, f);
    ImprimeProva(P2, f);
    ImprimeProva(Merged, f);

    FiltraMerge(Merged_Lista);

    ImprimeProva(Merged, f);

    LiberaProva(P1);
    LiberaProva(P2);
    LiberaProva(Merged);
    LiberaBancoDeQuestoes(BQ);

    fclose(f);

    return 0;
}