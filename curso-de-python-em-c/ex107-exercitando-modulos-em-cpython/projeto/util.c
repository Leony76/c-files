#include "util.h"

float metadePreco(float preco) {
    return preco / 2.0;
}

float dobroPreco(float preco) {
    return preco * 2;
}

float _10Aumento(float preco) {
    return preco + (preco * (10/100));
}