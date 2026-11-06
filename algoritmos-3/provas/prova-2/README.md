### ‎ >_ `#include <prova_02>` | Prova 2 - Algoritmos 3

### ✉︎ Sobre esta Prova

`cout << "sobre" << endl;`

- [x] `const string prova = "Prova 2";` Questões práticas da segunda avaliação de **Algoritmos 3**
- [x] `#include "questao_XX.cpp"` Cada resolução possui seu arquivo `.cpp` correspondente, linkado na tabela abaixo

* * *

### ✉︎ Índice

`vector<Questao> indice = { ... };`

| #  | Questão                                     | Status |          Solução           |
|:--:|:--------------------------------------------|:------:|:--------------------------:|
| 01 | Sistema de Drenagem e Bombas de Água        |   ☐   | [.cpp](./questao_01.cpp)   |
| 02 | Árvore de Habilidades (RPG Skill Tree)      |   ☐   | [.cpp](./questao_02.cpp)   |

* * *

### ✉︎ 01 - Sistema de Drenagem e Bombas de Água

#### Contexto

O prefeito de Anatriacé, Leon Jaspos, está sendo muito criticado pelas inundações constantes na cidade. Ele está reativando um sistema de drenagem de água e te contratou para ajudar a resolver o problema.

A cidade conta com algumas bombas de água conectadas a um sistema de encanamentos que leva até as regiões alagadas. Porém, essas bombas foram compradas um pouco abaixo da capacidade definida em projeto para que sobrasse um pouco de dinheiro da licitação para que ele pudesse fazer uma manutenção em seu iate particular.

Ele tem um mapa de todas as bombas e as conexões com as regiões alagadas, contendo o tamanho de cada um dos canos. Sabendo que a bomba tem a capacidade de atender todas as regiões a uma distância menor ou igual a 15 km, ele precisa saber quais regiões continuarão alagadas, dado o local de instalação da bomba.

#### Entrada

A entrada consiste de:

- Um número inteiro `R`, indicando a quantidade de regiões alagadas.
- Um número inteiro `C`, indicando a quantidade de encanamentos.
- As `C` linhas seguintes contêm três inteiros: o código da região de origem, o código da região de destino e o tamanho em quilômetros de cada cano.
- Por fim, um valor inteiro `B`, indicando em qual região a bomba será instalada.

#### Saída

A saída deve ser uma lista com os códigos das regiões que continuam alagadas (isto é, que estão a mais de 15 km da bomba), apresentadas em ordem crescente, uma por linha.

Caso nenhuma região continue alagada, imprima a mensagem:

```text
Nenhuma região alagada
```

#### Exemplo

**Exemplo de entrada**
```text
11
14
0 1 5
0 2 9
0 3 10
1 4 1
2 5 1
2 6 2
3 7 2
4 5 1
5 10 10
6 7 6
6 9 6
7 8 5
8 9 5
9 10 8
0
```

**Exemplo de saída**
```text
8
9
10
```

* * *

### ✉︎ 02 - Árvore de Habilidades

#### Contexto

Poles está desenvolvendo uma árvore de habilidades para o seu jogo de RPG. Ele quer que os personagens possam escolher, partindo de uma habilidade principal, algumas ramificações possíveis. Cada habilidade pode ser desbloqueada por diferentes caminhos de upgrades, porém todos os upgrades são direcionados.

Para cada upgrade de habilidade, o personagem deve gastar alguns pontos de experiência e pode adquirir alguma pontuação de poder.

Ele quer saber, dada uma determinada árvore de habilidades, qual é o custo mínimo de experiência para desbloquear todas as habilidades.

#### Entrada

A entrada consiste de:

- Um número inteiro `H`, indicando a quantidade de habilidades.
- As `H` linhas seguintes contêm o nome (palavra) e o poder (número real) de cada habilidade. Cada habilidade possui um código sequencial de `0` a `H - 1`, conforme a ordem da entrada de dados.
- Em seguida, um número inteiro `U`, indicando a quantidade de upgrades possíveis.
- As `U` linhas seguintes contêm três inteiros: o código da habilidade de origem, o código da habilidade de destino e o custo de experiência do upgrade.

#### Saída

A saída deve conter um único número inteiro indicando o custo mínimo de experiência necessário para desbloquear todas as habilidades.

#### Exemplo

**Exemplo de entrada**
```text
10
Base 0
Dash 1
Thief 3
Hunter 3
Assassin 4
BeastMaster 5
Berserker 7
WildMagic 2
Vengeance 4
Life 5
12
0 1 1
1 2 2
1 3 2
3 4 3
3 5 3
3 6 4
0 7 2
7 8 3
7 9 3
1 7 3
8 6 5
2 4 5
```

**Exemplo de saída**
```text
23
```

* * *
