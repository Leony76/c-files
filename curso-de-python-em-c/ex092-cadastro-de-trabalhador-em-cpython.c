#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char nome_trabalhador[50];
    int idade, aposentadoria;

    printf("Insira o \033[33mnome\033[m do trabalhador\033[32m: ");
    fgets(nome_trabalhador, sizeof(nome_trabalhador), stdin);
    nome_trabalhador[strcspn(nome_trabalhador, "\n")] = '\0';

    int ano_nasc_valido = 0;
    int ano_nascimento;

    while (!ano_nasc_valido) {

        printf("\033[mInsira seu \033[33mano de nascimento\033[32m: ");

        if (scanf("%d", &ano_nascimento) == 1) {
            ano_nasc_valido = 1;
            while (getchar() != '\n') {}
        } else {
            printf("\033[31mAno de nascimento invalido!\033[m\n");
            while (getchar() != '\n') {}
        }
    }   

    int carteira_valida = 0;
    int carteira;

    while (!carteira_valida) {

        printf("\033[mInsira a \033[33mcarteira de trabalho \033[31m(0 nao tem)\033[32m:");

        if (scanf("%d", &carteira) == 1) {
            carteira_valida = 1;
            while (getchar() != '\n') {}
        } else {
            printf("\033[31mCarteira de trabalho invalida!\033[m\n");
            while (getchar() != '\n') {}
        }
    }

    if (carteira != 0) {

        int contratacao_valida = 0;
        int contratacao;

        while  (!contratacao_valida) {
            printf("\033[mInsira o \033[33mano de contratacao\033[32m: ");
            
            if (scanf("%d", &contratacao) == 1) {
                contratacao_valida = 1;
                while (getchar() != '\n') {}
            } else {
                printf("\033[31mAno de contratacao invalida!\033[m\n");
                while (getchar() != '\n') {}
            }
        }
        
        int salario_valido = 0;
        float salario;

        while (!salario_valido) {

            printf("\033[mInsira o \033[33msalario\033[32m: ");

            if (scanf("%f", &salario) == 1) {
                salario_valido = 1;
                while (getchar() != '\n') {}
            } else {
                printf("\033[31mSalario invalido!\033[m\n");
                while (getchar() != '\n') {}
            }
        }

        printf("\033[34mO nome trabalhador e\033[32m: %s\n", nome_trabalhador);

        idade = 2025 - ano_nascimento;

        printf("\033[34mSua idade e de \033[32m%d anos\033[36m!\n", idade);

        printf("Sua carteira de trabalho e a \033[32m%d\033[36m!\n", carteira);

        printf("Sua contratacao ocorreu em \033[32m%d\033[36m!\n", contratacao);

        printf("Seu salario e de \033[32mR$ %.2f\033[34m!\n", salario);

        aposentadoria = idade + ((contratacao + 35) - 2025);
        
        printf("Sera aposentado com \033[32m%d anos\033[34m!\033[m\n", aposentadoria);

    } else {
        
        printf("\033[34mO nome trabalhador e\033[32m: %s\n", nome_trabalhador);

        idade = 2025 - ano_nascimento;

        printf("\033[34mSua idade e de \033[32m%d anos\033[36m!\n", idade);

        printf("\033[31mNao tem carteira de trabalho.\033[m\n");
    }

    return 0 ;
}