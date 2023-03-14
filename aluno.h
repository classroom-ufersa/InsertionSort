#ifndef ALUNO_H
#define ALUNO_H

/* cabecalho aluno */

/* Tipo exportado */
typedef struct aluno Aluno;

/* Funcoes exportadas */
Aluno *cria_aluno (char *nome, int matricula, int documento);
void exibe_alunos (Aluno **alunos, int n_alunos);
void libera_aluno (Aluno *aluno);

#endif