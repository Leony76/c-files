#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char nomes[12][20] = {"APRENDER", "PROGRAMAR", "LINGUAGEM", "CPYTHON", "CURSO", "GRATIS", "ESTUDAR", "PRATICAR", "TRABALHAR", "MERCADO", "PROGRAMADOR", "FUTURO"};

    for (int i = 0; i < 12; i++) {
        printf("A palavra \'%s\' possui as vogais: ", nomes[i]);

        for (int k = 0; nomes[i][k] != '\0'; k++) {
            nomes[i][k] = tolower((unsigned char)nomes[i][k]);
        }

        for (int j = 0; nomes[i][j] != '\0'; j++) {
            if ((nomes[i][j] == 'a') || (nomes[i][j] == 'e') || (nomes[i][j] == 'i') || (nomes[i][j] == 'o') || (nomes[i][j] == 'u')) {
                printf("%c ", nomes[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}