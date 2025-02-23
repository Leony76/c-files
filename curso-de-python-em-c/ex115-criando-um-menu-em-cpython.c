#include <stdio.h>
#include <string.h>
#include <windows.h>

int main() {

    int quantidade = 0;
    char nome_pessoas[50][50];
    int idade_pessoas[50];    

    while (1) {
        printf("\033[35m-----------------------------------------\n");
        printf("\033[36m              MENU PRINCIPAL        \n");
        printf("\033[35m-----------------------------------------\033[m\n");

        printf("\033[32m1 \033[m- \033[33mVer pessoas cadastradas\n");
        printf("\033[32m2 \033[m- \033[33mCadastrar novas pessoas\n");
        printf("\033[32m3 \033[m- \033[31mSair do programa\n");

        printf("\033[35m-----------------------------------------\033[m\n");

        int opcao_valida = 0;
        int opcao;

        while (!opcao_valida) {

            printf("\033[32mSua opcao\033[m: ");

            if (scanf("%d", &opcao) == 1) {
                opcao_valida = 1;
                while (getchar() != '\n');
                system("cls");
            } else {
                printf("\033[31mOpcao invalida!\033[m\n");
                while (getchar() != '\n');

                Sleep(2000);
            }
        }

        char nome[50];
        int idade;

        switch (opcao) {
            case 1:
                printf("\033[35m-----------------------------------------\n");
                printf("\033[36m             PESSOAS LISTADAS       \n");
                printf("\033[35m-----------------------------------------\033[m\n");
            
                if (quantidade > 0) {
                    
                    printf("\033[35m%-5s \033[37m%-5s \033[34m%20s\033[m\n", "Id", "Nome", "Idade");
                    for (int i = 0; i < quantidade; i++) {
                        printf("\033[31m%-5d \033[36m%-5s", (i + 1), nome_pessoas[i]);

                        for (size_t j = 0; j < (size_t)24 - (size_t)strlen(nome_pessoas[i]); j++) printf(" ");

                        printf("\033[32m%d\033[m\n", idade_pessoas[i]);
                    }

                } else {
                    printf("\033[31mAinda nao foi cadastrado pessoas aqui!\033[m\n");
                }

                printf("\033[35m-----------------------------------------\n");

                Sleep(3000);
                system("cls");

                break;
            case 2:

                printf("\033[35m-----------------------------------------\n");
                printf("\033[36m             CADASTRO PESSOAS       \n");
                printf("\033[35m-----------------------------------------\033[m\n");

                printf("\033[36mNome\033[m: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("\033[32m>>> %s adicionado a lista! <<<\033[m\n", nome);

                int idade_valida = 0;

                while (!idade_valida) {

                    printf("\033[36mIdade\033[m: ");

                    if (scanf("%d", &idade) == 1) {
                        idade_valida = 1;
                        while (getchar() != '\n');
                    } else {
                        printf("\033[31mIdade invalida!\033[m\n");
                        while (getchar() != '\n');
                    }
                }

                printf("\033[32m>>> Idade de %s, (%d) adicionado a lista! <<<\033[m\n", nome, idade);

                strcpy(nome_pessoas[quantidade], nome);
                idade_pessoas[quantidade] = idade;

                quantidade++;   

                Sleep(2000);
                system("cls");

                break;
            case 3:
                printf("\033[33mEncerrando...\033[m\n");

                Sleep(3000);

                printf("\033[31m<<< Programa encerrado! >>>\033[m\n");

                break;
            default:
                printf("\033[31mOpcao invalida!\033[m\n");

                Sleep(2000);
                system("cls");
        }
        
        if (opcao == 3) {
            break;
        }
    }

    return 0;
}