#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    char nome[50];

    printf("Insira um nome comepleto: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; nome[i] != '\0'; i++) {
        nome[i] = tolower((unsigned char)nome[i]);
    }

    int contador_a = 0;
    int primeiro_a = 0;
    int posicao_real = 0;
    int letras_nome = 0;
    int ultimo_a = 0;

    for (int i = 0; nome[i] != '\0'; i++) {
        if (nome[i] == 'a') {
            contador_a++;
        }
    }
    
    printf("A letra \'a\' apareceu %d vez(es)!\n", contador_a);

    for (int i = 0; nome[i] != '\0'; i++) {
        if (nome[i] != ' ') {
            if (nome[i] == 'a') {
                primeiro_a = posicao_real + 1;
                break;
            }
            posicao_real++;
        }
    }

    printf("O primeiro \'a\' apareceu na posicao %d !\n", primeiro_a);

    for (int i = 0; nome[i] != '\0'; i++) {
        if (nome[i] != ' ') {
            letras_nome++;
        }
    }

    posicao_real = letras_nome;

    for (int i = letras_nome; i > 0; i--) {
        if (nome[i] != ' ') {
            if (nome[i] == 'a') {
                ultimo_a = posicao_real - 1;
                break;
            }
            posicao_real--;
        }
    }

    printf("O ultimo \'a\' da nome se encontra na posicao %d !", ultimo_a);

    return 0;
}