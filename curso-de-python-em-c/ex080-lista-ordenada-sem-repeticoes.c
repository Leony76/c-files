#include <stdio.h>
#include <stdlib.h>

void ordenarEInserir(int lista[], int qtd, int num) {
    int i;

    for (i = qtd; i > 0 && lista[i-1] > num; i--) {
        lista[i] = lista[i-1];
    }
    lista[i] = num; 

    if (i == qtd)  {
        printf("\033[32m>>> O numero %d foi adicionado na ultima posicao!\033[m\n", num);
    } else {
        printf("\033[32m>>> O numero %d foi adicionado a posicao %d!\033[m\n", num, i+1);
    }
}

int main() {

    int lista_numeros[5] = {};

    for (int i = 0; i < 5; i++) {
        int numero_n_dup = 0;

        while (!numero_n_dup) {
            printf("Insira um valor: ");
            scanf("%d", &lista_numeros[i]);

            numero_n_dup = 1;

            for (int j = 0; j < i; j++) {
                if (lista_numeros[j] == lista_numeros[i]) {
                    numero_n_dup = 0;
                    break;
                }
            }

            if (numero_n_dup) {
                ordenarEInserir(lista_numeros, i, lista_numeros[i]);
            } else {
                printf("\033[31mEsse numero ja existe na lista!\033[m\n");
            }
        }
    }
    
    printf("A lista ficou: [ ");

    for (int i = 0; i < 5; i++) {
        printf("%d ", lista_numeros[i]);
    }

    printf("]!\n");

    return 0;
}