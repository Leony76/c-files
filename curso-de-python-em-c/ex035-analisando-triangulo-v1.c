#include <stdio.h>

int main() {

    float lado1, lado2, lado3;

    printf("Insira o primeiro lado do triangulo: ");
    scanf("%f", &lado1);
    fflush(stdout);

    printf("Insira o segundo lado do triangulo: ");
    scanf("%f", &lado2);
    fflush(stdout);

    printf("Insira o terceiro lado do triangulo: ");
    scanf("%f", &lado3);
    fflush(stdout);

    if ((lado1 < (lado2 + lado3)) && (lado2 < (lado1 + lado3)) && (lado3 < (lado1 + lado2))) {
        printf("O triangulo existe!\n");
    } else {
        printf("O triangulo nao existe!\n");
    }

    return 0;
}