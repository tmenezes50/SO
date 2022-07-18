#ifndef ESTRUTURA_H_
#define ESTRUTURA_H_

typedef struct posicao{
    int valor;
    long coordenadaX;
    long coordenadaY;

    struct posicao *proximo;
} posicao;

typedef struct {
    posicao *inicio;
    posicao *fim;
    int tamanho;
} lista;

void inicializa (lista *lista);
int ePrimo(int valor);
int inserir(lista *lista, int x, int y, int primo);

#endif


