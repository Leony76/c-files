#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void contador(int inicio, int fim, int passo) {

    if (inicio < fim) {
        printf("\033[35m[\033[m");
        for (int i = inicio; i <= fim; i += passo) {
            if (i == fim) {
                printf("\033[32m%d\033[35m]\033[m\n", i);
            } else {
                printf("\033[32m%d\033[35m,\033[m ", i);
            }
            Sleep(500);
        }
    } else if (inicio > fim) {
        printf("\033[35m[\033[m");
        for (int i = inicio; i >= fim; i -= passo) {
            if (i == fim) {
                printf("\033[32m%d\033[35m]\033[m\n", i);
            } else {
                printf("\033[32m%d\033[35m,\033[m ", i);
            }
            Sleep(500);
        }
    } 
}

int main() {

    printf("\033[34mContando de \033[32m0 \033[34ma \033[32m10 \033[34mde \033[31m2 \033[34mem \033[31m2\033[m:\n");

    printf("\033[35m[\033[m");

    for (int i = 0; i < 11; i += 2) {
        if (i == 10) {
            printf("\033[32m%d\033[35m]\033[m\n", i);
        } else {
            printf("\033[32m%d\033[35m,\033[m ", i);
        }
        Sleep(500);
    }

    printf("\033[34mContando de \033[32m10 \033[34ma \033[32m0 \033[34mde \033[31m2 \033[34mem \033[31m2\033[34m:\033[m\n");

    printf("\033[35m[\033[m");

    for (int i = 10; i >= 0; i -= 2) {
        if (i == 0) {
            printf("\033[32m%d\033[35m]\033[m\n", i);
        } else {
            printf("\033[32m%d\033[35m,\033[m ", i);
        }
        Sleep(500);
    }
    
    int p_partida, p_chegada, q_passo;

    printf("<<< \033[33mAgora e sua vez de escolher\033[m >>>\n");

    int valido = 0;

    while (!valido) {

        printf("Qual \033[33mponto de partida?\033[m: ");

        if (scanf("%d", &p_partida) == 1) {
            valido = 1;
            while (getchar() != '\n') {

            }
        } else {
            printf("\033[31mPonto de partida invalido!\033[m\n");
            while (getchar() != '\n') {

            }
        }   
    }
    
    valido = 0;

    while (!valido) {

        printf("Qual \033[33mponto de chegada?\033[m: ");

        if (scanf("%d", &p_chegada) == 1) {
            valido = 1;
            while (getchar() != '\n') {

            }
        } else {
            printf("\033[31mPonto de chegado invalido!\033[m\n");
            while (getchar() != '\n') {

            }
        }
    }

    if (p_chegada == p_partida) {
        printf("\033[31mO ponto de partida e chegado sao o mesmo numero!\033[m\n");

        return 0;
    }

    valido = 0;

    while (!valido) {

        printf("Qual \033[33mpasso?\033[m: ");

        if (scanf("%d", &q_passo) == 1) {
            valido = 1;
            q_passo = abs(q_passo);
            while (getchar() != '\n') {

            }
        } else {
            printf("\033[31mPasso invalido!\033[m\n");
            while (getchar() != '\n') {

            }
        }
        
    
    }

    contador(p_partida, p_chegada, q_passo);

    return 0;
}