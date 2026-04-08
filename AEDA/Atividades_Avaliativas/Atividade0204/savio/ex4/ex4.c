#include <stdio.h>

typedef struct{
    float x, y, lado;
} Quadrado;

float area(Quadrado q);

float perimetro(Quadrado q);

int main(){
    Quadrado q1;

    q1.x = 2.0;
    q1.y = 3.0;
    q1.lado = 5.0;

    printf("--- Dados do Quadrado ---\n");
    printf("Lado: %.2f\n", q1.lado);
    printf("Posicao: (%.1f, %.1f)\n", q1.x, q1.y);
    printf("Area: %.2f\n", area(q1));
    printf("Perimetro: %.2f\n", perimetro(q1));

    printf("\n");
    return 0;
}

float area(Quadrado q){
    return q.lado * q.lado;
}

float perimetro(Quadrado q){
    return 4 * q.lado;
}