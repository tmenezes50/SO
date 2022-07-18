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
    long tamanho;
} lista;

lista *inicializa ();
int inserir(lista *plista, long x, long y, int primo);

#endif


