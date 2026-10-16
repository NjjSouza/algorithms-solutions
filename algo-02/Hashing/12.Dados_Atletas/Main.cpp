#include <iostream>
#include <string>
#include <iomanip>
#include "hashing.h"

using namespace std;

int main()
{
    int m, op;

    // lê o tamanho da tabela
    cin >> m;

    // cria a tabela
    dado t[m];

    // inicializa todas as posições como vazias
    for (int i = 0; i < m; i++)
    {
        t[i].status = 0;
        t[i].k = -1;
    }

    // executa operações até receber a opção 5 (sair)
    while (cin >> op && op != 5)
    {
        switch (op)
        {
            case 1:
            {
                info atleta;

                // lê os dados do atleta
                getline(cin >> ws, atleta.nome);
                cin >> atleta.idade;
                cin >> atleta.peso;
                cin >> atleta.altura;

                // calcula a chave somando os valores ASCII dos caracteres do nome
                int k = 0;

                for (int i = 0; i < atleta.nome.size(); i++)
                {
                    k += atleta.nome[i];
                }

                // insere o atleta na tabela hash
                int pos = hash_insert(t, m, k);

                // se houver espaço, armazena os dados na posição encontrada
                if (pos != -1)
                {
                    t[pos].atleta = atleta;
                }

                break;
            }

            case 2:
            {
                string nome;

                // lê o nome do atleta que será pesquisado
                getline(cin >> ws, nome);

                // calcula a chave correspondente ao nome
                int k = 0;

                for (int i = 0; i < nome.size(); i++)
                {
                    k += nome[i];
                }

                // procura a posição do atleta na tabela
                int pos = hash_search(t, m, k);

                if (pos == -1)
                {
                    cout << nome << " nao encontrado" << endl;
                    cout << endl;
                }
                else
                {
                    // exibe os dados encontrados
                    cout << "Nome: " << t[pos].atleta.nome << endl;
                    cout << "Idade: " << t[pos].atleta.idade << endl;
                    cout << "Peso: " << t[pos].atleta.peso << endl;
                    cout << fixed << setprecision(2) << "Altura: " << t[pos].atleta.altura << endl;
                    cout << endl;
                    
                    cout.unsetf(ios::floatfield); // para passar no juíz
                    cout << defaultfloat << setprecision(6);
                }

                break;
            }

            case 3:
            {
                string nome;

                // lê o nome do atleta que será removido
                getline(cin >> ws, nome);

                // calcula a chave correspondente ao nome
                int k = 0;

                for (int i = 0; i < nome.size(); i++)
                {
                    k += nome[i];
                }

                // remove o atleta da tabela
                hash_remove(t, m, k);

                break;
            }

            case 4:
            {
                // percorre toda a tabela
                for (int i = 0; i < m; i++)
                {
                    // mostra apenas posições ocupadas
                    if (t[i].status == 1)
                    {
                        cout << "Nome: " << t[i].atleta.nome << endl;
                        cout << "Idade: " << t[i].atleta.idade << endl;
                        cout << "Peso: " << t[i].atleta.peso << endl;
                        cout << fixed << setprecision(2) << "Altura: " << t[i].atleta.altura << endl;
                        cout << endl;
                        
                        cout.unsetf(ios::floatfield); // para passar no juíz 
                        cout << defaultfloat << setprecision(6);
                    }
                }

                break;
            }

            default:
            {
                break;
            }
        }
    }

    return 0;
}