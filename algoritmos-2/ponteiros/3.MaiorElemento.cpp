#include <iostream>
using namespace std;

int main()
{
    int tamanho;
    cin >> tamanho;
    
    int *vetor = new int[tamanho]; // vetor dinamico
    int *p = vetor; 
    
    cin >> *p; // lê o primeiro elemento
    int maiorElemento = *p; // o maior começa com o primeiro
    p++;

    for(int i = 1; i < tamanho; i++){ // o primeiro valor já é referencia em maiorElemento, então começa igual a 1 para analisar o próximo
        cin >> *p;
        
        if (*p > maiorElemento){ // se o próximo é maior que o anterior, as posições são trocadas
            maiorElemento = *p; // e a posição de maior muda
        }
        
        p++; // para percorrer o vetor
    }
    
    cout << maiorElemento << endl; // printa o maior elemento
    
    delete[] vetor; // limpa (usado sempre que new é usado)
    return 0;
}