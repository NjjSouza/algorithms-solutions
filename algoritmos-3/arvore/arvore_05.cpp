#include <iostream>
#include <string>
using namespace std;

// Nó da árvore binária de busca
// Guarda os dados da rocha e ponteiros para os filhos esquerdo e direito
// A árvore é ordenada pelo nome da rocha
// nullptr significa que não existe filho nessa posição
struct No {
    string nome;
    string tipo;
    No* esq;
    No* dir;
};

// Cria um novo nó com os dados da rocha, sem filhos
No* criarNo(string nome, string tipo) {
    No* novo = new No;
    novo->nome = nome;
    novo->tipo = tipo;
    novo->esq = nullptr;
    novo->dir = nullptr;
    return novo;
}

// Insere uma rocha na árvore (recursiva)
// Regra: nomes menores (ordem alfabética) vão para a esquerda, maiores para a direita.
// Retorna a raiz da subárvore após a inserção
No* inserir(No* raiz, string nome, string tipo) {
    // Caso base: posição vazia, o novo nó entra aqui
    if (raiz == nullptr) {
        return criarNo(nome, tipo);
    }

    if (nome < raiz->nome) {
        raiz->esq = inserir(raiz->esq, nome, tipo); // desce pela esquerda
    } else if (nome > raiz->nome) {
        raiz->dir = inserir(raiz->dir, nome, tipo);  // desce pela direita
    }
    // Se nome == raiz->nome, a rocha já existe: não insere de novo

    return raiz;
}

// Busca uma rocha pelo nome na árvore (iterativa)
// Compara com o nó atual e desce para a esquerda ou direita
// Retorna o ponteiro do nó se encontrou, ou nullptr se não existe
No* buscar(No* raiz, string nome) {
    No* atual = raiz;

    while (atual != nullptr) {
        if (nome == atual->nome) {
            return atual; // achou
        } else if (nome < atual->nome) {
            atual = atual->esq; // procura à esquerda
        } else {
            atual = atual->dir; // procura à direita
        }
    }

    return nullptr; // chegou em nullptr: não existe
}

// Devolve o nó de menor nome de uma subárvore
// O menor nome fica sempre no nó mais à esquerda
No* encontrarMenor(No* raiz) {
    No* atual = raiz;
    while (atual->esq != nullptr) {
        atual = atual->esq;
    }
    return atual;
}

// Remove uma rocha pelo nome (recursiva)
// Retorna a raiz da subárvore após a remoção
// Se o nome não existe, a árvore fica como estava
No* remover(No* raiz, string nome) {
    // Caso base: chegou em posição vazia, o nome não existe
    if (raiz == nullptr) {
        return nullptr;
    }

    if (nome < raiz->nome) {
        raiz->esq = remover(raiz->esq, nome); // procura à esquerda
    } else if (nome > raiz->nome) {
        raiz->dir = remover(raiz->dir, nome); // procura à direita
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
        // Copia os dados do sucessor (menor nome da subárvore direita)
        // para este nó e depois remove o sucessor, que cai num dos casos acima
        No* sucessor = encontrarMenor(raiz->dir);
        raiz->nome = sucessor->nome;
        raiz->tipo = sucessor->tipo;
        raiz->dir = remover(raiz->dir, sucessor->nome);
    }

    return raiz;
}

// Libera a memória de toda a árvore
// Pós-ordem: apaga os filhos antes do pai
void liberar(No* raiz) {
    if (raiz == nullptr) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    delete raiz;
}

// Lê uma linha inteira (o nome pode ter espaços)
// Remove o '\r' do final, caso o arquivo de entrada seja do Windows
string lerLinha() {
    string linha;
    getline(cin, linha);
    if (!linha.empty() && linha.back() == '\r') {
        linha.pop_back();
    }
    return linha;
}

int main() {
    No* raiz = nullptr; // árvore começa vazia
    int opcao;

    // Repete até o usuário digitar 0 (ou a entrada acabar)
    while (cin >> opcao && opcao != 0) {
        if (opcao == 1) {
            // Inserir: lê nome e tipo da rocha
            cin.ignore(10000, '\n'); // descarta o resto da linha da opção
            string nome = lerLinha();
            string tipo = lerLinha();

            raiz = inserir(raiz, nome, tipo);
        } else if (opcao == 2) {
            // Pesquisar: lê só o nome e mostra os dados se encontrar
            cin.ignore(10000, '\n');
            string nome = lerLinha();

            No* achado = buscar(raiz, nome);
            if (achado != nullptr) {
                cout << "Nome: " << achado->nome << endl;
                cout << "Tipo: " << achado->tipo << endl;
            } else {
                cout << "Rocha nao encontrada" << endl;
            }
        } else if (opcao == 3) {
            // Remover: lê nome e tipo. Só remove se os dois baterem
            // com o que está guardado na árvore
            cin.ignore(10000, '\n');
            string nome = lerLinha();
            string tipo = lerLinha();

            No* achado = buscar(raiz, nome);
            if (achado != nullptr && achado->tipo == tipo) {
                raiz = remover(raiz, nome);
                cout << "Rocha removida com sucesso" << endl;
            } else {
                cout << "Rocha nao encontrada para remocao" << endl;
            }
        } else {
            cout << "Operacao invalida" << endl;
        }
    }

    liberar(raiz); // evita vazamento de memória
    return 0;
}