#include <iostream>
using namespace std;

int main()
{
    // alocar dinamicamente = criar vetor em tempo de execução usando ponteiros
    int tamanho; // tamanho do vetor 
    int *vetor; 
    vetor = new int[tamanho]; // cria dinamicamente o vetor
    
    cin >> tamanho;
    for (int i = 0; i < tamanho; i++){
        cin >> vetor[i]; // leitura dos valores
    }
    
    for (int i = 0; i < tamanho; i++){
        cout << vetor[i] << " "; // impressão
    }
    
    delete[] vetor; // libera memória
    
    return 0;
}