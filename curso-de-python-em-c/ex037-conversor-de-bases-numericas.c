#include <stdio.h>

void print_bin(int n) {
    unsigned mask = 1 << (sizeof(int) * 8 - 1);  // Cria uma máscara para o bit mais significativo
    int started = 0;

    // Imprime cada bit
    for (int i = 0; i < sizeof(int) * 8; i++) {
        if (n & mask) {
            printf("1");
            started = 1;
        } else {
            if (started) {
                printf("0");
            }
        }
        mask >>= 1;
    }

    if (!started) {
        printf("0");  // Caso o número seja 0
    }
    printf("\n");
}


int main() {

    int n, escolha;

    printf("Insira um numero: ");
    scanf("%d", &n);
    fflush(stdout);

    printf("Escolha uma das bases para conversao:\n");
    printf("[ 1 ] para converter para OCTAL\n");
    printf("[ 2 ] para converter para HEXADECIMAL\n");
    printf("[ 3 ] para converter para BINARIO\n");

    scanf("%d", &escolha);

    if (escolha == 1) {
        printf("%d em OCTAL fica %o!\n", n, n);
    } else if (escolha == 2) {
        printf("%d em HEXADECIMAL fica %X!\n", n, n);
    } else {
        printf("%d em BINARIO fica: ", n);
        print_bin(n);
    }

    return 0;
}