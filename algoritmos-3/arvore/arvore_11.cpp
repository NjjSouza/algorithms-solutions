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

// As três funções abaixo percorrem a árvore contando quantas cidades
// foram visitadas até chegar na cidade x.
//   - "cont" é incrementado a cada nó visitado (passado por referência).
//   - Devolvem true assim que acham x, para parar o percurso na hora.
//   - Se x não existir, percorrem tudo e devolvem false.

// Pré-ordem: nó, esquerda, direita.
bool contarPre(No* raiz, int x, int& cont) {
    if (raiz == nullptr) return false;

    cont++; // visita o nó
    if (raiz->valor == x) return true;

    if (contarPre(raiz->esq, x, cont)) return true;
    return contarPre(raiz->dir, x, cont);
}

// Em ordem: esquerda, nó, direita.
bool contarEm(No* raiz, int x, int& cont) {
    if (raiz == nullptr) return false;

    if (contarEm(raiz->esq, x, cont)) return true;

    cont++; // visita o nó
    if (raiz->valor == x) return true;

    return contarEm(raiz->dir, x, cont);
}

// Pós-ordem: esquerda, direita, nó.
bool contarPos(No* raiz, int x, int& cont) {
    if (raiz == nullptr) return false;

    if (contarPos(raiz->esq, x, cont)) return true;
    if (contarPos(raiz->dir, x, cont)) return true;

    cont++; // visita o nó
    return raiz->valor == x;
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

    // Lê as cidades e insere na árvore até aparecer o -1.
    // O -1 funciona só como marcador de fim e não entra na árvore.
    while (cin >> valor && valor != -1) {
        raiz = inserir(raiz, valor);
    }

    int x;
    cin >> x; // cidade onde está o chocolate

    // Quantas cidades cada percurso visita até chegar em x.
    int visitasPre = 0;
    int visitasEm = 0;
    int visitasPos = 0;
    contarPre(raiz, x, visitasPre);
    contarEm(raiz, x, visitasEm);
    contarPos(raiz, x, visitasPos);

    // O caminho mais rápido é o que visita menos cidades.
    // O enunciado garante que não há empate.
    if (visitasPre < visitasEm && visitasPre < visitasPos) {
        cout << "Pre" << endl;
    } else if (visitasEm < visitasPos) {
        cout << "Em" << endl;
    } else {
        cout << "Pos" << endl;
    }

    liberar(raiz); // evita vazamento de memória
    return 0;
}