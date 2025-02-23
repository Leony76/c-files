#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {

    char nome[50];

    printf("Escreva um nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; nome[i] != '\0'; i++) {
        nome[i] = tolower((unsigned char)nome[i]);
    }

    if (strstr(nome, "silva") != NULL) {
        printf("O nome \'Silva\' foi encontrado!\n");
    } else {
        printf("O nome \'Silva\' nao foi encontrado!\n");
    }

    return 0;
}