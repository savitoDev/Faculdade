#include <stdio.h>

void main(){
    int atual = 0;
    int maior;
    int menor;

    // Loop for() para repetir 10 vezes
    for(int i = 1; i <= 10; i++){
        printf("Digite o %d° valor: ", i);
        scanf("%d", &atual);
        // Armazena o valor mais recente em "atual"

        // Condicionais para o valor mais recente
        if(atual > maior){
            maior = atual;
        }
        if(atual < menor){
            menor = atual;
        }
    }

    // Êxito do loop e impressão de informações
    printf("O menor número foi: %d", menor);
    printf("\nO maior número foi: %d", maior);
}
