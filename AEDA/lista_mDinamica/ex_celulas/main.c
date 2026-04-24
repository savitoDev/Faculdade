#include <stdio.h>
#include "lista_d.h"

void apresentacao(lista *l) {
    printf("\nDADOS GERAIS\n");
    printf("Tamanho da lista: %d\n", tamanho(l));
    printf("A lista esta vazia? %s\n", (vazia(l) ? "SIM" : "NAO"));
}

int main() {
    lista *l1 = inicializar();
    if(l1 == NULL)
        return 0;

    apresentacao(l1);
    printf("Lista: ");
    exibir(l1);
    printf("\n");

    printf("\nINSERCAO\n");
    for(int i = 1; i <= 8; i++)
        if(inserir_fim(l1, i))
            printf("Valor %d inserido com sucesso\n", i);
        else
            printf("ERRO. Valor %d nao inserido\n", i);

    apresentacao(l1);
    printf("Lista: ");
    exibir(l1);
    printf("\n");

    printf("\nBUSCA\n");
    for(int i = 0; i <= 12; i++) {
        int posicao = buscar(l1, i);
        if(posicao)
            printf("Valor %d encontrado na %d posicao da lista \n", i, posicao);
        else
            printf("ERRO. Valor %d nao encontrado\n", i);
    }

    printf("\nREMOCAO\n");
    for(int i = 1; i <= 10; i++) {
        if(remover_inicio(l1))
            printf("Valor removido com sucesso\n");
        else
            printf("ERRO. Valor nao removido\n");
        exibir(l1);
        printf("\n");
    }
    printf("%p\n", l1);
    liberar(&l1);
    printf("%p\n", l1);

    return 0;
}