#include <stdio.h>
#include <stdlib.h>

void valorComVirgula(float valor) {
    char buffer[50];

    snprintf(buffer, sizeof(buffer), "%.2f", valor);

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '.') {
            buffer[i] = ',';
        }
    }

    printf("%s", buffer);

}

int main() {

    char valor[50];
    int valido = 0;

    while (!valido) {

        printf("Insira um valor \033[32m(R$)\033[m: ");
        fgets(valor, sizeof(valor), stdin);

        for (int i = 0; valor[i] != '\0'; i++) {
            if (valor[i] == '.') {
                valor[i] = ',';
            }
        }

        float valor_float = atof(valor);

        if (valor_float > 0) {
            valido = 1;
        } else {
            printf("\033[31mValor invalido!\033[m\n");
        }
    }

    float valor_float = atof(valor);

    float dobro_valor = valor_float * 2;
    float metade_valor = valor_float / 2.0;
    float aumento_35 = valor_float + (valor_float * (0.35));
    float reducao_25 = valor_float - (valor_float * (0.25));
    
    printf("\033[35m---------------------------------------\n");
    printf("\033[36m            RESUMO DO VALOR            \n");
    printf("\033[35m---------------------------------------\n");

    printf("\033[33mPreco analisado\033[m:               \033[32mR$ ");
    valorComVirgula(valor_float);

    printf("\n\033[33mDobro do valor\033[m:               \033[32m R$ ");
    valorComVirgula(dobro_valor);

    printf("\n\033[33mMetade do valor\033[m:               \033[32mR$ ");
    valorComVirgula(metade_valor);

    printf("\n\033[33m35%% acrescimo\033[m:               \033[32m  R$ ");
    valorComVirgula(aumento_35);

    printf("\n\033[33m25%% decrescimo\033[m:               \033[32m R$ ");
    valorComVirgula(reducao_25);

    printf("\n\033[35m---------------------------------------\033[m\n");

    return 0;
}