#include <stdio.h>

int main() {    

    int numero;

    printf("Insira um numero qualquer: ");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("O numero %d e PAR!", numero);
    } else {
        printf("O numero %d e IMPAR!", numero);
    }

    return 0;
}