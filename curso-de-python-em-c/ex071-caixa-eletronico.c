// #include <stdio.h>

// int main() {

//     int quantidade_sacar = 0;
//     int notas_100 = 0;
//     int notas_50 = 0;
//     int notas_20 = 0; 
//     int notas_10 = 0; 
//     int notas_5 = 0; 
//     int notas_1 = 0;

//     printf("Insira quanto quer sacar: R$");
//     scanf("%d", &quantidade_sacar);

//     while (quantidade_sacar > 0) {

//         printf("%d\n", quantidade_sacar);

//         if (quantidade_sacar >= 100) {
//             notas_100++;
//             quantidade_sacar =- 100;
//         }
//         else if (quantidade_sacar >= 50) {
//             notas_50++;
//             quantidade_sacar =- 50;
//         }
//         else if (quantidade_sacar >= 20) {
//             notas_20++;
//             quantidade_sacar =- 20;
//         }
//         else if (quantidade_sacar >= 10) {
//             notas_10++;
//             quantidade_sacar =- 10;
//         }
//         else if (quantidade_sacar >= 5) {
//             notas_5++;
//             quantidade_sacar =- 5;
//         }
//         else if (quantidade_sacar >= 1) {
//             notas_1++;
//             quantidade_sacar =- 1;
//         }

//     }

//     printf("Notas de 100 reais: %d\n", notas_100);
//     printf("Notas de 50 reais: %d\n", notas_50);
//     printf("Notas de 20 reais: %d\n", notas_20);
//     printf("Notas de 10 reais: %d\n", notas_10);
//     printf("Notas de 5 reais: %d\n", notas_5);
//     printf("Notas de 1 real: %d\n", notas_1);

//     return 0;
// }


// #include <stdio.h>
// #include <math.h>

// int main() {

//     int saque, _100 = 0, _50 = 0, _20 = 0, _10 = 0, _5 = 0, _1 = 0, resto;

//     printf("Insira quanto quer sacar: ");
//     scanf("%d", &saque);

//     resto = saque;

//     _100 = floor(resto / 100);
//     resto %= 100;

//     _50 = floor(resto / 50);
//     resto %= 50;

//     _20 = floor(resto / 20);
//     resto %= 20;

//     _10 = floor(resto / 10);
//     resto %= 10;

//     _5 = floor(resto / 5);
//     resto %= 5;

//     _1 = floor(resto / 1);
//     resto %= 1;

//     if (_100 != 0) {
//         printf("Notas de 100: %d\n", _100);
//     } 
//     if (_50 != 0) {
//         printf("Notas de 50: %d\n", _50);    
//     }
//     if (_20 != 0) {
//         printf("Notas de 20: %d\n", _20);
//     }
//     if (_10 != 0) {
//         printf("Notas de 10: %d\n", _10);
//     }
//     if (_5 != 0) {
//         printf("Notas de 5: %d\n", _5);
//     }
//     if (_1 != 0) {
//         printf("Notas de 1: %d\n", _1);
//     }
    
//     return 0;
// }

#include <stdio.h>
#include <math.h>

int main() {
    int saque, resto;

    // Definindo as denominações das notas
    int notas[] = {100, 50, 20, 10, 5, 1};
    int quantidades[6] = {0};

    printf("Insira quanto quer sacar: ");
    scanf("%d", &saque);

    resto = saque;

    // Calculando a quantidade de cada nota
    for (int i = 0; i < 6; i++) {
        quantidades[i] = resto / notas[i];
        resto %= notas[i];
    }

    // Exibindo as notas, se houver alguma
    for (int i = 0; i < 6; i++) {
        if (quantidades[i] != 0) {
            printf("Notas de %d: %d\n", notas[i], quantidades[i]);
        }
    }

    return 0;
}


