#include <stdio.h>

/*
    Este programa trata-se de um desafio proposto por um slide de vetores,
    onde o usuário proporciona o tamanho de 2 vetores que utilizam de parâmetro a variável N
    e, então, digita valores aleatórios para os dois vetores.
    Quando os dois vetores são preenchidos, um novo vetor anteriormente declarado assume os
    valores do primeiro e segundo vetor, seu tamanho sendo o dobro para poder alocar-los.
    Por fim, é mostrado na tela o resultado em ordem crescente dos 2 vetores juntos. (imprimindo o 3° vetor secreto)
*/

int main(){
    // Parâmetro do usuário
    int N = 0;

    // Início do programa
    printf("//// Desafio extra: Vetores ////\n");
    printf("Usuário, digite um valor inteiro para ser o tamanho do vetor.\nR: ");
    scanf("%d", &N); // N agora é atribuído o valor que o usuário digitou.

    // Vetores
    float v1[N];
    float v2[N];
    float v3[N*2]; // Para caber os valores dos dois vetores anteriores, v3 tem que ser o dobro do tamanho dado a eles.
    int i; // Estrutura de repetição

    // Valores aleatórios para o primeiro vetor
    printf("\nUsuário, digite quaisquer valores para as %d casas do primeiro vetor: ", N);
    for(i = 0; i < N; i++){
        scanf("%f", &v1[i]);
    }
    // Valores aleatórios para o segundo vetor
    printf("\nUsuário, digite quaisquer valores para as %d casas do segundo vetor: ", N);
    for(i = 0; i < N; i++){
        scanf("%f", &v2[i]);
    }

    // Para passar os parâmetros para v3, em primeira instância passamos separadamente
    for(i = 0; i < N; i++){
        v3[i] = v1[i]; // Para cada posição representado por i, v3 recebe o valor correspondente de v1
    }
    for(i = 0; i < N; i++){
        v3[N + i] = v2[i]; // v3 com os tamanho dado + o número de repetições é igualado à posição e seu valor em v2.
        // (Mas isso não sobrepõe os valores dados antes?)
        // R: Não. Estou apenas AUMENTANDO o v3 (eis a soma com 'i') para alocar espaço para os elementos de v2.
    }

    // Extra: ordenando realmente por tamanho cada elemento
    // Esta parte fica responsável por ordenar os elementos do vetor 3 em ordem crescente.
    float varTemp;
    int tamanho = N * 2; // Assim definimos o 3° vetor, por essa variável.
    int j; // "j" é só como eu quero chamar as posições

    // Técnica "Bubble sort"
    for(i = 0; i < tamanho; i++){ // Garante que a repetição seja feita apenas de acordo com o tamanho do vetor.
        for(j = 0; j < tamanho - 1 - i; j++){ // Enquanto 'j' for menor que o tamanho real de v3 e menos o número de repetições, aumentamos 1 posição.
            if(v3[j] > v3[j + 1]){ // se o elemento da posição atual for menor que a próxima, entra no loop:
                varTemp = v3[j]; // A variável temporária recebe o valor da posição atual de v3
                v3[j] = v3[j + 1]; // a posição atual de v3 é igualada à ela mesma + 1
                v3[j + 1] = varTemp; // A posição atual + 1 é igualada à variável temporária, terminando o loop
            }
        }
    }

    // Fim do programa, mostrando as informações
    printf("\n\n////// Valores para dois vetores atribuídos.");
    printf("\nOs dois vetores em ordem crescente é: {");
    for(i = 0; i < N * 2; i++){
        printf("%.1f", v3[i]); // Imprime os valores junto
        if(i < N * 2 - 1){ // Caso a repetição atual seja menor que o tamanho real de v3,
            printf(", "); // Ele confirma que há mais por vir, e imprime uma vírgula e um espaço para separar os elementos.
        }
    }
    printf("}\n"); // Termina fechando o vetor

    return 0;
}
