#include <iostream>
#include <list>

using namespace std;

bool encontrar(list<int> lista, int x) {
    // usando o iterador 
    for (list<int>::iterator it = lista.begin(); it != lista.end(); ++it) {
        if (*it == x) {
            return true;
        }
    }
    return false;
}

int main() {
    list<int> lista;
    int entrada;

    // lendo os números até encontrar 0
    while (cin >> entrada && entrada != 0) {
        lista.push_back(entrada);
    }

    int busca; // número procurado
    if (cin >> busca) {
        if (encontrar(lista, busca)) {
            cout << "Encontrado" << endl;
        } else {
            cout << "Nao encontrado" << endl;
        }
    }
    
	// liberando a memória alocada
	while(!lista.empty())
		lista.pop_front();

    return 0;
}