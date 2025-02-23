#include <stdio.h>

int main() {

    int ano_nasc, idade;

    printf("Em qual ano nasceu?: ");
    scanf("%d", &ano_nasc);

    idade = 2025 - ano_nasc;

    printf("Voce nasceu em %d e tem %d anos, logo: ", ano_nasc, idade);
    if (idade == 18) {
        printf("Voce deve se alistar nesse ano!");
    } else if (idade < 18) {
        printf("Voce deve se alistar em %d ano(s)!", (18 - idade));
    } else {
        printf("Voce deve ter se alistado a %d ano(s) atras!", (idade - 18));
    }

    return 0;
}