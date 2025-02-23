#include <stdio.h>

int main() {

    int pos = 0;
    int matriz[9];
    

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Insira o elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[pos]);
            pos++;
        }
    }

    for (int i = 0; i < 9; i++) { 
        printf("[ %d ]    ", matriz[i]);
        if ((i + 1) % 3 == 0) {
            printf("\n");
        }
    }

    return 0;
}