#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {

    char nome[50];

    printf("Digite um nome: ");
    fgets(nome, sizeof(nome), stdin);

    nome[strcspn(nome, "\n")] = '\0';

    printf("O nome digitado foi: %s", nome);

    for (int i = 0; nome[i] != '\0'; i++) {
        nome[i] = toupper((unsigned char)nome[i]);
    }

    printf("\nEm maiusculas fica: %s\n", nome);

    for (int i = 0; nome[i] != '\0'; i++) {
        nome[i] = tolower((unsigned char)nome[i]);
    }

    printf("Em minusculas fica: %s\n", nome);

    int contador = 0;

    for (int i = 0; nome[i] != '\0'; i++) {
        if (nome[i] != ' ') {
            contador++;
        }
    }

    printf("O nome tem exatas %d letras!\n", contador);

    int cont_pNome = 0;

    for (int i = 0; nome[i] != '\0' && nome[i] != ' '; i++) {
        if (nome[i] != ' ') {
            cont_pNome++;
        }
    }

    printf("O primeiro nome tem exatas %d letras!\n", cont_pNome);

    return 0;
}