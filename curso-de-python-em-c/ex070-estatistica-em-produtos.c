#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <float.h>

int main() {

    char produto[20];
    char produto_menor_preco[20];
    char escolha[2];
    float preco, total_compra = 0, menor_preco = FLT_MAX;
    int mais_de_1000 = 0;

    printf("\n=============================================\n");
    printf("               Loja de Lerico                \n");
    printf("=============================================\n");


    while (1) {

        printf("Nome do produto: ");
        scanf("%s", produto);
        getchar();

        printf("Preco: R$");
        scanf("%f", &preco);
        getchar();

        total_compra += preco;

        if (preco > 1000) {
            mais_de_1000++;
        }

        if (preco < menor_preco) {
            menor_preco = preco;
            strcpy(produto_menor_preco, produto);
        }

        while (1) {
            printf("Continuar? [S/N]: ");
            scanf("%s", escolha);

            for (int i = 0; escolha[i] != '\0'; i++) {
                escolha[i] = tolower((unsigned char)escolha[i]);
            }
            escolha[strcspn(escolha, "\n")] = '\0';

            if ((strcmp(escolha, "s") == 0) || (strcmp(escolha, "n") == 0)) {
                break;
            }
        }

        if (strcmp(escolha, "n") == 0) {
            break;
        }
    }

    printf("O total da compra foi de R$%.2f!\n", total_compra);
    printf("Foram registrados %d produtos com valor acima de R$1000.00!\n", mais_de_1000);
    printf("O produto mais barato registrado foi um(a) %s, custando R$%.2f!\n", produto_menor_preco, menor_preco);

    return 0;
}