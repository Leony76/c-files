#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

int main() {

    srand(time(NULL));

    int random = rand() % 11, random2 = rand() % 11, random3 = rand() % 11, random4 = rand() % 11, random5 = rand() % 11;
    int maior, menor;

    maior = INT_MIN;
    menor = INT_MAX;

    int lista_numeros[5] = {random, random2, random3, random4, random5};

    printf("Foram sorteados: (");
    for (int i = 0; i < 5; i++) {
        if (i == 4) {
            printf("%d", lista_numeros[i]);    
        } else {
            printf("%d ", lista_numeros[i]);
        }

        if (lista_numeros[i] > maior) {
            maior = lista_numeros[i];
        }

        if (lista_numeros[i] < menor) {
            menor = lista_numeros[i];
        }
    }
    printf(")!\n");

    printf("O maior numero desse sorteio foi %d!\n", maior);
    printf("O menor numero desse sorteio foi %d!\n", menor);

    return 0;
}