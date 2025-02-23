#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char nome[50];
    char gols[10] = "0";

    printf("Digite o nome do jogador: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    if (nome[0] == '\0') {
        strcpy(nome, "<desconhecido>");
    }

    printf("Digite quantos gols %s fez: ", nome);
    fgets(gols, sizeof(gols), stdin);
    gols[strcspn(gols, "\n")] = '\0';

    if (gols[0] == '\0') {
        strcpy(gols, "0");
    }
    
    printf("O(A) jogador(a) %s fez um total de %s gol(s)!", nome, gols);

    return 0;
}