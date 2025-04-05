/**************************************************************
      Pontificia Universidad Javeriana
        Autor: Sebastian Vargas Casquete
        Fecha: Abril 2025
        Materia: Sistemas Operativos
        Tema: Taller de Evaluación de Rendimiento
        Fichero: mm_clasica.c
        Descripcion: Implementación modular de la multiplicación de matrices
                     NxN usando hilos POSIX.
****************************************************************/

#include "mm_clasica.h"
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

struct timeval start, stop;

#define DATA_SIZE (1024*1024*64*3)

pthread_mutex_t MM_mutex;
static double MEM_CHUNK[DATA_SIZE];
double *mA, *mB, *mC;

void llenar_matriz(int SZ) {
    srand48(time(NULL));
    mA = MEM_CHUNK;
    mB = mA + SZ*SZ;
    mC = mB + SZ*SZ;

    for(int i = 0; i < SZ*SZ; i++) {
        mA[i] = 1.1 * i;
        mB[i] = 2.2 * i;
        mC[i] = 0;
    }
}

void print_matrix(int sz, double *matriz) {
    if (sz <= 10) {
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                printf("%f ", matriz[i * sz + j]);
            }
            printf("\n");
        }
    }
}

void* mm_clasica(void *args) {
    struct parametros *p = (struct parametros *) args;
    int nH = p->nH;
    int idH = p->idH;
    int N = p->N;

    int i, j, k;
    int ini = idH * (N / nH);
    int fin = (idH + 1) * (N / nH);

    for (i = ini; i < fin; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                mC[i * N + j] += mA[i * N + k] * mB[k * N + j];
            }
        }
    }

    pthread_exit(0);
}

double medir_tiempo() {
    return (double)((stop.tv_sec - start.tv_sec) * 1000 + 
                    (stop.tv_usec - start.tv_usec) / 1000.0);
}
