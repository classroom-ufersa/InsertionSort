from aluno import Aluno
from alunodao import AlunoDao

op = 0
# menu interativo
while op != 3:
    
    op = int(input('Menu\n1 - Cadastrar alunos\n2 - Listas alunos\n3 - sair\nDigite sua opção: '))

    if op == 1:
        nome = input('Digite o nome do aluno: ')
        matricula = int(input('Digite a matricula do aluno: '))
        documento = int(input('Digite o documento do aluno: '))
        #tratamento de nome p/ letra maiuscula
        nome =  nome.capitalize()
        aluno = Aluno(nome,matricula,documento)
        alunodao = AlunoDao()
        alunodao.cad1astrar_aluno(aluno)#cadastrando
        alunodao.ordenar_alunos()#ordenando
        
    elif op == 2:
        alunodao = AlunoDao()
        alunodao.listar_aluno()#listando
    
    elif op ==3:
        print('Saindo')

    else:
        print('Opção inválida')