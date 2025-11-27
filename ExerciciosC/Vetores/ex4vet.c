#include <stdio.h>

/*
    Este programa calcula a nota do trabalho de um grupo de 8 pessoas, onde
    cada integrante dá uma nota de 1 a 10 para os outros 7 integrantes do grupo.
*/

int main(){
    // Vetores
    float notas[8];
    int i; // Variável de controle
    // Outras variáveis
    float soma = 0;
    float media = 0;

    // Limpeza do vetor
    for(i = 0; i < 8; i++){notas[i] = 0;}

    // Começo do programa
    printf("////// Avaliação do trabalho //////");
    for(i = 0; i < 8; i++){
        do{
            printf("\nMembro %d, avalie seu trabalho de 1 a 10.\nR: ", (i+1));
            scanf("%f", &notas[i]);
        }while(notas[i] < 1 || notas[i] > 10);
    }
    // Apanha as notas em 1 variável
    for(i = 0; i < 8; i++){
        soma += notas[i];
    }
    // Faz a média
    for(i = 0; i < 8; i++){
        media = soma/8.0;
    }

    // Finaliza o programa e mostra as informações
    printf("///////// Resumo");
    printf("\nA média da nota do grupo foi: %.2f.", media);

    return 0;
}
