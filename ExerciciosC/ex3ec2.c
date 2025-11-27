#include <stdio.h>

double Fatorial_Harmonica(int N){
    double soma = 1.0;
    double fatorial = 1.0;
    
    for(int i = 1; i <= N; i++){
        fatorial *= i;
        soma = soma + (1.0/fatorial);
    }

    return soma;
}

void main(){
    int num = 0;
    printf("Insira um número para calcular sua fatoração e a série harmônica");
    scanf("%d", &num);

    double resultado = factorialAndHarmonical(num);

    printf("The number was: %d. The factorial and harmonical series resulted: %.6lf", num, resultado);
    
}
