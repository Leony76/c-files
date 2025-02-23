#include <stdio.h>
#include <stdlib.h>

void formatandoMoedas() {

    char valor[50];

    printf("\033[33mInsira um valor \033[32m(R$)\033[m: ");
    fgets(valor, sizeof(valor), stdin);

    float valor_float = atof(valor);
    
    float valorDobrado = valor_float * 2;
    float valorMetade = valor_float / 2.0;
    float valor_10amais = valor_float + (valor_float * (0.10));

    char valor_virgulado[50];

    snprintf(valor_virgulado, sizeof(valor_virgulado), "%.2f", valorDobrado);

    for (int i = 0; valor_virgulado[i] != '\0'; i++) {
        if (valor_virgulado[i] == '.') {
            valor_virgulado[i] = ',';
        }
    }

    for (int i = 0; i < 36; i++) printf("\033[30m-=\033[m");
    printf("\n");

    printf("\033[36mDobro\033[m:\033[32m R$ %s\n", valor_virgulado);

    snprintf(valor_virgulado, sizeof(valor_virgulado), "%.2f", valorMetade);

    for (int i = 0; valor_virgulado[i] != '\0'; i++) {
        if (valor_virgulado[i] == '.') {
            valor_virgulado[i] = ',';
        }
    }

    printf("\033[36mMetade\033[m:\033[32m R$ %s\n", valor_virgulado);

    snprintf(valor_virgulado, sizeof(valor_virgulado), "%.2f", valor_10amais);

    for (int i = 0; valor_virgulado[i] != '\0'; i++) {
        if (valor_virgulado[i] == '.') {
            valor_virgulado[i] = ',';
        }
    }

    printf("\033[36m10%% acrescimo\033[m:\033[32m R$ %s\n", valor_virgulado);

    for (int i = 0; i < 36; i++) printf("\033[30m-=\033[m");
    printf("\n");

}

int main() {

    formatandoMoedas();

    return 0;
}