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
    printf("\n\nInsira um número inteiro positivo");
    
    while(scanf("%d", &N) != 1 || N <= 0){
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("O número tem que ser um inteiro positivo. Bote um número válido.\n\n");
    }

    float resultado = serieHarmonica(N);

    printf("O resultado da série harmônica é: %.2f", resultado);
}