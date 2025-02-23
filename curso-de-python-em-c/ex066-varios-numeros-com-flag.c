#include <stdio.h>

int main() {
    
    int numero, soma_numeros = 0, cont_numeros = 0;

    while (1) {
        
        printf("Insira um numero [999 para parar]: ");
        scanf("%d", &numero);

        if (numero != 999) {
            soma_numeros += numero;
            cont_numeros++;
        }

        if (numero == 999) {
            break;
        }
    }

    if (cont_numeros == 0) {
        printf("Nenhum numero foi inserido!\n");
    } else if (cont_numeros == 1) {
        printf("Foi inserido um numero e a soma e ele mesmo, %d!\n", soma_numeros);
    } else {
        printf("Foram inseridos %d numeros e a soma deles resulta em %d!\n", cont_numeros, soma_numeros);
    }

    return 0;
}