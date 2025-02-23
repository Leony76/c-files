#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char sexo[2];

    while (1) {
    
        printf("Insira um sexo [M/F]: ");
        scanf("%s", sexo);

        for (int i = 0; sexo[i] != '\0'; i++) {
            sexo[i] = tolower((unsigned char)sexo[i]);
        }

        if ((strcmp(sexo, "f") == 0) || (strcmp(sexo, "m") == 0)) {
            break;
        } else {
            printf("\033[1;31mOPCAO INVALIDA!\033[m\n");
        }
    }

    return 0;
}