#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// OBSERVAÇÃO:

//  \033[m = Simboliza cores no terminal, ou seja, \033[31m por exemplo, pinta a linha posterior a esse comando de vermelho... apenas por título de informação; Link de um vídeo que explica melhor: (https://www.youtube.com/watch?v=0hBIhkcA8O8&t=7s)

// FUNÇÕES

//   CORES: const char* = Função do tipo constante que retorna strings literais, ou seja, que são armazenadas em uma seção de memória estática e não são destruídas após a função retornar

const char* corCinza() { return "\033[30m"; } 
const char* corVermelha() { return "\033[31m"; }
const char* corVerde() { return "\033[32m"; }
const char* corAmarela() { return "\033[33m"; }
const char* corAzulEscuro() { return "\033[34m"; }
const char* corRoxa() { return "\033[35m"; }
const char* corAzulClaro() { return "\033[36m"; }
const char* resetarCor() { return "\033[m"; }


void menuOpcoes() { // Função que exibe o menu de opções

    printf("%s<================< %sMENU %s>================>%s\n", corRoxa(), corAzulClaro(), corRoxa(), resetarCor());

    printf("%s[ 1 ] %sAdicionar cliente\n", corAmarela(), corVerde());
    printf("%s[ 2 ] %sRemover cliente\n", corAmarela(), corVerde());
    printf("%s[ 3 ] %sVer lista de clientes\n", corAmarela(), corVerde());        
    printf("%s[ 4 ] %sEncerrar programa\n", corAmarela(), corVermelha());

    printf("%s<===================%s<>%s===================>%s\n", corRoxa(), corAzulClaro(), corRoxa(), resetarCor());

}

void prosseguir() { // Função apenas para ter algo que segure o fluxo do programa em algum trecho

    char prosseguir;
    printf("%sPressione 'Enter' para continuar!%s", corCinza(), resetarCor());
    scanf("%c", &prosseguir); // Apenas para ter algo que segure o fluxo do programa

}

void erroIdInvalido() { // Função que exibe mensagem de erro do tipo: "Id inválido"
    printf("%s+----------------+%s\n", corVermelha(), resetarCor());
    printf("%s|(!) Id invalido!|%s\n", corVermelha(), resetarCor());
    printf("%s+----------------+%s\n", corVermelha(), resetarCor());
}

void erroSemClientes() { // Função que exibe mensagem de erro caso não haja clientes cadastrados na lista
    printf("%s+--------------------------------------+%s\n", corVermelha(), resetarCor());
    printf("%s|(!) Nao ha clientes cadastrados ainda!|%s\n", corVermelha(), resetarCor());
    printf("%s+--------------------------------------+%s\n", corVermelha(), resetarCor());
}

void erroSemClientesRemocao() { // Função que exibe mensagem de erro caso não haja clientes cadastrados na lista para remoção
    printf("%s+---------------------------------------------------+%s\n", corVermelha(), resetarCor());
    printf("%s|(!) Nao ha clientes cadastrados ainda para remocao!|%s\n", corVermelha(), resetarCor());
    printf("%s+---------------------------------------------------+%s\n", corVermelha(), resetarCor());
}

void erroOpcaoInvalida() { // Função que exibe mensagem de erro do tipo: "Opção inválido"
    printf("%s+-------------------+%s\n", corVermelha(), resetarCor());
    printf("%s|(!) Opcao Invalida!|%s\n", corVermelha(), resetarCor());
    printf("%s+-------------------+%s\n", corVermelha(), resetarCor());
}

void erroOpcaoInexistente(int opcao) { // Função que exibe mensagem de erro do tipo: "Opção inexistente"
    printf("%s+------------------------+%s\n", corVermelha(), resetarCor());
    printf("%s|(!) Opcao %s%d %sinexistente!|%s\n", corVermelha(), corAmarela(), opcao, corVermelha(), resetarCor());
    printf("%s+------------------------+%s\n", corVermelha(), resetarCor());
}

void linhaAdicionarCliente() { // Função que exibe linhas delimitadoras para o menu de "Adicionar cliente"
    printf("%s<===================%s<>%s====================>%s\n", corAzulClaro(), corAmarela(), corAzulClaro(), resetarCor());
}

void linhaRemoverCliente() { // Função que exibe linhas delimitadoras para o menu de "Remover cliente"
    printf("%s<===================%s<>%s====================>%s\n", corAzulClaro(), corVermelha(), corAzulClaro(), resetarCor());
}

void linhaListarClientes() { // Função que exibe linhas delimitadoras para o menu de "Listar clientes"
    printf("%s<====================%s<>%s===================>%s\n", corAmarela(), corVerde(), corAmarela(), resetarCor());
}

