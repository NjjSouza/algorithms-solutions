#include <iostream>
#include "hashing.h"

using namespace std;

/* função hash básica (h'(k))
h'(k) = k mod m */

int hash_aux(int k, int m){
    int h = k % m;
    
    // garante resultado positivo
    if (h < 0){
        h += m;
    }
    return h;
}

/* sondagem linear - para quando haver colisão
h(k,i) = (h'(k) + i) mod m */

int hash1(int k, int i, int m){
    int h = (hash_aux(k, m) + i) % m;
    return h;
}

/* sondagem quadrática - ao invés de avançar de uma em uma pocisão
quando há colisão, utiliza deslocamento quadrático
h(k,i) = (h'(k) + c1*i + c2*i²) mod m */

int hash2(int k, int i, int m, int c1, int c2){
    return (hash_aux(k, m) + c1*i + c2*i*i) % m;
}