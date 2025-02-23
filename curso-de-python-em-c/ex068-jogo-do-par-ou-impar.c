#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main() {

    int valor_jogador, valor_computador, escolha_computador, jogos_ganhos = 0;
    char escolha[10];

    srand(time(NULL));

    while (1) {

        printf("\n\033[1;35m------------- \033[1;36mJogo do Par ou Impar \033[1;35m-------------\n");
        printf("\033[1;30mInsira um valor\033[1;32m: ");
        scanf("%d", &valor_jogador);

        printf("\033[1;30mPar ou Impar?\033[1;32m: ");
        scanf("%s", escolha);

        for (int i = 0; escolha[i] != '\0'; i++) {
            escolha[i] = tolower((unsigned char)escolha[i]); 
        }
        escolha[strcspn(escolha, "\n")] = '\0';

        valor_computador = rand() % 11;

        if (strcmp(escolha, "par") == 0) {
            escolha_computador = 1;
        } else {
            escolha_computador = 0;
        }

        printf("\033[1;35m---------------------------------------------------------\n");
        printf("\033[1;34mVoce escolheu \033[1;32m%s \033[1;34me o computador ", escolha);
        if (escolha_computador == 0) {
            printf("\033[1;32mpar\033[1;34m, ");
        } else {
            printf("\033[1;32mimpar\033[1;34m, ");
        }

        printf("e a soma dos numeros que voce escolheu \033[1;32m(%d) \033[1;34me que o computador escolheu \033[1;32m(%d) \033[1;34mresulta em \033[1;33m%d\033[1;34m, logo voce ",valor_jogador ,valor_computador , (valor_computador + valor_jogador));
        
        if ((escolha_computador == 0) && (strcmp(escolha, "impar") == 0)) {
            if ((valor_computador + valor_jogador) % 2 == 0) {
                printf("\033[1;31mPERDEU, GAME OVER!\033[1;35m\n");
                printf("---------------------------------------------------------\033[m\n");
                break;
            } else {
                printf("\033[1;32mGANHOU, parabens!\033[1;37m\n\n");
                jogos_ganhos++;
                printf("Jogos ganhos\033[1;33m: %d\033[1;35m\n", jogos_ganhos);
                printf("---------------------------------------------------------\033[m\n");
            }
        } else if ((escolha_computador == 1) && (strcmp(escolha, "par") == 0)) {
            if ((valor_computador + valor_jogador) % 2 == 0) {
                printf("\033[1;32mGANHOU, parabens!\033[1;37m\n\n");
                jogos_ganhos++;
                printf("Jogos ganhos\033[1;33m: %d\033[1;35m\n", jogos_ganhos);
                printf("---------------------------------------------------------\033[m\n");
            } else {
                printf("\033[1;31mPERDEU, GAME OVER!\033[1;35m\n");
                printf("---------------------------------------------------------\033[m\n");
                break;
            }
        }
    }

    if (jogos_ganhos == 0) {
        printf("\033[1;31mInfelizmente voce nao ganhou nenhuma partida seguida!\033[m\n");
    } else {
        printf("\033[1;34mVoce ganhou \033[1;33m%d \033[1;34mpartidas seguidas!\033[m\n", jogos_ganhos);
    }

    return 0;
}