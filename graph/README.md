===== Trabalho de Grafos de EDA 2 ========
===================================

Alexandre Almeida Barbosa - 10/0006345 
Arthur de Moura Del Esposte - 10/0007813

O presente trabalho contempla a criação de uma estrutura completa de grafos e uma aplicação desta teoria.

Descrição da Aplicação
===================================
Esse trabalho está sendo realizado baseado em uma base de dados relacionada a informações de revistas em quadrinhos da Marvel que pode ser obtida através da API oficial da própria Marvel (http://developer.marvel.com/). Através dessa API foram obtidas duas informações principais:

- Personagens: personagens que estão presentes nas sagas e eventos dos quadrinhos e que serão os nós do grafo que serão relacionados entre si.
- Eventos: correspondem aos eventos que acontecem nos quadrinhos. Os eventos envolvem um ou mais personagens. Assim, sempre que um personagem A participar de um mesmo evento que um personagem B, os seus respectivos nós serão ligados nas duas direções caso ainda não sejam, incrementando o peso da aresta em 1.

Com o grafo montado, será possível verificar quais personagens possuem relações fortes com outros personagens, quais vilões estão mais presentes na vida de um herói, qual a distância entre um personagem e outro dentro do universo de eventos obtidos.


Estado atual
===================================
A maior parte da estrutura do Grafo já está pronta, incluindo operações importantes. Ainda é necessário implementar as modificações para que os nós representem os personagens, dar pesos às arestas e a apresentação/interação para apresentar os resultados do grafo (obter informações de um personagem, por exemplo).

Além disso, o parse para obter os dados da API já está finalizado e os principais dados a serem utilizados estão nos arquivos:
- events.txt
- characters.txt

Esse parse foi desenvolvido utilizando Ruby e está em anexo.
Para o escopo do trabalho, não será mais necessário evoluir este módulo, somente o projeto desenvolvido em C++.