#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <float.h>

#define MAX_NOME 50

int main() {

    int quantidade = 0;
    int* pos_maior = (int*) malloc(quantidade * sizeof(int));
    int* pos_menor = (int*) malloc(quantidade * sizeof(int));
    float* lista_pesos = (float*) malloc(quantidade * sizeof(float));
    char **lista_nomes = (char **) malloc(quantidade * sizeof(char *));
    char **lista_nome_menores = (char**) malloc(quantidade * sizeof(char *));
    char **lista_nome_maiores = (char**) malloc(quantidade * sizeof(char*));

    int quantidade_pessoas = 0;
    int quant_maior = 0, quant_menor = 0;
    float maior = FLT_MIN, menor = FLT_MAX;

    while (1) {

        lista_pesos = (float*) realloc(lista_pesos, (quantidade + 1) * sizeof(float));
        lista_nomes = (char **) realloc(lista_nomes, (quantidade + 1) * sizeof(char *));

        lista_nomes[quantidade] = (char*) malloc(MAX_NOME * sizeof(char));
        lista_nomes[quantidade][strcspn(lista_nomes[quantidade], "\n")] = '\0';

        printf("Insira o nome: ");
        scanf("%s", lista_nomes[quantidade]);

        float num;
        int valido = 0;

        while (!valido) {
            printf("Insira o peso(Kg): ");
            
            if (scanf("%f", &num) == 1) {
                while (getchar() != '\n') {}
                quantidade_pessoas++;
                valido = 1;
            } else {
                printf("\033[31mIdade de ser um numero inteiro!\033[m\n");
                while (getchar() != '\n') {}
            }
        }

        lista_pesos[quantidade] = num;

        if (num > maior) {
            maior = num;
            quant_maior = 0;
            lista_nome_maiores[quant_maior] = lista_nomes[quantidade];
            pos_maior[quant_maior] = quantidade;
            quant_maior++;
        } else if (num == maior) {
            lista_nome_maiores[quant_maior] = lista_nomes[quantidade];
            pos_maior[quant_maior] = quantidade;
            quant_maior++;
        }

        if (num < menor) {
            menor = num;
            quant_menor = 0;
            lista_nome_menores[quant_menor] = lista_nomes[quantidade];
            pos_menor[quant_menor] = quantidade;
            quant_menor++; 
        } else if (num == menor) {
            lista_nome_menores[quant_menor] = lista_nomes[quantidade];
            pos_menor[quant_menor] = quantidade;
            quant_menor++;
        }

        quantidade++;

        char continuar;

        while (1) {
            printf("Deseja continuar? [S/N]: ");
            scanf(" %c", &continuar);

            continuar = tolower((unsigned char)continuar);

            if (continuar == 's' || continuar == 'n') {
                while (getchar() != '\n') {}
                break;
            } else {
                printf("\033[31mOpcao invalida!\033[m\n");
                while (getchar() != '\n') {}
            }
        }

        if (continuar == 'n') {
            break;
        }

        for (int i = 0; i < 35; i++) {
            printf("\033[30m-\033[m");
        }
        printf("\n");
    }

    for (int i = 0; i < 35; i++) {
        printf("\033[30m-\033[m");
    }
    printf("\n");

    printf("\033[33m%-25s  %s\033[m\n", "Nome", "Peso(kg)");

    for (int i = 0; i < quantidade; i++) {
        printf("\033[34m%-25s ", lista_nomes[i]);

        printf("\033[32m %.1f\n", lista_pesos[i]);
    }

    for (int i = 0; i < 35; i++) {
        printf("\033[30m-\033[m");
    }

    printf("\nFoi registrado \033[33m%d\033[m pessoas!\n", quantidade_pessoas);
    
    int pesos_iguais = 0;
    float primeiro_peso = lista_pesos[0];

    for (int i = 0; i < quantidade; i++) {
        if (lista_pesos[i] != primeiro_peso) {
            pesos_iguais = 1;
            break;
        }
    }

    if (!pesos_iguais) {
        printf("\033[31mTodos os pesos sao iguais a \033[33m%.1f kg\033[31m!\033[m\n", primeiro_peso);
    } else {

        printf("O maior peso registrado foi de \033[33m%.1f kg\033[m!, de: \033[36m", maior);

        if (quant_maior == 1) {
            printf("%s!\033[m\n", lista_nome_maiores[0]);
        } else {
            for (int i = 0; i < quant_maior; i++) {
                if (i == (quant_maior - 1)) {
                    printf("e %s!\033[m\n", lista_nome_maiores[i]);
                } else {
                    printf("%s, ", lista_nome_maiores[i]);
                }
            }
        }

        printf("O menor peso registrado foi de \033[33m%.1f kg\033[m!, de: \033[36m", menor);

        if (quant_menor == 1) {
            printf("%s!\033[m\n", lista_nome_menores[0]);
        } else {
            for (int i = 0; i < quant_menor; i++) {
                if (i == (quant_menor - 1)) {
                    printf("e %s!\033[m\n", lista_nome_menores[i]);
                } else {
                    printf("%s, ", lista_nome_menores[i]);
                }
            }
        }
    }

    for (int i = 0; i < 35; i++) {
        printf("\033[30m-\033[m");
    }
    printf("\n");
    
    return 0;
}




