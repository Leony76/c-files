#include <stdio.h>
#include <windows.h>
#include <limits.h>

void maior(int n1, int n2, int n3, int n4, int n5, int n6, int n7) {

    int maior = INT_MIN;
    int pos_maior;
    int numeros[7] = {n1, n2, n3, n4, n5, n6, n7}; 
    
    for (int i = 0; i < 36; i++) {
        printf("\033[30m-=\033[m");
    } 

    printf("\n\033[35m[");

    for (int i = 0; i < 7; i++) {

        if (numeros[i] > maior) {
            maior = numeros[i];
            pos_maior = (i + 1);
        }

        if (i == 6) {
            printf("\033[32m%d\033[35m]\033[m\n", numeros[i]);
        } else {
            printf("\033[32m%d\033[35m,\033[m ", numeros[i]);
        }

        Sleep(500);
    }

    printf("\033[34mO maior numero listado foi \033[33m%d\033[34m, na posicao \033[32m%d\033[34m!\033[m\n", maior, pos_maior);

    for (int i = 0; i < 36; i++) {
        printf("\033[30m-=\033[m");
    }
    
    printf("\n");
}

int main() {

    maior(3, 4, 10, 38, 9, 0, 7);
    maior(4, 1, 4, 8, 12, 0, 3);
    maior(73, 83, 93, 03, 33, 23, 2);

    return 0;
}







