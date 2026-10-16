#include <iostream>
#include "hashing.h"
using namespace std;

int hash_aux(int k, int m){
    int h = k % m; 
    
    if (h < 0){
        h += m;
    }

    return h;
}

// h(k, i, m) = (h'(k,m) + i) % m

int hash1(int k, int i, int m) {

    int h = (hash_aux(k, m) + i) % m;

    return h;
}

int hash_search(dado T[], int m, int k){
    int i = 0;
    int j;
    
    do {
        j = hash1(k, i, m);
        
        // Verifica se encontrou a chave
        if (T[j].k == k) {
            return j;
        }
        
        i++;
    } while (T[j].status != 0 && i < m);
    
    return -1;
}