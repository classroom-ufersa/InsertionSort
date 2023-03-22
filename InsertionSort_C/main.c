#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#define MAX_ALUNOS 10

int main (void) {
    Aluno *alunos[MAX_ALUNOS]; // vetor de ponteiros para Aluno
    int n_alunos = obter_alunos(alunos), i; // vetor preenchido no inicio do programa
    //char* nome_arquivo = "dados_alunos.txt"; // nome do arquivo a ser lido
    char nome[81];
    int matricula, documento;

    printf("Bem-vindo ao Programa de Ordenação de Alunos!\n");
    int escolha = 0;
    while (escolha != 3) {
        printf("\nMenu:\n");
        printf("1. Cadastrar novo aluno\n");
        printf("2. Listar alunos cadastrados\n");
        printf("3. Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1:
                // add um aluno
                if (n_alunos <= MAX_ALUNOS-1) {
                    // Solicita ao usuário as informações do novo aluno
                    printf("Digite o nome do aluno: ");
                    scanf(" %[^\n]s", nome);
                    printf("Digite a matricula do aluno: ");
                    scanf("%d", &matricula);
                    printf("Digite o documento do aluno: ");
                    scanf("%d", &documento);

                    // Cria o novo aluno usando as informações fornecidas pelo usuário
                    Aluno *novo_aluno = cria_aluno(nome, matricula, documento);
                    alunos[n_alunos++] = novo_aluno;
                    atualiza_arquivo(alunos, n_alunos);
                } else {
                    printf("NÚMERO MÁXIMO DE ALUNOS ATINGIDO\n");
                }
                break;
            case 2:
                /* funcao de listar */
                exibe_alunos(alunos, n_alunos);
                break;
            case 3:
                printf("Saindo do programa...\n");
                // Liberando a memória alocada para cada aluno
                for (i = 0; i < n_alunos; i++) {
                    libera_aluno(alunos[i]);
                }
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }
    return 0;
}