#ifndef HASHING_H
#define HASHING_H

struct dado
{
    int k;
    int status;
};

int hash_aux(int k, int m);

int hash1(int k, int i, int m);

int hash_search(dado T[], int m, int k);

#endif