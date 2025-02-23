#include <stdio.h>

int main() {

    long long int quantos, t1, t2, t3, cont;

    printf("Quantos termos da sequencia deseja ver?: ");
    scanf("%lld", &quantos);

    t1 = 0;
    t2 = 1;

    printf("\033[1;32m%lld \033[1;33m-> \033[1;32m%lld", t1, t2);

    cont = 3;

    while (cont <= quantos) {
        t3 = t1 + t2;

        printf(" \033[1;33m-> \033[1;32m%lld", t3);

        t1 = t2;
        t2 = t3;

        cont++;
    }

    printf("\033[m");

    return 0;
}