# Exercício de boas vindas - Revisão AEDSs 1

[![Linguagem C](https://img.shields.io/badge/Linguagem-C-green.svg)](https://github.com/PedroLouback/TrabalhoFinal-Prog.2)
[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![ISO](https://img.shields.io/badge/ISO-Linux-blueviolet)


---

## Apresentação

Foi proposto como um exercício de boas vindas dado como revisão da matéria de `Arquitetura e Estruturas de Dados 1 do 3º Período do curso de Engenharia da Computação`, onde tinha como objetivo elaborar um pequeno programa que compunha de uma matriz quadrada onde sua ordem era dada como entrada e a partir disso, este programa precisava executar as seguintes operações:

- [X] Preencher a matriz quadrada com números aleatórios de 0 a 99;
- [X] Considerar a posição de linha 0 e coluna 0 como início;
- [X] Considerar a a ultima linha da ultima coluna seja a posição final;
- [X] Percorrer a matriz a partir do início, somando a cada passo, o próximo maior valor encontrado;
- [X] A celula podendo se locomover dentro da matriz tanto para baixo quanto para os lados;
- [X] Chegando a ultima linha a matriz deve ser percorrida somente para o lado do final;
- [X] Apresentar a soma dos valores percorridos do incio até o final.

Esta pequena revisão trabalhada é chamada de algoritmos gulosos, onde se caminha por uma matriz objetivando sempre a busca pelos maiores valores segunda as regras implementadas sempre buscando uma boa estruturação de código.

---

## Lógica

Ao tentar pensar em diversas formas de resolver o problema proposto de forma em que há uma boa estruturação de código e um bom custo computacional, foi então pensado na forma de tratar caso por caso como por exemplo começar tratar as bordas onde cada uma tinha uma particularidade diferente em seu modo de se locomover, após isso foi pensado em tratar a ultima linha como uma atenção maior no último elemento sendo seu final e também procurei tratar aqueles elementos que não estavam inclusos em nenhuma ocasião mencionado, sendo os elementos do "meio" onde podem se locomover tanto para os lados quanto para baixo. Foi criada uma função chamada `PercorrendoMatriz` onde primeiramente nela declarei uma variavel _bool_ que recebia o valor _false_ e já comecei tratando o primeiro elemento, armazenando o valor da sua celula na variavel *soma_dos_valores* para mais tarde essa variavel ir somando os valores percorridos, após isso, invalidei a primeira celula para meu programa não retorna-lá e criar um loop infinito caso seja um valor maior. Tratei as outras especifidades com `IFs` onde verificava se o proximo valor, seja ele pra baixo ou para os lados, é maior que os demais valores que é permitido percorrer e também se a celula não estava invalidada e ao acionar esse `IF` é realizada um total de 3 operações onde na primeira é feita a soma do próximo valor da posição passada pelo `IF`, já a segunda já invalidava a celula que foi encotrado o maior valor e na terceira operação é feita a locomoção dessa celula caso for para a direita sera **j++**, caso for para a esquerda sera **j--** e se for para baixo será **i++**. Um caso especifico foi tratado onde verificava com um `IF` se a posição sera a ultima e se caso a verificação for verdadeira será apenas locomovida a celula para a direita não havendo soma de valor nenhum pois a soma do valor dessa celula foi feita na verificação anterior pois tratei a as ações sempre nas celulas posteriores e no caso da ultima isso não poderia ocorrer, sendo ela a única verificação diferente para não exceder a matriz. Ao final dessa função é imprimido a soma de todos os valores que foram percorridos durante a matriz, resolvendo então a proposta do problema.  

---

## Representação gráfica

Segue a representação gráfica de um exemplo de uma matriz 5x5 dada pela execução do programa e a soma dos valores percorridos:

<div align="center">
<img src="https://imgur.com/9brGxhw.png" width="1500px" />
</div>

                                     Total do caminho percorrido feito pela soma dos valores: 
                                    73 + 63 + 38 + 37 + 19 + 42 + 96 + 26 + 52 + 90 + 89 = 625 

---

## Perguntas

### 1) - Há mais de uma maneira de resolver esse problema?

Existe diversas formas para resolver sendo elas tendo um custo computacional maior ou menor como por exemplo existe pode existir uma maneira onde seria tratado elemento por elemento solucionando então todas problemas apresentados como por exemplo para não exceder a matriz na bordas e um tratamento diferenciado nas pontas. Outra maneira de resolver esse problema que provavelmente haverá um custo menor resumiria em ordenar todos os elementos em ordem crescente em uma forma de L ordenando até o final obtendo assim os maiores valores e fazendo um pequeno caminho.

Ex: <div align="center">
<img src="https://imgur.com/iUXHFkY.png" width="400px" />
</div>

### 2) - Há algoritmos em literatura que resolvam esse problema?

Existe na literatura o algoritmo de Dijkstra em que ele trata de problemas com custo minimo do caminho.

### 3) - Pode existir mais de um caminho cujo valor total é o maximo?

Pode sim, foi pensando em uma maneira em que ordene os vetores em ordem crescente na primeira linha, na segunda, continuando do ultimo da primeira linha, seja ordenada em ordem crescente novamente e na terceira segue o mesmo raciocionio até chegar no final, obtendo assim um trilha com os maiores valores sendo percorridos em seguida, pegando todos os valores.

---

## Compilação e Execução

O programa feito de acordo com a proposta possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação             


---

## Autor

Criado por [Pedro Henrique Louback Campos](https://www.linkedin.com/in/pedro-henrique-louback-campos-0a4a03205/)

Aluno do 3° periodo do curso de `Engenharia da Computação` no [CEFET-MG](https://www.cefetmg.br)
