#include <stdio.h>

// Este programa lê um conjunto numérico e retorna o menor valor dele.
void main(){
    int atual = 1;
    int menor = 1;
    int numeros = 1;
    int posMenor = 0;

    printf("/////////////////////////////////////////////\n");
    printf("Digite quantos valores (inteiros) quiser...\n\n");
    printf("Ao digitar '0', o programa terminará.\n");
    printf("////////////////////////////////////////////\n\n");

    for(numeros; atual != 0; numeros++){
        scanf("%d", &atual);
        if(atual == 0){
            break;
        }
        if(atual < menor){
            menor = atual;
            posMenor = numeros;
        }
    }
    
    printf("\n\nFim dos conjuntos numéricos!!!\n");
    printf("%d números foram inseridos no conjunto. O menor foi o número %d na posição %d.", numeros-1, menor, posMenor);
}
