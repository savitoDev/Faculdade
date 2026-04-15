#include <stdio.h>
#include "lista.h"

lista inicializar(){
    lista l;
    l.cap = N;
    l.qtde = 0;
    return l;
}

int capacidade(lista l) {return l.cap;}

int tamanho(lista l) {return l.qtde;}

bool cheia(lista l) {return l.qtde == l.cap;}

bool vazia(lista l) {return l.qtde == 0;}

/////////////////////////////////////////////////////

bool inserir_inicio(lista *l, int v){
    if(cheia(*l)) return false;

    for(int i = l->qtde; i > 0; i--){
        l->dados[i] = l->dados[i - 1];
    }
    l->dados[0] = v;
    l->qtde++;
    
    return true;
}

bool inserir(lista *l, int v, int pos){
    if(cheia(*l) || pos < 1 || pos > l->qtde + 1)  return false;

    for(int i = l->qtde; i >= pos; i--){
        l->dados[i] = l->dados[i - 1];
    }
    l->dados[pos - 1] = v;
    l->qtde++;

    return true;
}

bool inserir_fim(lista *l, int v){
    if(cheia(*l)) return false;

    l->dados[l->qtde] = v;
    l->qtde++;

    return true;
}

bool remover_inicio(lista *l){
    if(vazia(*l)) return false;

    for(int i = 0; i < l->qtde; i++){
        l->dados[i] = l->dados[i+1];
    }
    l->qtde--;

    return true;
}

bool remover(lista *l, int pos){
    if(vazia(*l) || pos < 1 || pos > l->qtde) return false;

    for(int i = pos - 1; i < l->qtde - 1; i++){
        l->dados[i] = l->dados[i+1];
    }
    l->qtde--;

    return true;
}

bool remover_fim(lista *l){
    if(vazia(*l)) return false;

    l->qtde--;

    return true;
}

int buscar(lista l, int v){
    if(vazia(l)) return false;

    for(int i = 0; i < l.qtde; i++){
        if(l.dados[i] == v) return i + 1;
    }

    return 0;
}

void exibir(lista l){
    printf("{ ");
    for(int i = 0; i < l.qtde; i++){
        printf("%d ", l.dados[i]);
    }
    printf("}\n");
}