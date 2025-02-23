#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    char nome[50];

    printf("Insira um nome que comece com \'Lerico\':");
    scanf("%s", nome);

    for (int i = 0; nome[i] != '\0'; i++) {
        nome[i] = tolower((unsigned char)nome[i]);
    }

    if (strcmp(nome, "lerico") == 0) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    
    return 0;
}