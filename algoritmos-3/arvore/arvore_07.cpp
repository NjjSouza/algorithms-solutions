#include <iostream>
#include <iomanip>
using namespace std;

// Nó da árvore binária de busca
// Guarda um valor e ponteiros para os filhos esquerdo e direito
// nullptr significa que não existe filho nessa posição
struct No {
    int valor;
    No* esq;
    No* dir;
};

// Apelido para ponteiro de nó, usado no cabeçalho exigido pelo enunciado:
// float media(treenodeptr arvore)
typedef No* treenodeptr;

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
// Os repetidos são mantidos, pois entram na média
// Retorna a raiz da subárvore após a inserção.
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

// Soma todos os valores da árvore (recursiva)
// Soma = valor do nó + soma da esquerda + soma da direita
// Usa long long para não estourar o int com muitos números
long long somar(No* raiz) {
    if (raiz == nullptr) return 0;
    return raiz->valor + somar(raiz->esq) + somar(raiz->dir);
}

// Conta quantos nós a árvore tem (recursiva)
int contar(No* raiz) {
    if (raiz == nullptr) return 0;
    return 1 + contar(raiz->esq) + contar(raiz->dir);
}

// Calcula a média dos elementos da árvore
// Média = soma / quantidade. Árvore vazia devolve 0
float media(treenodeptr arvore) {
    int qtd = contar(arvore);
    if (qtd == 0) return 0;
    return (float) somar(arvore) / qtd;
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

    // fixed + setprecision(2): sempre 2 casas depois da vírgula
    cout << fixed << setprecision(2);
    cout << "Media: " << media(raiz) << endl;

    liberar(raiz); // evita vazamento de memória
    return 0;
}