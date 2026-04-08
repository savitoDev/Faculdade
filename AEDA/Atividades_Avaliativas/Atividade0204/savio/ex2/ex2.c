#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir(int *vetor, int n);

void inverter(int *vet, int tam);

void preencher(int *vetor, int tam, int min, int max);

int terceira_ocorrencia(int *vetor, int n, int v);

int main(){
    srand(time(NULL));

    int n = 50;
    int buscar = 7; // Valor a ser buscado no vetor
    int vetor[n];

    preencher(vetor, n, -15, 42);

    printf("Vetor original:\n");
    imprimir(vetor, n);

    int indice = terceira_ocorrencia(vetor, n, buscar);
    printf(indice != -1 ? "O valor %d foi encontrado pela terceira vez no indice %d.\n" : "O valor %d nao foi encontrado no vetor.\n", buscar, indice, buscar);

    inverter(vetor, n);
    printf("Vetor invertido:\n");
    imprimir(vetor, n);

    return 0;
}

void imprimir(int *vetor, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    /*

    Outra forma de imprimir de forma mais bonita o vetor. Como foi pedido apenas para separar por espaço, deixei a forma mais simples.

    printf("{");
    for(int i = 0; i < n; i++){
        printf("%d", vetor[i]);
        if(i < n-1){
            printf(", ");
        }
    }
    printf("}");

    printf("\n");
    */
}

void inverter(int *vet, int tam){
    for(int i = 0; i < tam / 2; i++){ // Rodar até a metade do vetor é a forma mais organizada que encontrei. Pois se o lado esquerdo todo foi invertido, o direito também.
        int temp = vet[i]; // Ex: posição 0, i = 0
        vet[i] = vet[tam-1-i]; // posição 5 recebe o valor da posição 49 
        vet[tam-1-i] = temp; // posição 49 recebe o valor da posição 0
    }
}

void preencher(int *vetor, int tam, int min, int max){
    for(int i = 0; i < tam; i++){
        int numeros = rand() % (max - min + 1) + min;
        vetor[i] = numeros;
    }
}

int terceira_ocorrencia(int *vetor, int n, int v){
    int ocorrencias = 0; // Variável de controle para a identificação das 3 vezes que o valor informado foi encontrado
    for(int i = 0; i < n; i++){
        if(vetor[i] == v){
            ocorrencias++;
            if(ocorrencias == 3) return i; // Caso tenha encontrado 3 vezes, ele retorna o índice da última busca (a terceira)
        }
    }

    return -1; // Caso não tenha encontrado nenhuma vez, retorna -1.
}