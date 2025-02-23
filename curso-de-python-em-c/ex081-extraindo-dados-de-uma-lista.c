#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

void bubbleSort(int lista[], int quantidade) {
    int i, j, temp;

    for (i = 0; i < (quantidade - 1); i++) {
        for (j = 0; j < quantidade - 1 - i; j++) {
            if (lista[j] > lista[j + 1]) {
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

int main() {

    int quantidade = 0;
    int* lista_numeros = (int*) malloc (quantidade * sizeof(int));
    int* lista_numeros_backup = (int*) malloc (quantidade * sizeof(int));
    int flag_programa = 1;  
    int _5encotrado = 0, posicao_5;

    while (flag_programa) {

        printf("insira o \033[34m%do\033[m numero: ", quantidade+1);
        scanf("%d", &lista_numeros[quantidade]);

        lista_numeros_backup[quantidade] = lista_numeros[quantidade];

        getchar();

        printf("\033[32m>>> Numero adicionado com sucesso!\033[m\n");

        quantidade++;

        char continuar[5] = {};

        int flag_continuar = 1;

        while (flag_continuar) {
            printf("Deseja continuar? \033[36m[S/N]\033[m: ");
            scanf("%s", continuar);

            for (int i = 0; continuar[i] != '\0'; i++) {
                continuar[i] = tolower((unsigned char)continuar[i]);
            }

            continuar[strcspn(continuar, "\n")] = '\0';

            if ((strcmp(continuar, "nao") == 0) || (strcmp(continuar, "sim") == 0) || ((continuar[0] == 's') && (strlen(continuar) == 1)) || ((continuar[0] == 'n') && (strlen(continuar) == 1))) {
                flag_continuar = 0;
            } else {
                printf("\033[31mResposta invalida!\033[m\n");
            }
        }

        if (strcmp(continuar, "nao") == 0 || continuar[0] == 'n') {
            flag_programa = 0;
        }

        printf("\033[30m--------------------------------------------------------\033[m\n");
    }

    printf("Voce digitou %d elementos!\n", quantidade);

    printf("Os numeros digitados foram: \033[33m[");

    for (int i = 0; i < quantidade; i++) {
        if (i == (quantidade - 1)) {
            printf("%d]\033[m\n", lista_numeros[i]);
        } else {
            printf("%d, ", lista_numeros[i]);
        }
    }

    printf("Essa listagem em ordem decrescente fica: \033[35m[");

    bubbleSort(lista_numeros, quantidade);

    for (int i = (quantidade - 1); i >= 0; i--) {
        if (i == 0) {
            printf("%d]\033[m\n", lista_numeros[i]);
        } else {
            printf("%d, ", lista_numeros[i]);
        }
    }

    for (int i = 0; i < quantidade; i++) {
        if (lista_numeros_backup[i] == 5) {
            _5encotrado++;
            posicao_5 = (i + 1);
            break;
        }
    }

    if (_5encotrado == 1) {
        printf("O numero 5 foi encontrado pela primeira vez na posicao %d!\n", posicao_5);
    } else {
        printf("O numero 5 nao foi encontrado!\n");
    }

    free(lista_numeros);

    return 0;
}