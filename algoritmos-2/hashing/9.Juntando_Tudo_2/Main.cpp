#include <iostream>
#include "hashing.h"

using namespace std;

int main() {

    int m, c1, c2;
    cin >> m >> c1 >> c2;

    // aloca dinamicamente a tabela
    dado* t = new dado[m];

    // inicializa a tabela
    for (int i = 0; i < m; i++) {
        t[i].k = -1;
        t[i].status = 0;
    }

    int opcao; // operação escolhida pelo usuário
    int chave; // chave utilizada nas operações

    // continua executando operações até receber a opção 5
    while (cin >> opcao && opcao != 5) {

        switch (opcao) {

            case 1: // inserir
                cin >> chave;
                hash_insert(t, m, chave, c1, c2); // inserido parâmetros de inserção quadrática
                break;

            case 2: // pesquisar
                cin >> chave;

                // hash_search já retorna a posição ou -1
                cout << hash_search(t, m, chave, c1, c2) << endl; // inserido parâmetros de busca quadrática
                break;

            case 3: // remover
                cin >> chave;
                hash_remove(t, m, chave, c1, c2); // inserido parâmetros de remoção quadrática
                break;

            case 4: // listar tabela
                for (int i = 0; i < m; i++) {

                    // mostra a chave se a posição estiver ocupada
                    if (t[i].status == 1)
                        cout << t[i].k;
                    else
                        cout << -1;

                    cout << " ";
                }

                cout << endl;
                break;

            default:
                // ignora opções inválidas
                break;
        }
    }

    // libera a memória alocada com new[]
    delete[] t;

    return 0;
}