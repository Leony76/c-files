#include <stdio.h>
#include <stdlib.h>

int main() {

    char valor[50];

    printf("Insira um valor (R$): ");
    fgets(valor, sizeof(valor), stdin);

    float valor_float = atof(valor);

    float dobroValor = valor_float * 2;
    float metadeValor = valor_float / 2.0;
    float _10Aumento = valor_float + (valor_float * (10.0/100.0));

    char valor_virgulado[50];

    for (int i = 0; i < 36; i++) printf("\033[30m-=\033[m");
    printf("\n");

    snprintf(valor_virgulado, sizeof(valor_virgulado), "%.2f", dobroValor);
    
    for (int i = 0; valor_virgulado[i] != '\0'; i++) {
        if (valor_virgulado[i] == '.') {
            valor_virgulado[i] = ',';
        }
    }

    printf("\033[36mDobro\033[m: \033[32mR$ %s\n", valor_virgulado);

    snprintf(valor_virgulado, sizeof(valor_virgulado), "%.2f", metadeValor);

    for (int i = 0; valor_virgulado[i] != '\0'; i++) {
        if (valor_virgulado[i] == '.') {
            valor_virgulado[i] = ',';
        }
    }

    printf("\033[36mMetade\033[m: \033[32mR$ %s\n", valor_virgulado);

    snprintf(valor_virgulado, sizeof(valor_virgulado), "%.2f", _10Aumento);

    for (int i = 0; valor_virgulado[i] != '\0'; i++) {
        if (valor_virgulado[i] == '.') {
            valor_virgulado[i] = ',';
        }
    }

    printf("\033[36m10%% acrescimo\033[m: \033[32mR$ %s\n", valor_virgulado);

    for (int i = 0; i < 36; i++) printf("\033[30m-=\033[m");
    printf("\n");

    return 0;
}