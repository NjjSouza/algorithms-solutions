#include <iostream>
#include <string>
using namespace std;

// Nó da árvore binária de busca
// Guarda os dados do filme e ponteiros para os filhos esquerdo e direito
// A árvore é ordenada pelo nome do filme
// nullptr significa que não existe filho nessa posição
struct No {
    string nome;
    string genero;
    int duracao;
    int classificacao;
    int ano;
    No* esq;
    No* dir;
};

// Cria um novo nó com os dados do filme, sem filhos
No* criarNo(string nome, string genero, int duracao, int classificacao, int ano) {
    No* novo = new No;
    novo->nome = nome;
    novo->genero = genero;
    novo->duracao = duracao;
    novo->classificacao = classificacao;
    novo->ano = ano;
    novo->esq = nullptr;
    novo->dir = nullptr;
    return novo;
}

// Insere um filme na árvore (recursiva)
// Regra: nomes menores (ordem alfabética) vão para a esquerda, maiores para a direita
// Retorna a raiz da subárvore após a inserção
No* inserir(No* raiz, string nome, string genero, int duracao, int classificacao, int ano) {
    // Caso base: posição vazia, o novo nó entra aqui
    if (raiz == nullptr) {
        return criarNo(nome, genero, duracao, classificacao, ano);
    }

    if (nome < raiz->nome) {
        raiz->esq = inserir(raiz->esq, nome, genero, duracao, classificacao, ano); // desce pela esquerda
    } else if (nome > raiz->nome) {
        raiz->dir = inserir(raiz->dir, nome, genero, duracao, classificacao, ano); // desce pela direita
    }
    // Se nome == raiz->nome, o filme já existe: não insere de novo

    return raiz;
}

// Busca um filme pelo nome na árvore (iterativa)
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

// Libera a memória de toda a árvore
// Pós-ordem: apaga os filhos antes do pai
void liberar(No* raiz) {
    if (raiz == nullptr) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    delete raiz;
}

// Lê uma linha inteira (o nome do filme pode ter espaços)
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
            // Inserir: lê nome, gênero, duração, classificação e ano
            string nome, genero;
            int duracao, classificacao, ano;

            cin.ignore(10000, '\n'); // descarta o resto da linha da opção
            nome = lerLinha();
            genero = lerLinha();
            cin >> duracao >> classificacao >> ano;

            raiz = inserir(raiz, nome, genero, duracao, classificacao, ano);
        } else if (opcao == 2) {
            // Pesquisar: lê só o nome e mostra os dados se encontrar
            cin.ignore(10000, '\n'); // descarta o resto da linha da opção
            string nome = lerLinha();

            No* achado = buscar(raiz, nome);
            if (achado != nullptr) {
                cout << "Nome: " << achado->nome << endl;
                cout << "Genero: " << achado->genero << endl;
                cout << "Duracao: " << achado->duracao << " mins" << endl;
                cout << "Classificacao: " << achado->classificacao << endl;
                cout << "Ano: " << achado->ano << endl;
            } else {
                cout << "Filme nao encontrado" << endl;
            }
        } else {
            cout << "Operacao invalida" << endl;
        }
    }

    liberar(raiz); // evita vazamento de memória
    return 0;
}