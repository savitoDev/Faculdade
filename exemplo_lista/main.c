#include <stdio.h>
#include "include/lista.h"

void apresentacao(lista l){
    printf("-- // Informações da lista // --\n");
    printf("Capacidade: %d | Tamanho: %d\n", capacidade(l), tamanho(l));
    printf("Cheia: %s | Vazia: %s\n", cheia(l) ? "SIM" : "NAO", vazia(l) ? "SIM" : "NAO"); 
}


int main(){
    lista l = inicializar();
    
    apresentacao(l);

    // inserção de valores maximos
    for(int i = 1; i <= N; i++){
        inserir_fim(&l, i);
    }
    exibir(l);

    printf("Cheia: %s | Vazia: %s\n", cheia(l) ? "SIM" : "NAO", vazia(l) ? "SIM" : "NAO");

    printf("////////////////////////////////\nTentativa de inserção na lista...\n");
    printf(inserir(&l, 3, 2) ? "Valor '%d' inserido com sucesso na posição '%d'.\n" : "ERRO: A lista está cheia.\n");

    exibir(l);
}