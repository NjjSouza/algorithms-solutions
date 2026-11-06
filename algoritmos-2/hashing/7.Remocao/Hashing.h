#ifndef HASHING_H
#define HASHING_H

struct dado
{
    int k;
    int status;
};

int hash_aux(int k, int m);
int hash_remove(dado t[], int m, int k);
int hash_search(dado T[], int m, int k);
int hash_insert(dado T[], int m, int k);

#endif