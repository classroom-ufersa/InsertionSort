#ifndef ALUNO_H
#define ALUNO_H

// Criando a struct que contém o nome, a matrícula e o número de documento do aluno. *
typedef struct aluno Aluno;

// A função cria_aluno() é responsável por criar um novo aluno e inicializar seus dados.
Aluno *cria_aluno (char *nome, int matricula, int documento);

// A função obter_alunos() lê informações de um arquivo de texto (dados_alunos.txt) e cria alunos com essas informações.
int obter_alunos(Aluno **alunos);

// A função exibe_alunos imprime os alunos na tela
void exibe_alunos (Aluno **alunos, int n_alunos);

// A função libera_aluno pega uma variavel do tipo Aluno e libera seu espaço alocado de memoria
void libera_aluno (Aluno *aluno);

// O algoritmo de InsertionSort recebe e ordena um vetor e seu tamanho.
void insertion_sort(char *vetor, int tam);

// A função ordena alunos recebe os alunos e a quantidade de alunos para organizalos com o InsertionSort.
void ordena_alunos(Aluno **alunos, int n_alunos);

// A função atualiza_arquivo recebe como argumento o resultado da função ordena_alunos para salvar no arquivo designado.
void atualiza_arquivo(Aluno **alunos, int n_alunos);

#endif