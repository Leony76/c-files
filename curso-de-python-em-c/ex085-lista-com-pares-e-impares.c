#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    int quantidade = 0;
    int* lista_pares = (int*) malloc(quantidade * sizeof(int)); 
    int quant_pares = 0;
    int* lista_impares = (int*) malloc(quantidade * sizeof(int)); 
    int quant_impares = 0;

    while (1) {
        
        int numero;
        int n_valido = 0;

        while (!n_valido) {
            printf("Insira o %do numero: ", quantidade + 1);
            
            if (scanf("%d", &numero) == 1) {
                n_valido = 1;
                quantidade++;
                
                lista_pares = (int*) realloc(lista_pares, quantidade * sizeof(int));
                lista_impares= (int*) realloc(lista_impares, quantidade * sizeof(int));

                if (numero % 2 == 0) {
                    lista_pares[quant_pares] = numero;
                    quant_pares++;
                } else {
                    lista_impares[quant_impares] = numero;
                    quant_impares++;
                }

                printf("\033[32m>>> numero %d adicionado com sucesso!\033[m\n", numero);

                while (getchar() != '\n') {

                }
            } else {
                printf("\033[31mNumero invalido!\033[m\n");
                while (getchar() != '\n') {

                }
            }
        }

        char continuar;

        while (1) {
            printf("Continuar? [S/N]: ");
            scanf(" %c", &continuar);

            continuar = tolower((unsigned char)continuar);

            while (getchar() != '\n') {

            }

            if (continuar == 's' || continuar == 'n') {
                break;
            } else {
                printf("\033[31mOpcao invalida!\033[m\n");
            }
        }

        if (continuar == 'n') {
            break;
        }

        printf("\033[30m-----------------------------------------------\033[m\n");
    }

    printf("\033[30m-----------------------------------------------\033[m\n");

    printf("Numeros pares: \033[34m[");
    for (int i = 0; i < quant_pares; i++) {
        if (i == (quant_pares - 1)) {
            printf("%d]\033[m\n", lista_pares[i]);
        } else {
            printf("%d, ", lista_pares[i]);
        }
    }

    printf("Numeros impares: \033[34m[");
    for (int i = 0; i < quant_impares; i++) {
        if (i == (quant_impares - 1)) {
            printf("%d]\033[m\n", lista_impares[i]);
        } else {
            printf("%d, ", lista_impares[i]);
        }
    }

    return 0;
}