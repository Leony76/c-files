#include <stdio.h>

int main() {

    int quantos, primeiro_t, razao, contagem = 1;

    printf("===== N PRIMEIROS TERMOS DE UMA PA =====\n");

    printf("Insira o quantos termos tera a sequencia: ");
    scanf("%d", &quantos);

    printf("Insira o primeiro termo da sequencia: ");
    scanf("%d", &primeiro_t);

    printf("Insira a razao: ");
    scanf("%d", &razao);

    while (1) {
        while (contagem <= quantos) {
            
            printf((contagem == (quantos)) ? "\033[1;32m%d " : "\033[1;32m%d \033[1;33m-> ", primeiro_t);

            primeiro_t += razao;
            contagem++;

        }
        printf("\n\033[1;31mPausa!!\033[m\n");
        printf("\033[1;35mQuantos a mais?\033[1;34m: ");
        scanf("%d", &quantos);

        contagem = 1;

        if (quantos == 0) {
            printf("\033[1;31mJa que e 0, a PA se encerra!\033[m\n");
            break;
        }
    }
    return 0;
}