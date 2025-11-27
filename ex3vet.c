#include <stdio.h>

// Este programa procura em um vetor o menor elemento e o seu índice.

int main(){
    float v[10]; // O vetor que armazenará os valores digitados pelo usuário
    float v1[10]; // O vetor que terá os valores acima da média
    float v2[10]; // O vetor que terá os valores abaixo da média
    int divisor = 10; // 10, pois serão 10 notas para dividir.

    int i; // Variável de controle
    float soma = 0;
    float media = 0;
    for(i = 0; i < 10; i++){
        v[i] = 0;
        v1[i] = 0; // Já que os 3 vetores possuem o mesmo número de espaços, mais fácil fazer
        v2[i] = 0; // um único laço que faz a mesma coisa para eles.
    }

    // Início do programa
    printf("/////// Calculador de média avançado ///////");
    printf("\nUsuário, insira 10 valores para calcular sua média.\nR:\n");
    for(i = 0; i < 10; i++){
        scanf("%f", &v[i]);
    }
    // Cálculo da média
    for(i = 0; i < 10; i++){
        soma += v[i];
    }
    media = soma/divisor;

    // Agora, cada elemento de V será analizado.
    // O elemento de menor valor que a média será enviado para v2.
    // O elemento de maior valor que a média será enviado para v1.

    int cont1 = 0;
    int cont2 = 0;
    // Separadamente para ficar mais organizado, e evitar que os vetores fiquem feios

    for(i = 0; i < 10; i++){
        if(v[i] > media){
            v1[cont1] = v[i];
            cont1++;
        }
        else if(v[i] < media){
            v2[cont2] = v[i];
            cont2++;
        }
    }
    
    printf("\n//////// Fim do cálculo da média ////////\n");
    printf("A média foi: %f\n\n", media);
    printf("Notas acima da média: \n{");
    for(i = 0; i < cont1; i++){
        printf("%.2f", v1[i]);
        if(i < cont1 -1){
            printf(", ");
        }
    }
    printf("}");
    printf("\n\nNotas abaixo da média: \n{");
    for(i = 0; i < cont2; i++){
        printf("%.2f", v2[i]);
        if(i < cont2 - 1){
            printf(", ");
        }
    }
    printf("}\n");

    return 0;
}
