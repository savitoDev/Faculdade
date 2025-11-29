#include <stdio.h>
#define tamanho 4

// Este programa procura em um vetor o índice com maior valor armazenado

int main(){
    int vetor[tamanho];
    int i; // Variável de controle de repetição
    for(i = 0; i < tamanho; i++){vetor[i] = 0;} // Limpa o lixo de memória no vetor ao zerar tudo nele

    // Variáveis para o vetor
    int maiorIndice = 0;
    int maiorN = 0; 

    // Começo da interação
    printf("Digite valores para %d posições em um vetor:\nR: ", tamanho);
    for(i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
        if(vetor[i] > maiorN){
            maiorN = vetor[i];
            maiorIndice = i;
        }
    }

    printf("Indice com elemento de maior valor: %d", maiorIndice);

    return 0;
}