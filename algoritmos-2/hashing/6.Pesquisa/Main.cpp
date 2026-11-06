#include <iostream>
#include "hashing.h"

using namespace std;

int main() {

    int m;
    cin >> m; // tamanho da tabela

    // vetor dinamico com ponteiro
    dado* tabela = new dado[m];

    // inicializacao da tabela
    for (int i = 0; i < m; i++) {
        tabela[i].status = 0;
        tabela[i].k = 0;
    }
    int chave;

    // inserção de elementos
    while (cin >> chave && chave != 0) {

        for (int i = 0; i < m; i++) {
            int j = hash1(chave, i, m);
            if (tabela[j].status == 0) {

                tabela[j].k = chave;
                tabela[j].status = 1;

                break;
            }
        }
    }

    // busca
    cin >> chave;

    int pos = hash_search(tabela, m, chave);

    if (pos != -1) {
        cout << "Chave " << chave << " encontrada na posicao " << pos << endl;
    }
    else {
        cout << "Chave " << chave << " nao encontrada" << endl;
    }

    delete[] tabela; // limpar memória

    return 0;
}