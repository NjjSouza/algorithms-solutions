### ‎ >_ `#include <arvore>` | Enunciados

### ✉︎ Sobre este Tópico

`cout << "sobre" << endl;`

- [x] `const string tema = "Árvore";` Enunciados dos problemas de **Árvore**
- [x] `#include "arvore_XX.cpp"` Cada solução está em um arquivo separado, linkado logo abaixo do enunciado

* * *

### ✉︎ Índice

`vector<Problema> indice = { ... };`

| #  | Problema                             | Status |         Solução         |
|:--:|:-------------------------------------|:------:|:-----------------------:|
| 01 | (AVR) Pesquisa Em Arvores            |   ☑   | [.cpp](./arvore_01.cpp) |
| 02 | (ABB1) Biblioteca de Alexandria      |   ☑   | [.cpp](./arvore_02.cpp) |
| 03 | (ABB1) Plataforma de Streaming       |   ☑   | [.cpp](./arvore_03.cpp) |
| 04 | (ABB2) Reino de Dataland             |   ☑   | [.cpp](./arvore_04.cpp) |
| 05 | (ABB2) Organizando Rochas            |   ☑   | [.cpp](./arvore_05.cpp) |
| 06 | (ARV) Remover nós                    |   ☑   | [.cpp](./arvore_06.cpp) |
| 07 | (ARV) Média                          |   ☑   | [.cpp](./arvore_07.cpp) |
| 08 | (AVR) Ordenação                      |   ☑   | [.cpp](./arvore_08.cpp) |
| 09 | (ARV) Maior e menor elemento         |   ☑   | [.cpp](./arvore_09.cpp) |
| 10 | (AVR) Percurso em nível              |   ☑   | [.cpp](./arvore_10.cpp) |
| 11 | (AVR) Jovem Laka                     |   ☑   | [.cpp](./arvore_11.cpp) |
| 12 | (ARV) Contando primos                |   ☑   | [.cpp](./arvore_12.cpp) |
| 13 | (AVR) Número de folhas de uma árvore |   ☑   | [.cpp](./arvore_13.cpp) |

* * *

### ✉︎ 01 - Pesquisa em Árvores

#### Contexto

Faça um programa que leia `N` números inteiros e os insira em uma árvore binária.

Depois, o programa deve ler um outro número `X` e verificar se o mesmo está ou não na árvore.

#### Entrada

A entrada consiste de três linhas:

- A primeira consiste de um único inteiro `N`, que corresponde à quantidade de números a serem inseridos na árvore.
- A segunda linha contém `N` números inteiros, que devem ser inseridos na árvore.
- A última linha contém um único inteiro `X`, que é o elemento a ser procurado.

#### Saída

Na saída, o programa deve mostrar a mensagem `"Encontrado"`, se `X` estiver na árvore, ou `"Nao encontrado"`, caso contrário.

#### Exemplos

**Exemplo de entrada 1**
```text
8
10 7 15 2 8 12 20 3
3
```

**Exemplo de saída 1**
```text
Encontrado
```

**Exemplo de entrada 2**
```text
8
10 7 15 2 8 12 20 3
1
```

**Exemplo de saída 2**
```text
Nao encontrado
```

* * *

### ✉︎ 02 - Biblioteca de Alexandria

#### Contexto

Imagine que você é um bibliotecário na renomada Biblioteca de Alexandria. Sua tarefa é organizar uma vasta coleção de manuscritos usando uma técnica antiga, mas incrivelmente eficaz, conhecida como Árvore Binária de Busca (BST).

Cada manuscrito é representado por um número único e deve ser facilmente acessível. Seu desafio é desenvolver um sistema para inserir números de manuscritos na BST, de modo que possam ser recuperados rapidamente quando pesquisados.

A eficiência do seu sistema será testada através de uma série de inserções e buscas, refletindo o trabalho diário de catalogar e localizar manuscritos na biblioteca.

#### Entradas

- **Número de Operações (`N`):** O primeiro número inteiro na entrada (`1 ≤ N ≤ 100`) indica quantas operações serão realizadas.
- **Operações:** Cada uma das próximas `N` linhas descreve uma operação e pode ser de dois tipos:
    - `i x`: Insere o inteiro `x`, representando o número de um manuscrito, na árvore binária (`-10⁹ ≤ x ≤ 10⁹`).
    - `b x`: Busca o inteiro `x`, o número do manuscrito, na árvore binária e retorna se o manuscrito está catalogado ou não.

