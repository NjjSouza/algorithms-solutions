#include <iostream>
#include <list>

using namespace std;

int main() {

    list<int> lista1;
    list<int> lista2;
    list<int> lista3;

    int num;

    // leitura da primeira lista.
    // 0 indica fim da entrada, não pode inserir
    cin >> num;
    while (num != 0) {
        lista1.push_back(num);
        cin >> num;
    }

    // leitura da segunda lista
    cin >> num;
    while (num != 0) {
        lista2.push_back(num);
        cin >> num;
    }

    // iteradores para percorrer as duas listas
    list<int>::iterator it1 = lista1.begin();
    list<int>::iterator it2 = lista2.begin();

    // percorre as duas listas ao mesmo tempo
    while (it1 != lista1.end() && it2 != lista2.end()) {

        // se o elemento da lista1 for menor, adiciona na lista3 e avança it1
        if (*it1 < *it2) {

            lista3.push_back(*it1);
            ++it1;

        }

        // se o elemento da lista2 for menor, adiciona na lista3 e avança it2.
        else if (*it2 < *it1) {

            lista3.push_back(*it2);
            ++it2;

        }

        // se forem iguais, adiciona apenas uma vez para evitar elementos repetidos
        else {

            lista3.push_back(*it1);
            ++it1;
            ++it2;

        }
    }

    // caso ainda sobre elementos na lista1, copia todos para a lista3
    while (it1 != lista1.end()) {

        lista3.push_back(*it1);
        ++it1;

    }

    // caso ainda sobre elementos na lista2
    while (it2 != lista2.end()) {

        lista3.push_back(*it2);
        ++it2;

    }

    // lista resultante
    for (list<int>::iterator it = lista3.begin();
         it != lista3.end();
         ++it) {

        cout << *it << " ";
    }

    cout << endl;

    // libera memória 
    while (!lista1.empty())
        lista1.pop_front();

    while (!lista2.empty())
        lista2.pop_front();

    while (!lista3.empty())
        lista3.pop_front();

    return 0;
}