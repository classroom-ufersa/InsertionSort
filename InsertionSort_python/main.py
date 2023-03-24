from aluno import Aluno
from alunodao import AlunoDao

op = 0

while op != 3:
    op = int(input('Menu\n1 - Cadastrar alunos\n2 - Listas alunos\n3 - sair\nDigite sua opção: '))

    if op == 1:
        nome = input('Digite o nome do aluno: ')
        matricula = int(input('Digite a matricula do aluno: '))
        documento = int(input('Digite o documento do aluno: '))
        aluno = Aluno(nome,matricula,documento)
        alunodao = AlunoDao()
        alunodao.cadastrar_aluno(aluno)
        alunodao.ordenar_alunos()
        
    elif op == 2:
        alunodao = AlunoDao()
        alunodao.listar_aluno()

