#include <stdio.h>

int main() {

    int tabuada, cont_tabuada = 10, n = 1;

    while (1) {

        printf("Qual tabuada voce deseja ver? [-(X) para parar]: ");
        scanf("%d", &tabuada);

        if (tabuada < 0) {
            break;
        }

        cont_tabuada = 10;
        n = 1;

        while (cont_tabuada > 0) {
            printf("%d x %d = %d\n", tabuada, n, (tabuada * n));
            cont_tabuada--;
            n++;
        }
    }
    

    return 0;
}