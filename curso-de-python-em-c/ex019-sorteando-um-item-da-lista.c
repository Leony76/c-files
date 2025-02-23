#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    char nomes[5][50];

    srand(time(NULL));

    int escolha = rand() % 5;

    for (int i = 0; i < 5; i++) {
        printf("Nome %d: ", i+1);
        scanf("%49s", nomes[i]);
    }
    printf("Os nomes comentados foram: \n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", nomes[i]);
    }
    printf("O nome escolhido entre os 5 foi: %s\n", nomes[escolha]);



    return 0;
}