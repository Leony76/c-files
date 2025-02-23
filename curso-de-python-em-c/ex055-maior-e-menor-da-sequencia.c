#include <stdio.h>

int main() {

    int tamanho = 5;
    float pesos[tamanho];
    float maior, menor;

    for (int i = 0; i < tamanho; i++) {
        printf("Insira o %do peso: ", i+1);
        scanf("%f", &pesos[i]);
    }

    maior = menor = pesos[0];

    for (int i = 1; i < tamanho; i++) {
        if (pesos[i] > maior) {
            maior = pesos[i];
        }

        if (pesos[i] < menor) {
            menor = pesos[i];
        } 
    }

    printf("O maior peso lido foi %.1fkg!\n", maior);
    printf("O menor peso lido foi %.1fkg!\n", menor);

    return 0;
}