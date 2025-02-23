#include <stdio.h>

int main() {

    float medida_m, medida_km, medida_hm, medida_dam, medida_dc, medida_cm, medida_mm;

    printf("Indique uma medida em m: ");
    scanf("%f", &medida_m);

    medida_km = medida_m / 1000;
    medida_hm = medida_m / 100;
    medida_dam = medida_m / 10;
    medida_dc = medida_m * 10;
    medida_cm = medida_m * 100;
    medida_mm = medida_m * 1000;

    printf("%.2fm nas unidades fica:\n", medida_m);
    printf("\033[1;33mkm: \033[1;32m%f\n", medida_km);
    printf("\033[1;33mhm: \033[1;32m%f\n", medida_hm);
    printf("\033[1;33mdam: \033[1;32m%f\n", medida_dam);
    printf("\033[1;33mdc: \033[1;32m%f\n", medida_dc);
    printf("\033[1;33mcm: \033[1;32m%f\n", medida_cm);
    printf("\033[1;33mmm: \033[1;32m%f\n", medida_mm);

    return 0;
}