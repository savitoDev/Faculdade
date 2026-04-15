#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

#define N 15

typedef struct {
    int dados[N];
    int cap;
    int qtde;
} lista;

lista inicializar();

int capacidade(lista l);

int tamanho(lista l);

bool cheia(lista l);

bool vazia(lista l);

/////////////////////////////////////////////////////////////

bool inserir_inicio(lista *l, int v);

bool inserir(lista *l, int v, int pos);

bool inserir_fim(lista *l, int v);

bool remover_inicio(lista *l);

bool remover(lista *l, int pos);

bool remover_fim(lista *l);

int buscar(lista l, int v);

void exibir(lista l);

#endif