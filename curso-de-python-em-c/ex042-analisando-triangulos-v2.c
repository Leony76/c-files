#include <stdio.h>

int main() {

    float l1, l2, l3;

    for (int i = 0; i < 4; i++) {
        printf("Insira o primeiro lado do triangulo: ");
        scanf("%f", &l1);
        fflush(stdout);

        printf("Insira o segundo lado do triangulo: ");
        scanf("%f", &l2);
        fflush(stdout);

        printf("Insira o terceiro lado do triangulo: ");
        scanf("%f", &l3);
        fflush(stdout);

        printf("Com lados %.2f, %.2f e %.2f, o triangulo ", l1, l2, l3);

        if ((l1 < l2 + l3) && (l2 < l1 + l3) && (l3 < l1 + l2)) {
            printf("EXISTE e e um ");
            if ((l1 != l2) && (l2 != l3) && (l3 != l1)) {
                printf("ESCALENO!\n");
            } else if ((l1 == l2) && (l2 == l3) && (l3 == l1)) {
                printf("EQUILATERO!\n");
            } else {
                printf("ISOCELES!\n");
            }
        } else {
            printf("NAO EXISTE!\n");
        }
    }
    return 0;
}