#include <stdio.h>

char* podeVotar(int idade) {

    static char mensagem[200];

    if ((idade < 18) && (idade > 15)) {
        sprintf(mensagem, "Voce tem %d anos e ja pode votar, porem nao tem obrigacao!\n", idade);
        return mensagem;
    } else if (idade >= 18) {
        sprintf(mensagem, "Voce tem %d anos e deve votar, pois e obrigatorio!\n", idade);
        return mensagem;
    } else {
        sprintf(mensagem, "Voce ainda tem %d anos e nao pode votar, somente daqui %d anos podera!\n", idade, (18 - idade));   
        return mensagem;
    }
}

int main() {

    int ano_nascimento;
    int idade;

    printf("Em que ano voce nasceu?: ");
    scanf("%d", &ano_nascimento);

    idade = 2025 - ano_nascimento;

    printf("%s", podeVotar(idade));

    return 0;
}