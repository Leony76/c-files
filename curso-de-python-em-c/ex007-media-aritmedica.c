#include <stdio.h>

int main() {

    float n1, n2, n3, media;

    printf("Indique a primeira nota: ");
    scanf("%f", &n1);

    printf("Indique a segunda nota: ");
    scanf("%f", &n2);

    printf("Indique a terceira nota: ");
    scanf("%f", &n3);

    media = (n1 + n2 + n3) / 3;

    printf("A media aritmedica entre %.1f, %.1f e %.1f, e de %.1f !\n", n1, n2, n3, media);

    if (media >= 7) {
        printf("\033[1;32mEsta aprovado!\033[m");
    } else {
        printf("\033[1;31mEsta reprovado!\033[m");
    }

    return 0;
}