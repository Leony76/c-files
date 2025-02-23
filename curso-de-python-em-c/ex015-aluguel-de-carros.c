#include <stdio.h>

int main() {

    int dias, dias_rodados;
    float kms, kms_rodados, total;

    printf("Quantos km rodados?: ");
    scanf("%f", &kms);

    printf("Quantos dias usados?: ");
    scanf("%d", &dias);

    dias_rodados = dias * 60;
    kms_rodados = kms * 0.15;
    total = dias_rodados + kms_rodados;

    printf("Com %d dias usados e %.2f kms rodados, sera pago R$%.2f no total!", dias, kms, total);

    return 0;
}