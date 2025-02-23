#include <stdio.h>

void numeroValido(int numero) {

    int valido = 0;

    while (!valido) {
        if ((scanf("%d", &numero) == 1)) {
            valido = 1;
            while (getchar() != '\n');
        } else {
            printf("\033[31mInsira um numero inteiro!\033[m: ");
            while (getchar() != '\n');
        }
    }
}


int main() {

    int numero;

    printf("Insira um numero: ");

    scanf("%d", &numero);

    numeroValido(numero);

    return 0;
}