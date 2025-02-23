#include <stdio.h>

int main() {

    int numero;
    int quantidade = 0;
    int e_div = 0;

    printf("Insira um numero: ");
    scanf("%d", &numero);
    fflush(stdout);

    printf("O numero \033[1;32m%d\033[m e divisivel por: \n", numero);
    
    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            printf("\033[1;32m%d\033[m ", i);
            e_div++;
            quantidade++;
        } else {
            printf("\033[1;31m%d\033[m ", i);
        }
    }

    printf("\nSendo divisivel por \033[1;33m%d\033[m numeros, ele ", quantidade);

    if (e_div == 2) {
        printf("\033[1;32mE PRIMO!\033[m\n");
    } else {
        printf("\033[1;31mNAO E PRIMO!\033[m\n");
    }

    return 0;
}