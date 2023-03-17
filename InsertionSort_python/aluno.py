
class Aluno(): #criando a classe de aluno e encapsulando
    def __init__(self,nome,matricula,documento) -> None:
        self.nome=nome
        self.matricula=matricula
        self.documento=documento
        pass
    
    def getNome(self):
        return self.nome
   
    def setNome(self,nome):
        self.nome = nome
    
    def getMatricula(self):
        return self.matricula
   
    def setMatricula(self,matricula):
        self.matricula = matricula
    
    def getDocumento(self):
        return self.documento
   
    def setDocumento(self,documento):
        self.documento = documento

    
    nome = property(fget=getNome,fset=setNome)
    documento = property(fget=getDocumento, fset=setDocumento)
    matricula = property(fget=getMatricula,fset=setMatricula)