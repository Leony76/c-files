#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

    int quantidade = 0, quant_pares = 0, quant_impares = 0;
    int* lista_numeros = (int*) malloc(quantidade * sizeof(int));
    int* lista_pares = (int*) malloc(quantidade * sizeof(int));
    int* lista_impares = (int*) malloc(quantidade * sizeof(int));
    int flag_programa = 1;

    while (flag_programa) {
        
        int valido = 0;
        int num;

        while (!valido) {
            printf("Insira um numero: ");

            if (scanf("%d", &num) == 1) {
                valido = 1;
            } else {
                printf("\033[31mTente novamente!\033[m\n");
                while (getchar() != '\n') {

                }
            }
        }
        
        lista_numeros[quantidade] = num;

        if (num % 2 == 0) {
            getchar();
            lista_pares[quant_pares] = num;
            quant_pares++;
        } else {
            getchar();
            lista_impares[quant_impares] = num;
            quant_impares++;
        }

        quantidade++;

        char continuar;
        int flag_continuar = 1;
        
        while (flag_continuar) {

            printf("Deseja continuar? [S/N]: ");
            scanf(" %c", &continuar);

            continuar = tolower((unsigned char)continuar);

            if ((continuar == 'n' || continuar == 's')) {
                flag_continuar = 0;
                while (getchar() != '\n') {
                    
                }
            } else {
                printf("\033[31mOpcao invalida!\033[m\n");
                while (getchar() != '\n') {
                    
                }
            }
        }

        if (continuar == 'n') {
            flag_programa = 0;
        }
    }

    printf("A lista completa e: \033[33m[");

    for (int i = 0; i < quantidade; i++) {
        if (i == (quantidade - 1)) {
            printf("%d]\033[m\n", lista_numeros[i]);
        } else {
            printf("%d, ", lista_numeros[i]);
        }
    }

    printf("Os numeros pares citados sao: \033[34m[ ");

    for (int i = 0; i < quantidade; i++) {
        if (lista_numeros[i] % 2 == 0) {
            printf("%d ", lista_numeros[i]);
            // if (i == (quant_pares - 1)) {
            //     printf("%d]\033[m\n", lista_numeros[i]);
            // } else {
            //     printf("%d, ", lista_numeros[i]);
            // }
        }
    }
    printf("]\033[m\n");

    printf("Os numeros impares citados sao: \033[34m[ ");

    for (int i = 0; i < quantidade; i++) {
        if (lista_numeros[i] % 2 != 0) {
            printf("%d ", lista_numeros[i]);
            // if (i == (quant_impares - 1)) {
            //     printf("%d]\033[m\n", lista_numeros[i]);
            // } else {
            //     printf("%d, ", lista_numeros[i]);
            // }
        }
    }
    printf("]\033[m\n");
    
    return 0;
}


