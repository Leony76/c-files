#include <stdio.h>

int main() {

    float nota1, nota2, nota3, media;

    printf("Insira a primeira nota: ");
    scanf("%f", &nota1);
    fflush(stdout);

    printf("Insira a segunda nota: ");
    scanf("%f", &nota2);
    fflush(stdout);

    printf("insira a terceira nota: ");
    scanf("%f", &nota3);
    fflush(stdout);

    media = (nota1 + nota2 + nota3) / 3.0;

    printf("O aluno tirou %.1f, %.1f e %.1f e ficou com a media %.1f, logo: ", nota1, nota2, nota3, media);

    if (media >= 7) {
        printf("ESTA APROVADO!\n");
    } else if (media < 5) {
        printf("ESTA REPROVADO!\n");
    } else {
        printf("ESTA DE RECUPERACAO!\n");
    }

    return 0;
}