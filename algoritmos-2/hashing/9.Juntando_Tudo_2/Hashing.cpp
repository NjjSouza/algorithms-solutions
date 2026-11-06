#include "hashing.h"

// Função base para hashing
int hash_aux(int k, int m)
{
    int h = k % m;
    if (h < 0)
        h += m;
    return h;    
}

// Sondagem linear
int hash1(int k, int i, int m)
{
    return (hash_aux(k,m) + i) % m;
}

// Sondagem quadrática
int hash2(int k, int i, int m, int c1, int c2)
{
    return (hash_aux(k,m) + c1 * i + c2 * i * i) % m;
}

// Função auxiliar 1 para double hashing
int h1(int k, int m)
{
    int h = k % m;
    if (h < 0)
        h += m;
    return h;    
}

// Função auxiliar 2 para double hashing
int h2(int k, int m)
{
    int h = 1 + (k % (m-1));
    if (h < 0)
        h += m;
    return h;    
}

// Songagem double hashing
int dhash(int k, int i, int m)
{
    return (h1(k, m) + i * h2(k, m)) % m;
}

// Função para inserção de elementos - alterada para sondagem quadrática
int hash_insert(dado t[], int m, int k, int c1, int c2)
{
    int i = 0;
    int j;

    do
    {
        j = hash2(k, i, m, c1, c2);

        if (t[j].status != 1) // livre ou removido
        {
            t[j].k = k;
            t[j].status = 1;
            return j;
        }

        i++;

    } while (i < m);

    return -1; // tabela cheia
}

// Função para pesquisa - alterada para sondagem quadrática
int hash_search(dado t[], int m, int k, int c1, int c2)
{
    int i = 0;
    int j;

    do
    {
        j = hash2(k, i, m, c1, c2);

        if (t[j].status == 0) // alterada para verificar status
            return -1; // nunca foi ocupado

        if (t[j].status == 1 && t[j].k == k)
            return j;

        i++;

    } while (i < m);

    return -1;
}

// Função para remoção - alterada para sondagem quadrática
int hash_remove(dado t[], int m, int k, int c1, int c2)
{
    int j = hash_search(t, m, k, c1, c2);

    if (j != -1)
    {
        t[j].status = 2; // removido
        t[j].k = -1;
        return 0;
    }

    return -1;
}