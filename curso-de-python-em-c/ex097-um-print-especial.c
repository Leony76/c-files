#include <stdio.h>
#include <string.h>

void escreva(char nome[]) {

    int tamanho = strlen(nome) + 8;

    for (int i = 0; i < tamanho; i++) {
        printf("\033[33m-\033[");
    }
    printf("\n");

    printf("\033[36m    %s\n", nome);

    for (int i = 0; i < tamanho; i++) {
        printf("\033[33m-\033[m");
    }
    printf("\n");
} 

int main() {

    char nome[50];

    printf("Insira um nome: ");
    scanf("%s", nome);

    escreva(nome);

    return 0;
}