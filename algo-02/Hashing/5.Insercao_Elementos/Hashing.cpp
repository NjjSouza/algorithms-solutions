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

int hash1(int k, int i, int m) {
    int h = (hash_aux(k, m) + i) % m;

    return h;
}

int hash_insert(dado T[], int m, int k){ 
    int i = 0; 
    int j; 
    
    do { 
        j = hash1(k, i, m); 
        
        if (T[j].status != 1){ // verifica se a posição está vazia (status != 1)
            T[j].k = k; 
            T[j].status = 1; 
            return j; // elemento inserido
        } else {
            i++; 
        }
    } while (i < m); // percorre até que i seja igual ao tamanho máximo da tabela
    
    return -1; // indica que a tabela esta cheia
}