void limparBuffer() { // Função sem retorno que "limpa" o buffer de entrada até que a linha inteira seja consumida, ou seja, até que o usuário pressione "Enter". Isso é útil para garantir que qualquer entrada residual (como caracteres extras ou espaços) seja descartada antes de continuar o programa.
    while (getchar() != '\n');
}

void removerBarraZero(char str[]) { // Função sem retorno que remove o '\0' que todo cadeida de caractres em C possui, para possibilitar comparação de o valor de um string caso necessário 
    str[strcspn(str, "\n")] = 0;
}

void adicionarCliente(char lista_clientes[101][50], int *indice) { // Função sem retorno (void) que adiciona o nome do cliente na lista de clientes... Nela há dois parâmetros, o "char lista_clientes[101][50]" que recebe a lista dos clientes e o "int *indice", que é para receber o índice com ponteiro apontando para a variável "indice" na função "int main(), para que seja possível alterar o valor dela a partir dessa função"

    char cliente[50];

    printf("%s<==========< %sADICIONAR CLIENTE %s>==========>%s\n", corAzulClaro(), corAmarela(), corAzulClaro(), resetarCor());

    printf("%s(!) digite 'sair' para cancelar a acao%s\n", corCinza(), resetarCor());
    printf("Nome do cliente%s: ", corAzulEscuro());

    fgets(cliente, sizeof(cliente), stdin); // Consegue pegar o nome    completo do cliente

    removerBarraZero(cliente); // Remove o '\0' presente no que for digitado na variável 'cliente' para viabilizar uma comparação com 'strcmp'

    if (strcmp(cliente, "sair") != 0) { // Se o que foi digitado não for 'sair', a função desempenha seu propósito, se não, passa direto

        printf("%s>>> Cliente adicionado com sucesso! <<<%s\n", corVerde(), resetarCor());

        strcpy(lista_clientes[*indice], cliente); // Copia o nome do cliente inserido em CLIENTE para o array de LISTA_CLIENTES, na posição do indice corresponde
    
        (*indice)++; // Incrementa +1 no indice apontado no int main()
        
        linhaAdicionarCliente(); // Exibe um linha roxa
    
        prosseguir(); // Função que para o fluxo do programa até que seja pressionado 'enter'
    }

}

void removerCliente(char lista_clientes[101][50], int *indice) { // Função sem retorno (void) que remove o nome do cliente na lista de clientes... Nela há dois parâmetros, o "char lista_clientes[101][50]" que recebe a lista dos clientes e o "int *indice", que é para receber o índice com ponteiro apontando para a variável "indice" na função "int main(), para que seja possível alterar o valor dela a partir dessa função"

    int id_cliente_remover;

    printf("%s<===========< %sREMOVER CLIENTE %s>===========>%s\n", corAzulClaro(), corVermelha(), corAzulClaro(), resetarCor());

    int repetir_titulo = 0; // Flag para verificar se é preciso repitir o título se o loop de validação der erro... a pricípio será 'Falso' porque se caso não for, o título "REMOVER CLIENTES" seria printado 2x ,uma no começo do case 2, e outra ao entrar no while de validação

    if (*indice > 1) { // Caso exista clientes para exibir seus nomes IDs e nomes;
        
        while (1) { // Entra em um loop while de validacao

            if (repetir_titulo) { // Se for a primeira vez, esse if é ignorado, porém se houver erro, será printado  
                printf("%s<===========< %sREMOVER CLIENTE %s>===========>%s\n", corAzulClaro(), corVermelha(), corAzulClaro(), resetarCor());
            }

            printf("%s%-5s %-20s%s\n", corCinza(), "Id", "Cliente", resetarCor()); // Tabula ID com 5 espaços alinhados a esquerda e CLIENTE 20 espaços alinhados a esquerda

            for (int i = 1; i < *indice; i++) { // Percorre pelo array LISTA_CLIENTES e exibe seus IDs e nomes, tabulados com as mesmas especificações anterioras, porém para conceber os dados
                printf("%s%-5d %s%-5s\n", corVermelha(), i, corAzulEscuro(), lista_clientes[i]);
            }   

            linhaRemoverCliente(); // Exibe um linha roxa

            printf("%s(!) Digite '0' para cancelar a acao%s\n", corCinza(), resetarCor());

            printf("Digite o Id corresponte ao cliente que deseja remover%s: ", corVermelha());
            scanf("%d", &id_cliente_remover); // Pega o id do cliente no qual sera removido

            if (id_cliente_remover != 0) { // Caso o id digitado não for '0', a função desempenha sua tarefa, se não , passa direto

                if ((id_cliente_remover > 0) && (id_cliente_remover < *indice)) { // Confere se o Id é válido dentre os listados, se sim, sai do loop while de validacao

                    limparBuffer(); // Limpa o buffer
    
                    break;
    
                } else { // Se não, persiste até que seja valido
    
                    erroIdInvalido(); // Exibe uma mensagem de erro do tipo "Id inválido"
    
                    limparBuffer(); // Limpa o buffer
    
                    repetir_titulo = 1; // Equivalente a 'True', o que faz com que o título "REMOVER CLIENTES" seja repetido no próximo loop
    
                }

            }

            if (id_cliente_remover == 0) { // Caso for digitado '0' (cancelar ação), quebra loop while
                break;
            }

        }

        if (id_cliente_remover != 0) { // Caso 'id_cliente_remover' for diferente de '0', o resto do fluxo do programa segue normalmente, se não, é ignorado  

            for (int i = id_cliente_remover; i < *indice - 1; i++) { // Desloca os clientes para "remover" o cliente no índice id_cliente_remover
                strcpy(lista_clientes[i], lista_clientes[i + 1]);
            }
    
            (*indice)--; // Índice apontado do int main() é decrementado, pois um cliente foi removido
    
            printf("%s>>> Cliente removido com sucesso! <<<%s\n", corVerde(), resetarCor());
    
            linhaRemoverCliente(); // Exibe um linha roxa
    
            prosseguir(); // Função que para o fluxo do programa até que seja pressionado 'enter'

        } 

    } else { // Caso não exista

        erroSemClientesRemocao(); // Exibe uma mensagem de erro exclarecendo que não há clientes na lista para remoção

        linhaRemoverCliente(); // Exibe um linha roxa

        prosseguir(); // Função que para o fluxo do programa até que seja pressionado 'enter'

    }
    
}

