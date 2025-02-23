#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    int flag_programa = 1;

    while (flag_programa) {

        char expressao[50];
        int abertura = 0, fechamento = 0;

        printf("Insira uma expressao matematica: ");
        scanf("%s", expressao);

        for (int i = 0; expressao[i] != '\0'; i++) {
            if (expressao[i] == '(') {
                abertura++;
            }

            if (expressao[i] == ')') {
                fechamento++;
            }
        }

        if (abertura == fechamento) {
            printf("\033[32mEssa expressao e valida!\033[m\n");
        } else {
            printf("\033[31mEssa expressao e invalida!\033[m\n");
        }
        
        char continuar;
        int flag_continuar = 1;

        while (flag_continuar) {
            printf("Deseja continuar?[S/N]: ");
            scanf(" %c", &continuar);

            continuar = tolower((unsigned char)continuar);

            if (continuar == 's' || continuar == 'n') {
                flag_continuar = 0;
                while (getchar() != '\n') {

                }
            } else {
                printf("\033[31mOpcao invalida!\033[m\n");
                while (getchar() != '\n') {

                }
            }
        }

        if (continuar == 'n') {
            flag_programa = 0;
        }
    }

    return 0;
}