#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    int sorteio;
    int palpite;
    int tentativas = 1;

    srand(time(NULL));

    sorteio = rand() % 11;

    printf("Pensei em um numero entre 0 e 10, consegue advinhar qual?:\n");

    while (1) {

        scanf("%d", &palpite);

        if (palpite == sorteio) {
            printf("Parabens, voce acertou com %d tentativas!\n", tentativas);
            break;
        } else {
            if (palpite > sorteio) {
                printf("Menos... Tente novamente!\n");
            } else {
                printf("Mais... Tente novamente!\n");
            }
            tentativas++;
        }
    }

    return 0;
}