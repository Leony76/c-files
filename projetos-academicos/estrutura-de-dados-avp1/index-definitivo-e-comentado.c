#include <stdio.h>     // Inclusão da biblioteca para funções de entrada e saída (printf, scanf).
#include <stdlib.h>    // Inclusão da biblioteca para funções gerais (como alocação de memória).
#include <string.h>    // Inclusão da biblioteca para manipulação de strings (como strcpy, strncpy).
#include <ctype.h>     // Inclusão da biblioteca para funções de manipulação de caracteres (como tolower).

#define MAX_CLIENTES 50            // Define o número máximo de clientes que podem ser adicionados à fila.
#define MAX_TAMANHO_NOME 50        // Define o número máximo de caracteres para o nome de um cliente.

typedef struct { // Declaro um struct.
    char clientes[MAX_CLIENTES][MAX_TAMANHO_NOME];  // Array bidimensional para armazenar os nomes dos clientes.
    int incio_da_fila, final_da_fila;               // Variáveis para controlar o início e o final da fila.
} Fila;  // Definição de um tipo 'Fila', que armazena os clientes e os índices de controle da fila.

void criarFila(Fila *f) { // Função sem retorno (void).....// '*f' é um ponteiro que aponta para o array e/ou variáveis inclusas no tipo Fila, pegando seus endereços para modifica-los caso necessário. No caso a sintaxe (f->'NOME DA VARIÀVEL' = 'VALOR QUALQUER'), '*f' sem o asterisco '*', ou seja, 'f', está por meio do '->' acessando a variável que está no tipo Fila, nesse caso, as 'final_da_fila' e 'inicio_da_fila', e está atribuindo uma valor, nesse caso '0'.
    f->final_da_fila = 0;     // Inicializa o final da fila como 0 (fila vazia).
    f->incio_da_fila = 0;     // Inicializa o início da fila como 0 (fila vazia).
}

int filaEstaVazia(Fila *f) { // Função com retorno do tipo int (inteiro).....// '*f' é um ponteiro que aponta para o array e/ou variáveis inclusas no tipo Fila, pegando seus endereços para modifica-los caso necessário. No caso a sintaxe (f->'NOME DA VARIÀVEL' == f->'NOME DA VARIÀVEL'), '*f' sem o asterisco '*', ou seja, 'f', está por meio do '->' acessando a variável que está no tipo Fila, nesse caso, as 'final_da_fila' e 'inicio_da_fila', e está comparando o valor entre essas.
    return f->incio_da_fila == f->final_da_fila;  // Verifica se o início da fila é igual ao final, indicando que a fila está vazia.
}

int filaEstaCheia(Fila *f) { // Função com retorno do tipo int (inteiro).....// '*f' é um ponteiro que aponta para o array e/ou variáveis inclusas no tipo Fila, pegando seus endereços para modifica-los caso necessário. No caso a sintaxe (f->'NOME DA VARIÀVEL' == 'NOME DA VARIÀVEL'), '*f' sem o asterisco '*', ou seja, 'f', está por meio do '->' acessando a variável que está no tipo Fila, nesse caso, 'final_da_fila', e está comparando o seu valor com 'MAX_CLIENTES', que é outra variável com valor 50, definido pelo '#define'.
    return f->final_da_fila == MAX_CLIENTES;  // Verifica se o número de clientes na fila atingiu o limite máximo.
}

