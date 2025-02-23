#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define MAX_LENGTH 50

void titulo() {
    printf("\033[35m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n");
    printf("\033[32m                    MEDIA DOS ALUNOS                         \033[m\n");
    printf("\033[35m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n");    
}

int main() {

    int quantidade = 0;
    float* lista_medias = (float*) malloc(quantidade * sizeof(float));
    char **lista_nomes = (char **) malloc(quantidade * sizeof(char*));
    float listas_notas[50][2];

    titulo();

    while (1) {

        lista_medias = (float*) realloc(lista_medias, (quantidade + 1) * sizeof(float));
        lista_nomes = (char **) realloc(lista_nomes, (quantidade + 1) * sizeof(char*));

        lista_nomes[quantidade] = (char*) malloc(MAX_LENGTH * sizeof(char*));
        lista_nomes[quantidade][strcspn(lista_nomes[quantidade], "\n")] = '\0'; 

        printf("\033[34mNome\033[m: ");
        scanf("%s", lista_nomes[quantidade]);

        int valido = 0;
        float nota1;

        while (!valido) {
            printf("\033[32mNota 1\033[m: ");

            if (scanf("%f", &nota1) == 1) {
                valido = 1;
                while (getchar() != '\n') {

                }
            } else {
                printf("\033[31mNota invalida!\033[m\n");
                while (getchar() != '\n') {

                }
            }
        }

        valido = 0;
        float nota2;

        while (!valido) {
            printf("\033[32mNota 2\033[m: ");
            
            if (scanf("%f", &nota2) == 1) {
                valido = 1;
                while (getchar() != '\n') {

                }
            } else {
                printf("\033[31mNota invalida!\033[m\n");
                while (getchar() != '\n') {

                }
            }
        }

        listas_notas[quantidade][0] = nota1;
        listas_notas[quantidade][1] = nota2;

        float media = (nota1 + nota2) / 2.0;

        lista_medias[quantidade] = media;

        quantidade++;

        char continuar;

        while (1) {
            printf("Continuar? \033[35m[S/N]\033[m: ");
            scanf(" %c", &continuar);

            continuar = tolower((unsigned char)continuar);

            while (getchar() != '\n') {
                
            }

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

    while (1) {

        printf("\033[30m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n");

        printf("\033[35m%-10s \033[33m%-20s %10s\033[m\n", "Id", "Nome", "Media");
    
        for (int i = 0; i < quantidade; i++) {
            printf("\033[31m%-10d \033[m", (i));
            printf("\033[36m%-20s \033[m", lista_nomes[i]);
            printf("\033[32m%10.1f\033[m\n", lista_medias[i]);
        }
    
        printf("\033[30m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[m\n");

        int id_aluno;

        printf("De qual aluno deseja ver sua notas?: \033[31m(999 para parar!)\033[m: ");
        scanf("%d", &id_aluno);

        if (id_aluno == 999) {
            printf("\033[33mEncerrando programa...\033[m\n");
            Sleep(3000);
            printf("\033[31mPrograma Encerrado!\033[m\n");
            break;
        }

        int id_valido = 0;

        for (int i = 0; i < quantidade; i++) {
            if (i == id_aluno) {
                id_valido = 1;
                break;
            }
        }

        if (!id_valido) {
            printf("\033[31mId de aluno nao encotrado!\033[m\n");
            Sleep(2000);

        } else {

            printf("\033[35m%-5s \033[1;37m%-20s \033[33m%10s %10s\033[m\n", "Id", "Nome", "Nota 1", "Nota 2");

            printf("\033[31m%-5d\033[m ", id_aluno);
            printf("\033[36m%-20s\033[m ", lista_nomes[id_aluno]);
            printf("\033[32m%10.1f\033[m ", listas_notas[id_aluno][0]);
            printf("\033[32m%10.1f\033[m\n", listas_notas[id_aluno][1]);

            Sleep(3000);
        }
    }

    return 0;
}