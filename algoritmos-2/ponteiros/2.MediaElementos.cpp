#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int tamanho;
    cin >> tamanho;
    
    int *vetor;
    vetor = new int[tamanho]; // vetor dinamico 
    int *p = vetor; 
    
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        cin >> *p; // lê direto na posição apontada
        soma += *p; // usa ponteiro para somar
        p++; // anda para próxima posição
    }
    
    cout << fixed << setprecision(2) << (float)soma / tamanho << endl; // impressão da média
    
    return 0;
}