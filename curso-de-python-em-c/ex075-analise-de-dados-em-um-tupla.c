#include <stdio.h>

int main() {

    int n1, n2, n3, n4;
    int x9 = 0;
    int _3p = -1;
    int pares = 0;

    printf("Insira um numero: ");
    scanf("%d", &n1);

    printf("Insira outro numero: ");
    scanf("%d", &n2);

    printf("Insira mais um numero: ");
    scanf("%d", &n3);

    printf("Insira um ultimo numero: ");
    scanf("%d", &n4);

    int numeros[4] = {n1, n2, n3, n4};

    printf("Voce digitou os numeros: (");
    for (int i = 0; i < 4; i++) {
        if (i == 3) {
            printf("%d)\n",  numeros[i]);
        } else {
            printf("%d ", numeros[i]);
        }

        if (numeros[i] == 9) {
            x9++;
        }

        if ((numeros[i] == 3) && (_3p == -1)) {
            _3p = i;
        }

        if (numeros[i] % 2 == 0) {
            pares++;
        }
    }

    if (x9 == 0) {
        printf("O numero 9 nao apareceu!\n");
    } else if (x9 == 1) {
        printf("O numero 9 apareceu %d vez!\n", x9);
    } else {
        printf("O numero 9 apareceu %d vezes!\n", x9);
    }
    
    if (_3p != -1) {
        printf("O numero 3 aparece na %da posicao!\n", (_3p + 1));
    } else {
        printf("O numero 3 nao apareceu!\n");
    }
    
    if (pares == 0) {
        printf("Nenhum numero par apareceu!\n");
    } else if (pares == 1) {
        printf("Foi digitado %d numero par!\n", pares);
    } else {
        printf("Foram digitados %d numeros pares!\n", pares);
    }
    

    return 0;
}