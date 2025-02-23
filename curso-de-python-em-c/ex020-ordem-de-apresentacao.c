#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    char nomes[5][50];

    srand(time(NULL));

    for (int i=0; i<5; i++) {
        printf("Nome %d: ", i+1);
        scanf("%49s\n", nomes[i]);
    }

    for (int i = 4; i > 0; i--) {
        // Gera um índice aleatório entre 0 e i
        int j = rand() % (i + 1);

        // Troca os nomes em nomes[i] e nomes[j]
        char temp[50];
        snprintf(temp, sizeof(temp), "%s", nomes[i]);
        snprintf(nomes[i], sizeof(nomes[i]), "%s", nomes[j]);
        snprintf(nomes[j], sizeof(nomes[j]), "%s", temp);
    }

    printf("\nNomes embaralhados:\n");
    for (int i = 0; i < 5; i++) {
        printf("Nome %d: %s\n", i+1, nomes[i]);
    }

    return 0;
}