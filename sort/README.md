===== Lista 02 de EDA 2 ========

Alexandre Almeida Barbosa - 10/0006345
Arthur de Moura Del Esposte - 10/0007813


Para compilar o programa utilize o Makefile com a seguinte linha de comando em um ambiente linux:
$ make clean
$ make

Ou se preferir pode compilar manualmente utilizando o seu compilador, seguindo o mesmo realizado no Makefile

para executar:
$ ./prog

este programa contém a resolução e testes criados para as questões 5, 6 e 7 da lista 02

O programa principal, arquivo main.cpp, contém a execução de todos os algoritmos de ordenação criados para esta lista. Todos executam a ordenação em um vetor aleatoriamente desordenado. Para cada algoritmo, são impressas as seguintes informações:
===========Nome do Algoritmo=======
Vetor Inicial

Vetor Ordenado
===================================

- Para a questão 5 foi implementado uma estrutura de lista duplamente encadeada (List.hpp e List.cpp) que foi sorteada utilizando a classe do QuickSort (Quick.cpp e Quick.hpp).

- Para a questão 6 foi implementado as duas formas solicitadas de ordenação utilizando HeapSort. Ambas utilizam a estrutura Heap criada (HeapTree.cpp e HeapTree.hpp), sendo que a primeira que ordena de modo normal pode ser vista na classe Heap (Heap.cpp e Heap.hpp) e a segunda, que ordena inserindo todos os elementos e depois removendo-os, pode ser vista na classe InsertHeap (InsertHeap.cpp e InsertHeap.hpp). Ambas são executadas no programa principal, com complexidade O (log n). Isto se deve pois, tanto a remoção quanto a inserção do segundo método possuem complexidade O(log n), mas são executados independentes, um após o outro com um total de interação igual à 2log(n).

