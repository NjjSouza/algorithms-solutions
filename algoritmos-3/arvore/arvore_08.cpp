#include <iostream>
using namespace std;

// Nó da árvore binária de busca
// Guarda um valor e ponteiros para os filhos esquerdo e direito
// nullptr significa que não existe filho nessa posição
struct No {
    int valor;
    No* esq;
    No* dir;
};

// Cria um novo nó com o valor informado, sem filhos
No* criarNo(int valor) {
    No* novo = new No;
    novo->valor = valor;
    novo->esq = nullptr;
    novo->dir = nullptr;
    return novo;
}

// Insere um valor na árvore (recursiva)
// Regra: menores vão para a esquerda, iguais e maiores vão para a direita
// Os repetidos são mantidos, para aparecerem na sequência ordenada
// Retorna a raiz da subárvore após a inserção
No* inserir(No* raiz, int valor) {
    // Caso base: posição vazia, o novo nó entra aqui
    if (raiz == nullptr) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor); // desce pela esquerda
    } else {
        raiz->dir = inserir(raiz->dir, valor); // desce pela direita
    }

    return raiz;
}

// Mostra a árvore em ordem DECRESCENTE (direita, nó, esquerda)
// É o percurso em ordem invertido: visita primeiro os maiores
// "primeiro" controla o espaço entre os números, sem sobrar espaço no final
void emOrdemDecrescente(No* raiz, bool& primeiro) {
    if (raiz == nullptr) return;

    emOrdemDecrescente(raiz->dir, primeiro);

    if (!primeiro) {
        cout << " ";
    }
    cout << raiz->valor;
    primeiro = false;

    emOrdemDecrescente(raiz->esq, primeiro);
}

// Libera a memória de toda a árvore
// Pós-ordem: apaga os filhos antes do pai
void liberar(No* raiz) {
    if (raiz == nullptr) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    delete raiz;
}

int main() {
    No* raiz = nullptr; // árvore começa vazia
    int valor;

    // Lê os números e insere na árvore até aparecer o -1
    // O -1 funciona só como marcador de fim e não entra na árvore
    while (cin >> valor && valor != -1) {
        raiz = inserir(raiz, valor);
    }

    // Percorre a árvore do maior para o menor
    bool primeiro = true;
    emOrdemDecrescente(raiz, primeiro);
    cout << endl;

    liberar(raiz); // evita vazamento de memória
    return 0;
}