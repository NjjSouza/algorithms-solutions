#include <iostream>
#include "hashing.h"

using namespace std;

int main() {
    int m, chave;
    
    cin >> m; // tamanho da tabela

    // vetor dinamico
    dado *tabela = new dado[m];
    
    // inicializacao
    for (int i = 0; i < m; i++) {
        tabela[i].status = 0; 
        tabela[i].k = -1; 
    }

    // leitura e inserção das chaves
    while (cin >> chave && chave != 0) {
        hash_insert(tabela, m, chave);
    }

    for (int i = 0; i < m; i++) {
        cout << tabela[i].k << " ";
    }
    cout << endl;

    delete[] tabela; // libera memória 

    return 0;
}