#### Saída

Para cada operação de busca (`b x`), imprima `"Sim"` se o manuscrito estiver catalogado na árvore ou `"Não"` caso contrário.

#### Exemplos

**Exemplo de entrada**
```text
5
i 1023
i 581
i 2048
b 581
b 9999
```

**Exemplo de saída**
```text
Sim
Não
```

***

### ✉︎ 03 - Plataforma de Streaming

#### Contexto

Você está trabalhando em uma nova rede de streaming e, para organizar os filmes na plataforma, decidiu utilizar uma árvore binária de busca ordenada pelos nomes dos filmes.

Faça um programa que insira o nome, gênero, duração em minutos, classificação de idade e ano de cada filme na árvore. Além disso, dado o nome de um determinado filme, o programa deve realizar uma pesquisa e mostrar suas informações.

#### Entradas

A entrada terá 3 opções:

- `1`: Inserir um filme. O usuário deverá informar o nome, gênero, duração, classificação de idade e ano do filme.
- `2`: Pesquisar um filme pelo nome. O usuário deverá informar apenas o nome do filme que deseja pesquisar.
- `0`: Sair do programa.

#### Saída

Quando um filme for pesquisado:

- Se ele estiver na árvore, mostre todas as suas informações.
- Caso contrário, mostre a mensagem `"Filme nao encontrado"`.

Adicionalmente, se o usuário inserir uma opção diferente das três anteriores, mostre a mensagem `"Operação inválida"`.

#### Exemplos

**Exemplo de entrada**
```text
1
Hereditario
Terror
127
16
2018
1
Aniquilacao
Terror
115
14
2018
1
Maze Runner - Correr ou Morrer
Acao
114
14
2014
1
O Preco do Amanha
Sci-fi
109
12
2011
1
Ex_machina - Instinto Artificial
Sci-fi
108
14
2015
2
Aniquilacao
4
2
Forrest Gump
2
Ex_machina - Instinto Artificial
0
```

**Exemplo de saída**
```text
Nome: Aniquilacao
Genero: Terror
Duracao: 115 mins
Classificacao: 14
Ano: 2018
Operacao invalida
Filme nao encontrado
Nome: Ex_machina - Instinto Artificial
Genero: Sci-fi
Duracao: 108 mins
Classificacao: 14
Ano: 2015
```

***

### ✉︎ 04 - Reino de Dataland

#### Contexto

No reino de Dataland, os dados são organizados em estruturas mágicas chamadas Árvores Binárias de Busca (BST).

Você, um mago dos dados, recebeu uma tarefa especial: gerenciar essas árvores, inserindo, removendo e verificando a presença de elementos.

Você precisa garantir que os elementos possam ser adicionados e removidos eficientemente e que, após a remoção, eles realmente desapareçam da árvore.

Este exercício simulará essas operações para testar suas habilidades de manipulação da BST.

#### Entradas

- **Número de Operações (`N`):** O primeiro número inteiro na entrada (`1 ≤ N ≤ 100`) indica quantas operações serão realizadas.
- **Operações:** Cada uma das próximas `N` linhas descreve uma operação e pode ser de três tipos:
  - `i x`: Insere o inteiro `x` na árvore binária (`-10⁹ ≤ x ≤ 10⁹`).
  - `r x`: Remove o inteiro `x` da árvore binária.
  - `b x`: Busca o inteiro `x` na árvore binária e retorna se o elemento ainda está presente ou não.

#### Saída

Para cada operação de busca (`b x`), imprima:

- `"Sim"` se o elemento `x` ainda estiver presente na árvore após as operações de inserção e remoção.
- `"Não"` se o elemento tiver sido removido com sucesso e não estiver mais presente.

#### Exemplos

**Exemplo de entrada**
```text
7
i 50
i 30
i 70
r 30
b 30
b 50
b 70
```

**Exemplo de saída**
```text
Não
Sim
Sim
```

***

### ✉︎ 05 - Organizando Rochas

#### Contexto

Sua amiga Isabela anda muito atarefada ultimamente com seu novo emprego como geóloga e quer uma forma mais eficiente de organizar os nomes e classificações de suas amostras de rochas.

Para ajudá-la, você decidiu fazer um programa que utiliza uma **árvore binária de busca (BST)**, que guardará o nome e o tipo de cada amostra, ordenando-a por seus nomes.

O programa deve permitir que Isabela:

