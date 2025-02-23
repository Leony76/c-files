#include <stdio.h>

struct Tupla {
    char _0[20], _1[20], _2[20], _3[20], _4[20], _5[20], _6[20], _7[20], _8[20], _9[20], _10[20], _11[20], _12[20], _13[20], _14[20], _15[20], _16[20], _17[20], _18[20], _19[20], _20[20];
};


int main() {

    struct Tupla t = {"Zero", "Um", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Onze", "Doze", "Treze", "Catorze", "Quinze", "Dizesseis", "Dizessete", "Dezoito", "Dizenove", "Vinte"};

    int numero ;

        printf("Insira um numero entre 0 e 20: ");
        scanf("%d", &numero);

        while (numero < 0 || numero > 20) {
            printf("Numero invalido! Digite um numero entre 0 e 20: ");
            scanf("%d", &numero);
        }
    
        switch (numero) {
            case 0: printf("Voce citou o numero: %s\n",t._0); break;
            case 1: printf("Voce citou o numero: %s\n",t._1); break;
            case 2: printf("Voce citou o numero: %s\n",t._2); break;
            case 3: printf("Voce citou o numero: %s\n",t._3); break;
            case 4: printf("Voce citou o numero: %s\n",t._4); break;
            case 5: printf("Voce citou o numero: %s\n",t._5); break;
            case 6: printf("Voce citou o numero: %s\n",t._6); break;
            case 7: printf("Voce citou o numero: %s\n",t._7); break;
            case 8: printf("Voce citou o numero: %s\n",t._8); break;
            case 9: printf("Voce citou o numero: %s\n",t._9); break;
            case 10: printf("Voce citou o numero: %s\n",t._10); break;
            case 11: printf("Voce citou o numero: %s\n",t._11); break;
            case 12: printf("Voce citou o numero: %s\n",t._12); break;
            case 13: printf("Voce citou o numero: %s\n",t._13); break;
            case 14: printf("Voce citou o numero: %s\n",t._14); break;
            case 15: printf("Voce citou o numero: %s\n",t._15); break;
            case 16: printf("Voce citou o numero: %s\n",t._16); break;
            case 17: printf("Voce citou o numero: %s\n",t._17); break;
            case 18: printf("Voce citou o numero: %s\n",t._18); break;
            case 19: printf("Voce citou o numero: %s\n",t._19); break;
            case 20: printf("Voce citou o numero: %s\n",t._20); break;
        }       

    return 0;
}