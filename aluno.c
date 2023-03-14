#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "aluno.h"

struct aluno {
    char nome[81];
    int matricula;
};

/* Funcao que cria um aluno e retorna como ponteiro */
/// @brief 
/// @param nome 
/// @param matricula 
/// @return 
Aluno *cria_aluno (char *nome, int matricula) {
    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
    // verifica se ocorreu tudo certo com a alocacao
    if (aluno == NULL) {
        printf("Memoria insuficiente!\n");
        exit(1);
    }
    strcpy(aluno->nome, nome);
    aluno->matricula = matricula;
    return aluno;
}

/* Funcao que exibe os alunos */
/// @brief 
/// @param alunos 
/// @param n_alunos 
void exibe_alunos (Aluno **alunos, int n_alunos) { 
    int i;
    printf("----------ALUNOS----------\n");
    for (i = 0; i < n_alunos; i++) {
        printf("\nAluno %d:\n", i+1);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Matricula: %d\n", alunos[i]->matricula);
    }
}

/* Funcao que libera os espaco de memoria ocupado por um tipo aluno */
void libera_aluno (Aluno *aluno) {
    free(aluno);
}
