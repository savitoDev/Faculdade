#include <stdio.h>

// Este programa procura em um vetor o menor elemento e o seu índice.

int main(){
    /*
        Como explicado no slide, para inicializar vetores pequenos, é bom
        botar {0, 0, 0, 0} de uma vez, pois isto já elimina o lixo de memória.
        Porém, para vetores maiores, é recomendado declará-los em um
        laço de repetição que todas as posições recebem 0.
        Uma forma mais organizada do que uma linha longa que requer atenção do programador.
    */
    int vetor[20];
    int i; // Variável de controle de repetição
    for(i = 0; i < 20; i++){vetor[i] = 0;} // Incialização em uma só linha para poupar espaço
    
    // Parâmetros de análise
    int menorIndice = 0;
    int menor = 0;

    // Começo do programa
    printf("///////// Análise de vetor(es) /////////\n");

    printf("Usuário, digite o primeiro valor do primeiro elemento: ");
    scanf("%d", &vetor[0]);
    menor = vetor[0];
    /*
        Leva-se como parâmetro o valor do primeiro elemento como o menor número.
        Isto é uma das soluções para este problema. Outra solução seria inicalizar a variável com um valor muito alto.
    */

    // Registro dos elementos
    printf("\nDigite 20 números (inteiros) para o vetor:\n");
    for(i = 0; i < 19; i++){
        scanf("%d", &vetor[i]);
        if(vetor[i] < menor){
        // Se o valor inserido for menor que o menor elemento do vetor, entra no loop
            menorIndice = i;
            menor = vetor[i];
        }
    }

    // Fim do programa
    printf("\n\n///////// Fim da digitação dos valores /////////");
    printf("\n O menor valor do vetor foi: %d", menor);
    printf("\n O seu índice é: [%d]", menorIndice);

    return 0;
}
