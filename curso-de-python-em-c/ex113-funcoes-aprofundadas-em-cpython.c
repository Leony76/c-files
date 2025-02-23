#include <stdio.h>
#include <string.h>

int main() {

    int int_valido = 0;
    float flutuante;
    char char_inteiro[50];

    while (!int_valido) {

        printf("Insira um numero inteiro: ");

        fgets(char_inteiro, sizeof(char_inteiro), stdin);
        char_inteiro[strcspn(char_inteiro, "\n")] = '\0';

        int valido = 1;

        for (int i = 0; char_inteiro[i] != '\0'; i++) {
            if (((i == 0) && (char_inteiro[i] == '-')) || ((char_inteiro[i] >= '0') && (char_inteiro[i] <= '9'))) {
                continue;
            } else {
                valido = 0;
                break;
            }
        }

        if (valido) {
            int inteiro = 0;

            if (sscanf(char_inteiro, "%d", &inteiro) == 1) {
                int_valido = 1;
            } else {
                printf("\033[31mNumero inteiro invalido!\033[m\n");
            }
        } else {
            printf("\033[31mNumero inteiro invalido!\033[m\n");
        }
    }

    while (1) {

        printf("Insira um numero real: ");

        if (scanf("%f", &flutuante) == 1) {
            if (flutuante == (int)flutuante) {
                printf("\033[31mNumero real invalido!\033[m\n");
                while (getchar() != '\n');
            } else {
                break;
            }
        } else {
            printf("\033[31mNumero real invalido!\033[m\n");
            while (getchar() != '\n');
        }
    }

    printf("Foi digitado o numero inteiro %s e o numero real %.2f!", char_inteiro, flutuante);

    return 0;
}