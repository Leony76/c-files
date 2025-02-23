#include <stdio.h>

int main() {

    float largura,altura,area,litros;

    printf("Largura da parede: ");
    scanf("%f", &largura);

    printf("Altura da parede: ");
    scanf("%f", &altura);

    area = largura * altura;
    litros = area / 2;

    printf("Com uma casa de %.2fx%.2fm de altura, temos %.2fm quadrados de area!\n", largura, altura, area);
    printf("Com isso, sao necessarios %.2fl de tinta para pinta-la!\n", litros);

    return 0;
}