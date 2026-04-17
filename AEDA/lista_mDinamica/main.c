#include <stdio.h>
#include "include/lista_d.h"

void apresentacao(lista l){
    printf("-- // Informações da lista // --\n");
    printf("Capacidade: %d | Tamanho: %d\n", capacidade(l), tamanho(l));
    printf("Cheia: %s | Vazia: %s\n", cheia(l) ? "SIM" : "NAO", vazia(l) ? "SIM" : "NAO"); 
}

int main(){
    lista l = inicializar(45);
    
    apresentacao(l);

    // inserção de valores maximos
    for(int i = 1; i <= l.cap; i++){
        inserir_fim(&l, i);
    }
    exibir(l);

    printf("Capacidade: %d | Tamanho: %d\n", capacidade(l), tamanho(l));
    printf("Cheia: %s | Vazia: %s\n", cheia(l) ? "SIM" : "NAO", vazia(l) ? "SIM" : "NAO");

    if(inserir(&l, 3, 2)){
        printf("Valor inserido com sucesso!\n");
    }else{
        printf("ERRO. Lista cheia.\n");
    }

    exibir(l);

    printf("Limpando lista...\n");
    destruir(&l);
    printf("Lista excluída com sucesso.");

    printf("\n");
    return 0;
}