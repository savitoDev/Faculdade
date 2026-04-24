#include <stdio.h>
#include <stdlib.h>
#include "lista_d.h"

typedef struct celula{
    int info;
    struct celula *prox;
} celula;

celula* criar_celula(int info){
    celula *novo = (celula*) malloc(sizeof(celula));
    if(novo){
        novo->info = info;
        novo->prox = NULL;
    }

    return novo;
}

struct lista{
    celula *prim;
    int tam;
};

int buscar(lista *l, int v){
    if(vazia(l)) return 0;

    celula* temp = l->prim;
    int cont = 1;
    while(temp != NULL){
        if(temp->info == v) return cont;
        cont++;
        temp = temp->prox;
    }

    return 0;
}

void destruir(lista **l){
    if(l == NULL) return false;

    free(*l);
}

void exibir(lista *l){
    if(vazia(l)) return;

    celula* temp = l->prim;
    while(temp != NULL){
        printf("%d ", temp->info);
        temp = temp->prox;
    }
}

lista* inicializar(){
    lista* l = (lista*) malloc(sizeof(lista));

    if(l == NULL) return NULL;

    l->prim = NULL;
    l->tam = 0;

    return l;
}

/////////////////////////////////////////////////////////////

bool inserir_fim(lista *l, int v){
    if(l == NULL) return false;

    celula *novo = criar_celula(v);
    if(!novo) return false;

    celula *temp = l->prim;
    if(vazia(l)){
        l->prim = novo;
    }else{
        while(temp->prox != NULL){
           temp = temp->prox; 
        }
        temp->prox = novo;
    }
    l->tam++;

    return true;
}

bool inserir_inicio(lista *l, int v){
    if(l == NULL) return false;
    
    celula* novo = criar_celula(v);
    if(novo == NULL) return false;
    
    novo->prox = l->prim;
    l->prim = novo;
    l->tam++;

    return true;
}

// bool inserir(lista *l, int v, int pos);

bool remover_inicio(lista *l){
    if(vazia(l)) return false;

    celula *temp = l->prim;

    l->prim = temp->prox;
    free(temp);
    l->tam--;

    return true;
}

bool remover(lista *l, int pos){
    if(vazia(l) || (pos < 1 || pos > tamanho(l))) return false;

    if(pos == 1) return remover_inicio(l);

    celula* ant = NULL;
    celula* temp = l->prim;
    int atual = 1;

    while(atual <= pos){
        ant = temp;
        temp = temp->prox;
        atual++;
    }
    ant->prox = temp->prox;
    free(temp);
    l->tam--;

    return true;
}

bool remover_fim(lista *l){
    if(vazia(l)) return false;

    celula *ant = NULL;
    celula *temp = l->prim;

    if(temp->prox == NULL){
        l->prim = NULL;
    }else{
        while(temp->prox != NULL){
            ant = temp;
            temp = temp->prox;
        }
        ant->prox = NULL;
    }

    free(temp);
    l->tam--;
    
    return true;
}                                        

int tamanho(lista *l){
    if(l == NULL) return true;

    return l->tam;
}

bool vazia(lista *l){
    if(l == NULL) return true;

    return l->tam == 0;
}