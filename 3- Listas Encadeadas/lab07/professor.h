#ifndef _PROFESSOR_H
#define _PROFESSOR_H

typedef struct Professor tProfessor;

tProfessor *CriaProfessor(char *nome, int CPF, float salario);
void ImprimeProfessor(void *p, FILE *f);
void LiberaProfessor(void *p);
char GetClasseProfessor(void *p);
float GetSalario(void *p);


#endif