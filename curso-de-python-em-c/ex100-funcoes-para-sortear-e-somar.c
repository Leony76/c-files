#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int sorteio(int lista[]) {

   int sorteio;
   int repetido;

   do {
        repetido = 0;
        sorteio = (rand() % 99) + 1;
        
        for (int i = 0; i < 10; i++) {
            if (lista[i] == sorteio) {
                repetido = 1;
                break;
            }
        }
    } while (repetido);

   return sorteio;
}

int somaPar(int lista[]) {

    int soma = 0;

    for (int i = 0; i < 10; i++) {
        if (lista[i] % 2 == 0) {
            soma += lista[i];
        }
    }

    return soma;
}

int main() {

    int lista[10] = {};

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        lista[i] = sorteio(lista);
    }

    for (int i = 0; i < 36; i++) printf("\033[30m-=\033[m"); 

    printf("\n\033[33m10 numeros \033[34msorteados \033[33maleatoriamente\033[34m: \n");
    printf("\033[35m[");

    for (int i = 0; i < 10; i++) {
        if (i == 9) {
            printf("\033[32m%d\033[35m]\033[m\n", lista[i]);
        } else {
            printf("\033[32m%d\033[35m,\033[m ", lista[i]);
        }
        Sleep(500);
    }

    printf("\033[34mA \033[33msoma \033[34mdos \033[33mnumeros pares \033[34mresulta em \033[32m%d\033[34m!\033[m\n", somaPar(lista));

    for (int i = 0; i < 36; i++) printf("\033[30m-=\033[m");
    printf("\n");

    return 0;
}