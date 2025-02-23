#include <stdio.h>
#include <string.h>

int main() {

    char nome_jogador[50];
    int quantidade_partidas;
    int total_gols = 0;
    int lista_partida_gols[50][1];

    printf("Insira o \033[33mnome\033[m do jogador de futebol\033[36m: ");
    fgets(nome_jogador, sizeof(nome_jogador), stdin);
    nome_jogador[strcspn(nome_jogador, "\n")] = '\0';

    int quant_part_valido = 0;

    while (!quant_part_valido) {
        printf("\033[33mQuantas partidas \033[36m%s \033[mjogou?\033[35m: ", nome_jogador);

        if (scanf("%d", &quantidade_partidas) == 1) {
            quant_part_valido = 1;
            while (getchar() != '\n') {}
        } else {
            printf("\033[31mQuantidade invalida!\033[m\n");
            while (getchar() != '\n') {}
        }
    }

    printf("\n");

    for (int i = 0; i < quantidade_partidas; i++) {
        
        int gols;
        int gols_valido = 0;

        while (!gols_valido) {

            printf("    \033[33mQuantos gols \033[mna partida \033[33m%d\033[m?\033[32m: ", (i+1));
            
            if (scanf("%d", &gols) == 1) {
                gols_valido = 1;
                while (getchar() != '\n') {}
            } else {
                printf("    \033[31mQuantidade de gols invalido!\033[m\n");
                while (getchar() != '\n') {}
            }
        }

        total_gols += gols;
        lista_partida_gols[i][0] = gols;
    }

    printf("\033[30m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n");

    printf("\033[34mNome do jogador\033[m:\033[36m %s\n", nome_jogador);
    printf("\033[34mGols\033[m: \033[35m[");

    for (int i = 0; i < quantidade_partidas; i++) {
        if (i == (quantidade_partidas - 1)) {
            printf("\033[32m%d\033[35m]\n", lista_partida_gols[i][0]);
        } else {
            printf("\033[32m%d\033[35m, ", lista_partida_gols[i][0]);
        }
    }

    printf("\033[34mTotal\033[m: \033[32m%d\n", total_gols);

    printf("\033[30m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n");

    printf("O jogador \033[36m%s \033[mjogou \033[35m%d \033[mpartidas!\n\n", nome_jogador, quantidade_partidas);

    for (int i = 0; i < quantidade_partidas; i++) {
        printf("    \033[31m=> \033[34mNa partida \033[33m%d\033[34m, fez \033[32m%d gols\033[34m.\n", (i + 1), lista_partida_gols[i][0]);
    }

    printf("\n\033[mFoi um total de \033[32m%d \033[mgols!\n", total_gols);

    printf("\033[30m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n");

    return 0;
}