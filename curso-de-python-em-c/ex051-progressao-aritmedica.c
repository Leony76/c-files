#include <stdio.h>

int main() {

    int p_termo, razao, n_termos;

    printf("---------- n termos de uma PA ----------\n");
    
    printf("Quantos termos?: ");
    scanf("%d", &n_termos);
    fflush(stdout);

    printf("Primeiro termo: ");
    scanf("%d", &p_termo);
    fflush(stdout);

    printf("Razao: ");
    scanf("%d", &razao);
    fflush(stdout);

    for (int i = 0; i < n_termos; i++) {
        printf("%d - ", p_termo);
        p_termo += razao;
    }

    printf("FIM!\n");

    return 0;
}