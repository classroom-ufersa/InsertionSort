from aluno import Aluno
from alunodao import AlunoDao

#teste por enquanto
aluno = Aluno('antrcos',111,123124)
alunodao = AlunoDao()
alunodao.cadastrar_aluno(aluno)
alunodao.listar_aluno()
