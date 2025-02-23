#include <stdio.h>
#include <stdlib.h>

float dobroValor(float valor) {
    return valor * 2;
}

float metadeValor(float valor) {
    return valor / 2.0;
}

float _10Aumento(float valor) {
    return valor + (valor * (10.0/100.0));
}

void imprimirComVirgula(float valor) {
    char buffer[50];
    snprintf(buffer, sizeof(buffer), "%.2f", valor);

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '.') {
            buffer[i] = ',';
        }
    }

    printf("%s\n", buffer);
}

int main() {

    char valor[50]; 

    printf("Insira um \033[33mvalor \033[32m(R$)\033[m: ");
    fgets(valor, sizeof(valor), stdin);

    float valor_virgulado = atof(valor);

    for (int i = 0; i < 36; i++) printf("\033[30m-=\033[m");
    printf("\n");

    printf("\033[36mDobro\033[m:\033[32m R$ ");
    imprimirComVirgula(dobroValor(valor_virgulado));
    printf("\033[36mMetade\033[m:\033[32m R$ ");
    imprimirComVirgula(metadeValor(valor_virgulado));
    printf("\033[36m10%% de acrescimo\033[32m:\033[32m R$ ");
    imprimirComVirgula(_10Aumento(valor_virgulado));

    for (int i = 0; i < 36; i++) printf("\033[30m-=\033[m");
    printf("\n");

    return 0;   
}