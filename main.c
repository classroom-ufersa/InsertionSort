#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.c"
#define TAM_LINHA 100

/*
    //int nlinhas = 0;
    //char nome[100];
    //int matricula, documento;

    while((fgets(linha, tam_linha, al_file))!=NULL)
        printf("%s", linha); 
        sscanf(linha, "%[^;]s;%d;%d", &nome[*nlinhas], &matricula[*nlinhas], &documento[*nlinhas]);
        (*nlinhas)++;
        //fprintf(resultados, "%s;%d;%d\n", nome, matricula, documento);
*/

//void ler_arquivo(char **nomes_alunos, int quantidade_alunos);
//int conta_linhas();
void insertion_sort(char *vetor, int tam);
void ordena_alunos(char **nomes_alunos, int quantidade_alunos);
void atualiza_arquivo(char **nomes_alunos, int quantidade_alunos);

int main (void) {
    int i;
    int quantidade_alunos = conta_linhas();
    char **nomes_alunos;
    // Aloca memória para o array de ponteiros
    Aluno *alunos = (Aluno*) malloc(200*sizeof(Aluno));

    int menu = 1, op;
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
    }

    
  
  
    nomes_alunos = (char**) malloc(quantidade_alunos * sizeof(char *));
    for (i = 0; i < quantidade_alunos; i++) {
        nomes_alunos[i] = (char*) malloc(80 * sizeof(char *));
    }
    
    //Aluno *aluno1 = cria_aluno("Arthur Silva", 12334, 111);
    //Aluno *aluno2 = cria_aluno("Isabella Santos", 23445, 222);

    //Aluno *alunos[2];
    //alunos[0] = aluno1;
    //alunos[1] = aluno2;
    //exibe_alunos(alunos, 2);

    //ler_arquivo(nomes_alunos, quantidade_alunos);
    ordena_alunos(nomes_alunos, quantidade_alunos);

    // Imprime os nomes dos alunos
    atualiza_arquivo(nomes_alunos, quantidade_alunos);
    free(alunos);
    return 0;
}

/*
void ler_arquivo(char **nomes_alunos, int quantidade_alunos){
    FILE *arquivo_origem;
    char linha[TAM_LINHA];
    char nome[80];
    int i = 0;

    arquivo_origem = fopen("dados_alunos.txt", "r"); // abre o arquivo_origem para leitura
    if (arquivo_origem == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    while (fgets(linha, TAM_LINHA, arquivo_origem) != NULL) { // lê cada linha do arquivo
        sscanf(linha, "%[^;]s", nome); // resgata o nome do aluno
        strcpy(nomes_alunos[i++], nome); // copia o nome presente na linha para uma linha do vetor
    }

    fclose(arquivo_origem); // fecha o arquivo
}

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
*/

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

void ordena_alunos(char **nomes_alunos, int quantidade_alunos) {
    int i, j;
    char aux[80];
    char iniciais[quantidade_alunos];

    for (i = 0; i < quantidade_alunos; i++) {
        iniciais[i] = nomes_alunos[i][0];
    }

    insertion_sort(iniciais, quantidade_alunos);
    
    for (i = 0; i < quantidade_alunos; i++) {
        for ( j = 0; j < quantidade_alunos; j++) {
            if (iniciais[i] == nomes_alunos[j][0]) {
                strcpy(aux, nomes_alunos[i]);
                strcpy(nomes_alunos[i], nomes_alunos[j]);
                strcpy(nomes_alunos[j], aux);
            }
        }
    }  
}

void atualiza_arquivo(char **nomes_alunos, int quantidade_alunos){
    int i;
    FILE *arquivo;
    arquivo = fopen("resultados.txt", "w"); // abre o arquivo para escrita

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    for (i = 0; i < quantidade_alunos; i++) {
        fprintf(arquivo, "%s\n",nomes_alunos[i]); // imprime os nomes ordenados no arquivo
    }
    
    fclose(arquivo); // fecha o arquivo
    printf("Arquivo atualizado!\n");
}