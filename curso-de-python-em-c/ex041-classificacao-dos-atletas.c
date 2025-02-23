#include <stdio.h>

int main() {

    int ano_nasc, idade;

    for (int i = 0; i < 5; i++) {
        printf("Insira o ano de nascimento do atleta: ");
        scanf("%d", &ano_nasc);
        fflush(stdout);

        idade = 2025 - ano_nasc;

        printf("Com %d anos, o atleta e considerado da categoria: ", idade);

        if (idade < 10) {
            printf("MIRIM\n");
        } else if (idade < 15) {
            printf("INFANTIL\n");
        } else if (idade < 20) {
            printf("JUNIOR\n");
        } else if (idade < 26) {
            printf("SENIOR\n");
        } else {
            printf("MASTER\n");
        }
    }

    return 0;
}