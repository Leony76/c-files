#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int main() {

    int numero, maior = INT_MIN, menor = INT_MAX, soma_numeros = 0, cont_numeros = 0;
    char escolha[2];
    float media;

    while (1) {
        printf("Insira um numero: ");
        scanf("%d", &numero);

        soma_numeros += numero;
        cont_numeros++;

        if (numero > maior) {
            maior = numero;
        }

        if (numero < menor) {
            menor = numero;
        }

        printf("Deseja continuar? [S/N]: ");
        scanf("%s", escolha);

        for (int i = 0; escolha[i] != '\0'; i++) {
            escolha[i] = tolower((unsigned char)escolha[i]);
        }
        escolha[strcspn(escolha, "\n")] = '\0';

        if (strcmp(escolha, "n") == 0) {
            break;
        }
    }

    media = (float)soma_numeros / (float)cont_numeros;

    printf("A media dos %d numeros e de %.1f!\n", cont_numeros, media);
    printf("O maior numero catalogado e %d e o menor, %d\n!", maior, menor);

    return 0;
}