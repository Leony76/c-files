#include <stdio.h>
#include <stdlib.h>

int main() {

    int numero, soma_numeros = 0, cont_numeros = 0;

    while (numero != 999) {

        printf("Digite um numero: [999 para parar!]");
        scanf("%d", &numero);

        if (numero != 999) {
            soma_numeros += numero;
            cont_numeros++;
        }
    }

    if (cont_numeros > 0) {
        printf("Voce digitou %d numero(s) e a soma deles e %d!", cont_numeros, soma_numeros);
    } else {
        printf("Voce digitou nenhum numero!");
    }

    return 0;
}