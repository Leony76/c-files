#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* corCinza() { return "\033[30m"; } 
const char* corVermelha() { return "\033[31m"; }
const char* corVerde() { return "\033[32m"; }
const char* corAmarela() { return "\033[33m"; }
const char* corAzulEscuro() { return "\033[34m"; }
const char* corRoxa() { return "\033[35m"; }
const char* corAzulClaro() { return "\033[36m"; }
const char* resetarCor() { return "\033[m"; }

void menuOpcoes() {
    printf("%s============= %sMENU %s=============%s\n", corRoxa(), corAzulClaro(), corRoxa(), resetarCor());
    printf("%s[ 1 ] %sAdicionar cliente\n", corAmarela(), corVerde());
    printf("%s[ 2 ] %sRemover cliente\n", corAmarela(), corVerde());
    printf("%s[ 3 ] %sVer lista de clientes\n", corAmarela(), corVerde());        
    printf("%s[ 4 ] %sEncerrar programa\n", corAmarela(), corVermelha());
    printf("%s================================%s\n", corRoxa(), resetarCor());
}

void prosseguir() {
    char prosseguir;
    printf("%sPressione 'Enter' para continuar!%s", corCinza(), resetarCor());
    scanf("%c", &prosseguir);
}

void erroIdInvalido() {
    printf("%s+----------------+%s\n", corVermelha(), resetarCor());
    printf("%s|(!) Id invalido!|%s\n", corVermelha(), resetarCor());
    printf("%s+----------------+%s\n", corVermelha(), resetarCor());
}

void erroSemClientes() {
    printf("%s+--------------------------------------+%s\n", corVermelha(), resetarCor());
    printf("%s|(!) Nao ha clientes cadastrados ainda!|%s\n", corVermelha(), resetarCor());
    printf("%s+--------------------------------------+%s\n", corVermelha(), resetarCor());
}

void erroSemClientesRemocao() {
    printf("%s+---------------------------------------------------+%s\n", corVermelha(), resetarCor());
    printf("%s|(!) Nao ha clientes cadastrados ainda para remocao!|%s\n", corVermelha(), resetarCor());
    printf("%s+---------------------------------------------------+%s\n", corVermelha(), resetarCor());
}

void erroOpcaoInvalida() {
    printf("%s+-------------------+%s\n", corVermelha(), resetarCor());
    printf("%s|(!) Opcao Invalida!|%s\n", corVermelha(), resetarCor());
    printf("%s+-------------------+%s\n", corVermelha(), resetarCor());
}

void erroOpcaoInexistente(int opcao) {
    printf("%s+------------------------+%s\n", corVermelha(), resetarCor());
    printf("%s|(!) Opcao %s%d %sinexistente!|%s\n", corVermelha(), corAmarela(), opcao, corVermelha(), resetarCor());
    printf("%s+------------------------+%s\n", corVermelha(), resetarCor());
}

void linhaAdicionarCliente() {
    printf("%s======================================%s\n", corRoxa(), resetarCor());
}

void linhaRemoverCliente() {
    printf("%s===================================%s\n", corRoxa(), resetarCor());
}

void linhaListarClientes() {
    printf("%s=====================================%s\n", corRoxa(), resetarCor());
}

void limparBuffer() {
    while (getchar() != '\n');
}

void removerBarraZero(char str[]) {
    str[strcspn(str, "\n")] = 0;
}

void adicionarCliente(char lista_clientes[101][50], int *indice) {
    char cliente[50];
    printf("%s========= %sADICIONAR CLIENTE %s=========%s\n", corRoxa(), corAzulClaro(), corRoxa(), resetarCor());
    printf("Nome do cliente %s(digite 'sair' para cancelar)%s: ", corCinza(), corAzulEscuro());
    fgets(cliente, sizeof(cliente), stdin);
    removerBarraZero(cliente);
    if (strcmp(cliente, "sair") != 0) {
        printf("%s>>> Cliente adicionado com sucesso! <<<%s\n", corVerde(), resetarCor());
        strcpy(lista_clientes[*indice], cliente);
        (*indice)++;
        linhaAdicionarCliente();
        prosseguir();
    }
}

