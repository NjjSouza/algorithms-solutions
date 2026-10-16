#ifndef HASHING_H
#define HASHING_H

struct dado
{
    int k;
    int status;
};

// Função base para hashing
int hash_aux(int k, int m);

// Sondagem linear
int hash1(int k, int i, int m);

// Sondagem quadrática
int hash2(int k, int i, int m, int c1, int c2);

// Função auxiliar 1 para double hashing
int h1(int k, int m);

// Função auxiliar 2 para double hashing
int h2(int k, int m);

// Songagem double hashing
int dhash(int k, int i, int m);

// Função para inserção de elementos 
int hash_insert(dado t[], int m, int k, int c1, int c2); // alterada para quadrática

// Função para pesquisa 
int hash_search(dado t[], int m, int k, int c1, int c2); // alterada para quadrática

// Função para remoção de elementos em tabelas hash
int hash_remove(dado t[], int m, int k, int c1, int c2); // alterada para quadrática

#endif