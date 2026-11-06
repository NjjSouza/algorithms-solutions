#include <iostream>
#include <list>

using namespace std;

struct dados {
    int op; // 1 ou 2
    int codigo;
};

int main() {

    dados op;
    int n; // número de operações

    list<int> estoque;
    list<int> disponiveis;

    cin >> n;

    for (int i = 0; i < n; i++) {

        cin >> op.op;

        // adiciona produto ao estoque
        if (op.op == 1) {

            cin >> op.codigo;
            estoque.push_back(op.codigo);

        }
        // remove produto do estoque para venda
        else if (op.op == 2) {

            if (!estoque.empty()) {

                // obtém o primeiro produto do estoque
                int codigo = estoque.front();

                // remove o produto do estoque
                estoque.pop_front();

                // adiciona o produto ao início da lista de venda
                disponiveis.push_front(codigo);
            }
        }
    }

    cout << "Estoque: ";

    for (list<int>::iterator it = estoque.begin();
         it != estoque.end();
         ++it) {
        cout << *it << " ";
    }

    cout << endl;

    cout << "Venda: ";

    for (list<int>::iterator it = disponiveis.begin();
         it != disponiveis.end();
         ++it) {
        cout << *it << " ";
    }

    cout << endl;

    // limpa memória
    while (!estoque.empty())
        estoque.pop_front();

    while (!disponiveis.empty())
        disponiveis.pop_front();

    return 0;
}