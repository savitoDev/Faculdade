#include <stdio.h>
#include <unistd.h>
#define lim_vendas 1000
#define meses 3
#define produtos 3

void pVetor(float vendas[lim_vendas][meses], float precos[lim_vendas], int nItens){
    char *nMeses[] = {"Junho", "Julho", "Agosto"};
    for(int i = 0; i < nItens; i++){
        printf("Insira o preço unitário atual do produto %d\nR$:", i+1);
        scanf("%f", &precos[i]);

        for(int j = 0; j < meses; j++){
            printf("Insira o valor de venda do produto %d em %s \nR: ", i+1, nMeses[j]);
            scanf("%f", &vendas[i][j]);
        }
    }
}

void precoUnitario(float vendas[lim_vendas][meses], int nItens){
    float totalProduto;

    for(int i = 0; i < nItens; i++){
        totalProduto = 0.0;

        for(int j = 0; j < meses; j++){
            totalProduto = totalProduto + vendas[i][j];
        }

        printf("  Produto %d: R$%.2f\n", i+1, totalProduto);
    }
}

float totalTrimestre(float vendas[lim_vendas][meses], int nItens){
    float totGeral = 0.0;

    for(int i = 0; i < nItens; i++){
        for(int j = 0; j < meses; j++){
            totGeral = totGeral + vendas[i][j];
        }
    }

    return totGeral;
}

void reajustar_preco(float precos[lim_vendas], int nItens){
    const float adicional = 1.10;

    for(int i = 0; i < nItens; i++){
        precos[i] = precos[i] * adicional;
    }
}

int main(){
    float vendas[lim_vendas][meses];
    float pUnitario[lim_vendas];

    float totalVendido;

    printf("///// Simulação de venda trimestral (Junho, Julho e Agosto) ///// \n\n");
    printf("Processando %d produtos para o teste...\n", produtos);
    sleep(3);

    printf("Preenchendo dados...\n");
    sleep(2);
    pVetor(vendas, pUnitario, produtos);
    printf("Aguarde...\n\n");
    sleep(3);

    printf("Total vendido por produto:\n");
    precoUnitario(vendas, produtos);
    printf("Aguarde...\n\n");
    sleep(3);

    printf("Total geral da loja:\n");
    totalVendido = totalTrimestre(vendas, produtos);
    sleep(5);
    printf("O total geral vendido na loja no trimestre foi: R$%.2f\n", totalVendido);

    printf("Reajustando preços.. adicionando(10porcento) em cima de todos os preços..\n");
    sleep(3);
    reajustar_preco(pUnitario, produtos);

    sleep(5);

    printf("Preços reajustados! Novos preços unitários:\n");
    for(int i = 0; i < produtos; i++){
        printf("Produto %d; Novo preço unitário: %.2f\n", i+1, pUnitario[i]);
    }

    printf("Fim da simulação!\n\n");

    return 0;
}
