#include <stdio.h>

void main(){
    // Declaração de variáveis
    int atual;
    int maior = 1;
    int menor = 1;
    int posicaoMaior = 1;
    int posicaoMenor = 1;
    
    // Começo do programa
    printf("Digite 10 valores: \n");
    for(int i = 1; i <= 10; i++){
        scanf("%d", &atual);
        // Repete o scan a cada iteração do loop enquanto a condição é válida
        
        // Loops que conferem a condição do número ser maior ou menor
        if(atual > maior){
            maior = atual;
            posicaoMaior = i;
            /*  
            Já que o "i" é utilizado para armazenar o valor da repetição atual, pode ser
            utilizado também para armazenar posições.
            */
        }
        if(atual < menor){
            menor = atual;
            posicaoMenor = i;
        }
    }
    
    // Êxito do for() loop e imprime parâmetros, como posição do número e o maior/menor inserido
    printf("\nO menor número foi: %d. Sua posição na linha é: %d°", menor, posicaoMenor);
    printf("\nO maior número foi: %d. Sua posição na linha é: %d°", maior, posicaoMaior);
}
