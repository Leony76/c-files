#include <stdio.h>

int main() {

    int n1, n2, n3, maior, menor;

    printf("Insira o primeiro numero: ");
    scanf("%d", &n1);
    fflush(stdout);

    printf("Insira o segundo numero: ");
    scanf("%d", &n2);
    fflush(stdout);

    printf("Insira o terceiro numero: ");
    scanf("%d", &n3);
    fflush(stdout);

    maior = n1;
    if (n2 > n1 && n2 > n3) {
        maior = n2;
    } else if (n3 > n1 && n3 > n2) {
        maior = n3;
    }

    menor = n1;
    if (n2 < n1 && n2 < n3) {
        menor = n2;
    } else if (n3 < n1 && n3 < n2) {
        menor = n3;
    }

    printf("O maior e %d e o menor, %d!", maior, menor);

    return 0;
}