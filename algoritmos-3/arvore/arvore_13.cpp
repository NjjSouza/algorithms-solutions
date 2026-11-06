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

// Apelido para ponteiro de nó, usado no cabeçalho exigido pelo enunciado:
// int contaFolhas(treenodeptr arvore)
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

// Conta as folhas da árvore (recursiva).
// Folha = nó sem filho esquerdo e sem filho direito.
int contaFolhas(treenodeptr arvore) {
    // Árvore vazia não tem folhas.
    if (arvore == nullptr) return 0;

    // Este nó é uma folha: conta 1.
    if (arvore->esq == nullptr && arvore->dir == nullptr) {
        return 1;
    }

    // Senão, as folhas estão nas subárvores.
    return contaFolhas(arvore->esq) + contaFolhas(arvore->dir);
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
    No* raiz = nullptr; // árvore começa vazia
    int valor;

    // Lê os números e insere na árvore até aparecer o -1.
    // O -1 funciona só como marcador de fim e não entra na árvore.
    while (cin >> valor && valor != -1) {
        raiz = inserir(raiz, valor);
    }

    cout << contaFolhas(raiz) << endl;

    liberar(raiz); // evita vazamento de memória
    return 0;
}