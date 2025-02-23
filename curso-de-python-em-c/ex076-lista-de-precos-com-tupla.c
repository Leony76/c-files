#include <stdio.h>
#include <string.h>

int main() {

    char produtos[9][20] = {"Lapis", "Borracha", "Caderno", "Estojo", "Transferidor", "Compasso", "Mochila", "Caneta", "Livro"};

    float precos[9] = {1.75, 2, 15.9, 25, 4.2, 9.99, 120.32, 22.30, 34.90};
    
    printf("--------------------------------------\n");
    printf("          LISTAGEM DE PRECOS          \n");
    printf("--------------------------------------\n");

    for (int i = 0; i < 9; i++) {
        printf("%s ", produtos[i]);
        for (size_t j = 0; j < ((size_t)30 - (size_t)strlen(produtos[i])); j++) {
            printf(".");
        }
        printf(" R$%.2f\n", precos[i]);
    }

    printf("--------------------------------------\n");

    return 0;
}