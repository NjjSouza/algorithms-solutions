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
// Aqui os repetidos são mantidos (ficam à direita), pois o enunciado
// fala em remover "todos" os nós com o valor x
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

// Devolve o nó de menor valor de uma subárvore
// O menor valor fica sempre no nó mais à esquerda
No* encontrarMenor(No* raiz) {
    No* atual = raiz;
    while (atual->esq != nullptr) {
        atual = atual->esq;
    }
    return atual;
}

// Remove um nó com o valor x da árvore (recursiva)
// Remove apenas UMA ocorrência por chamada
// Retorna a raiz da subárvore após a remoção
No* remover(No* raiz, int x) {
    // Caso base: chegou em posição vazia, o valor não existe
    if (raiz == nullptr) {
        return nullptr;
    }

    if (x < raiz->valor) {
        raiz->esq = remover(raiz->esq, x); // procura à esquerda
    } else if (x > raiz->valor) {
        raiz->dir = remover(raiz->dir, x); // procura à direita
    } else {
        // Achou o nó a ser removido. Existem três casos:
        // Caso 1: sem filho esquerdo (cobre também o nó folha)
        // O filho direito (ou nullptr) ocupa o lugar do nó
        if (raiz->esq == nullptr) {
            No* filho = raiz->dir;
            delete raiz;
            return filho;
        }

        // Caso 2: sem filho direito
        // O filho esquerdo ocupa o lugar do nó
        if (raiz->dir == nullptr) {
            No* filho = raiz->esq;
            delete raiz;
            return filho;
        }

        // Caso 3: dois filhos
        // Troca o valor pelo sucessor (menor valor da subárvore direita)
        // e depois remove o sucessor, que cai num dos casos acima
        No* sucessor = encontrarMenor(raiz->dir);
        raiz->valor = sucessor->valor;
        raiz->dir = remover(raiz->dir, sucessor->valor);
    }

    return raiz;
}

// Mostra a árvore em ordem crescente (esquerda, nó, direita)
// "primeiro" controla o espaço entre os números, sem sobrar espaço no final
void emOrdem(No* raiz, bool& primeiro) {
    if (raiz == nullptr) return;

    emOrdem(raiz->esq, primeiro);

    if (!primeiro) {
        cout << " ";
    }
    cout << raiz->valor;
    primeiro = false;

    emOrdem(raiz->dir, primeiro);
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

    // Lê os números e insere na árvore até aparecer o 0
    // O 0 funciona só como marcador de fim e não entra na árvore
    while (cin >> valor && valor != 0) {
        raiz = inserir(raiz, valor);
    }

    int x;
    cin >> x; // valor a ser removido

    // Como pode haver repetidos, remove enquanto ainda existir algum x
    while (buscar(raiz, x)) {
        raiz = remover(raiz, x);
    }

    // Mostra o que sobrou em ordem crescente
    bool primeiro = true;
    emOrdem(raiz, primeiro);
    cout << endl;

    liberar(raiz); // evita vazamento de memória
    return 0;
}