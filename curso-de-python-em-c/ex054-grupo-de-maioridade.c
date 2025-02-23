#include <stdio.h>

int main() {

    int ano_nasc, idade, maior_idade = 0, menor_idade = 0;

    for (int i = 0; i < 7; i++) {
        printf("Insira o ano de nascimento da %da pessoa: ", i+1);
        scanf("%d", &ano_nasc);

        idade = 2025 - ano_nasc;

        if (idade >= 18) {
            maior_idade++;
        } else {
            menor_idade++;
        }
    }

    printf("Foram no total %d pessoas maiores de 18 anos e %d menores!\n", maior_idade, menor_idade);

    return 0;
}