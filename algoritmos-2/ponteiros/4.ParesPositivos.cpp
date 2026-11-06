#include <iostream>
using namespace std;

int main()
{
    int tamanho;
    cin >> tamanho;
    
    int *vetor = new int[tamanho]; // vetor dinamico
    int *p = vetor;
    
    int paresPositivos = 0; // contador de números pares e positivos
    for(int i = 0; i < tamanho; i++) { 
        cin >> *p; // leitura dos números inteiros
        
        if (*p > 0 && (*p % 2 == 0)){ // checagem
            paresPositivos++;
        }
    }
    
    cout << paresPositivos << endl; // impressão do número dos pares positivos
    
    return 0;
}