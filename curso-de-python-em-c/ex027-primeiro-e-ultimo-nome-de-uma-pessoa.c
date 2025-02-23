#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

    char nome[50];
    char primeiro_n[10];
    char ultimo_n[10];
    int j = 0;
    int i = 0;
    int letras_nome = 0;

    printf("Digite um nome completo: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';  // Remove o caractere de nova linha

    // Extrai o primeiro nome
    for (i = 0; nome[i] != '\0'; i++) {
        if (nome[i] != ' ') {
            primeiro_n[j] = nome[i];
            j++;
        } else {
            break;  // Quando encontrar o espaço, interrompe
        }
    }
    primeiro_n[j] = '\0';  // Termina a string do primeiro nome

    printf("Seu primeiro nome é: %s\n", primeiro_n);

    // Reinicializa variáveis
    j = 0;
    letras_nome = 0;

    // Conta o número total de caracteres não-espaços
    for (i = 0; nome[i] != '\0'; i++) {
        if (nome[i] != ' ') {
            letras_nome++;
        }
    }

    // Encontra a posição do último nome
    int posicao_espaco = -1;
    for (i = 0; i < strlen(nome); i++) {
        if (nome[i] == ' ') {
            posicao_espaco = i;  // Armazena a posição do último espaço
        }
    }

    // Copia o último nome
    j = 0;
    for (i = posicao_espaco + 1; nome[i] != '\0'; i++) {
        ultimo_n[j] = nome[i];
        j++;
    }
    ultimo_n[j] = '\0';  // Termina a string do último nome

    printf("O último nome é: %s\n", ultimo_n);

    return 0;
}
