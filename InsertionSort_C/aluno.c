#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include "aluno.h"
#define TAM_LINHA 100

struct aluno {
    char nome[81];
    int matricula;
    int documento;
};

/* Funcao que cria um aluno e retorna como ponteiro */
/// @brief 
/// @param nome 
/// @param matricula 
/// @param documento 
/// @return 
Aluno *cria_aluno (char *nome, int matricula, int documento) {
    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
    // Verifica se ocorreu tudo certo com a alocacao
    if (aluno == NULL) {
        printf("Memoria insuficiente!\n");
        exit(1);
    }
    nome[0] = toupper(nome[0]); /* Transforma a primeira letra do nome em maiusculo */
    strcpy(aluno->nome, nome);
    aluno->matricula = matricula;
    aluno->documento = documento;

    printf("Aluno criado com sucesso!\n");
    return aluno;
}

/* Funcao que exibe todos os alunos */
/// @brief 
/// @param alunos 
int obter_alunos(Aluno **alunos){
    FILE *arquivo_origem;
    char linha[TAM_LINHA], nome[81];
    int matricula, documento, i = 0, linhas = 0;;

    //Lendo arquivo com as informacoes dos alunos
    arquivo_origem = fopen("dados_alunos.txt", "r"); // Abre o arquivo_origem para leitura
    if (arquivo_origem == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    while (fgets(linha, TAM_LINHA, arquivo_origem) != NULL) {
        Aluno *aluno = (Aluno*) malloc(sizeof(Aluno));
        sscanf(linha, " %[^;];%d;%d", nome, &matricula, &documento); // Resgata as informações do aluno
        strcpy(aluno->nome, nome); 
        aluno->matricula = matricula;
        aluno->documento = documento;
        alunos[i++] = aluno; // Inclui um ponteiro de Aluno para o vetor
        linhas++;
    }

    fclose(arquivo_origem); // Fecha o arquivo

    return linhas;
}

void exibe_alunos (Aluno **alunos, int n_alunos) {
    int i;
    printf("----------ALUNOS----------\n");
    printf("Nome        Matricula       Documento\n");
    for (i = 0; i < n_alunos; i++) {
            printf("%d - %s\t\t%d\t%d\n", i+1, alunos[i]->nome, alunos[i]->matricula, alunos[i]->documento);
    }
}

/* Funcao que libera os espaco de memoria ocupado por uma struct do tipo aluno */
void libera_aluno (Aluno *aluno) {
    free(aluno);
}

/* Funcao insertion sort, responsavel por ordenar as iniciais dos alunos em ordem alfabetica */
void insertion_sort(char *vetor, int tam){
    clock_t inicio, fim;
    double tempo_execucao;

    // Inicio da funcao insertion_sort 
    inicio = clock(); // Armazena o horario de inicio da funcao
    int i, j, aux; // Executa 1 vez, c1
    for (i = 1; i < tam; i++){ // Executa n-1 vezes, c2
        aux = vetor[i]; // Executa n-1 vezes, c3
        j = i-1;// Executa n-1 vezes, c4
        while ((j >= 0) && (aux < vetor[j])){ // Executa n(n-1) vezes, c5
            vetor[j+1] = vetor[j]; //Executa n(n-1) vezes, c6
            j--; //Executa n(n-1) vezes, c7
        }
        vetor[j+1] = aux; //Executa n-1 vezes, c8
    }
    // Fim da funcao insertion_sort 
    /* T(n) = c1 + (c2+c3+c4+c8)(n-1) + n(n-1)(c5+c6+c7)

    T(n) = c + b(n-1) + n(n-1)*a

    T(n) = c + bn - b + an² - an

    T(n) = bn + an² - an

    T(n) = n + n² - n

    T(n) = n²

    T(n) = O(n²)
    
    Pior e Medio Insertion
    T(n) = O(n²)

    Melhor Insertion
    T(n) = O(n)
    */
    
    fim = clock(); // Armazena o horario de termino da funcao
    tempo_execucao = ((double) (fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo de execucao da funcao
    printf("Tempo de execucao: %.2f segundos\n", tempo_execucao); //Exibindo o tempo de execucao da funcao
}

/* Funcao ordena_alunos, responsavel por ordenar os alunos no vetor */
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
/* Funcao para atualizar o arquivo dos alunos*/
void atualiza_arquivo(Aluno **alunos, int n_alunos){
    int i;
    FILE *arquivo;
    arquivo = fopen("dados_alunos.txt", "w"); // Abre o arquivo para escrita

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
    
    fclose(arquivo); // Fecha o arquivo
    printf("Arquivo atualizado!\n");
}