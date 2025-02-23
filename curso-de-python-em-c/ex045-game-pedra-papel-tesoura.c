#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    int escolha, escolha_comp;

    for (int i = 0; i < 5; i++) {

        printf("Opcoes:\n");
        printf("[ 1 ] Pedra\n");
        printf("[ 2 ] Papel\n");
        printf("[ 3 ] Tesoura\n");

        printf("Qual sua opcao?: ");
        scanf("%d", &escolha);

        srand(time(NULL));

        escolha_comp = rand() % 3;
        
        // PEDRA
        if (escolha_comp == 0) {
            if (escolha == 1) {
                printf("Voce escolheu PEDRA e o computador PEDRA: EMPATE!\n");
            } else if (escolha == 2) {
                printf("Voce escolheu PAPEL e o computador PEDRA: VOCE GANHOU!\n");
            } else if (escolha == 3) {
                printf("Voce escolheu TESOURA e o computador PEDRA: VOCE PERDEU!\n");
            } else {
                printf("\033[1;31mOPCAO INVALIDA!\033[m\n");
            }
        } else if (escolha_comp == 1) { // PAPEL
            if (escolha == 1) {
                printf("Voce escolheu PEDRA e o computador PAPEL: VOCE PERDEU!\n");
            } else if (escolha == 2) {
                printf("Voce escolheu PAPEL e o computador PAPEL: EMPATE!\n");
            } else if (escolha == 3) {
                printf("Voce escolheu TESOURA e o computador PAPEL: VOCE GANHOU!\n");
            } else {
                printf("\033[1;31mOPCAO INVALIDA!\033[m\n");
            }
        } else { // TESOURA
            if (escolha == 1) {
                printf("Voce escolheu PEDRA e o computador TESOURA: VOCE GANHOU!\n");
            } else if (escolha == 2) {
                printf("Voce escolheu PAPEL e o computador TESOURA: VOCE PERDEU!\n");
            } else if (escolha == 3) {
                printf("Voce esoclheu TESOURA e o computador TESOURA: EMPATE!\n");
            } else {
                printf("\033[1;31mOPCAO INVALIDA!\033[m\n");
            }
        }
    }

    return 0;
}