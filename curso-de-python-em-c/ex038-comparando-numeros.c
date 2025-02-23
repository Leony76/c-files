#include <stdio.h>

int main() {

    float n1, n2, maior, menor;

    printf("Insira um valor: ");
    scanf("%f", &n1);
    fflush(stdout);

    printf("Insira um outro valor: ");
    scanf("%f", &n2);
    fflush(stdout);

    if (n1 > n2) {
        maior = n1;
    } else if (n2 > n1) {
        maior = n2;
    } 

    if (n1 < n2) {
        menor = n1;
    } else if (n2 < n1) {
        menor = n2;
    }

    if (n1 != n2) {
        printf("%.2f e maior que %.2f!", maior, menor);
    } else {
        printf("%.2f e %.2f sao iguais!", n1, n2);
    }
    return 0;
}