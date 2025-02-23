#include <stdio.h>
#include <string.h>

int main() {

    char nome_aluno[50];
    float notas = 0, media;

    printf("Nome do aluno: ");
    fgets(nome_aluno, sizeof(nome_aluno), stdin);
    nome_aluno[strcspn(nome_aluno, "\n")] = '\0';

    for (int i = 0; i < 3; i++) {
        float nota;
        printf("Nota %d: ", (i+1));
        scanf("%f", &nota);

        notas += nota;
    }

    media = notas / 3.0;

    printf("O nome do(a) aluno(a) e \033[36m%s\033[m!\n", nome_aluno);
    printf("A media de \033[36m%s \033[me de \033[33m%.1f\033[m!\n", nome_aluno, media);

    if (media >= 7) {
        printf("\033[36m%s \033[32mesta aprovado(a)!\033[m\n", nome_aluno);
    } else if (media < 4) {
        printf("\033[36m%s \033[31mesta reprovado!\033[m\n", nome_aluno);
    } else {
        printf("\033[36m%s \033[33mesta de recuperacao!\033[m\n", nome_aluno);
    }

    return 0;
}