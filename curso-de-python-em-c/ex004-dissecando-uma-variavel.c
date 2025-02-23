#include <stdio.h>
#include <ctype.h>

int main() {

    int coisa;

    printf("Digite uma coisa: ");
    scanf("%d", &coisa);

    if (isdigit('0' + coisa)) {
        printf("E um numero!");
    } else {
        printf("E uma cadeia de caracteres!");
    }

    return 0;
}