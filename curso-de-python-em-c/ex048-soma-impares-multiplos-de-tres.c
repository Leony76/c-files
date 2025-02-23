#include <stdio.h>

int main() {

    int ate_500 = 0;
    int total = 0;
    int soma = 0;

    while (ate_500 <= 500) {
        if ((ate_500 % 2 != 0) && (ate_500 % 3 == 0)) {
            soma += ate_500;
            total++;
        }
        ate_500++;
    }

    printf("A soma dos %d numeros e de %d!", total, soma);

    return 0;
}