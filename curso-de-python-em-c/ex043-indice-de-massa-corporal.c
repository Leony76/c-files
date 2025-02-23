#include <stdio.h>
#include <math.h>

int main() {

    float peso, altura, imc;

    for (int i = 0; i < 4; i++) {
        printf("Insira seu peso: ");
        scanf("%f", &peso);
        fflush(stdout);

        printf("Insira sua altura: ");
        scanf("%f", &altura);
        fflush(stdout);

        imc = peso / pow(altura, 2.0);

        printf("Com IMC de %.1f, voce esta ", imc);
        if (imc < 18.5) {
            printf("ABAIXO DO PESO!\n");
        } else if (imc < 25) {
            printf("com PESO IDEAL!\n");
        } else if (imc < 30) {
            printf("com SOBREPESO!\n");
        } else if (imc < 40) {
            printf("com OBESIDADE!\n");
        } else {
            printf("com OBESIDADE MORBIDA!\n");
        }
    }

    return 0;
}