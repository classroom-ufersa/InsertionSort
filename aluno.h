#ifndef ALUNO_H
#define ALUNO_H

/* cabecalho aluno */

/* Tipo exportado */
typedef struct aluno Aluno;

/* Funcoes exportadas */
int conta_linhas();
Aluno *cria_aluno (char *nome, int matricula, int documento);
void obter_alunos(Aluno **alunos, int n_alunos);
void exibe_alunos (Aluno **alunos, int n_alunos);
void libera_aluno (Aluno *aluno);
void insertion_sort(char *vetor, int tam);
void ordena_alunos(Aluno **alunos, int n_alunos);
void atualiza_arquivo(Aluno **alunos, int n_alunos);

#endif