#ifndef _MUSICA_H
#define _MUSICA_H

#include <stdio.h>
typedef struct Musica tMusica;
typedef struct Playlist tPlaylist;

#include "lista.h"

tMusica *CriaMusica(int ID, char *nome);
void LiberaMusica(tMusica *m);
void PrintaMusica(tMusica *m, FILE *f);
int getID(tMusica *m);
char *GetNome(tMusica *m);

tPlaylist *CriaPlay(char *nome);
void AlteraPlaylist(tPlaylist *P);
tLista *getLista(tPlaylist *P);

void ImprimePlaylsit(tPlaylist *P, FILE *f);
void LiberaPlay(tPlaylist *P);

#endif