#include "biblioteca.h"
#include "estrutura.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>


#define LADOS_MATRIZ 25000
#define NUM_THREADS 2
#define SIZE_BLOCO (LADOS_MATRIZ*LADOS_MATRIZ)/NUM_THREADS
#define TRUE 1
#define FALSE 0
#define TIMELONG(tv) (tv.tv_sec*1000000 + tv.tv_usec) 

int threadID[NUM_THREADS];
pthread_t threadList[NUM_THREADS];
pthread_mutex_t travaThreads = PTHREAD_MUTEX_INITIALIZER;


int matriz[LADOS_MATRIZ*LADOS_MATRIZ];
lista *primoLista;
void *primoThread(void* pacote);

struct timeval inicio, fim;

int main() {

    printf("Criando a matriz...\n\n");

    primoLista = inicializa();
    randMatriz(LADOS_MATRIZ, 2);

    printf("Verificando números de primos na matriz...\n\n");

    
    gettimeofday(&inicio, NULL);
    for (int i = 0; i < NUM_THREADS; i++){
        threadID[i] = i;
        pthread_create(&threadList[i], NULL, primoThread,(void*) &threadID[i]);
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threadList[i], NULL);
    }

    gettimeofday(&fim, NULL);

    printf("Achamos %ld primos\n\n", primoLista->tamanho);
    printf("Tempo de execução: %ld ms\n\n", (TIMELONG(fim) - TIMELONG(inicio))/1000);
    return 0;

}

void *primoThread(void* pacote) {
    int thread_id = *(int*) pacote;
    long inicio = thread_id * SIZE_BLOCO;
    long fim = (thread_id + 1) * SIZE_BLOCO - 1;
    for (long i = inicio; i < fim; i++) {
        if (ePrimo(matriz[i]) == 1) {
            pthread_mutex_lock(&travaThreads);
            inserir(primoLista, (i/LADOS_MATRIZ), (i%LADOS_MATRIZ), matriz[i]);
            pthread_mutex_unlock(&travaThreads);
        }
    }
    pthread_exit(NULL);
    
}