#include <iostream>
#include "hashing.h"

/* primeira função hash auxiliar - calcula a posição inicial da chave k na tabela de tamanho m
h1(k,m) = k mod m
como o operador % em C++ pode gerar resultados negativos, ajustamos o valor para garantir um 
índice válido entre 0 e m-1. */

int h1(int k, int m){
    int h = k % m;

    if (h < 0)
        h += m;

    return h;
}

/* segunda função hash auxiliar
h2(k,m) = 1 + (k mod (m-1)) */

int h2(int k, int m){
    return 1 + (k % (m - 1));
}

/* double hashing - utiliza duas funções hash para gerar a sequência de sondagem
h(k,i,m) = (h1(k,m) + i*h2(k,m)) mod m
o resultado final é ajustado para permanecer no intervalo
[0, m-1], mesmo quando h2 gerar valores negativos */

int dhash(int k, int i, int m){

    int h = (h1(k, m) + i * h2(k, m)) % m;

    if (h < 0)
        h += m;

    return h;
}