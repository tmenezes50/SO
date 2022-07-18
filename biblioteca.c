#include <stdlib.h>
#include "biblioteca.h"

void randMatriz(int lados, int seed) {
    srand(seed);

    for (long i = 0; i < lados * lados; i++) {
            matriz[i] = 1 + rand() % 100;
        }
}

void enumMatriz(int lados) {
    int contador = 1;

    for (long i = 0; i < lados * lados; i++) {
            matriz[i] = contador;
            if(contador > 30000)
                contador = 0;
            contador++;
        }
}
