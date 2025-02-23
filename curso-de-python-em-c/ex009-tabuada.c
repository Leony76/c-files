#include <stdio.h>

int main() {

    int numero;

    printf("Insira um numero para ver sua tabuada: ");
    scanf("%d", &numero);

    for (int i = 1; i <= 10; i++) {
        printf("\033[1;36m%d \033[1;33mx \033[1;36m%d \033[1;33m= \033[1;32m%d\n", numero, i, (numero * i));
    }

    return 0;
}