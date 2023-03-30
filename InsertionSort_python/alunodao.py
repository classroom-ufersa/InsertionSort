from aluno import Aluno

class AlunoDao():
    def __init__(self) -> None:
        pass

    def cadastrar_aluno(self,aluno: Aluno):#função pra cadastro
        
        cadastro = f"{aluno.nome};{aluno.matricula};{aluno.documento}\n" #pegando o aluno a ser cadastrado
        db = open('InsertionSort_python/db/alunos.txt','a') #abrindo arquivo 
        db.write(cadastro) #cadastrando 
        db.close() #fechando
    
    def listar_aluno(self): 
        db = open('InsertionSort_python/db/alunos.txt','r') #abrindo o arquivo pra leitura
        print("Nome Matricula Documento")
        for i in db: #for que vai passar por todo o arquivo e imprimir linha por linhas
            print(i)

    def ordenar_alunos(self):

        vetor_iniciais = []
        #abrindo arquivo pra leitura
        db = open('InsertionSort_python/db/alunos.txt','r')
        linhas = db.readlines()#metodo q transforma as linhas do arquivo em uma lista
        db.close()

        for i in linhas:
            vetor_iniciais.append(i[0][0]) #coletando as iniciais para passar como argumento
        
        #Função para ordenar as letras
        
        for i in range(1, len(vetor_iniciais)):
    
            pos = vetor_iniciais[i]
            j = i-1
            while j >= 0 and pos < vetor_iniciais[j] :
                    vetor_iniciais[j + 1] = vetor_iniciais[j]
                    j -= 1
            vetor_iniciais[j + 1] = pos

        #ordenando os nomes em função das iniciais
        for x in range(0,len(vetor_iniciais)):    
            for y in range(0,len(vetor_iniciais)):
                if vetor_iniciais[x] == linhas[y][0]:
                    aux = linhas[x]
                    linhas[x] = linhas[y]
                    linhas[y] = aux
        #reescrevendo o arquivo txt
        result = open('InsertionSort_python/db/alunos.txt','w')        
        
        for z in range(0,len(vetor_iniciais)):
            aux2 = linhas[z]
            result.write(aux2)

        result.close()

