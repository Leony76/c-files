#include <stdio.h>
#include <math.h>

int main() {

    float angulo, a_radius ,sen, coss, tang;

    printf("Digite um angulo: ");
    scanf("%f", &angulo);

    a_radius = angulo * (3.1415/180.0);

    sen = sin(a_radius);
    coss = cos(a_radius);
    tang = tan(a_radius);

    printf("O angulo de %.1f equivale a:\n", angulo);
    printf("Seno: %.2f\n", sen);
    printf("Cosseno: %.2f\n", coss);
    printf("Tangente: %.2f\n", tang);

    return 0;
}