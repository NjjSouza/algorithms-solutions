#include<iostream>
#include<list>
#include<string>
using namespace std;

#define INF 99999

struct Aresta{
	int origem;
	int destino;
	int peso;
};

void bfs(list<Aresta> grafo[], int vertices, int origem){
    bool visitado[vertices];
	list<int> fila_visitacao;
	list<Aresta>::iterator it;


	for(int i=0; i<vertices; i++)
		visitado[i] = false;

	fila_visitacao.push_back(origem);
	visitado[origem] = true;

	while( !fila_visitacao.empty()){
		int atual = fila_visitacao.front();
		for(it = grafo[atual].begin(); it != grafo[atual].end(); it++){
			int i = it->destino;//(*it).destino;
			if(!visitado[i]){
				fila_visitacao.push_back(i);
				visitado[i] = true;
			}
		}
		fila_visitacao.pop_front();
	}
}

int prim(list<Aresta> grafo[], int vertices, int origem){
    bool visitado[vertices];
    int pai[vertices], distancia[vertices], atual;
    for(int i=0; i<vertices; i++){
        visitado[i] = false;
        pai[i] = -1;
        distancia[i] = INF;
    }
    atual = origem;
    distancia[atual] = 0;
    while(!visitado[atual]){
        visitado[atual] = true;
        list<Aresta>::iterator it;
        for(it=grafo[atual].begin();it!=grafo[atual].end();it++){
            int d = it->destino, p = it->peso;
            if(!visitado[d] && p < distancia[d]){
                distancia[d] = p;
                pai[d] = atual;
            }
        }
        int menor_distancia = INF;
        for(int i=0; i<vertices; i++){
            if(!visitado[i] && distancia[i] < menor_distancia){
                menor_distancia = distancia[i];
                atual = i;
            }
        }
    }
    int peso_mst = 0;
    for(int i=0; i<vertices; i++){
        peso_mst += distancia[i];
    }
    return peso_mst;
}

void dijkstra(list<Aresta> grafo[], int vertices, int origem){
    bool visitado[vertices];
    int distancia[vertices], pai[vertices];
	for(int i=0; i<vertices; i++){
		visitado[i] = false;
		distancia[i] = INF;
		pai[i] = -1;
	}
    distancia[origem] = 0;
    int atual = origem;
    while(visitado[atual] == false){
        visitado[atual] = true;
        list<Aresta>::iterator it;
        for(it = grafo[atual].begin(); it != grafo[atual].end(); it++){
            int destino = it->destino;
            int peso = it->peso;
			if(distancia[destino] > distancia[atual] + peso && visitado[destino] == false){
                distancia[destino] = distancia[atual] + peso;
                pai[destino] = atual;
			}
		}
        atual = 0;
        int menor_distancia = INF;
        for(int i=0; i<vertices; i++){
            if(visitado[i]==false && distancia[i] < menor_distancia){
                menor_distancia = distancia[i];
                atual = i;
			}
		}
	}
}



int main(){

    // Use as funções e as structs fornecidas para resolver a atividade.
    // Não esqueça de fazer os ajustes necessários nas funções para que elas retornem o resultado esperado.

    // Tome cuidado com a passagem de parâmetros.
    // Verifique cada um deles e tente enteder o que cada um deles traz de informação para resolver o problema.

    // Você também pode implementar a sua própria solução

}
/*

O prefeito de Anatricé, Leon Jaspos está sendo muito criticado pelas inundações constantes na cidade. Ele está reativando um sistema de drenagem de água e te contratou para ajudar a resolver o problema. A cidade conta com algumas bombas de água conectas a um sistema de encanamentos que leva até as regiões alagadas. Porém essas bombas foram compradas um pouco abaixo da capacidade definida em projeto para que sobrasse um pouco de dinheiro da licitação para que ele pudesse fazer uma manutenção em seu Iate particular. Ele tem um mapa de todas as bombas e as conexões com as regiões alagadas, contendo o tamanho de cada um dos canos. Ele precisa saber quais encanamentos deve ser desligados para que a soma dos tamanhos dos canos seja o menor possível.

Entrada
A entrada começa com um número inteiro indicando a quantidade R de regiões alagadas. Em seguida é informado um valor inteiro indicando a quantidade C de encanamentos. As C linhas seguintes contêm três inteiros indicando o código da região origem, o código da região destino e o tamanho de cada cano. Considere que a região 0 é a região onde a bomba está instalada.

Saída
A saída é uma lista de encanamentos que precisam ser desligados, onde cada cano é representado pela região de origem e região de destino, conforme o exemplo abaixo.

------------------------
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

8
9
10


*/