#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char lista_nomes[50][50]; 
    char lista_sexo[50]; 
    int lista_idade[50];

    char lista_nome_mulheres[50][50];
    float media_idade;
    int soma_idades = 0;
    int quantidade = 0, quant_mulheres = 0;  

    while (1) {

        char nome[50];

        printf("\033[36mNome\033[m: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';

        char sexo;

        while (1) {

            printf("\033[35mSexo [M/F]\033[m: ");
            scanf(" %c", &sexo);

            sexo = tolower((unsigned char)sexo);

            while (getchar() != '\n') {}

            if (sexo == 'm' || sexo == 'f') {
                if (sexo == 'f') {
                    strcpy(lista_nome_mulheres[quant_mulheres], nome);
                    quant_mulheres++;
                }

                break;
            }

            printf("\033[31mSexo invalido!\033[m\n");
        }

        int idade_valida = 0;
        int idade;
        
        while (!idade_valida) {

            printf("\033[32mIdade\033[m: ");

            if (scanf("%d", &idade) == 1) {
                idade_valida = 1;
                while (getchar() != '\n') {}
            } else {
                printf("\033[31mIdade invalida!\033[m\n");
                while (getchar() != '\n') {}
            }
        }

        strcpy(lista_nomes[quantidade], nome);
        lista_sexo[quantidade] = sexo;
        lista_idade[quantidade] = idade;

        soma_idades += idade;
        quantidade++;

        char continuar;

        while (1) {

            printf("\033[33mContinuar? [S/N]\033[m: ");
            scanf(" %c", &continuar);

            continuar = tolower((unsigned char)continuar);

            while (getchar() != '\n') {}

            if (continuar == 's' || continuar == 'n') {
                break;
            }

            printf("\033[31mOpcao invalida!\033[m\n");
        }

        if (continuar == 'n') {
            break;
        }

        printf("\033[30m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n");
    }

    printf("\033[30m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n");

    media_idade = (float) soma_idades / (float) quantidade; 

    printf("\033[34mAo todo, temos \033[33m%d \033[34mpessoas cadastradas!\n", (quantidade));

    printf("A \033[33mmedia \033[34mde idade e de \033[33m%.1f \033[34manos!\n", media_idade);

    if (quant_mulheres != 0) {

        printf("As \033[33mmulheres \033[34mcadastradas foram: ");

        for (int i = 0; i < quant_mulheres; i++) {
            printf("\033[35m{%s} \033[m", lista_nome_mulheres[i]);
        }
        printf("\n");
    } else {
        printf("\033[31mNao ha mulheres nessa listagem!\033[m\n");
    }

    int acima_media = 0;

    for (int i = 0; i < quantidade; i++) {
        if (lista_idade[i] > media_idade) {
            acima_media = 1;
            break;
        }
    }
    
    if (acima_media) {

        printf("\033[34mLista das pessoas que estao \033[33macima da media\033[34m: \n\n");

        for (int i = 0; i < quantidade; i++) {
            if (lista_idade[i] > media_idade) {
                if (lista_sexo[i] == 'f') {
                    printf(" >> \033[31mNome\033[m: \033[36m%s    \033[31msexo\033[m: \033[35mFeminino    \033[31midade\033[m: \033[32m%d anos\033[m\n", lista_nomes[i], lista_idade[i]);
                } else {
                    printf(" >> \033[31mNome\033[m: \033[36m%s    \033[31msexo\033[m: \033[35mMasculino    \033[31midade\033[m: \033[32m%d anos\033[m\n", lista_nomes[i], lista_idade[i]);
                }
            }
        }
    } else {
        printf("\033[31mNenhum pessoa ficou acima da media!\033[m\n");
    }

    printf("\033[30m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n");

    return 0;
}


