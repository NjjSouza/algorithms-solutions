#include <iostream>
#include <list>
using namespace std;

int main(){
	list<int> lista; // "ponteiro" para a lista
	list<int>::iterator p; // "ponteiro"
	
	int n;
    for (int i = 0; i < 4; i++) {
        cin >> n;
        lista.push_back(n); 
    }
    
	for(p = lista.begin(); p != lista.end(); p++)
		cout << *p << " ";
	
	// liberando a memória alocada
	while(!lista.empty())
		lista.pop_front();
	
	return 0;
}