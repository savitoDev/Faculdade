#include <stdio.h>

// Este programa converte desde 50 graus fahrenheight até 150, e retorna seu valor na tela.

float FtoC(float F){
    float conta = (F-32)/1.8;

    return conta;
}

void main(){
    // Enquanto "i" for menor ou igual a 150, ele chamará a função e retorna seu resultado na tela.
    for(int i = 50; i <= 150; i++){
        printf("%d_Fahrenheight em Celcius: %.2f\n\n",i, FtoC(i));
    }
}
