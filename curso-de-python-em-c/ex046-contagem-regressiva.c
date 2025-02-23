#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

int main() {

    int contagem = 10;

    while (contagem >= 0) {
        printf("%d\n", contagem);
        Sleep(500);
        contagem--;
    }

    printf("CABO'SS...\n");

    return 0;
}