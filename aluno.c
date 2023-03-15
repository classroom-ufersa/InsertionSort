#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "aluno.h"
#define tam_linha 100

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
void exibe_alunos (Aluno **alunos, int n_alunos) { 
    int i;
    printf("----------ALUNOS----------\n");
    for (i = 0; i < n_alunos; i++) {
        printf("\nAluno %d:\n", i+1);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Matricula: %d\n", alunos[i]->matricula);
        printf("Documento: %d\n", alunos[i]->documento);
    }
}

int obter_alunos(Aluno* alunos){
    int nlinhas =0;
    FILE *al_file, *resultados;
    char * linha = (char*) malloc(tam_linha*sizeof(char));
    //int nlinhas = 0;
    //char nome[100];
    //int matricula, documento;

    //verificando alocacao de linha
    if (linha == NULL) printf("Erro de alocação.");
    //lendo arquivos
    al_file = fopen("dados_alunos.txt", "r+");
    //verificando se o arquivo foi lido com sucesso.
    if (al_file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
   //lendo cada linha do arquivo, salvando os dados
    /*
    while((fgets(linha, sizeof(linha), al_file))!=NULL){
        printf("%s", linha); 
        sscanf(linha, "%20[\t];%d;%d", &alunos[nlinhas].nome, &alunos[nlinhas].matricula, &alunos[nlinhas].documento);
        (nlinhas)++;
        //fprintf(resultados, "%s;%d;%d\n", nome, matricula, documento);
    }*/
    while (fscanf(al_file, "%[^;];%d;%d\n", alunos[nlinhas].nome, &alunos[nlinhas].matricula, &alunos[nlinhas].documento) != EOF) {
        printf("Nome: %s\n", alunos[nlinhas].nome);
        printf("Matricula: %d\n", alunos[nlinhas].matricula);
        printf("Documento: %d\n\n", alunos[nlinhas].documento);
        (nlinhas)++;
    }


    int i;
    printf("----------ALUNOS----------\n");
    for (i = 0; i < nlinhas; i++) {
        printf("\nAluno %d:\n", i+1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Documento: %d\n", alunos[i].documento);
    }
    printf("\nTotal de alunos: %d\n", nlinhas);


    if(fclose(al_file)!=0) printf("Erro ao fechar arquivo.");
    free(linha);
    return nlinhas;
}

/* Funcao que libera os espaco de memoria ocupado por um tipo aluno */
void libera_aluno (Aluno *aluno) {
    free(aluno);
}
