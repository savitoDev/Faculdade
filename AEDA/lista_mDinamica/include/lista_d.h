#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef struct {
    int *dados;
    int cap;
    int qtde;
} lista;

// Para inicializar a lista com valores base.
lista inicializar(int cap_desejada);

// Retorna a capacidade da lista.
int capacidade(lista l);

// Retorna o tamanho da lista.
int tamanho(lista l);

// Verifica se a lista está cheia.
bool cheia(lista l);

// Verifica se a lista está vazia.
bool vazia(lista l);

/////////////////////////////////////////////////////////////

// Insere um valor inteiro 'v' no início da lista.
bool inserir_inicio(lista *l, int v);

// Insere um valor inteiro 'v' em uma posição válida da lista.
bool inserir(lista *l, int v, int pos);

// Insere um valor inteiro 'v' no final da lista.
bool inserir_fim(lista *l, int v);

// Remove o primeiro índice da lista.
bool remover_inicio(lista *l);

// Remove um índice válido da lista.
bool remover(lista *l, int pos);

// Remove o índice final da lista.
bool remover_fim(lista *l);

// Busca um valor inteiro 'v' válido na lista.
int buscar(lista l, int v);

// Exibe o vetor da lista.
void exibir(lista l);

// Encerra uma lista de forma segura.
void destruir(lista *l);

#endif