#include <stdio.h>

void calcularArea() {
    float largura, comprimento, area;

    printf("Insira a \033[33mlargura (m)\033[m: ");
    scanf("%f", &largura);

    printf("Insira o \033[33mcomprimento (m)\033[m: ");
    scanf("%f", &comprimento);

    area = largura * comprimento;

    printf("\033[34mA area de um terreno de \033[33m%.1fm \033[mx \033[33m%.1fm \033[34me de \033[32m%.1f m quadrados\033[34m!\033[m\n", largura, comprimento, area);

}

int main() {

    calcularArea();

    return 0;
}