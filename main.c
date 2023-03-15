#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.c"

int main (void) {
    //int matricula = 0, nlinhas = 0, documento = 0;
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

    free(alunos);
    return 0;
}