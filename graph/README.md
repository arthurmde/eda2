===== Trabalho de Grafos de EDA 2 ========
===================================

Alexandre Almeida Barbosa - 10/0006345
Arthur de Moura Del Esposte - 10/0007813

O presente trabalho contempla a criação de uma estrutura completa de grafos e uma aplicação desta teoria.

Descrição da Aplicação
===================================
Esse trabalho foi realizado baseado em uma base de dados relacionada a informações de revistas em quadrinhos da Marvel que pode ser obtida através da API oficial da própria Marvel (http://developer.marvel.com/). Através dessa API foram obtidas duas informações principais:

- Personagens: personagens que estão presentes nas sagas e eventos dos quadrinhos e que serão os nós do grafo que serão relacionados entre si.
- Eventos: correspondem aos eventos que acontecem nos quadrinhos. Os eventos envolvem um ou mais personagens. Assim, sempre que um personagem A participar de um mesmo evento que um personagem B, os seus respectivos nós serão ligados nas duas direções caso ainda não sejam, incrementando o peso da aresta em 1.

Com o grafo montado, será possível verificar quais personagens possuem relações fortes com outros personagens, quais vilões estão mais presentes na vida de um herói, qual a distância entre um personagem e outro dentro do universo de eventos obtidos.


Além disso, o parse para obter os dados da API já está finalizado e os principais dados a serem utilizados estão nos arquivos:
- events.txt
- characters.txt

Esse parse foi desenvolvido utilizando Ruby e está em anexo.
Para o escopo do trabalho, não será mais necessário evoluir este módulo, somente o projeto desenvolvido em C++.

Para compilar, basta rodar o make:
$ make clean
$ make
Caso se tenha o programa dotty instalado em um ambiente linux, o programa pode ser executado para gerar um subgrafo relacionado à uma personagem específico através da linha de comando
$ ./prog <id do personagem> | dot -Tpng -ograph.png

Irá ser gerado um arquivo graph.png com o grafo de relacionamento direto do personagem.

Outros dados mais detalhados do personagem podem ser acessados apenas executando-se o programa normalmente:
$ ./prog

Será solicitado o Id do personagem para o qual será impressa as informações em detalhes relacionados ao seu nó no grafo.

Use como exemplo o ID 1009368 referente ao Homem de Ferro e se divirta \o/.
