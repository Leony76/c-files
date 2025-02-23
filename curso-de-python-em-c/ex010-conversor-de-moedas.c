#include <stdio.h>

int main() {

    float dinheiro,d_dolar;

    printf("Insira quanto de dinhero voce tem: \033[1;32mR$");
    scanf("%f", &dinheiro);

    d_dolar = dinheiro / 6;

    printf("\033[mCom \033[1;32mR$%.2f \033[mreais, voce pode comprar \033[1;32mUS$%.2f\033[m dolares americanos!", dinheiro, d_dolar);

    return 0;
}