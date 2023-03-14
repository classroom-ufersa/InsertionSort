#include <stdio.h>
#include "aluno.h"

int main (void) {
    Aluno *aluno1 = cria_aluno("Dayvison Silva", 12334);
    Aluno *aluno2 = cria_aluno("Yeniffer Gustov", 23445);

    Aluno *alunos[2];
    alunos[0] = aluno1;
    alunos[1] = aluno2;

    exibe_alunos(alunos, 2);
    return 0;
}