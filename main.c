#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#define TAM_LINHA 100
#define MAX_ALUNOS 10

int main (void) {
    int n_alunos = conta_linhas(), i;
    Aluno *alunos[MAX_ALUNOS];
    obter_alunos(alunos, n_alunos);

    exibe_alunos(alunos, n_alunos); // exibe as informações dos alunos
    ordena_alunos(alunos, n_alunos); // ordena os alunos pelos nomes em ordem alfabetica
    printf("\n");
    exibe_alunos(alunos, n_alunos); // exibe as informações agora em forma ordenada

    // add um aluno
    if (n_alunos <= MAX_ALUNOS-1) {
        Aluno *aluno1 = cria_aluno("Dayvison Silva", 12334, 111); // add um novo aluno
        alunos[n_alunos++] = aluno1;
        atualiza_arquivo(alunos, n_alunos);
    } else {
        printf("Número máximo de alunos atingido!\n");
    }
    // Liberando a memória para os ponteiros de Alunos
    for (i = 0; i < n_alunos; i++) {
        libera_aluno(alunos[i]); // apoós todos os alunos adicionados e ordenador em um arquivo, a memória é liberada
    }

    /*int menu = 1, op;
    while(menu == 1){
        int total_alunos = obter_alunos(alunos);
        printf("- Menu -\n1- Cadastar aluno\n2- ...\n0- Sair.\n");
        scanf("%d", &op);
        switch(op){
        case 0:
            menu = 0;
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
        }
    }*/
    return 0;
}