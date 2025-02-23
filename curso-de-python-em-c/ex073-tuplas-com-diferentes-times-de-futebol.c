#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {

    char lista_times[20][20] = {"Botafogo", "Palmeiras", "Flamengo", "Fortaleza", "Internacional", "Sao Paulo", "Corinthians", "Bahia", "Cruziero", "Vasco da Gama", "EC Vitoria", "Atletico-MG", "Fluminense", "Gremio", "Juventude", "Bragantino", "Atletico-PR", "Criciuma", "Atletico-GO", "Cuiaba"};

    printf("Os cinco primeiros colocados da tabela sao: ");
    for (int i = 0; i < 5; i++) {
        if (i == 4) {
            printf("e %s!", lista_times[i]);
        } else if (i == 3) {
            printf("%s ", lista_times[i]);
        } else {
            printf("%s, ", lista_times[i]);
        }
    }
    printf("\n\n");

    printf("Os 4 ultimos colocados das lista sao: ");
    for (int i = 19; i > 15; i--) {
        if (i == 16) {
            printf("e %s!", lista_times[i]);
        } else if (i == 17) {
            printf("%s ", lista_times[i]);
        } else {
            printf("%s, ", lista_times[i]);
        }
    }
    printf("\n\n");

    qsort(lista_times, 20, sizeof(lista_times[0]), comparar);

    printf("As colocacoes ordenados alfabeticamente fica: ");
    for (int i = 0; i < 20; i++) {
        if (i == 19) {
            printf("e %s!", lista_times[i]);
        } else if (i == 18) {
            printf("%s ", lista_times[i]);
        } else {
            printf("%s, ", lista_times[i]);
        }
    }
    printf("\n\n");

    char lista_times1[20][20] = {"Botafogo", "Palmeiras", "Flamengo", "Fortaleza", "Internacional", "Sao Paulo", "Corinthians", "Bahia", "Cruziero", "Vasco da Gama", "EC Vitoria", "Atletico-MG", "Fluminense", "Gremio", "Juventude", "Bragantino", "Atletico-PR", "Criciuma", "Atletico-GO", "Cuiaba"};

    char flamengo[] = "Flamengo";
    int posicao = -1;

    for (int i = 0; i < 20; i++) {
        if (strcmp(lista_times1[i], flamengo) == 0) {
            posicao = i;
            break;
        }
    }

    if (posicao != -1) {
        printf("O Flamengo aparece na posicao %d!\n", (posicao + 1));
    } else {
        printf("Flamengo nao foi encontrada em nenhum posicao!\n");
    }
    return 0;
}