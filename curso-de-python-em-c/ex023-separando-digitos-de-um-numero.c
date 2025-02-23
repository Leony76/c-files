#include <stdio.h>

int main() {

    int numero, unidade, dezena, centena, milhar;

    printf("Digite um numero com 4 digitos: ");
    scanf("%d", &numero);

    unidade = numero / 1 % 10;
    dezena = numero / 10 % 10;
    centena = numero / 100 % 10;
    milhar = numero / 1000 % 10;

    printf("Com o numero %d, partindo ele temos: \n", numero);
    printf("Unidade: %d\n", unidade);
    printf("Dezena: %d\n", dezena);
    printf("Centena: %d\n", centena);
    printf("Milhar: %d\n", milhar);

    return 0;
}