#include <stdio.h>
#include <math.h>

int main() {

    int n, dobro, triplo;
    float raiz;
    
    printf("Digite um numero para ver seu dobro, triplo, raiz quadrada: ");
    scanf("%d", &n);

    dobro = n * 2;
    triplo = n * 3;
    raiz = sqrt(n);

    printf("O dobro de %d e %d, o triplo, %d e a raiz quadrada, %.2f !", n, dobro, triplo, raiz);

    return 0;
}