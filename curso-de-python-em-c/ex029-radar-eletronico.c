#include <stdio.h>

int main() {

    int velocidade;

    printf("\033[1;37mInsira qual a velocidade do veiculo em km/s\033[1;32m: ");
    scanf("%d", &velocidade);

    printf("\033[1;34mSua velocidade foi de \033[1;33m%dkm/s...", velocidade);
    if (velocidade > 80) {
        float multa;
        multa = (velocidade - 80.0) * 7.0;
        printf("\033[1;31mVoce sera multado por \033[1;32mR$%.2f \033[1;31mpor ter passado \033[1;33m%d kms \033[1;31macima do limite!\033[m\n", multa, (velocidade - 80));
    } else {
        printf("\033[1;32mPode continuar sem problemas!\033[m\n");
    }

    return 0;
}