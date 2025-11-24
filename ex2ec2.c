#include <stdio.h>

float serieHarmonica(int N){
    float E = 0.0;

    for(int i = 1; i <= N; i++){
        E = E + (1.0/i);
    }

    return E;
}

void main(){
    int N = 0;
    printf("Calculador de série harmônica");

    do{
        printf("\n\nInsira um número inteiro positivo: ");
        scanf("%d", &N);
        if (N <= 0){
            printf("//////////////////////////////\n");
            printf("O número deve ser positivo E diferente de zero..");
            printf("\n//////////////////////////////");
        }
    }while (N <= 0);

    float resultado = serieHarmonica(N);

    printf("O resultado da série harmônica é: %.2f", resultado);
}