void adicionarNaFila(Fila *f, const char *cliente) { // Função sem retorno (void).....// '*f' é um ponteiro que aponta para o array e/ou variáveis inclusas no tipo Fila, pegando seus endereços para modifica-los caso necessário. No caso a sintaxe (f->'NOME DA VARIÀVEL'[f->'NOME DA VARIÀVEL']), '*f' sem o asterisco '*', ou seja, 'f', está por meio do '->' acessando a variável que está no tipo Fila, nesse caso, 'final_da_fila', e está acessando a posição do array 'clientes' do tipo Fila de acordo com o valor armazenado na variável 'final_da_fila', ou seja, se for 5 o valor dela, vai acessar o cliente armazenado na posição 5 do array, no caso seria 4 porque em arrays a posição é definida pela subtração da posição, decrementando um (posição(ex:5) - 1)......// 'const char *cliente' é uma string que aponta para um conjunto de caracteres(char), como 'João' ou 'Maria' e, por possir a restrição 'const', garante que a string não poderá ser modificada por ser uma constante.
    if (filaEstaCheia(f)) { // Esse 'f' é um ponteiro que aponta para a função 'filaEstaCheia()', que dependendo de seu retorno (se for '1', true, se for '0', false), indicará se a fila está ou não cheia, no caso se for 1, estará.
        printf("\033[1;37;41m(!) A Fila esta cheia\n");  // Exibe uma mensagem de erro se a fila estiver cheia.
        return; // Apenas para sair da função de imediato logo após a mensagem ter sido exibida.
    }
    
    // Adiciona o cliente na fila, copiando o nome para a posição de 'final_da_fila' no array.
    strncpy(f->clientes[f->final_da_fila], cliente, MAX_TAMANHO_NOME - 1); // A função 'strncpy' serve para copiar uma string de uma varável para outra e ,os parâmentros dessa função se resumem em 'strncpy(DESTINO, ORIGEM, N° MÁXIMO DE CARACTERES QUE SERÃO COPIADOS)', nesse caso o destino seria 'f->clientes[f->final_da_fila]', ou seja, o indice do array 'cliente's que possui o valor da variável 'final_da_fila', e a origem seria justamente 'cliente', que está abreviado de sua declaração (cons char *cliente), no qual já vai receber um parâmetro do nome. O 'MAX_TAMANHO_NOME - 1' seria a quantida máxima de caracteres que o nome que vai ser copiado deve ter, menos um pelo \0 que as string por padrão sempre têm em C. Isso impede que nomes maiores que a capacidade que o array comporta de caracteres vazem e possa entrar lixo de buffer....RESUMINDO TUDO ISSO, essa função pega o nome que vai ser adionado na lista clientes e o copia para esse array, adicinando \0 caso o número de caracteres dessa string for menor que o MAX_TAMANHO_NOME, senão, nem adicona \0.
    f->final_da_fila++;  // Incrementa o índice 'final_da_fila', pois se isso não for feito, o próximo nome a ser adicionada seria armazenado na mesma posição no anterior, sempre sobrescrevendo-o dessa forma. Quando incremento 1, o próximo nome a ser adiconado será na próxima posição do array, o que não será a mesma do nome que foi anteriormente armazenado.

    printf("\033[1;37;42m (!) Cliente %s acidionado a fila com sucesso\033[m\n", cliente);  // Exibe uma mensagem de sucesso.
}

char* removerDaFila(Fila *f) { // Função com retorno do tipo string (char*).....// O tipo 'char*' significa que a função vai retornar um string, no caso o nome do cliente que será removido 
    if (filaEstaVazia(f)) { // Esse 'f' é um ponteiro que aponta para a função 'filaEstaVazia()', que dependendo de seu retorno (se for '1', true, se for '0', false), indicará se a fila está ou não vazia, no caso se for 1, estará.
        printf("\033[1;37;41m (!) Nao e possivel remover clientes porque a fila esta vazia\033[m\n");
        return NULL;  // Retorna NULL se a fila estiver vazia.
    } else {
        char *cliente = f->clientes[f->incio_da_fila];  // Pega o cliente do início da fila....// char *cliente' é uma string que aponta para um conjunto de caracteres(char), como 'João' ou 'Maria' por exemplo. Nesse caso o 'f' está acessando o posição referente ao valor da variável 'inicio_da_fila' no array 'clientes', e será o nome do cliente nessa posição que vai ser removido da fila
        f->incio_da_fila++;  // Incrementa o índice 'incio_da_fila', removendo o cliente da fila, pois a posição dos nomes dos clientes na fila incrementará em 1, ou seja, se um cliente estiver armazenado na posição 0 do array e o índice do mesmo for incrementado, não será mais possível acessar a posição desse nome porque 0 passou a ser 1, ou seja, saiu do escopo da fila.

        return cliente;  // Retorna o nome do cliente removido.
    }
}

void exibirClientes(Fila *f) { // Função sem retorno (void).....//
    if (filaEstaVazia(f)) { // Esse 'f' é um ponteiro que aponta para a função 'filaEstaVazia()', que dependendo de seu retorno (se for '1', true, se for '0', false), indicará se a fila está ou não vazia, no caso se for 1, estará.
        printf("\033[1;37;41m(!) Nao e possivel exibir clientes porque a fila esta vazia\033[m\n");
    }

    printf("==========================\n");
    printf("    CLIENTES NA LISTA     \n");
    printf("==========================\n");

    for (int i = f->incio_da_fila; i < f->final_da_fila; i++) { // Laço de repetição 'for' que começa com 'i' valendo o valor da variável 'inicio_da_fila' e, enquanto o valor dessa variável for menor que o do 'final_da_fila', irá sendo incremnetado em 1 até que seja igual...
        printf(" - %s\n", f->clientes[i]);  // Exibe todos os clientes na fila, do índice 'incio_da_fila' até 'final_da_fila'.
    }
}

