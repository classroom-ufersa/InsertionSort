//declarando vetor de alunos
let alunos = [];

//função pra cadastro de alunos
function addAluno() {
  let nome = document.getElementById("nome").value;
  let matricula = document.getElementById("matricula").value;
  let documento = document.getElementById("documento").value;

  alunos.push({ nome, matricula, documento });
  insertionSort(alunos);

  let tbody = document.querySelector("#lista-alunos tbody");
  tbody.innerHTML = "";
  for (let aluno of alunos) {
    tbody.innerHTML += `<tr><td>${aluno.nome}</td><td>${aluno.matricula}</td><td>${aluno.documento}</td></tr>`;
  }
}
//função pra ordenar o vetor de alunos
function insertionSort(arr) {
  for (let i = 1; i < arr.length; i++) {
    let j = i - 1;
    let temp = arr[i];
    while (j >= 0 && arr[j].nome > temp.nome) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}