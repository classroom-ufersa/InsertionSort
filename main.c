#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.c"




int main (void) {
    //int matricula = 0, nlinhas = 0, documento = 0;
    char * nomes = (char*) malloc(100*sizeof(char));
    int * matriculas = (int*) malloc(100*sizeof(int));
    int * documentos = (int*) malloc(100*sizeof(int));
    Aluno *alunos = (Aluno*) malloc(200*sizeof(Aluno));
    
    
    int menu = 1, op;

    while(menu == 1){
        int total_alunos = obter_alunos(alunos);
        printf("- Menu -\n1-9: opcoes...\n0- Sair.\n");
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

    /*
    Aluno *aluno1 = cria_aluno("Dayvison Silva", 12334, 111);
    Aluno *aluno2 = cria_aluno("Yeniffer Gustov", 23445, 222);

    Aluno *alunos[2];
    alunos[0] = aluno1;
    alunos[1] = aluno2;

    exibe_alunos(alunos, 2);
    */
    free(nomes);
    free(matriculas);
    free(documentos);
    free(alunos);
    return 0;
}