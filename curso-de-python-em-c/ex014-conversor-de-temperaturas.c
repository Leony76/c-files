#include <stdio.h>

int main() {

    float temperatura, graus_f;

    printf("Insira uma temperatura para ser convertida em graus farenheit: ");
    scanf("%f", &temperatura);

    graus_f = ((9.0/5.0) * temperatura) + 32.0;

    printf("%.1f graus celsius em graus fahrenheit equivale a %.1f !", temperatura, graus_f);

    return 0;
}