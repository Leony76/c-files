#include <stdio.h>

int main() {

    float valor_casa, salario, prestacao_mensal, _30_salario;
    int anos_emprestimo;

    printf("Insira o valor da casa: ");
    scanf("%f", &valor_casa);
    fflush(stdout);

    printf("Insira o salario: ");
    scanf("%f", &salario);
    fflush(stdout);

    printf("Insira quantos anos de emprestimo: ");
    scanf("%d", &anos_emprestimo);
    fflush(stdout);

    prestacao_mensal = valor_casa / (anos_emprestimo * 12.0);
    _30_salario = salario * (30.0/100.0);

    printf("Para pagar uma casa custando R$%.2f por %d anos, pagara R$%.2f por mes: ", valor_casa, anos_emprestimo, prestacao_mensal);
    if (_30_salario >= prestacao_mensal) {
        printf("EMPRESTIMO ACEITO!");
    } else {
        printf("EMPRESTIMO RECUSADO!");
    }

    return 0;
}