void listarClientes(char lista_clientes[101][50], int indice) { // Função sem retorno (void) que lista o nome dos clientes na lista de clientes... Nela há dois parâmetros, o "char lista_clientes[101][50]" que recebe a lista dos clientes e o "int indice", que é para receber o índice do int main()... perceba que "int indice" não está com ponteiro, pois nesse caso não haverá incremento ou decremento nela, apenas será lido o valor 

    printf("%s<==========< %sLISTA DE CLIENTES %s>==========>%s\n", corAmarela(), corVerde(), corAmarela(), resetarCor());

    if (indice > 1) { // Caso exista clientes para exibir seus nomes IDs e nomes;

        printf("%s%-5s %-20s%s\n", corCinza(), "Id", "Cliente", resetarCor()); // Tabula ID com 5 espaços alinhados a esquerda e CLIENTE 20 espaços alinhados a esquerda
        for (int i = 1; i < indice; i++) { // Percorre pelo array LISTA_CLIENTES e exibe seus IDs e nomes, tabulados com as mesmas especificações anterioras, porém para conceber os dados
            printf("%s%-5d %s%-5s\n", corVermelha(), i, corAzulEscuro(), lista_clientes[i]);
        }

        linhaListarClientes(); // Exibe um linha roxa

    } else { // Caso não exista

        erroSemClientes(); // Exibe uma mensagem de erro exclarecendo que nã há clientes na lista

        linhaListarClientes(); // Exibe um linha roxa

    }

    prosseguir(); // Função que para o fluxo do programa até que seja pressionado 'enter'

}

int encerrarPrograma(int confirmar_encerrar, int confirmar_encerrar_valido, int continuar) { // Função com retorno que desempenha o processo de encerrar o programa, no caso ela irá retorna um número inteiro de valor '1' (true) ou '0' (false) que servirá como verificação depois

    while (1) { // Loop while de validação 

        while (!confirmar_encerrar_valido) { // Loop while de validação que só sairá caso a variável 'confirmar_encerrar_valido' se torne 1 (true)

            printf("%sConfirma Sair?%s: (1 = sim / 0 = nao)%s ", corAmarela(), corRoxa(), corVermelha());

            if (scanf("%d", &confirmar_encerrar) == 1) { // Se a opção inserida for válida

                confirmar_encerrar_valido = 1; // A variável se torna 1, ou true, equivalente a opção válida e, nesse caso, o loop quebra

                limparBuffer(); // Limpa o buffer

            } else {

                erroOpcaoInvalida(); // Exibe uma mensagem de erro do tipo "Opção inválida"

                limparBuffer(); // Limpa o buffer

            }       
        }

        if ((confirmar_encerrar >= 0) && (confirmar_encerrar < 2)) { // Só será validado se for digitado 1 ou 0

            if (confirmar_encerrar == 1) { // Se for digitado 1, O programa se encerra de fato

                printf("%s<<< Programa Encerrado! >>>%s\n", corVermelha(), resetarCor());

                return continuar; // A função retorna a variável 'continuar' com valor 0 (false)

            } else {

                continuar = 1; // Se for digitado 0, a variável 'continuar' se torna 'true', o que imperdirá o encerramento do laço posteriormente 

                return continuar; // A função retorna a variável 'continuar' com valor 0 (false)

            }
        } else {

            erroOpcaoInvalida(); // Exibe uma mensagem de erro do tipo "Opção inválida"

        }

    }

}

