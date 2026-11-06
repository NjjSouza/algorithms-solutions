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

// Calcula a altura da árvore em níveis (recursiva).
// Árvore vazia tem altura 0; só a raiz tem altura 1.
int altura(No* raiz) {
    if (raiz == nullptr) return 0;

    int alturaEsq = altura(raiz->esq);
    int alturaDir = altura(raiz->dir);

    // Fica com a maior das duas subárvores e soma 1 pelo nó atual.
    if (alturaEsq > alturaDir) {
        return 1 + alturaEsq;
    }
    return 1 + alturaDir;
}

// Mostra apenas os nós de um nível (1 = raiz, 2 = filhos da raiz, ...).
// Desce na árvore diminuindo "nivel" até chegar em 1: aí imprime o nó.
// "primeiro" controla o espaço entre os números, sem sobrar espaço no final.
void imprimirNivel(No* raiz, int nivel, bool& primeiro) {
    if (raiz == nullptr) return;

    if (nivel == 1) {
        if (!primeiro) {
            cout << " ";
        }
        cout << raiz->valor;
        primeiro = false;
    } else {
        imprimirNivel(raiz->esq, nivel - 1, primeiro);  // esquerda antes da direita
        imprimirNivel(raiz->dir, nivel - 1, primeiro);
    }
}

// Percurso em nível: mostra nível 1, depois nível 2, e assim por diante.
// Essa forma dispensa fila: basta repetir imprimirNivel para cada nível.
void percursoNivel(No* raiz) {
    int h = altura(raiz);
    bool primeiro = true;

    for (int nivel = 1; nivel <= h; nivel++) {
        imprimirNivel(raiz, nivel, primeiro);
    }
    cout << endl;
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
    No* raiz = nullptr; // arvore começa vazia
    int valor;

    // Lê os números e insere na árvore até aparecer o -1.
    // O -1 funciona só como marcador de fim e não entra na árvore.
    while (cin >> valor && valor != -1) {
        raiz = inserir(raiz, valor);
    }

    percursoNivel(raiz);

    liberar(raiz); // evita vazamento de memória
    return 0;
}