#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <windows.h>

// OBSERVAÇÕES:

//  \033[m = Simboliza cores no terminal, ou seja, \033[31m por exemplo, pinta a linha posterior a esse comando de vermelho... apenas por título de informação; Link de um vídeo que explica melhor: (https://www.youtube.com/watch?v=0hBIhkcA8O8&t=7s)


//  A Biblioteca <windows.h> parace que somente funciona em IDEs com MinGW, ou seja, em compiladores online o programa da erro, então vai estar ocultado os Sleep() com '//'

int main() {

    char lista_clientes[101][50]; strcpy(lista_clientes[0], "Inicializando array com indice 1"); // Apenas desloquei o indice do array que se inializa com '0' colocando uma string qualquer para que ele se inicialize com '1', para inteirar os IDs dos clientes 
    char cliente[50];
    int opcao, opcao_valida;
    int indice = 1;
    int id_cliente_remover;

    while (1) { // Loop while principal por onde todo programa principal transcorre
        while (1) { // Loop while que valida uma das opções do menu, caso seja selecionado uma delas (de 1 a 4), o loop é quebrado e o programa transcorre    
            printf("\033[35m============= \033[36mMENU \033[35m=============\033[m\n");

            printf("\033[33m[ 1 ] \033[32mAdicionar cliente\n");
            printf("\033[33m[ 2 ] \033[32mRemover cliente\n");
            printf("\033[33m[ 3 ] \033[32mVer lista de clientes\n");        
            printf("\033[33m[ 4 ] \033[31mEncerrar programa\n");

            printf("\033[35m================================\033[m\n");

            opcao_valida = 0; // Inicializo como inválida para depois se for válida se tornar válida (verificação que a tornará ou não)

            // Para esse caso: (0 = false ; 1 = true) , não existe boolean em C

            while (!opcao_valida) {// Verificação para ver se essa variável é válida, no caso, enquanto ela for inválida(0), o loop continuará perguntando até que seja digitado uma opção válida dentre as 4 citadas no menu

                printf("\033[30mSua opcao\033[33m: ");

                if (scanf("%d", &opcao) == 1) { // Se a opção inserida for válida
                    opcao_valida = 1; // A variável se torna 1, ou true,equivalente a opção válida e, nesse caso, o loop quebra
                    while (getchar() != '\n'); // Limpa o buffer
                } else { // Caso não for válida
                    printf("\033[31mOpcao Invalida!\033[m\n");
                    while (getchar() != '\n'); // Limpa o buffer
                    //Sleep(2000); // Delay de 2 segundos antes de prosseguir com o programa
                }
            }

            if (opcao > 0 && opcao < 5) {// Somente valida se a opção escolhida estiver no intervalo de uma das 4 do menu
                break; // Quebra o loop while e o programa transcorre
            } else { // Caso contrário, exibe erro
                printf("\033[31mOpcao \033[33m%d \033[31minexistente!\033[m\n", opcao);
                //Sleep(2000); // Delay de 2 segundos antes de prosseguir com o programa
            }
        }

        switch (opcao) { // Verifica qual opcao escolhida e acessa a função de acordo
            case 1: { // Opcao de adicionar cliente

                printf("\033[35m========= \033[36mADICIONAR CLIENTE \033[35m=========\033[m\n");

                printf("Nome do cliente\033[36m: ");
                fgets(cliente, sizeof(cliente), stdin); // Consegue pegar o nome completo do cliente

                printf("\033[32m>>> Cliente adicionado com sucesso! <<<\033[m\n");

                strcpy(lista_clientes[indice], cliente); // Copia o nome do cliente inserido em CLIENTE para o array de LISTA_CLIENTES, na posição do indice corresponde

                indice++; // Incrementa +1 no indice

                printf("\033[35m=====================================\033[m\n");

                //Sleep(3000);// Delay de 3 segundos antes de prosseguir com o programa

                break;

            } case 2: { // Opcao de remover cliente

                printf("\033[35m========= \033[36mREMOVER CLIENTE \033[35m=========\033[m\n");

                int repetir_titulo = 0; // Flag para verificar se é preciso repitir o título se o loop de validação der erro... a pricípio será 'Falso' porque se caso não for, o título "REMOVER CLIENTES" seria printado 2x ,uma no começo do case 2, e outra ao entrar no while de validação

                if (indice > 1) { // Caso exista clientes para exibir seus nomes IDs e nomes;
                    
                    while (1) { // Entra em um loop while de validacao

                        if (repetir_titulo) { // Se for a primeira vez, esse if é ignorado, porém se houver erro, será printado  
                            printf("\033[35m========= \033[36mREMOVER CLIENTE \033[35m=========\033[m\n");
                        }

                        printf("\033[33m%-5s \033[33m%-20s\033[m\n", "Id", "Cliente"); // Tabula ID com 5 espaços alinhados a esquerda e CLIENTE 20 espaços alinhados a esquerda

                        for (int i = 1; i < indice; i++) { // Percorre pelo array LISTA_CLIENTES e exibe seus IDs e nomes, tabulados com as mesmas especificações anterioras, porém para conceber os dados
                            printf("\033[31m%-5d \033[36m%-5s", i, lista_clientes[i]);
                        }   

                        printf("\033[35m===================================\033[m\n");

                        printf("\033[mInsira o Id corresponte ao cliente que deseja remover\033[31m: ");
                        scanf("%d", &id_cliente_remover); // Pega o id do cliente no qual sera removido

                        if (id_cliente_remover > 0 && id_cliente_remover < indice) { // Confere se o Id é válido dentre os listados, se sim, sai do loop while de validacao
                            break;
                        } else { // Se não, persiste até que seja valido
                            printf("\033[31mId invalido!\033[m\n");
                            
                            repetir_titulo = 1; // Equivalente a 'True', o que faz com que o título "REMOVER CLIENTES" seja repetido no próximo loop

                            //Sleep(2000); // Delay de 2 segundos antes de prosseguir com o programa
                        } 
                    }

                    for (int i = id_cliente_remover; i < indice - 1; i++) { // Desloca os clientes para "remover" o cliente no índice id_cliente_remover
                        strcpy(lista_clientes[i], lista_clientes[i + 1]);
                    }

                    indice--; // Índice é decrementado, pois um cliente foi removido

                    printf("\033[32m>>> Cliente removido com sucesso! <<<\033[m\n");

                    printf("\033[35m===================================\033[m\n");

                    //Sleep(4000); // Delay de 4 segundos antes de prosseguir com o programa

                } else { // Caso não exista

                    printf("\033[31mNao ha clientes cadastrados ainda para remocao!\033[m\n");

                    printf("\033[35m===================================\033[m\n");

                    //Sleep(2000); // Delay de 2 segundos antes de prosseguir com o programa
                }

                break;
            } case 3: { // Opcao de ver lista de clientes

                printf("\033[35m========= \033[36mLISTA DE CLIENTES \033[35m=========\033[m\n");

                if (indice > 1) { // Caso exista clientes para exibir seus nomes IDs e nomes;

                    printf("\033[33m%-5s \033[33m%-20s\033[m\n", "Id", "Cliente"); // Tabula ID com 5 espaços alinhados a esquerda e CLIENTE 20 espaços alinhados a esquerda
                    for (int i = 1; i < indice; i++) { // Percorre pelo array LISTA_CLIENTES e exibe seus IDs e nomes, tabulados com as mesmas especificações anterioras, porém para conceber os dados
                        printf("\033[31m%-5d \033[36m%-5s", i, lista_clientes[i]);
                    }

                    printf("\033[35m=====================================\033[m\n");

                    //Sleep(4000); // Delay de 4 segundos antes de prosseguir com o programa
                } else { // Caso não exista
                    printf("\033[31mNao ha clientes cadastrados ainda!\033[m\n");

                    printf("\033[35m=====================================\033[m\n");

                    //Sleep(2000); // Delay de 2 segundos antes de prosseguir com o programa
                }

                break;
            } default: { // Opcao de encerrar o programa

                printf("\033[33mEncerrando programa...\033[m\n");

                //Sleep(3000); // Delay de 4 segundos antes de prosseguir e encerrar o programa

                printf("\033[31m<<< Programa Encerrado! >>>\033[m\n");

                break;
            }
        }

        if (opcao == 4) { // Encerra o programa se opção for 4
            break;
        }
    }

    return 0; // Retorna 0 para indicar que o programa encerrou-se sem erros
}