#include <stdio.h>
#include <limits.h>

int main() {

    int numeros[5] = {};
    int maior = INT_MIN, pos_maior[5] = {}, cont_maior = 0;
    int menor = INT_MAX, pos_menor[5] = {}, cont_menor = 0; 

    for (int i = 0; i < 5; i++) {
        printf("Insira o %do numero da lista: ", i+1);
        scanf("%d", &numeros[i]);
    }

    printf("Voce digitou os valores: [");

    for (int i = 0; i < 5; i++) {
        if (i == 4) {
            printf("%d]!\n", numeros[i]);
        } else {
            printf("%d, ", numeros[i]);
        }

        if (numeros[i] > maior) {
            maior = numeros[i];
            cont_maior = 0;
            pos_maior[cont_maior++] = i + 1; 
        } else if (numeros[i] == maior) {
            pos_maior[cont_maior++] = i + 1;
        }

        if (numeros[i] < menor) {
            menor = numeros[i];
            cont_menor = 0;
            pos_menor[cont_menor++] = i + 1;
        } else if (numeros[i] == menor) {
            pos_menor[cont_menor++] = i + 1;
        }
    } 

    printf("O maior numero citado foi %d, aparecendo nas posicoes ", maior);

    for (int i = 0; i < cont_maior; i++) {
        printf("%d ", pos_maior[i]);
    }
    printf("!\n");

    printf("O menor numero citado foi %d, aparecendo nas posicoes ", menor);

    for (int i = 0; i < cont_menor; i++) {
        printf("%d ", pos_menor[i]);
    }
    printf("!\n");

    return 0;
}


