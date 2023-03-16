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

int obter_alunos(Aluno* alunos){
    int nlinhas =0;
    FILE *al_file;
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
   //lendo cada linha do arquivo, salvando os dados e exibindo na tela.
    printf("----------ALUNOS----------\n");
    printf("Nome\t\tMatricula\tDocumento\n");
    while (fscanf(al_file, "%[^;];%d;%d\n", alunos[nlinhas].nome, &alunos[nlinhas].matricula, &alunos[nlinhas].documento) != EOF) {
        printf("%d- %s\t", nlinhas+1, alunos[nlinhas].nome);
        printf("%d\t\t", alunos[nlinhas].matricula);
        printf("%d\n", alunos[nlinhas].documento);
        (nlinhas)++;
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
