from aluno import Aluno

class AlunoDao:
    def __init__(self) -> None:
        pass

    def cadastrar_aluno(self,aluno: Aluno):#função pra cadastro
        cadastro = f"{aluno.nome};{aluno.matricula};{aluno.documento}\n" #pegando o aluno a ser cadastrado
        db = open('//home/augusto/Documentos/codigos/atividades est de dados/InsertionSort/InsertionSort_python/db/alunos.txt','a') #abrindo arquivo 
        db.write(cadastro) #cadastrando 
        
        #ESPAÇO PRA ORD

        db.close #fechando
    
    def listar_aluno(self):
        db = open('//home/augusto/Documentos/codigos/atividades est de dados/InsertionSort/InsertionSort_python/db/alunos.txt','r') #abrindo o arquivo pra leitura
        print("Nome Matricula Documento")
        for i in db:
            print(i) 
    
    def insertionSort(arr):
        #Função pro sort
        for i in range(1, len(arr)):
    
            pos = arr[i]
            j = i-1
            while j >= 0 and pos < arr[j] :
                    arr[j + 1] = arr[j]
                    j -= 1
            arr[j + 1] = pos

