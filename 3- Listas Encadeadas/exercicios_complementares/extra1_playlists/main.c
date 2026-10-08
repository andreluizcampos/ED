#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"
#include "lista.h"

int main()
{

    FILE *f1 = fopen("entrada.txt", "r");
    FILE *f2 = fopen("saida.txt", "w");

    int n = 0;
    fscanf(f1, " %d", &n);

    tLista *BQ = CriaLista();

    for (int i = 0; i < n; i++)
    {

        int code = 0;
        char *name;

        fscanf(f1, " M%d %m[^\n]", &code, &name);
        tMusica *m = CriaMusica(code, name);
        InsereElemento(m, BQ);
        free(name);
    }

    char *name;
    int N = 0;

    fscanf(f1, "%ms %d", &name, &N);

    tPlaylist *P1 = CriaPlay(name);
    free(name);

    for (int i = 0; i < N; i++)
    {

        int id = 0;

        fscanf(f1, " M%d", &id);
        SelecionaMusica(id, BQ, getLista(P1));
    }

    char *name2;

    fscanf(f1, "%ms %d", &name2, &N);

    tPlaylist *P2 = CriaPlay(name2);
    free(name2);

    for (int i = 0; i < N; i++)
    {

        int id = 0;

        fscanf(f1, " M%d", &id);
        SelecionaMusica(id, BQ, getLista(P2));
    }

    ImprimePlaylsit(P1, f2);
    ImprimePlaylsit(P2, f2);

    fscanf(f1, " %d", &N);

    for (int i = 0; i < N; i++)
    {

        int id = 0;

        fscanf(f1, " M%d", &id);
        RemoveElemento(id, getLista(P1));
    }

    ImprimePlaylsit(P1, f2);

    fscanf(f1, " %d", &N);

    for (int i = 0; i < N; i++)
    {

        int id = 0;

        fscanf(f1, " M%d", &id);
        SelecionaMusica(id, BQ, getLista(P1));
    }

    ImprimePlaylsit(P1, f2);

    fclose(f1);
    fclose(f2);

    LiberaPlay(P1);
    LiberaPlay(P2);
    LiberaBancoMusicas(BQ);

    return 0;
}