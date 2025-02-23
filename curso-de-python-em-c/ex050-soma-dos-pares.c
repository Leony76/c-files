#include <stdio.h>

int main() {

    int numeros;
    int soma = 0;

    for (int i = 0; i < 6; i++) {
        printf("Insira o numero %d: ", (i+1));
        scanf("%d", &numeros);

        if (numeros % 2 == 0) {
            soma += numeros;
        }
    }

    if (soma > 0) {
        printf("A soma dos numeros pares citados e de: %d\n", soma);
    } else {
        printf("Nenhum numero par foi encontrado!\n");
    }
    
    return 0;
}