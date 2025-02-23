#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int numero, sorteio;

    printf("\033[1;33m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\033[1;36mDirei um numero entre 0 e 5, consegue advinhar?\n");
    printf("\033[1;33m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    scanf("%d", &numero);

    srand(time(NULL));

    sorteio = rand() % 6;

    printf("\033[1;34mO numero sorteado foi \033[1;32m%d\033[1;34m, e voce chutou \033[1;33m%d\033[1;34m, logo voce... ", sorteio, numero);
    
    if (numero == sorteio) {
        printf("\033[1;32MGANHOU !!!, PARABENS!\033[m\n");
    } else {
        printf("\033[1;31mPERDEU!!!, MEUS PESAMES!\033[m\n");
    }

    return 0;
}