#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "musica.h"
#include "lista.h"

struct Musica
{

    char *nome;
    int ID;
};

struct Playlist
{

    char *nome;
    tLista *Musicas;
};

tMusica *CriaMusica(int ID, char *nome)
{
    tMusica *M = (tMusica *)malloc(sizeof(tMusica));
    int len = strlen(nome) + 1;
    M->nome = malloc(sizeof(char) * len);
    strcpy(M->nome, nome);
    M->ID = ID;

    return M;
}

void LiberaMusica(tMusica *m)
{

    free(m->nome);
    free(m);
}

void PrintaMusica(tMusica *m, FILE *f)
{
    fprintf(f, "ID: M%d, Titulo: %s\n", m->ID, m->nome);
}

int getID(tMusica *m)
{

    return m->ID;
}

char *GetNome(tMusica *m)
{

    return m->nome;
}

tPlaylist *CriaPlay(char *nome)
{
    tPlaylist *p = malloc(sizeof(tPlaylist));
    int len = strlen(nome) + 1;
    p->nome = malloc(sizeof(char) * len);
    strcpy(p->nome, nome);
    p->Musicas = CriaLista();

    return p;
}

tLista *getLista(tPlaylist *P)
{

    return P->Musicas;
}

void ImprimePlaylsit(tPlaylist *P, FILE *f)
{

    fprintf(f, "%s\n", P->nome);
    ImprimeLista(P->Musicas, f);
}

void LiberaPlay(tPlaylist *P)
{

    free(P->nome);
    LiberaLista(P->Musicas);
    free(P);
}
