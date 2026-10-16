#include <iostream>
#include "hashing.h"
using namespace std;

int main(){
    int k, m, i = 0; // m = tamanho do vetor, k = elemento que será guardado no vetor
    
    // lendo os números até k = 0 e m = 0
    while (cin >> k >> m && (k != 0 || m != 0)) {
        cout << hash_aux(k, m) << endl;
        i++;
    }

    return 0;
}