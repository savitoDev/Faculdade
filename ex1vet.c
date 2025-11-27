#include <stdio.h>

// Este código soma 2 vetores e passa seu resultado para um 3° vetor.

int main(){
    int vetA[5] = {0, 0, 0, 0, 0};
    int vetB[5] = {0, 0, 0, 0, 0};
    int vetC[5] = {0, 0, 0, 0, 0};
    // Inicialização dos vetores
    int v;
    // Preferência, mas criei uma variável para contar. Melhor do que criar uma nova variável para cada laço novo.

    printf("Digite 5 valores para o primeiro vetor: ");
    for (v = 0; v < 5; v++){
        scanf("%d", &vetA[v]);
        // Atribui valores ao primeiro vetor
    }
    printf("Digite mais 5 valores para o segundo vetor: ");
    for (v = 0; v < 5; v++){
        scanf("%d", &vetB[v]);
        // Atribui valores ao segundo vetor
    }
    // Soma dos vetores
    // Sim, a soma tem que ser feita separadamente com um for para ser mais otimizado
    for(v = 0; v < 5; v++){
        vetC[v] = vetA[v] + vetB[v];
    }
    
    /*
        MUITO MPORTANTE
        Imprimir um vetor apenas chamando sua variável e com o tipo adequado dela é ERRADO.
        Você imprimirá apenas o endereço de memória do vetor!
        Use um laço separado.
    */
    printf("\n\nO vetor resultante é: {");
    for(v = 0; v < 5; v++){
        printf("%d", vetC[v]);
        if(v < 4){
            printf(", ");
        }
    }
    printf("}");

    return 0;
}
