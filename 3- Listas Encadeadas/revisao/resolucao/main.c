#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "provas.h"
#include "lista.h"


// Professora esqueci de enviar até antes de quinta mas eu fiz!! ;----;)
int main()
{

    tLista *BQ = CriaLista();

    FILE *f = fopen("entrada.txt", "r");
    int n = 0;
    fscanf(f, " %d", &n);

    char *name;
    int id;

    for (int i = 0; i < n; i++)
    {
        fscanf(f, " Q%d %m[^\n]", &id, &name);
        tQuestao *q = CriaQuest(name, id);
        AdicionaElemento(BQ, q);
        free(name);
    }

    char *name1;

    fscanf(f, "%ms", &name1);
    tProva *p1 = CriaProva(name1);
    tLista *P1_Q = getLista(p1);
    free(name1);

    int num = 0;

    fscanf(f, "%d", &num);
    int *P1_QUESTS = malloc(sizeof(int) * num);

    for (int i = 0; i < num; i++)
    {

        fscanf(f, " Q%d", &P1_QUESTS[i]);
    }

    for (int i = 0; i < num; i++)
    {

        AdicionaQuest(P1_Q, BQ, P1_QUESTS[i]);
    }

    char *name2;

    fscanf(f, "%ms", &name2);
    tProva *p2 = CriaProva(name2);
    tLista *P2_LIST = getLista(p2);
    free(name2);

    fscanf(f, "%d", &num);

    int *P2_QUESTS = malloc(sizeof(int) * num);

    for (int i = 0; i < num; i++)
    {

        fscanf(f, " Q%d", &P2_QUESTS[i]);
    }

    for (int i = 0; i < num; i++)
    {

        AdicionaQuest(P2_LIST, BQ, P2_QUESTS[i]);
    }

    fclose(f);

    tLista *Merged = Merge(P2_LIST, P1_Q);

    f = fopen("saida.txt", "w");

    ImprimeProva(p1, f);
    ImprimeProva(p2, f);

    fprintf(f, "Prova: Merge\n");
    ImprimeLista(Merged, f);

    FiltraMerge(Merged);

    fprintf(f, "Prova: Merge\n");
    ImprimeLista(Merged, f);

    fclose(f);

    free(P1_QUESTS);
    free(P2_QUESTS);
    LiberaLista(Merged);
    LiberaProva(p1);
    LiberaProva(p2);
    LiberaBancoDeQuestoes(BQ);

    return 0;
}
