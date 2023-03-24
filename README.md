# InsertionSort
## Descrição

É um algoritmo de ordenação que, dado uma estrutura (array, lista) constrói uma matriz final com um elemento de cada vez, uma inserção por vez. Assim como algoritmos de ordenação quadrática, é bastante eficiente para problemas com pequenas entradas, sendo o mais eficiente entre os algoritmos desta ordem de classificação.

## Características
Apesar de ser menos eficiente do que algoritmos como Merge Sort e Quick Sort (de ordem O(nlog(n))), o Insertion Sort possui algumas características consideráveis:

 – É de simples implementação, leitura e manutenção;

 – In-place: Apenas requer uma quantidade constante de O(1) espaço de memória adicional;

 – Estável: Não muda a ordem relativa de elementos com valores iguais;

 – Útil para pequenas entradas;

 – Muitas trocas, e menos comparações;

 – Melhor caso: O(n), quando a matriz está ordenado;

 – Médio caso: O(n²/4), quando a matriz tem valores aleatórios sem ordem de classificação (crescente ou decrescente);

 – Pior caso: O(n²), quando a matriz está em ordem inversa, daquela que deseja ordenar.

## Vantagens e Desvantagens
Vantagem:

 – É o método a ser utilizado quando o arquivo está "quase" ordenado;

 – É um bom método quando se desejar adicionar poucos elementos em um arquivo já ordenado, pois seu custo é linear;

 – O algoritmo de ordenação por inserção é estável.


Desvantagem:

 – Alto custo de movimentação de elementos no vetor.