- Insira novas amostras na árvore.
- Pesquise uma amostra pelo seu nome, mostrando todas as suas informações como resultado da pesquisa.
- Remova as amostras que foram descartadas, considerando o nome e o tipo da rocha.

#### Entrada

A entrada terá 4 opções:

- `1`: Inserir uma amostra. Serão informados o nome e o tipo da rocha.
- `2`: Pesquisar uma amostra. Apenas o nome será informado.
- `3`: Remover uma amostra. O nome e o tipo da pedra devem estar de acordo com as informações contidas na árvore.
- `0`: Terminar o programa.

#### Saída

- Quando uma pedra for pesquisada, mostre seu nome e tipo se for encontrada. Caso contrário, mostre a mensagem `"Rocha nao encontrada"`.
- Ao remover uma pedra, informe se ela foi removida com sucesso ou não.
- Se o usuário inserir uma opção diferente das quatro anteriores, mostre a mensagem `"Operação inválida"`.

#### Exemplos

**Exemplo de entrada**
```text
1
Arenito
Sedimentar
1
Evaporitos
Sedimentar
1
Basalto
Magmatica
1
Xisto
Metamorfica
1
Diabasio
Magmatica
1
Calcario
Sedimentar
3
Arenito
Magmatica
2
Arenito
3
Arenito
Sedimentar
2
Arenito
0
```

**Exemplo de saída**
```text
Rocha nao encontrada para remocao
Nome: Arenito
Tipo: Sedimentar
Rocha removida com sucesso
Rocha nao encontrada
```

***

### ✉︎ 06 - Remover Nós

#### Contexto

Faça um programa que leia vários números inteiros e os insira em uma árvore binária.

Depois, o programa deve ler um inteiro `x` e remover todos os nós cujo campo `info` seja igual a `x`, mostrando os elementos restantes em ordem crescente.

#### Entrada

A entrada consiste de duas linhas:

- A primeira linha contém vários números inteiros, que devem ser inseridos na árvore. Esta linha termina com o número `0`, que não deve ser inserido na árvore.
- A segunda linha contém o valor de `x`, que representa o elemento a ser removido.

#### Saída

Após remover todos os nós cujo campo `info` seja igual a `x`, o programa deve mostrar os nós restantes em ordem crescente, como no exemplo abaixo.

#### Exemplos

**Exemplo de entrada**
```text
10 7 4 2 4 5 0
4
```

**Exemplo de saída**
```text
2 5 7 10
```

***

### ✉︎ 07 - Média

#### Contexto

Faça um programa que insira vários números em uma árvore binária e, depois, verifique qual é a média dos elementos armazenados na árvore.

A média deve ser calculada através de uma função com o seguinte cabeçalho:

```cpp
float media(treenodeptr arvore);
```

#### Entrada

Na primeira linha da entrada serão fornecidos vários números inteiros, que deverão ser inseridos na árvore até que seja lido o número `-1`, que não deve ser inserido.

#### Saída

O programa deve informar a média dos elementos da árvore com **2 casas decimais de precisão**.

#### Exemplos

**Exemplo de entrada**
```text
8 3 10 14 6 4 13 7 1 -1
```

**Exemplo de saída**
```text
Media: 7.33
```

***

### ✉︎ 08 - Ordenação

#### Contexto

Dada uma sequência de números, ordene-os em ordem decrescente utilizando os conceitos de árvore binária.

#### Entrada

Serão fornecidos `N` números inteiros, que deverão ser inseridos na árvore até que seja lido o valor `-1`, que indica o fim da entrada e não deve ser inserido.

#### Saída

A saída deve conter a sequência de números em **ordem decrescente**.

#### Exemplos

**Exemplo de entrada**
```text
10 7 15 2 8 12 20 3 -1
```

**Exemplo de saída**
```text
20 15 12 10 8 7 3 2
```

***

### ✉︎ 09 - Maior e menor elemento

#### Contexto

Faça um programa que verifique qual é o menor e o maior elemento de uma árvore binária.

Crie as seguintes funções para encontrar esses elementos:

```cpp
int maior(treenodeptr arvore);

int menor(treenodeptr arvore);
```

#### Entrada

A entrada consiste em uma sequência de números inteiros, que representam os valores a serem inseridos na árvore, até que seja informado o valor `-1`, indicando o fim da entrada.

#### Saída

A saída deve conter o menor e o maior elemento da árvore, separados pela palavra `"e"`.

