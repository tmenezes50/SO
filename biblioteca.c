#include <stdlib.h>
#include <math.h>
#include "biblioteca.h"

void randMatriz(int lados, int seed) {
    srand(seed);

    for (long i = 0; i < lados * lados; i++) {
            matriz[i] = 1 + rand() % 29999;
        }
}

void enumMatriz(int lados) {
    int contador = 1;

    for (long i = 0; i < lados * lados; i++) {
            matriz[i] = contador;
            contador++;
            if(contador > 30000)
                contador = 0;
        }
}

int ePrimo(int valor) {
    if(valor < 3 || (valor % 2 == 0 && valor > 2))
        return 0;
    for(int i = 3; i <= sqrt(valor) + 1; i++) {
        if (valor % i == 0)
            return 0;
    }

    return 1;

}
