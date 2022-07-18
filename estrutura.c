#include <stdlib.h>
#include "estrutura.h"
#include <math.h>

void inicializa (lista *lista) {
    lista = (lista*)malloc(sizeof(lista));
    if(lista == NULL) {
        return;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

int inserir(lista *lista, int x, int y, int primo) {
    posicao *novo;
    novo = (posicao*)malloc(sizeof(posicao));
    if(novo == NULL) {
        return -1;
    }

    novo->coordenadaX = x;
    novo->coordenadaY = y;
    novo->valor = primo;
    novo->proximo = NULL;

    if(lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    lista->tamanho ++;
    return 0;
}

int ePrimo(int valor) {
    if(valor < 3 || (valor % 2 == 0 && valor > 2)) {
        return 0;
    }

    for(int i = 3; i < sqrt(valor) + 1; i++) {
        if(valor % i == 0) {
            return 0;
        }
    }
    return 1;
}
