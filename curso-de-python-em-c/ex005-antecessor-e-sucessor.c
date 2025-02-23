#include <stdio.h>

int main() {

    int n;

    printf("\033[1;37mDigite um \033[1;33mnumero \033[1;37mpara ver seu \033[1;33msucessor \033[1;30me \033[1;33mantecessor\033[1;32m: ");
    scanf("%d", &n);

    printf("\033[1;36mO \033[1;33msucessor \033[1;36mde \033[1;33m%d \033[1;36me \033[1;32m%d \033[1;36me o \033[1;33mantecessor, \033[1;32m%d\033[1;36m!", n, (n+1), (n-1));

    return 0;
}