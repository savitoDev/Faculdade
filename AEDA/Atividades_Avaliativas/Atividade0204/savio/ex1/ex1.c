#include <stdio.h>

int main(){
    int linha_troca = 5; // em que ponto a pirâmide inverte
    
    for(int i = 0; i < 9; i++){ // '9' pois são 9 linhas no total.
        int linha_atual; // variável de controle para saber a 'linha' que o programa irá criar.

        // Lógica para espelhar a pirâmide
        if(i < linha_troca){
            linha_atual = i; // Atualiza a varíavel de controle pelo incremento atual.
        }else{
            linha_atual = 8 - i;
            /*
            Utilizei '8 - i' para que, quando 'i' aumentar, 'linha_atual' diminua.
            Exemplos: Quando i = 5, linha_atual = 3. Quando i = 6, linha_atual = 2.
            Desta forma, a lógica para quando a pirâmide está crescendo ou diminuindo pode ser feita em um único loop.
            */
        }

        int asteriscos = 9 - 2*linha_atual; // Representa a quantidade de asteriscos a serem impressos baseado na variável 'linha_atual'.

        for(int j = 0; j < linha_atual; j++){
            printf(" "); // Se linha atual == 3, 3 espaços são impressos.
        }

        for(int k = 0; k < asteriscos; k++){
            printf("*");
            /*
            Cada linha, até a linha de um único asterisco, possui uma discrepância de 2 asteriscos a menos entre elas.
            Sendo então 9 asteriscos na maior linha, e 2 a menos por linha, posso fazer a função (9 - 2*linha_atual).
            Baseado na linha que estiver, o loop saberá a quantidade de asteriscos a imprimir.
            Ex: linha_atual = 2
            A 3° linha de uma pirâmide, seguindo a lei de formação (9 asteriscos de maior base e 2 a menos por linha), terá 5 asteriscos, e 2 espaços.
            */
        }
        // Depois que todos os loops foram acessados (ou não), troca-se de linha para terminar o incremento.
        printf("\n");
    }

    printf("\n");
    return 0;
}