void removerCliente(char lista_clientes[101][50], int *indice) {
    int id_cliente_remover;
    int repetir_titulo = 0;
    if (*indice > 1) {
        while (1) {
            if (repetir_titulo) {
                printf("%s========= %sREMOVER CLIENTE %s=========%s\n", corRoxa(), corAzulClaro(), corRoxa(), resetarCor());
            }
            printf("%s%-5s %-20s%s\n", corAmarela(), "Id", "Cliente", resetarCor());
            for (int i = 1; i < *indice; i++) {
                printf("%s%-5d %s%-5s\n", corVermelha(), i, corAzulEscuro(), lista_clientes[i]);
            }
            linhaRemoverCliente();
            printf("%sInsira o Id corresponte ao cliente que deseja remover %s(Digite '0' para cancelar)%s: ", resetarCor(), corCinza(), corVermelha());
            scanf("%d", &id_cliente_remover);
            if (id_cliente_remover != 0) {
                if ((id_cliente_remover > 0) && (id_cliente_remover < *indice)) {
                    limparBuffer();
                    break;
                } else {
                    erroIdInvalido();
                    limparBuffer();
                    repetir_titulo = 1;
                }
            }
            if (id_cliente_remover == 0) {
                break;
            }
        }
        if (id_cliente_remover != 0) {
            for (int i = id_cliente_remover; i < *indice - 1; i++) {
                strcpy(lista_clientes[i], lista_clientes[i + 1]);
            }
            (*indice)--;
            printf("%s>>> Cliente removido com sucesso! <<<%s\n", corVerde(), resetarCor());
            linhaRemoverCliente();
            prosseguir();
        }
    } else {
        erroSemClientesRemocao();
        linhaRemoverCliente();
        prosseguir();
    }
}

void listarClientes(char lista_clientes[101][50], int indice) {
    printf("%s========= %sLISTA DE CLIENTES %s=========%s\n", corRoxa(), corAzulClaro(), corRoxa(), resetarCor());
    if (indice > 1) {
        printf("%s%-5s %-20s%s\n", corAmarela(), "Id", "Cliente", resetarCor());
        for (int i = 1; i < indice; i++) {
            printf("%s%-5d %s%-5s\n", corVermelha(), i, corAzulEscuro(), lista_clientes[i]);
        }
        linhaListarClientes();
    } else {
        erroSemClientes();
        linhaListarClientes();
    }
    prosseguir();
}

int encerrarPrograma(int confirmar_encerrar, int confirmar_encerrar_valido, int continuar) {
    while (1) {
        continuar = 0;
        confirmar_encerrar_valido = 0;
        while (!confirmar_encerrar_valido) {
            printf("%sConfirma Sair?%s: (1 = sim / 0 = nao)%s ", corAmarela(), corRoxa(), corVermelha());
            if (scanf("%d", &confirmar_encerrar) == 1) {
                confirmar_encerrar_valido = 1;
                limparBuffer();
            } else {
                erroOpcaoInvalida();
                limparBuffer();
            }
        }
        if ((confirmar_encerrar >= 0) && (confirmar_encerrar < 2)) {
            if (confirmar_encerrar == 1) {
                printf("%s<<< Programa Encerrado! >>>%s\n", corVermelha(), resetarCor());
                return continuar;
            } else {
                continuar = 1;
                return continuar;
            }
        } else {
            erroOpcaoInvalida();
        }
    }
}

int main(int argc, char *argv[]) {
    char lista_clientes[101][50]; strcpy(lista_clientes[0], "Inicializando array com indice 1");
    int opcao, opcao_valida;
    int indice = 1;
    int confirmar_encerrar, confirmar_encerrar_valido, continuar;
    while (1) {
        while (1) {
            opcao_valida = 0;
            while (!opcao_valida) {
                menuOpcoes();
                printf("%sSua opcao%s: ", corCinza(), corAmarela());
                if (scanf("%d", &opcao) == 1) {
                    opcao_valida = 1;
                    limparBuffer();
                } else {
                    erroOpcaoInvalida();
                    limparBuffer();
                }
            }
            if (opcao > 0 && opcao < 5) {
                break;
            } else {
                erroOpcaoInexistente(opcao);
            }
        }
        switch (opcao) {
            case 1:
                adicionarCliente(lista_clientes, &indice);
                break;
            case 2:
                removerCliente(lista_clientes, &indice);
                break;
            case 3:
                listarClientes(lista_clientes, indice);
                break;
            default:
                continuar = encerrarPrograma(confirmar_encerrar, confirmar_encerrar_valido, continuar);
                break;
        }
        if ((opcao == 4) && (!continuar)) {
            break;
        }
    }
    return 0;
}
