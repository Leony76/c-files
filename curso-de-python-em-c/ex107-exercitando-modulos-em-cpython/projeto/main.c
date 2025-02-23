#include "util.h"
#include <stdio.h>

int main() {

    float preco;

    printf("Insira um preco (R$): ");
    scanf("%f", &preco);

    printf("%.2f", metadePreco(preco));
    printf("%.2f", dobroPreco(preco));
    printf("%.2f", _10Aumento(preco));

    return 0;
}