#include <stdio.h>

int main() {

    int tabuada;

    printf("Qual tabuada deseja ver?: ");
    scanf("%d", &tabuada);
    fflush(stdout);

    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", tabuada, i, (tabuada * i));
    }

    return 0;
}