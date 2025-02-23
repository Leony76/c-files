#include <stdio.h>
#include <limits.h>

int main() {

    int pos = 0;
    int matriz[9];
    int soma_pares = 0, soma_3rd_col = 0;
    int maior_2nd_row = INT_MIN;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            int numero;

            printf("Insira um valor para \033[37m[\033[33m%d\033[37m]\033[37m[\033[33m%d\033[37m]\033[m: ", i, j);
            scanf("%d", &numero);

            if (numero % 2 == 0) {
                soma_pares += numero;
            }

            if (j == 2) {
                soma_3rd_col += numero;
            }

            if (i == 1) {
                if (numero > maior_2nd_row) {
                    maior_2nd_row = numero;
                }
            }

            matriz[pos] = numero;

            pos++;
        }
    }

    printf("\033[30m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n");

    for (int i = 0; i < 9; i++) {
        printf("\033[37m| \033[33m%d \033[37m|  ", matriz[i]);
        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }

    printf("\033[30m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n");

    printf("A soma dos valores pares e de \033[32m%d\033[m!\033[m\n", soma_pares);

    printf("A soma dos numeros da terceira coluna e de \033[32m%d\033[m!\n", soma_3rd_col);

    printf("O maior numero da segunda linha e o \033[32m%d\033[m!\n", maior_2nd_row);

    return 0;
}