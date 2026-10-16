#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> lista;
    list<int>::iterator p;
    
    int n;
    for (int i = 0; i < 4; i++) {
        cin >> n;
        lista.push_front(n); // insere no topo
    }
    
    for(p = lista.begin(); p != lista.end(); p++) {
        cout << *p << " ";
    }
    
    // liberando a memória alocada
	while(!lista.empty())
		lista.pop_front();
    
    return 0;
}