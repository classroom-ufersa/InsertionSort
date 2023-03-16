#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "aluno.h"
#define TAM_LINHA 100


struct aluno {
    char nome[81];
    int matricula;
    int documento;
};

int conta_linhas(){
    FILE *arquivo_origem;
    char linha[100];
    int linhas = 0;

    arquivo_origem = fopen("dados_alunos.txt", "r"); // abre o arquivo_origem para leitura
    if (arquivo_origem == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    while (fgets(linha, 100, arquivo_origem) != NULL) { // lê cada linha do arquivo
        linhas++;
    }

    fclose(arquivo_origem); // fecha o arquivo
    return linhas; // retorna a quantidade de linhas = quantidade de alunos
}

/* Funcao que cria um aluno e retorna como ponteiro */
/// @brief 
/// @param nome 
/// @param matricula 
/// @param documento 
/// @return 
Aluno *cria_aluno (char *nome, int matricula, int documento) {
    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
    // verifica se ocorreu tudo certo com a alocacao
    if (aluno == NULL) {
        printf("Memoria insuficiente!\n");
        exit(1);
    }
    strcpy(aluno->nome, nome);
    aluno->matricula = matricula;
    aluno->documento = documento;
    return aluno;
}

/* Funcao que exibe todos os alunos */
/// @brief 
/// @param alunos 
/// @param n_alunos 
void obter_alunos(Aluno **alunos, int n_alunos){
    FILE *arquivo_origem;
    char linha[TAM_LINHA], nome[81];
    int matricula, documento, i = 0;

    //lendo arquivo com as informacoes dos alunos
    arquivo_origem = fopen("dados_alunos.txt", "r"); // abre o arquivo_origem para leitura
    if (arquivo_origem == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    while (fgets(linha, TAM_LINHA, arquivo_origem) != NULL) {
        Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
        sscanf(linha, " %[^;];%d;%d", nome, &matricula, &documento); // resgata as informações do aluno
        strcpy(aluno->nome, nome); 
        aluno->matricula = matricula;
        aluno->documento = documento;
        alunos[i++] = aluno; // inclui um ponteiro de Aluno para o vetor
    }

    fclose(arquivo_origem); // fecha o arquivo
}

void exibe_alunos (Aluno **alunos, int n_alunos) {
    int i;
    printf("----------ALUNOS----------\n");
    printf("Nome        Matricula       Documento\n");
    for (i = 0; i < n_alunos; i++) {
            printf("%d - %s\t\t%d\t%d\n", i+1, alunos[i]->nome, alunos[i]->matricula, alunos[i]->documento);
    }
}

/* Funcao que libera os espaco de memoria ocupado por um tipo aluno */
void libera_aluno (Aluno *aluno) {
    free(aluno);
}

void insertion_sort(char *vetor, int tam){
    int i, j, aux;
    for (i = 1; i < tam; i++){
        aux = vetor[i];
        j = i-1;
        
        while ((j >= 0) && (aux < vetor[j])){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = aux;
    }
}

void ordena_alunos(Aluno **alunos, int n_alunos) {
    Aluno *aux;
    int i, j;
    char iniciais[n_alunos];

    for (i = 0; i < n_alunos; i++) {
        iniciais[i] = alunos[i]->nome[0];
    }

    insertion_sort(iniciais, n_alunos);
    
    for (i = 0; i < n_alunos; i++) {
        for ( j = 0; j < n_alunos; j++) {
            if (iniciais[i] == alunos[j]->nome[0]) {
                aux = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = aux;
            }
        }
    }  
}

void atualiza_arquivo(Aluno **alunos, int n_alunos){
    int i;
    FILE *arquivo;
    arquivo = fopen("resultados.txt", "w"); // abre o arquivo para escrita

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    ordena_alunos(alunos, n_alunos);
    
    for (i = 0; i < n_alunos; i++) {
        if (i == n_alunos-1) {
            fprintf(arquivo ,"%s;%d;%d", alunos[i]->nome, alunos[i]->matricula, alunos[i]->documento);
        } else {
            fprintf(arquivo ,"%s;%d;%d\n", alunos[i]->nome, alunos[i]->matricula, alunos[i]->documento);
        }
    }
    
    fclose(arquivo); // fecha o arquivo
    printf("Arquivo atualizado!\n");
}