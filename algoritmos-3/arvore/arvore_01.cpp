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

// Cria um novo nó com o valor informado, sem filhos.
No* criarNo(int valor) {
    No* novo = new No;
    novo->valor = valor;
    novo->esq = nullptr;
    novo->dir = nullptr;
    return novo;
}

// Insere um valor na árvore (recursiva)
// Regra: menores vão para a esquerda, maiores vão para a direita
// Retorna a raiz da subárvore após a inserção
No* inserir(No* raiz, int valor) {
    // Caso base: posição vazia, o novo nó entra aqui
    if (raiz == nullptr) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor); // desce pela esquerda
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor); // desce pela direita
    }
    // Se valor == raiz->valor, é repetido: não insere de novo
    // Isso não afeta a busca, pois o valor já está na árvore

    return raiz;
}

// Busca um valor na árvore (iterativa)
// Compara com o nó atual e desce para a esquerda ou direita
// Retorna true se encontrou, false se chegou a um ponto vazio
bool buscar(No* raiz, int x) {
    No* atual = raiz;

    while (atual != nullptr) {
        if (x == atual->valor) {
            return true; // achou
        } else if (x < atual->valor) {
            atual = atual->esq; // procura à esquerda
        } else {
            atual = atual->dir; // procura à direita
        }
    }

    return false; // chegou em nullptr: não existe
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
    int n;
    cin >> n; // quantidade de números

    No* raiz = nullptr; // árvore começa vazia

    // Lê os N números e insere cada um direto na árvore
    // Não é preciso guardar em array/vector antes
    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;
        raiz = inserir(raiz, valor);
    }

    int x;
    cin >> x; // número a ser procurado

    if (buscar(raiz, x)) {
        cout << "Encontrado" << endl;
    } else {
        cout << "Nao encontrado" << endl;
    }

    liberar(raiz); // evita vazamento de memória
    return 0;
}