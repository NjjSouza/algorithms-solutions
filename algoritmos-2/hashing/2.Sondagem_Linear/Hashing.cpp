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