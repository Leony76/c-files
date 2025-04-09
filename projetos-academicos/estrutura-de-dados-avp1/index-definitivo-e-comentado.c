#include <stdio.h>     // Inclusão da biblioteca para funções de entrada e saída (printf, scanf).
#include <stdlib.h>    // Inclusão da biblioteca para funções gerais (como alocação de memória).
#include <string.h>    // Inclusão da biblioteca para manipulação de strings (como strcpy, strncpy).
#include <ctype.h>     // Inclusão da biblioteca para funções de manipulação de caracteres (como tolower).

#define MAX_CLIENTES 50            // Define o número máximo de clientes que podem ser adicionados à fila.
#define MAX_TAMANHO_NOME 50        // Define o número máximo de caracteres para o nome de um cliente.

typedef struct {
    char clientes[MAX_CLIENTES][MAX_TAMANHO_NOME];  // Array bidimensional para armazenar os nomes dos clientes.
    int incio_da_fila, final_da_fila;               // Variáveis para controlar o início e o final da fila.
} Fila;  // Definição de um tipo 'Fila', que armazena os clientes e os índices de controle da fila.

void criarFila(Fila *f) {
    f->final_da_fila = 0;     // Inicializa o final da fila como 0 (fila vazia).
    f->incio_da_fila = 0;     // Inicializa o início da fila como 0 (fila vazia).
}

int filaEstaVazia(Fila *f) {
    return f->incio_da_fila == f->final_da_fila;  // Verifica se o início da fila é igual ao final, indicando que a fila está vazia.
}

int filaEstaCheia(Fila *f) {
    return f->final_da_fila == MAX_CLIENTES;  // Verifica se o número de clientes na fila atingiu o limite máximo.
}

void adicionarNaFila(Fila *f, const char *cliente) {
    if (filaEstaCheia(f)) {
        printf("\033[1;37;41m(!) A Fila esta cheia\n");  // Exibe uma mensagem de erro se a fila estiver cheia.
        return;
    }
    
    // Adiciona o cliente na fila, copiando o nome para a posição de 'final_da_fila' no array.
    strncpy(f->clientes[f->final_da_fila], cliente, MAX_TAMANHO_NOME - 1);
    f->final_da_fila++;  // Incrementa o índice 'final_da_fila'.

    printf("\033[1;37;42m (!) Cliente %s acidionado a fila com sucesso\033[m\n", cliente);  // Exibe uma mensagem de sucesso.
}

char* removerDaFila(Fila *f) {
    if (filaEstaVazia(f)) {
        printf("\033[1;37;41m (!) Nao e possivel remover clientes porque a fila esta vazia\033[m\n");
        return NULL;  // Retorna NULL se a fila estiver vazia.
    } else {
        char *cliente = f->clientes[f->incio_da_fila];  // Pega o cliente do início da fila.
        f->incio_da_fila++;  // Incrementa o índice 'incio_da_fila', removendo o cliente da fila.

        return cliente;  // Retorna o nome do cliente removido.
    }
}

void exibirClientes(Fila *f) {
    if (filaEstaVazia(f)) {
        printf("\033[1;37;41m(!) Nao e possivel exibir clientes porque a fila esta vazia\033[m\n");
    }

    printf("==========================\n");
    printf("    CLIENTES NA LISTA     \n");
    printf("==========================\n");

    for (int i = f->incio_da_fila; i < f->final_da_fila; i++) {
        printf(" - %s\n", f->clientes[i]);  // Exibe todos os clientes na fila, do índice 'incio_da_fila' até 'final_da_fila'.
    }
}

int main () {
    Fila s_fila;  // Declaração de uma variável do tipo 'Fila'.

    int opcao;  // Variável para armazenar a opção escolhida pelo usuário.
    char nome_cliente[50], confirmar_remocao, confirmar_encerramento;  // Variáveis para armazenar dados temporários (nome do cliente, confirmação de remoção, confirmação de encerramento).

    criarFila(&s_fila);  // Chama a função para inicializar a fila.

    while (1) {  // Inicia um loop infinito para mostrar o menu repetidamente até que o programa seja encerrado.
        printf("==========================\n");
        printf("           MENU           \n");
        printf("==========================\n");

        // Exibe as opções do menu.
        printf("[ 1 ] Adicionar cliente\n");
        printf("[ 2 ] Remover cliente\n");
        printf("[ 3 ] Listar Clientes\n");
        printf("[ 4 ] Encerrar Programa\n");

        printf("==========================\n");

        printf("Qual opcao: ");
        scanf("%d", &opcao);  // Lê a opção escolhida pelo usuário.
        getchar();  // Consome o caractere de nova linha deixado por scanf.

        switch (opcao) {  // Avalia a opção escolhida pelo usuário.
            case 1: {
                printf("(!) Digite \"!\" para cancelar a acao\n");

                printf("Nome do cliente: ");
                fgets(nome_cliente, sizeof(nome_cliente), stdin);  // Lê o nome do cliente.
                nome_cliente[strcspn(nome_cliente, "\n")] = '\0';  // Remove o caractere de nova linha que fgets captura.

                if (nome_cliente[0] == '!') {
                    break;  // Se o usuário digitar "!", cancela a ação de adicionar cliente.
                }

                adicionarNaFila(&s_fila, nome_cliente);  // Adiciona o cliente à fila.

                break;
            }
            case 2: {
                while (1) {  // Pergunta ao usuário se ele tem certeza de que deseja remover um cliente.
                    printf("Deseja mesmo remover um cliente? [S/N]: ");
                    scanf("%c", &confirmar_remocao);  // Lê a resposta de confirmação.
                    getchar();  // Consome o caractere de nova linha.

                    confirmar_remocao = tolower(confirmar_remocao);  // Converte a resposta para minúsculo.

                    if (confirmar_remocao == 's' || confirmar_remocao == 'n') {
                        if (confirmar_remocao == 's') {
                            char *confirma_remocao = removerDaFila(&s_fila);  // Chama a função para remover o cliente da fila.
                            if (confirma_remocao != NULL) {
                                printf("\033[1;30;42m    (!) Cliente %s removido com sucesso    \033[m\n", confirma_remocao);
                            }
                        }
                        break;
                    } else {
                        printf("\033[1;30;41m    (!) Insira uma opcao valida    \033[m\n");  // Exibe mensagem de erro se a resposta for inválida.
                    }
                }

                break;
            }
            case 3: {
                exibirClientes(&s_fila);  // Chama a função para exibir os clientes na fila.
                break;
            }
            case 4: {
                printf("Tem certeza que deseja encerrar?[S/N]: ");
                scanf("%c", &confirmar_encerramento);  // Lê a confirmação para encerrar o programa.
                getchar();

                confirmar_encerramento = tolower(confirmar_encerramento);  // Converte para minúsculo.

                if (confirmar_encerramento == 's' || confirmar_encerramento == 's') {
                    if (confirmar_encerramento == 's') {
                        printf("\033[1;30;41m   >>> (!) Programa encerrado <<<  \033[m\n");  // Exibe mensagem de encerramento.
                    }
                }

                break;
            }
            default: {
                printf("\033[1;30;41m    (!) Insira uma opcao valida do menu    \033[m\n");  // Exibe mensagem de erro se a opção for inválida.
            }
        }

        if ((opcao == 4) && (confirmar_encerramento == 's')) {
            break;  // Sai do loop e encerra o programa se a opção for 4 e a confirmação for "s".
        }
    }

    return 0;  // Encerra a execução do programa.
}
