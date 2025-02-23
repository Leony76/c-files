#include <stdio.h>

int main() {

    float preco_compras;
    int forma_pag;

    for (int i = 0; i < 5; i++) {
        printf("========== LOJA LERICORIANA ==========\n");
        printf("Preco das compras?: R$");
        scanf("%f", &preco_compras);

        printf("Forma de pagamento?: \n");

        printf("[ 1 ] a vista dinheiro/cheque\n");
        printf("[ 2 ] a vista cartao\n");
        printf("[ 3 ] 2x no cartao\n");
        printf("[ 4 ] 3x ou mais no cartao\n");

        printf("Qual sua opcao?: ");
        scanf("%d", &forma_pag);
        fflush(stdout);

        if (forma_pag == 1) {

            float desconto_10 = preco_compras - (preco_compras * (10.0/100.0));

            printf("Sua compra de R$%.2f saira por R$%.2f, com 10%% de desconto aplicado!\n", preco_compras, desconto_10);

        } else if (forma_pag == 2) {

            float desconto_5 = preco_compras - (preco_compras * (5.0/100.0));

            printf("Sua compra de R$%.2f saira por R$%.2f, com 5%% de desconto aplicado!\n", preco_compras, desconto_5);
            
        } else if (forma_pag == 3) {

            float _2x = preco_compras / 2.0;

            printf("Sua compra de R$%.2f foi parcelada em 2x no cartao, sendo cada prestacao, R$%.2f!\n", preco_compras, _2x);

        } else if (forma_pag == 4) {

            int quantidade;

            printf("Quantas parcelas?: ");
            scanf("%d", &quantidade);

            float _xx = preco_compras / (float) quantidade;
            float juros = _xx + (_xx * (20.0/100.0));
            float total = juros * quantidade;

            printf("Sua compra de R$%.2f foi parcelada em %dx no cartao, sendo cada prestacao R$%.2f, com 20%% de juros cada, totalizando R$%.2f!\n", preco_compras, quantidade, juros, total);

        } else {
            printf("Forma de pagamento invalido!\n");
        }
    }
    return 0;
}