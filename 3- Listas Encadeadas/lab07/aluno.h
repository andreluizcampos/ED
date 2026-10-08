#ifndef _ALUNO_H
#define _ALUNO_H

typedef struct Aluno tAluno;

tAluno *CriaAluno(char *nome, int CPF, float CR);
void LiberaAluno(void *a);
void ImprimeAluno(void *a, FILE *f);
char GetClasseAluno(void *a);
float GetCR(void *a);


#endif