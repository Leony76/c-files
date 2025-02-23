#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int idade;
    char sexo[2];
    char continuar[2];
    int pessoas_mais18 = 0, homens = 0, mulheres_menos20 = 0;

    while (1) {

        printf("---------- CADASTRE UMA PESSOA ----------\n");

        printf("Idade: ");
        scanf("%d", &idade);

        printf("Sexo [M/F]: ");
        scanf("%s", sexo);

        for (int i = 0; sexo[i] != '\0'; i++) {
            sexo[i] = tolower((unsigned char)sexo[i]);
        }
        sexo[strcspn(sexo, "\n")] = '\0';

        if (idade >= 18) {
            pessoas_mais18++;
        }

        if (strcmp(sexo, "m") == 0) {
            homens++;
        } else {
            if (idade < 20) {
                mulheres_menos20++;
            }
        }

        while (1) {
            printf("Continuar? [S/N]: ");
            scanf("%s", continuar);

            for (int i = 0; continuar[i] != '\0'; i++) {
                continuar[i] = tolower((unsigned char)continuar[i]);
            }
            continuar[strcspn(continuar, "\n")] = '\0';

            if ((strcmp(continuar, "s") == 0) || (strcmp(continuar, "n") == 0)) {
                break;
            }
        }

        if (strcmp(continuar, "n") == 0) {
            break;
        }
    }

    printf("-----------------------------------------\n");

    if (pessoas_mais18 > 1) {
        printf("Ao todo, foram catalogados %d pessoas maiores de 18 anos!\n", pessoas_mais18);
    } else if (pessoas_mais18 == 1) {
        printf("Ao todo, foi catalogado %d pessoa maior de 18 anos!\n", pessoas_mais18);
    } else {
        printf("Nenhuma pessoa maior de 18 anos foi catalogada!\n");
    }

    if (homens > 1) {
        printf("Ao todo, foram catalogados %d homens!\n", homens);
    } else if (homens == 1) {
        printf("Ao todo, foi catalogado %d homem!\n", homens);
    } else {
        printf("Nenhum homem foi catalogado!\n");
    }

    if (mulheres_menos20 > 1) {
        printf("Ao todo, foram catalogados %d mulheres abaixo de 20 anos!\n", mulheres_menos20);
    } else if (mulheres_menos20 == 1) {
        printf("Ao todo, foi catalogado %d mulher abaixo de 20 anos!\n", mulheres_menos20);
    } else {
        printf("Nenhum mulher abaixo de 20 anos foi catalogada!\n");
    }

    return 0;
}