#include <iostream>
#include "hashing.h"

using namespace std;

int main() {

    int m;
    cin >> m;

    dado T[m];

    // inicializa a tabela
    for (int i = 0; i < m; i++) {
        T[i].k = -1;
        T[i].status = 0;
    }

    // lê e insere as chaves
    int chave;

    while (cin >> chave && chave != 0) {
        hash_insert(T, m, chave);
    }

    // lê a chave que será removida
    int remover;
    cin >> remover;

    hash_remove(T, m, remover);

    // imprime a tabela
    for (int i = 0; i < m; i++) {

        if (T[i].status == 1)
            cout << T[i].k;
        else
            cout << -1;

        cout << " ";
    }

    cout << endl;

    return 0;
}