#include <stdio.h>

int main() {

    float n_decimal;
    int n_inteiro;

    printf("Insira um numero decimal: ");
    scanf("%f", &n_decimal);

    n_inteiro = (int)n_decimal;

    printf("%f em sua parte inteira e %d !", n_decimal, n_inteiro);

    return 0;
}