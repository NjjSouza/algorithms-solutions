#include <iostream>
#include <string>
#include "hashing.h"

using namespace std;

int main()
{
    int m;
    cin >> m;

    dado* t = new dado[m];

    for (int i = 0; i < m; i++)
    {
        t[i].info = "";
        t[i].k = -1;
        t[i].status = 0;
    }

    int opcao;
    string info;

    while (cin >> opcao && opcao != 5)
    {
        switch (opcao)
        {
            case 1:
            {
                cin >> info;

                int k = 0;
                for (char c : info)
                    k += (int)c;

                hash_insert(t, m, k, info);
                break;
            }

            case 2:
            {
                cin >> info;

                int k = 0;
                for (char c : info)
                k += (int)c;

                int pos = hash_search(t, m, k, info);

                if (pos == -1)
                    cout << info << " nao encontrado" << endl;
                else
                    cout << info << " encontrado na posicao "
                    << pos << endl;
                break;
            }

            case 3:
            {
                cin >> info;

                int k = 0;
                for (char c : info)
                    k += (int)c;

                hash_remove(t, m, k, info);
                break;
            }

            case 4:
            {
                for (int i = 0; i < m; i++)
                {
                    if (t[i].status == 1)
                        cout << t[i].info << endl;
                    else
                        cout << "vazio" << endl;
                }
                break;
            }
        }
    }

    delete[] t;
    return 0;
}