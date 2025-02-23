#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {

    char nome[50];
    char sem_espaco[50];
    char nome_invertido[50];
    int quantidade = 0;
    int j = 0;
    int k = 0;

    printf("Insira um nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; nome[i] != '\0'; i++) {
        nome[i] = toupper((unsigned char)nome[i]); 
    }

    for (int i = 0; nome[i] != '\0'; i++) {
        if (nome[i] != ' ') {
            sem_espaco[j] = nome[i];
            j++;
        }
    }

    sem_espaco[j] = '\0';

    for (int i = 0; sem_espaco[i] != '\0'; i++) {
        quantidade++;
    }

    for (int i = quantidade - 1; sem_espaco[i] >= 0; i--) {
        nome_invertido[k] = sem_espaco[i];
        k++;
    } 

    nome_invertido[k] = '\0';

    printf("O inverso de \033[1;33m%s\033[m fica \033[1;33m%s\033[m, logo ", sem_espaco ,nome_invertido);

    if (strcmp(nome_invertido, sem_espaco) == 0) {
        printf("\033[1;32mSAO PALINDROMOS!\033[m\n");
    } else {
        printf("\033[1;31mNAO SAO PALINDROMOS!\033[m\n");
    }

    return 0;
}