#include <stdio.h>
#include <string.h>
#include <limits.h>

void corNotas(float nota) {
    if (nota > 6) {
        printf("\033[32m%.1f\033[m\n", nota);
    } else if (nota > 4) {
        printf("\033[33m%.1f\033[m\n", nota);
    } else {
        printf("\033[31m%.1f\033[m\n", nota);
    }

}

void situacao(float nota1, float nota2, float nota3) {

    int notas[3] = {nota1, nota2, nota3};

    int total = 0;    
    float maior = INT_MIN;
    float menor = INT_MAX;
    float media = 0, soma_notas = 0;
    char situacao[20];

    total += 3;

    for (int i = 0; i < 3; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
        }

        if (notas[i] < menor) {
            menor = notas[i];
        }

        soma_notas += notas[i];
    }

    media = soma_notas / 3.0;
    
    if (media > 8) {
        strcpy(situacao, "\033[32mExelente!\033[m");
    } else if (media > 6) {
        strcpy(situacao, "\033[32mBom!\033[m");
    } else if (media > 4) {
        strcpy(situacao, "\033[33mMelhore!\033[m");
    } else if (media > 2) {
        strcpy(situacao, "\033[31mRuim!\033[m");
    } else {
        strcpy(situacao, "\033[31mPessima!\033[m");
    }

    for (int i = 0; i < 36; i++) printf("\033[30m-=\033[m");
    printf("\n");

    printf("\033[34mTotal de notas\033[m: \033[33m%d\n", total);
    printf("\033[34mMaior nota\033[m: ");
    corNotas(maior); 
    printf("\033[34mMenor nota\033[m: ");
    corNotas(menor); 
    printf("\033[34mMedia\033[m: ");
    corNotas(media); 
    printf("\033[34mSituacao\033[m: %s\033[m\n", situacao);

    for (int i = 0; i < 36; i++) printf("\033[30m-=\033[m");
    printf("\n");
}

int main() {

    float n1, n2, n3;

    printf("<<< \033[35mInsira 3 notas \033[m>>> \n");

    printf("\033[36mNota 1\033[32m: ");
    scanf("%f", &n1);

    printf("\033[36mNota 2\033[32m: ");
    scanf("%f", &n2);

    printf("\033[36mNota 3\033[32m: ");
    scanf("%f", &n3);

    situacao(n1, n2, n3);

    return 0;
}