#include <stdio.h>

int fatorial(int numero, int mostrar_caminho) {

    int fatoral = 1;

    for (int i = numero; i > 0; i--) {

        fatoral *= i;

        if (mostrar_caminho == 1) {
            if (i == 1) {
                printf("%d = ", i);
            } else {
                printf("%d x ", i);
            }
        } 
    }

    return fatoral;
}

int main() {

    int numero;

    printf("Insira um numero para ver seu fatorial: ");
    scanf("%d", &numero);

    printf("%d", fatorial(numero, 0));

    return 0;
}