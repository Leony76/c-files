#include <stdio.h>

int main() {

    float salario, aumento;

    printf("Insira qual o salario do funcionario: R$");
    scanf("%f", &salario);

    aumento = salario + (salario * (15.0/100.0));

    printf("O salario do funcionario de R$%.2f agora passara a valer R$%.2f pelo aumento de 15%% !", salario, aumento);

    return 0;
}