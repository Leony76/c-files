// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// void bubbleSort(int lista[], int quantidade) {

//     int i, j, temp;

//     for (int i = 0; i < (quantidade - 1); i++) {
//         for (int j = 0; j < (quantidade - 1 - i); j++) {
//             if (lista[j] > lista[j + 1]) {
//                 temp = lista[j];
//                 lista[j] = lista[j + 1];
//                 lista[j + 1] = temp;
//             }
//         }
//     }
// }

// int main() {

//     int quantidade = 0;
//     int* lista_numeros = (int*) malloc(quantidade * sizeof(int));

//     while (1) {
//         while (1) {
//             printf("Digite um numero: ");

//             lista_numeros = (int*) realloc(lista_numeros, (quantidade + 1) * sizeof(int));
            
//             scanf("%d", &lista_numeros[quantidade]);

//             int ja_ta = lista_numeros[quantidade];

//             if (quantidade == 0) {
//                 printf("\033[32m>>> Adicionado com sucesso!\033[m\n");
//                 break;
//             } else {
//                 for (int i = 0; i < quantidade; i++) {
//                     if (lista_numeros[i] == ja_ta) {
//                         while (1) {
//                             printf("\033[31mEsse numero ja esta na lista!, digite outro!: \033[m");
//                             scanf("%d", &lista_numeros[quantidade]);

//                             int ainda_ta = lista_numeros[quantidade];

//                             if (ja_ta != ainda_ta) {
//                                 break;
//                             }
//                        }
//                    } else {
//                        break;
//                    }
//                 }
//                 printf("\033[32m>>> Adicionado com sucesso!\033[m\n");
//             }
//             break;
//         }

//         quantidade++;

//         char continuar[] = "lrc";

//         while (1) { 
//             printf("Deseja continuar? [Sim/Nao]: ");
//             scanf("%s", continuar);

//             for (int i = 0; continuar[i] != '\0'; i++) {
//                 continuar[i] = tolower((unsigned char)continuar[i]); 
//             }
//             continuar[strcspn(continuar, "\n")] = '\0';

//             if ((strcmp(continuar, "sim") == 0) || (strcmp(continuar, "nao") == 0)) {
//                 break;
//             }
//         }

//         if (strcmp(continuar, "nao") == 0) {
//             break;
//         }
//     }

//     bubbleSort(lista_numeros, quantidade);

//     printf("Voce digitou os numeros: [");

//     for (int i = 0; i < quantidade; i++) {
//         if (i == (quantidade - 1)) {
//             printf("%d]!\n", lista_numeros[i]);
//         } else {
//             printf("%d ", lista_numeros[i]);
//         }
//     }

//     free(lista_numeros);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void bubbleSort(int lista[], int quantidade) {
    int i, j, temp;
    for (i = 0; i < (quantidade - 1); i++) {
        for (j = 0; j < (quantidade - 1 - i); j++) {
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
    int* lista_numeros = (int*) malloc(quantidade * sizeof(int));

    while (1) {
        int numero_valido = 0;

        while (!numero_valido) {
            printf("Digite um numero: ");
            lista_numeros = (int*) realloc(lista_numeros, (quantidade + 1) * sizeof(int));
            scanf("%d", &lista_numeros[quantidade]);

            int ja_ta = lista_numeros[quantidade];  // Número digitado

            // Verifica se o número já está na lista
            numero_valido = 1;  // Assume que o número é válido

            for (int i = 0; i < quantidade; i++) {
                if (lista_numeros[i] == ja_ta) {
                    numero_valido = 0;  // Número já existe na lista
                    break;  // Sai do loop se encontrar duplicata
                }
            }

            if (numero_valido) {
                printf("\033[32m>>> Adicionado com sucesso!\033[m\n");
                quantidade++;  // Só aumenta a quantidade se o número for válido
            } else {
                printf("\033[31mEsse numero ja esta na lista!, digite outro!: \033[m");
            }
        }

        char continuar[10];

        while (1) { 
            printf("Deseja continuar? [Sim/Nao]: ");
            scanf("%s", continuar);

            for (int i = 0; continuar[i] != '\0'; i++) {
                continuar[i] = tolower((unsigned char)continuar[i]); 
            }
            continuar[strcspn(continuar, "\n")] = '\0';

            if ((strcmp(continuar, "sim") == 0) || (strcmp(continuar, "nao") == 0) || (continuar[0] == 's') || (continuar[0] == 'n')) {
                break;
            }
        }

        if (strcmp(continuar, "nao") == 0 || continuar[0] == 'n') {
            break;
        }
    }

    bubbleSort(lista_numeros, quantidade);

    printf("Voce digitou os numeros: [");

    for (int i = 0; i < quantidade; i++) {
        if (i == (quantidade - 1)) {
            printf("%d]!\n", lista_numeros[i]);
        } else {
            printf("%d ", lista_numeros[i]);
        }
    }

    free(lista_numeros);

    return 0;
}
