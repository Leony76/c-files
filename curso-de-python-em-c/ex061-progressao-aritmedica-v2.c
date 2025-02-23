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

    while (contagem <= quantos) {
        
        printf((contagem == (quantos)) ? "\033[1;32m%d " : "\033[1;32m%d \033[1;33m-> ", primeiro_t);

        primeiro_t += razao;
        contagem++;
    }

    return 0;
}