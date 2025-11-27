#include <stdio.h>

void main(){
    float alt_chico = 1.50;
    float crescChico = 0.02;

    float alt_ze = 1.40;
    float crescZe = 0.03;

    int anos = 0;

    do{
        alt_chico = alt_chico + crescChico;
        alt_ze = alt_ze + crescZe;
        anos++;
    }while (alt_ze < alt_chico);
    printf("%d Anos se passaram até Zé ser maior que Chico.\n\n", anos);
    printf("Alturas finais: \n\nChico: %.2f m\nZé: %.2f m", alt_chico, alt_ze);
}