int main(int argc, char *argv[]) { // Esse "int argc, char *argv[]" em um breve resumo, permite passar informações para o programa diretamente pela linha de comando, como cmd prompt... (Não tem interferência alguma no funcionamento do programa) 

    char lista_clientes[101][50]; strcpy(lista_clientes[0], "Inicializando array com indice 1"); // Apenas desloquei o indice do array que se inializa com '0' colocando uma string qualquer para que ele se inicialize com '1', para inteirar os IDs dos clientes 
    int opcao, opcao_valida;
    int indice = 1;
    int confirmar_encerrar, confirmar_encerrar_valido, continuar;

    while (1) { // Loop while principal por onde todo programa principal transcorre
        while (1) { // Loop while que valida uma das opções do menu, caso seja selecionado uma delas (de 1 a 4), o loop é quebrado e o programa transcorre    

            opcao_valida = 0; // Inicializo como inválida para depois se for válida se tornar válida (verificação que a tornará ou não)

            // Para esse caso: (0 = false ; 1 = true) , não existe boolean em C

            while (!opcao_valida) {// Verificação para ver se essa variável é válida, no caso, enquanto ela for inválida(0), o loop continuará perguntando até que seja digitado uma opção válida dentre as 4 citadas no menu

                menuOpcoes(); // Exibe o menu de opções

                printf("%sSua opcao%s: ", corCinza(), corAmarela());

                if (scanf("%d", &opcao) == 1) { // Se a opção inserida for válida

                    opcao_valida = 1; // A variável se torna 1, ou true,equivalente a opção válida e, nesse caso, o loop quebra
                    
                    limparBuffer(); // Limpa o buffer

                } else { // Caso não for válida

                    erroOpcaoInvalida(); // Exibe uma mensagem de erro do tipo "Opção inválida"

                    limparBuffer(); // Limpa o buffer
                    
                }
            }

            if (opcao > 0 && opcao < 5) {// Somente valida se a opção escolhida estiver no intervalo de uma das 4 do menu

                break; // Quebra o loop while e o programa transcorre

            } else { // Caso contrário, exibe erro

                erroOpcaoInexistente(opcao); // Exibe uma mensagem de erro do tipo "Opção inexistente"

            }

        }

        switch (opcao) { // Verifica qual opcao escolhida e acessa a função de acordo

            case 1: { // Opcao de adicionar cliente

                adicionarCliente(lista_clientes, &indice);

                break; // Quebra o case do switch

            } case 2: { // Opcao de remover cliente

                removerCliente(lista_clientes, &indice);

                break; // Quebra o case do switch

            } case 3: { // Opcao de ver lista de clientes

                listarClientes(lista_clientes, indice);

                break; // Quebra o case do switch

            } default: { // Opcao de encerrar o programa

                continuar = 0; // Uma flag que servirá como veficação no final
                confirmar_encerrar_valido = 0; // Inicializo como inválida para depois se for válida se tornar válida (verificação que a tornará ou não)
                confirmar_encerrar = 0; // Inicializo como inválida para depois se for válida se tornar válida (verificação que a tornará ou não)

                // Para esse caso: (0 = false ; 1 = true) , não existe boolean em C

                continuar = encerrarPrograma(confirmar_encerrar, confirmar_encerrar_valido, continuar); // Aqui a variável 'continuar' vai receber o retorno da função que será ou '1' (true) ou '0' (false)

                break; // Quebra o case do switch

            }

        }

        if ((opcao == 4) && (!continuar)) { // Encerra o programa se opção escolhida no menu for 4 e se houver confirmação que queria encerrar (No caso se a variável 'continuar' tiver resultado 0 (false))

            break; // Quebra o loop while principal do código e o pragrama se encerra

        }

    }

    return 0; // Retorna 0 para indicar que o programa encerrou-se sem erros
}