int main () { // Função principal por onde todo código é executado, no qual retorna um int (inteiro) caso nenhum erro ocorrer (0).
    Fila s_fila;  // Declaração de uma variável do tipo 'Fila'.

    int opcao;  // Variável para armazenar a opção escolhida pelo usuário.
    char nome_cliente[50], confirmar_remocao, confirmar_encerramento;  // Variáveis para armazenar dados temporários (nome do cliente, confirmação de remoção, confirmação de encerramento).

    criarFila(&s_fila);  // Chama a função para inicializar a fila pegando o endereço da variável 's_fila' do tipo Fila.

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

                adicionarNaFila(&s_fila, nome_cliente);  // Adiciona o cliente à fila. Como o primeiro parâmetro da função 'adicionarNaFila()' espera um ponteiro, é pego o endereço da variável 's_fila' do tipo Fila.

                break;
            }
            case 2: {
                while (1) {  // Pergunta ao usuário se ele tem certeza de que deseja remover um cliente.
                    printf("Deseja mesmo remover um cliente? [S/N]: ");
                    scanf("%c", &confirmar_remocao);  // Lê a resposta de confirmação.
                    getchar();  // Consome o caractere de nova linha.

                    confirmar_remocao = tolower(confirmar_remocao);  // Converte a resposta para minúsculo pra evitar respostas em capslock.

                    if (confirmar_remocao == 's' || confirmar_remocao == 'n') { // Se a confirmação da remoção for 's' ou 'n', segue na condicional.
                        if (confirmar_remocao == 's') { // Se for 's', acontece a remoção.
                            char *confirma_remocao = removerDaFila(&s_fila);  // Chama a função para remover o cliente da fila. Perceba que tive que declarar uma variável para receber o retorno da função 'removerDaFila()', pois é a partir do que retornou que o fluxo irá prosseguir. Essa variável 'confirmar_remocao' é do tipo char com ponteiro pelo fato de ela receber uma string, que será ou o nome do cliente removido ou 'NULL' caso não houver clientes na fila.
                            if (confirma_remocao != NULL) { // Caso haja clientes, ou seja, diferente de NULL, é removido.
                                printf("\033[1;30;42m    (!) Cliente %s removido com sucesso    \033[m\n", confirma_remocao);
                            }
                        }
                        break;
                    } else { // Senão, foi porque não foi escolhido uma das duas opções 's' ou 'n'.
                        printf("\033[1;30;41m    (!) Insira uma opcao valida    \033[m\n");  // Exibe mensagem de erro se a resposta for inválida.
                    }
                }

                break;
            }
            case 3: {
                exibirClientes(&s_fila);  // Chama a função para exibir os clientes na fila, usando o endereço da vairável 's_fila' do tipo Fila como parâmetro da função 'exibirClientes()'.
                break;
            }
            case 4: {
                printf("Tem certeza que deseja encerrar?[S/N]: ");
                scanf("%c", &confirmar_encerramento);  // Lê a confirmação para encerrar o programa.
                getchar(); // Consome o caractere de nova linha.

                confirmar_encerramento = tolower(confirmar_encerramento); // Converte a resposta para minúsculo pra evitar respostas em capslock.

                if (confirmar_encerramento == 's' || confirmar_encerramento == 'n') { // Se a confirmação de encerrar o programa for 's' ou 'n', segue na condicional.
                    if (confirmar_encerramento == 's') { // Se for 's', o programa será encerrado ao sair do switch.
                        printf("\033[1;30;41m   >>> (!) Programa encerrado <<<  \033[m\n");  // Exibe mensagem de encerramento.
                    }
                }

                break;
            }
            default: {
                printf("\033[1;30;41m    (!) Insira uma opcao valida do menu    \033[m\n");  // Exibe mensagem de erro se a opção for inválida, ou seja, não for uma das 4 do menu.
            }
        }

        if ((opcao == 4) && (confirmar_encerramento == 's')) {
            break;  // Sai do loop e encerra o programa se a opção for 4 e a confirmação for "s".
        }
    }

    return 0;  // Encerra a execução do programa.
}
