#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

void linha() {
    printf("\033[30m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n");
}

int main() {

    int quantidade = 0;
    char lista_nomes[50][50];
    int lista_gols[50][50];
    int quant_partidas[50];
    int total_gols[50] = {0};

    while (1) {

        char nome[50];

        printf("\033[36mInsira o nome do jogador\033[m: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';

        strcpy(lista_nomes[quantidade], nome);

        int quantas_partidas;
        int qp_valido = 0;

        while (!qp_valido) {
            printf("\033[35mQuantas partidas \033[36m%s \033[35mjogou?\033[m: ", nome);

            if (scanf("%d", &quantas_partidas) == 1) {
                qp_valido = 1;
                quant_partidas[quantidade] = quantas_partidas;
                while (getchar() != '\n') {}
            } else {
                printf("\033[31mQuantidade de partidas invalido!\033[m\n");
                while (getchar() != '\n') {}
            }
        }

        int tot_gols = 0;

        for (int i = 0; i < quantas_partidas; i++) {
            int gols_valido = 0;
            int gols = 0;

            while (!gols_valido) {
                printf("    \033[1;30mQuantos gols na \033[33m%da \033[1;30mpartida?\033[m: ", (i+1));
                
                if (scanf("%d", &gols) == 1) {
                    gols_valido = 1;

                    tot_gols += gols;
                    
                    lista_gols[quantidade][i] = gols;

                    while (getchar() != '\n') {}
                } else {
                    printf("\033[31mQuantidade de gols invalido!\033[m\n");
                    while (getchar() != '\n') {}
                }
            }
        }

        total_gols[quantidade] += tot_gols;

        quantidade++;

        char continuar[5];

        while (1) {
            printf("\033[33mQuer continuar? [S/N]\033[m: ");
            scanf("%s", continuar);

            for (int i = 0; continuar[i] != '\0'; i++) {
                continuar[i] = tolower((unsigned char)continuar[i]);
            }
            continuar[strcspn(continuar, "\n")] = '\0';

            if ((continuar[0] == 'n' || continuar[0] == 's') && strlen(continuar) == 1) {
                while (getchar() != '\n') {}
                break;
            } else {
                printf("\033[31mOpcao invalida!\033[m\n");
                while (getchar() != '\n') {}
            }
        }

        if (continuar[0] == 'n') {
            break;
        }

        linha();
    }

    linha();

    printf("%-5s %-20s %-25s %5s\n", "Id", "Nome", "Gols", "Total");

    for (int i = 0; i < quantidade; i++) {
        printf("%-5d %-20s [", i, lista_nomes[i]);

        for (int j = 0; j < quant_partidas[i]; j++) {
            if (j == (quant_partidas[i] - 1)) {
                printf("%d", lista_gols[i][j]);
            } else {
                printf("%d, ", lista_gols[i][j]);
            }
        }
        printf("]");

        int ajuste = 0;

        if (quant_partidas[i] > 1) {
            ajuste += (3 * (quant_partidas[i] - 1));
        }
        
        if ((total_gols[i] > 9)  && (total_gols[i] < 100)) {
            for (int j = 0; j < abs(21 - ajuste); j++) {
                printf(" ");
            }    
        } else if ((total_gols[i] > 99) && (total_gols[i] < 1000)) {
            for (int j = 0; j < abs(20 - ajuste); j++) {
                printf(" ");
            }
        } else if (total_gols[i] > 999) {
            for (int j = 0; j < abs(19 - ajuste); j++) {
                printf(" ");
            }
        } else {
            for (int j = 0; j < abs(22 - ajuste); j++) {
                printf(" ");
            }
        }
        
        printf(" %5d\n", total_gols[i]);
    }

    linha();
    
    while (1) {
        int id_jogador;
        int id_jog_valido = 0;

        while (!id_jog_valido) {
            printf("Qual jogador deseja ver ? (999 para parar): ");

            if (scanf("%d", &id_jogador) == 1) {
                id_jog_valido = 1;
                while (getchar() != '\n');
            } else {
                printf("\033[31mId invalido!\033[m\n");
                while (getchar() != '\n');
            }
        }

        if (id_jogador == 999) {
            printf("\033[33mEncerrando programa...\033[m\n");
            
            Sleep(3000);

            printf("\033[31m<< Programa encerrado! >>\033[m\n");
            break;
        }

        int existe_id = 0;

        for (int i = 0; i < quantidade; i++) {
            if (i == id_jogador) {
                existe_id = 1;
                break;
            }
        }

        linha();

        if (existe_id) {

            printf("\033[37mLevantamento do(a) jogador(a) \033[36m%s\033[37m:\n", lista_nomes[id_jogador]);

            printf("    \033[35m%-10s \033[33m%5s\033[m\n", "Partidas", "Gols");

            for (int i = 0; i < quant_partidas[id_jogador]; i++) {
                printf("    \033[31m%-10d \033[32m%5d\033[m\n", (i + 1), lista_gols[id_jogador][i]);
            }

            linha();

            Sleep(3000);
        } else {
            printf("\033[31mId de jogador nao encontrado!\033[m\n");

            linha();

            Sleep(1000);
        }
    }

    return 0;
}