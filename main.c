#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.c"
#define tam_linha 100

void obter_dados(int* nlinhas, char* nome, int* matricula, int* documento){
    FILE *al_file, *resultados;
    char * linha = (char*) malloc(tam_linha*sizeof(char));
    //int nlinhas = 0;
    //char nome[100];
    //int matricula, documento;

    //verificando alocacao de linha
    if (linha == NULL) printf("Erro de alocação.");
    //lendo arquivos
    al_file = fopen("dados_linhas.txt", "rt");
    //resultados = fopen("resultados.txt", "wt");
    //verificando se o arquivo foi lido com sucesso.
    if (al_file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
   //lendo cada linha do arquivo, salvando os dados
    while((fgets(linha, tam_linha, al_file))!=NULL){
        printf("%s", linha); 
        sscanf(linha, "%[^;]s;%d;%d", &nome[*nlinhas], &matricula[*nlinhas], &documento[*nlinhas]);
        (*nlinhas)++;
        //fprintf(resultados, "%s;%d;%d\n", nome, matricula, documento);
    }
    printf("\nNumero de linhas: %d\n", *nlinhas);


    if(fclose(al_file)!=0) printf("Erro ao fechar arquivo.");
    free(linha);
}

int main (void) {
    //int matricula = 0, nlinhas = 0, documento = 0;
    int *nlinhas = 0;
    char * nomes = (char*) malloc(100*sizeof(char));
    int * matriculas = (int*) malloc(100*sizeof(int));
    int * documentos = (int*) malloc(100*sizeof(int));

    obter_dados(nlinhas, nomes, matriculas, documentos);


    Aluno *aluno1 = cria_aluno("Dayvison Silva", 12334, 111);
    Aluno *aluno2 = cria_aluno("Yeniffer Gustov", 23445, 222);

    Aluno *alunos[2];
    alunos[0] = aluno1;
    alunos[1] = aluno2;

    exibe_alunos(alunos, 2);
    
    return 0;
}