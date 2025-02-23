#include <stdio.h>

int main() {

    int pares = 0;

    while (pares <= 50) {
        if (pares % 2 == 0) {
            printf("%d - ", pares);
        }
        pares++;
    }

    printf("FIM!\n");

    return 0;
}