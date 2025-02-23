#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void titulo() {
    printf("\033[35m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n");
    printf("\033[32m                    PALPITES DA MEGA SENA                         \033[m\n");
    printf("\033[35m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n");
}

void ordenamento(int lista[], int quantidade) {
    int i, j, temp;

    for (i = 0; i < (quantidade - 1); i++) {
        for (j = 0; j < quantidade - 1 - i; j++) {
            if (lista[j] < lista[j + 1]) {
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

int main() {

    titulo();

    int quantos_jogos;
    int n_sorteio = 1;

    srand(time(NULL));

    printf("Quantos jogos voce quer que seja sorteado?: ");
    scanf("%d", &quantos_jogos);

    printf("\033[33m--------------------=<< \033[32mSORTEANDO %d JOGOS \033[33m>>=--------------------\033[m\n", quantos_jogos);

    for (int k = 0; k < quantos_jogos; k++) {

        int lista[6]; 
        int numero_sorteado, i = 0;

        while (i < 6) {
            numero_sorteado = rand() % 60;

            int ja_sorteado = 0;

            for (int j = 0; j < i; j++) {
                if (lista[j] == numero_sorteado) {
                    ja_sorteado = 1;
                    break;
                }
            }

            if (!ja_sorteado) {
                lista[i] = numero_sorteado;
                i++;
            }
        }

        ordenamento(lista, 6);
        
        printf("\033[31mSorteio %d: \033[36m[", n_sorteio);
        for (int i = 5; i >= 0; i--) {
            if (i == 0) {
                printf("%d]\033[m\n", lista[i]);
            } else {
                printf("%d, ", lista[i]);
            }
        }
        
        Sleep(1000);

        n_sorteio++;
    }

    printf("\033[33m--------------------=<< \033[35mFACAM SUAS APOSTAS!\033[33m >>=--------------------\033[m\n");

    return 0;
}