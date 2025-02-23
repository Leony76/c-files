#include <stdio.h>
#include <math.h>

int main() {

    float c_oposto, c_adjacente, hipo;

    printf("Insira o cateto oposto: ");
    scanf("%f", &c_oposto);

    printf("Insira o cateto adjeacente: ");
    scanf("%f", &c_adjacente);

    hipo = hypot(c_oposto, c_adjacente);

    printf("Com %.2f como cateto oposto e %.2f como cateto adjacente, temos %.2f como hipotenusa!", c_oposto, c_adjacente, hipo);   

    return 0;
}