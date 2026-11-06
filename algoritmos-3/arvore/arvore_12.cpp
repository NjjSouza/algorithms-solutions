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
// int contaPrimos(treenodeptr arvore)
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
// Os repetidos são mantidos, pois cada número inserido conta.
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

// Verifica se um número é primo.
// Primo: maior que 1 e sem divisores além de 1 e dele mesmo.
// Basta testar divisores até a raiz quadrada (i * i <= n).
bool ehPrimo(int n) {
    if (n < 2) return false;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; // achou um divisor: não é primo
        }
    }

    return true;
}

// Conta quantos elementos da árvore são primos (recursiva).
// Total = (1 se o nó atual é primo, senão 0) + primos da esquerda + primos da direita.
int contaPrimos(treenodeptr arvore) {
    if (arvore == nullptr) return 0;

    int esteNo = ehPrimo(arvore->valor) ? 1 : 0;
    return esteNo + contaPrimos(arvore->esq) + contaPrimos(arvore->dir);
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

    cout << contaPrimos(raiz) << " numeros primos" << endl;

    liberar(raiz); // evita vazamento de memória
    return 0;
}