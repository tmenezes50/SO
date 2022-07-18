#include "estrutura.h"
#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>

#define LADOS_MATRIZ 3

#define TRUE 1
#define FALSE 0

int matriz[LADOS_MATRIZ * LADOS_MATRIZ];


int main() {
    int counter = 0;

    enumMatriz(LINHA_DA_MATRIZ, COLUNA_DA_MATRIZ, matriz);

    for(int i = 0; i < LINHA_DA_MATRIZ; i ++) {
    	for(int j = 0; j < COLUNA_DA_MATRIZ; j++) {
    		if(j == COLUNA_DA_MATRIZ - 1)
    			printf("\n");
    	}
    }

    printf("%d", counter);


    return 0;

}
