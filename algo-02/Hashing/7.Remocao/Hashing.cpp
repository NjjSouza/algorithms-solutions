#include <iostream>
#include "hashing.h"

using namespace std;

// h'(k) = k mod m
int hash_aux(int k, int m){
    int h = k % m;

    if (h < 0){
        h += m;
    }

    return h;
}

// h(k,i) = (h'(k) + i) mod m
int hash1(int k, int i, int m){

    int h = (hash_aux(k, m) + i) % m;

    return h;
}

// insere elementos na tabela 
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

// busca uma chave na tabela
int hash_search(dado T[], int m, int k){

    int i = 0;
    int j;

    do {

        j = hash1(k, i, m);

        // a chave só é considerada encontrada
        // se a posição estiver ocupada
        if (T[j].status == 1 && T[j].k == k){
            return j;
        }

        i++;

    } while (T[j].status != 0 && i < m);

    return -1;
}

// remove uma chave da tabela
int hash_remove(dado t[], int m, int k){

    int j = hash_search(t, m, k);

    if (j != -1){

        t[j].status = 2; // marca como removido
        t[j].k = -1; 

        return 0;
    }

    return -1;
}