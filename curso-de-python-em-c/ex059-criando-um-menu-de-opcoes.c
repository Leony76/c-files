#include <stdio.h>
#include <windows.h>

int main() {

    int n1, n2, escolha;

    printf("\033[1;30mInsira um numero\033[1;32m: ");
    scanf("%d", &n1);

    printf("\033[1;30mInsira um outro numero\033[1;32m: ");
    scanf("%d", &n2);

    while (1) {
        printf("\033[1;35m{}======== \033[1;36mMENU DE OPCOES \033[1;35m========{}\033[m\n");

        printf("\033[1;33m[ 1 ] \033[1;34mSomar\033[m\n");
        printf("\033[1;33m[ 2 ] \033[1;34mMultiplicar\033[m\n");
        printf("\033[1;33m[ 3 ] \033[1;34mMaior\033[m\n");
        printf("\033[1;33m[ 4 ] \033[1;34mNovos numeros\033[m\n");
        printf("\033[1;33m[ 5 ] \033[1;31mEncerrar programa\033[m\n");

        printf("\033[1;30mQual sua escolha?\033[1;33m: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            printf("\033[m>>>>> \033[1;33m%d \033[1;34m+ \033[1;33m%d \033[1;34m= \033[1;32m%d\033[m\n", n1, n2, (n1 + n2));
        } else if (escolha == 2) {
            printf("\033[m>>>>> \033[1;33m%d \033[1;34mx \033[1;33m%d \033[1;34m= \033[1;32m%d\033[m\n", n1, n2, (n1 * n2));
        } else if (escolha == 3) {

            int maior = n1;

            if (n2 > maior) {
                maior = n2;
            }

            printf("\033[m>>>>> O \033[1;33mmaior \033[mentre ambos e o \033[1;32m%d\033[m!\n", maior);

        } else if (escolha == 4) {

            printf("\033[1;30mInsira o \033[1;33mnovo primeiro \033[1;30mnumero\033[1;32m: ");
            scanf("%d", &n1);

            printf("\033[1;30mInsira o \033[1;33mnovo segundo \033[1;30mnumero\033[1;32m: ");
            scanf("%d", &n2);

            printf("\033[m>>>>> \033[1;32mNUMEROS ATUALIZADOS!\033[m\n");

        } else if (escolha == 5) {

            printf("\033[m>>>>> \033[1;33mEncerrando programa...\033[m\n");
            Sleep(3000);
            printf("\033[m>>>>> \033[1;31mPROGRAMA ENCERRADO!\033[m <<<<<\n");

            break;

        } else {
            printf("\033[m<<<<< \033[1;31mOPCAO INVALIDA!\033[m >>>>>\n");
        }
    }

    return 0;
}