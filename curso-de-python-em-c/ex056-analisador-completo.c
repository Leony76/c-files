#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    int quantidade = 1;
    int idade;
    int soma_idades = 0;
    int mais_velho = -1;
    int mulheres = 0;
    int mulheres_abaixo20 = 0;
    int maior;
    float media;
    char nome[10];
    char nome_mais_velho[10];
    char sexo[2];

    maior = -1;

    for (int i = 0; i < quantidade; i++) {
        printf("===== %da pessoa =====\n", i+1);
        printf("Nome: ");
        scanf("%s", nome);

        printf("Idade: ");
        scanf("%d", &idade);
        
        soma_idades += idade;

        printf("Sexo[M/F]: ");
        scanf("%s", sexo);

        for (int i = 0; sexo[i] != '\0'; i++) {
            sexo[i] = tolower((unsigned char)sexo[i]);
        }

        if ((idade > maior) && (strcmp(sexo, "m") == 0)) {
            mais_velho = idade;
            strcpy(nome_mais_velho, nome);
            maior = idade; 
        }

        if (strcmp(sexo, "f") == 0) {
            mulheres++;
        }

        if ((idade < 20) && (strcmp(sexo, "f") == 0)) {
            mulheres_abaixo20++;
        }
    }
    
    media = (float) soma_idades / (float) quantidade;

    printf("A media de idade do grupo e de %.1f anos!\n", media);
    if (mais_velho != -1) {
        printf("O homem com maior idade tem %d anos e se chama %s!\n", mais_velho, nome_mais_velho);
    } else {
        printf("Nao ha nenhum homem nessa listagem!\n");
    }
    if (mulheres_abaixo20 > 0) {
        printf("Existem %d mulhere(s) que tem idade abaixo de 20 anos!\n", mulheres_abaixo20);
    } else if (mulheres_abaixo20 == 0) {
        printf("Nao existe nenhuma mulher que tenha idade abaixo de 20 anos!\n");
    } else if (mulheres == 0) {
        printf("Nao ha nenhuma mulher nessa listagem!\n");
    }

    return 0;
}