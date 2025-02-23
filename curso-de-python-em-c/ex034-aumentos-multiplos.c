#include <stdio.h>

int main() {

    float salario;

    printf("Insira qual o salario: ");
    scanf("%f", &salario);

    if (salario > 1250.00) {
        float aumento = salario + (salario * (10.0/100.0));
        printf("O novo salario sera de R$%.2f, com 10%% de aumento!\n", aumento);
    } else {
        float aumento = salario + (salario * (15.0/100.0));
        printf("O novo salario sera de R$%.2f, com 15%% de aumento!\n", aumento);
    }

    return 0;
}