===== Lista 01 de EDA 2 ========

Alexandre Almeida Barbosa	- 10/0006345
Arthur de Moura Del Esposte - 10/0007813

# Busca de melhor critério para algoritmo guloso

Este programa busca identificar o melhor critério para a obtenção de um
caso ótimo para o problema de agendamento de tarefas, que se caracteriza
por ter solução otimizada através desse tipo de abordagem.

O programa consiste na geração de um conjunto randômico de tarefas, a serem
organizadas de modo a não se chocarem e obter-se o maior número de tarefas 
completadas.

A cada iteração, o programa analisa o conjunto-solução gerado a partir de 
cada tipo de ordenação. Assim, os casos considerados não ótimos (aqueles,
cuja quantidade de elementos é inferior à outros conjuntos-solução) são
descartados do grupo de soluções possíveis. 
O algoritmo termina quando há somente uma única solução ótima para o problema.


# Compilação e execução

Para compilar o programa utilize a seguinte linha de comando em ambiente linux com o compilador g++:

$ make

para executar:
$ ./prog

