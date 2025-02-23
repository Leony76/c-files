#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void ordenagem(int lista[][2], int quantidade) {
    int temp_valor, temp_jogador;

    for (int i = 0; i < quantidade - 1; i++) {
        for(int j = 0; j < quantidade - 1 - i; j++) {
            if (lista[j][1] < lista[j + 1][1]) {

                temp_valor = lista[j][1];
                lista[j][1] = lista[j + 1][1];
                lista[j + 1][1] = temp_valor;

                temp_jogador = lista[j][0];
                lista[j][0] = lista[j + 1][0];
                lista[j + 1][0] = temp_jogador;
            }
        }
    }
}

int main() {

    int jogadores[4][2];

    srand(time(NULL));

    printf("\033[30m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n");

    for (int i = 0; i < 4; i++) {
        int sorteio;

        sorteio = (rand() % 6) + 1;

        jogadores[i][0] = (i+1);
        jogadores[i][1] = sorteio;

        printf("\033[36mJogador \033[33m%d \033[36mtirou \033[32m%d\033[36m!\033[m\n", i+1, sorteio);
        Sleep(1000);
    }

    printf("\033[30m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n");

    ordenagem(jogadores, 4);

    printf("\033[31m<><>=={ \033[35mRANKING DOS JOGADORES \033[31m}==<><>\033[m\n\n");

    for (int i = 0; i < 4; i++) {
        printf("\033[33m%do Lugar \033[m= \033[36mJogador %d\033[m: \033[32m%d\033[m!\n", (i + 1), jogadores[i][0], jogadores[i][1]);
        Sleep(1000);
    }

    printf("\033[30m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n");

    return 0;
}