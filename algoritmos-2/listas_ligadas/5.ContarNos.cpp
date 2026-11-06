#include <iostream>
#include <list>

using namespace std;

int contar(list<int> lista)
{
    int total = 0;
    // usando o iterador 
    for (list<int>::iterator it = lista.begin(); it != lista.end(); ++it) {
        total++;
    }
    return total;
}

int main()
{
    list<int> lista;
    int entrada;

    // lendo os números até encontrar 0
    while (cin >> entrada && entrada != 0) {
        lista.push_back(entrada);
    }
    
    cout << contar(lista) << endl;
    
	// liberando a memória alocada
	while(!lista.empty())
		lista.pop_front();
    
    return 0;
}