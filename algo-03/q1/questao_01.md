Enunciado:
O prefeito de Anatriacé, Leon Jaspos está sendo muito criticado pelas inundações constantes na cidade. Ele está reativando um sistema de drenagem de água e te contratou para ajudar a resolver o problema. A cidade conta com algumas bombas de água conectas a um sistema de encanamentos que leva até as regiões alagadas. Porém essas bombas foram compradas um pouco abaixo da capacidade definida em projeto para que sobrasse um pouco de dinheiro da licitação para que ele pudesse fazer uma manutenção em seu iate particular. Ele tem um mapa de todas as bombas e as conexões com as regiões alagadas, contendo o tamanho de cada um dos canos. Sabendo que a bomba tem a capacidade de atender todas as regiões a uma distância menor ou igual a 15 km, ele precisa saber quais regiões vão continuar alagadas dado o local de instalação da bomba.

Entrada
A entrada começa com um número inteiro indicando a quantidade R de regiões alagadas. Em seguida é informado um valor inteiro indicando a quantidade C de encanamentos. As C linhas seguintes contêm três inteiros indicando o código da região origem, o código da região destino e o tamanho em quilômetros de cada cano. Por fim, é informado um valor B, indicando em qual região a bomba vai ser instalada.

Saída
A saída é uma lista de regiões que continuam alagadas, ou seja, que estão a mais de 15 km da bomba, conforme o exemplo abaixo. Caso nenhum região continue alagada, apresente a mensagem "Nenhuma região alagada".



Exemplo de entrada     	Exemplo de saída
11                              8
14                              9
0 1 5                          10
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


