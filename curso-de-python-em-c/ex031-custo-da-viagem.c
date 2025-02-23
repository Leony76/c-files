#include <stdio.h>

int main() {

    int viagem;

    printf("Insira a distancia da viagem em km: ");
    scanf("%d", &viagem);

    if (viagem > 200) {
        int kms_acima = (viagem - 200);
        float preco = viagem * 0.45;
        printf("Voce pagara R$%.2f por uma viagem de %d kms, tendo um desconto de R$0.05 por cada km por ter sido %d kms acima de 200!", preco, viagem, kms_acima);
    } else {
        float preco = viagem * 0.50;
        printf("Voce pagara R$%.2f por uma viagem de %d kms !", preco, viagem);
    }

    return 0;
}