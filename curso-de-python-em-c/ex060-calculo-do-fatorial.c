#include <stdio.h>

int main() {

    int numero, resultado = 1;

    printf("Insira um numero para calcular o fatorial: ");
    scanf("%d", &numero);

    while (numero > 0) {
        printf((numero == 1) ? "\033[1;36m%d" : "\033[1;36m%d \033[1;33mx ", numero);
        resultado *= numero;
        numero--;
    } 

    printf(" \033[1;33m= \033[1;32m%d\033[m\n", resultado);

    return 0;
}