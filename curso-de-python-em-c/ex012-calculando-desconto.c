#include <stdio.h>

int main() {

    float preco, desconto;

    printf("Insira o valor do produto: R$");
    scanf("%f", &preco);

    desconto = preco - (preco * (5.0/100.0));

    printf("O produto que vale R$%.2f, com desconto de 5%% vale R$%.2f !", preco, desconto);

    return 0;
}