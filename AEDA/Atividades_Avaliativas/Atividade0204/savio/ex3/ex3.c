#include <stdio.h>
#include <string.h>

void roda_string(char *str);

int main(){
    char frase[100];

    printf("Digite uma palavra ou frase.\nR: ");
    fgets(frase, 100, stdin);

    int tam = strlen(frase);
    if(frase[tam-1] == '\n'){
        frase[tam-1] = '\0';
    }

    roda_string(frase);

    printf("String rodada: %s\n", frase);

    return 0;
}

void roda_string(char *str){
    int tam = strlen(str);

    if (tam <=1) return; // Se tiver 1 letra ou nada, não há o que rodar.

    char ultimo = str[tam - 1];
    for(int i = tam - 1; i > 0; i--){ // De trás para frente, todos são dislocados para a direita.
        str[i] = str[i - 1];
    }

    str[0] = ultimo;
}