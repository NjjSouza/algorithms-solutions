#include <iostream>
using namespace std;

// Nó da árvore binária de busca.
// Guarda um valor e ponteiros para os filhos esquerdo e direito.
// nullptr significa que não existe filho nessa posição.
struct No {
    int valor;
    No* esq;
    No* dir;
};

// Apelido para ponteiro de nó, usado nos cabeçalhos exigidos pelo enunciado:
// int maior(treenodeptr arvore) e int menor(treenodeptr arvore)
typedef No* treenodeptr;

// Cria um novo nó com o valor informado, sem filhos.
No* criarNo(int valor) {
    No* novo = new No;
    novo->valor = valor;
    novo->esq = nullptr;
    novo->dir = nullptr;
    return novo;
}

// Insere um valor na árvore (recursiva).
// Regra: menores vão para a esquerda, iguais e maiores vão para a direita.
// Retorna a raiz da subárvore após a inserção.
No* inserir(No* raiz, int valor) {
    // Caso base: posição vazia, o novo nó entra aqui.
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

// Devolve o menor elemento da árvore.
// O menor fica sempre no nó mais à esquerda.
// Pré-condição: a árvore não está vazia.
int menor(treenodeptr arvore) {
    No* atual = arvore;
    while (atual->esq != nullptr) {
        atual = atual->esq;
    }
    return atual->valor;
}

// Devolve o maior elemento da árvore.
// O maior fica sempre no nó mais à direita.
// Pré-condição: a árvore não está vazia.
int maior(treenodeptr arvore) {
    No* atual = arvore;
    while (atual->dir != nullptr) {
        atual = atual->dir;
    }
    return atual->valor;
}

// Libera a memória de toda a árvore.
// Pós-ordem: apaga os filhos antes do pai.
void liberar(No* raiz) {
    if (raiz == nullptr) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    delete raiz;
}

int main() {
    No* raiz = nullptr;  // árvore começa vazia
    int valor;

    // Lê os números e insere na árvore até aparecer o -1.
    // O -1 funciona só como marcador de fim e não entra na árvore.
    while (cin >> valor && valor != -1) {
        raiz = inserir(raiz, valor);
    }

    // Só calcula se a árvore tiver pelo menos um elemento.
    if (raiz != nullptr) {
        cout << menor(raiz) << " e " << maior(raiz) << endl;
    }

    liberar(raiz); // evita vazamento de memória
    return 0;
}