#### Exemplo

**Exemplo de entrada**
```text
10 7 15 2 8 12 20 3 -1
```

**Exemplo de saída**
```text
2 e 20
```

* * *

### ✉︎ 10 - Percurso em nível

#### Contexto

Faça um programa que insira vários números em uma árvore binária e, depois, mostre o percurso em nível.

Não se esqueça de liberar a memória utilizada pela árvore.

#### Entrada

Na primeira linha da entrada serão fornecidos vários números inteiros, que deverão ser inseridos na árvore até que seja lido o número `-1`.

#### Saída

O programa deve mostrar o percurso em nível da árvore.

#### Exemplo

**Exemplo de entrada**
```text
8 3 10 14 6 4 13 7 1 -1
```

**Exemplo de saída**
```text
8 3 10 1 6 14 4 7 13
```

* * *

### ✉︎ 11 - Jovem Laka

#### Contexto

Jovem Laka é um pirata que adora sair nesse mundão atrás de baús. Porém, esses baús não possuem ouro, possuem chocolates.

Talento era o nome do pai de Laka e, antes de morrer, Talento disse para Laka que todos os mapas de chocolate possuem um padrão: cada número representa uma cidade. Quando esse número é inserido em uma árvore, é possível verificar qual o melhor caminho para se chegar ao tesouro que está na cidade `X`.

Laka sempre sabe a cidade onde está o chocolate, portanto, faça um programa que, depois de fornecidas as cidades, diga ao jovem Laka qual o melhor caminho.

#### Entrada

A entrada consiste de duas linhas:

- A primeira linha contém `N` (`1 ≤ N ≤ 100`) números inteiros, que representam as cidades e devem ser inseridos na árvore até que a entrada seja `-1`, indicando o fim da sequência (o valor `-1` não deve ser inserido).
- A segunda linha contém um único número inteiro `X`, que representa a cidade em que está o chocolate.

#### Saída

A saída deve conter `"Pre"`, `"Em"` ou `"Pos"`, indicando qual percurso é o caminho mais rápido (`PreOrdem`, `EmOrdem` ou `PosOrdem`) até a cidade informada.

Considere que não haverá empate.

#### Exemplo

**Exemplo de entrada**
```text
10 7 15 2 8 12 20 3 -1
8
```

**Exemplo de saída**
```text
Pos
```

No exemplo acima, os percursos mostrariam as cidades nas seguintes ordens:

- **PreOrdem:** `10 7 2 3 8 15 12 20`
- **EmOrdem:** `2 3 7 8 10 12 15 20`
- **PosOrdem:** `3 2 8 7 12 20 15 10`

Repare que a resposta é `"Pos"`, pois o caminho mais rápido até a cidade informada é usando **PosOrdem**.

* * *

### ✉︎ 12 - Contando primos

#### Contexto

Faça um programa que vá lendo e inserindo vários números em uma árvore binária.

Depois, faça uma função que varra esta árvore e mostre quantos elementos inseridos são primos. O cabeçalho desta função deve ser:

```cpp
int contaPrimos(treenodeptr arvore);
```

Finalmente, o programa deve fazer uso desta função para mostrar a quantidade de números primos inseridos na árvore.

#### Entrada

A entrada consiste de uma única linha com vários números inteiros positivos, que deverão ser inseridos na árvore até que seja lido o número `-1`, que não deve ser inserido.

#### Saída

Na saída, o programa deve mostrar a quantidade de números primos presentes na árvore, seguida da mensagem `"numeros primos"`, conforme o exemplo.

#### Exemplo

**Exemplo de entrada**
```text
10 7 15 2 8 12 20 3 -1
```

**Exemplo de saída**
```text
3 numeros primos
```

* * *

### ✉︎ 13 - Número de folhas de uma árvore

#### Contexto

Faça um programa que, dada uma árvore binária, informe quantas folhas essa árvore possui.

As folhas devem ser contadas através de uma função com o seguinte cabeçalho:

```cpp
int contaFolhas(treenodeptr arvore);
```

#### Entrada

Haverá `N` números inteiros a serem inseridos na árvore até que a entrada seja `-1`, que indica o fim da leitura e não deve ser inserido na árvore.

#### Saída

A saída deve conter o número de folhas da árvore.

#### Exemplo

**Exemplo de entrada**
```text
10 7 15 2 8 12 20 3 -1
```

**Exemplo de saída**
```text
4
```

* * *
