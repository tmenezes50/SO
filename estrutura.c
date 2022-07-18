#include <stdlib.h>
#include "estrutura.h"

lista *inicializa () {

    lista *plista = (lista*)malloc(sizeof(lista));
    plista->inicio = NULL;
    plista->fim = NULL;
    plista->tamanho = 0;
    return plista;
}

int inserir(lista *plista, long x, long y, int primo) {
    posicao *novo;
    novo = (posicao*)malloc(sizeof(posicao));
    if(novo == NULL) {
        return -1;
    }

    novo->coordenadaX = x;
    novo->coordenadaY = y;
    novo->valor = primo;
    novo->proximo = NULL;

    if(plista->inicio == NULL) {
        plista->inicio = novo;
        plista->fim = novo;
    } else {
        plista->fim->proximo = novo;
        plista->inicio = novo;
    }
    plista->tamanho ++;
    return 0;
}