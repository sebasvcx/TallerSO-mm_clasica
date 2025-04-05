/**************************************************************
      Pontificia Universidad Javeriana
        Autor: Sebastian Vargas Casquete
        Fecha: Abril 2025
        Materia: Sistemas Operativos
        Tema: Taller de Evaluación de Rendimiento
        Fichero: main.c
        Descripción: Programa principal que ejecuta la multiplicación
                     de matrices NxN usando hilos POSIX.
****************************************************************/

#include "mm_clasica.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <dimension_matriz> <numero_hilos>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int N = atoi(argv[1]);   // Dimensión de la matriz
    int NH = atoi(argv[2]);  // Número de hilos

    pthread_t hilos[NH];
    struct parametros args[NH];

    llenar_matriz(N); // Inicializa las matrices A, B y C

    gettimeofday(&start, NULL); // Tiempo de inicio

    for (int i = 0; i < NH; i++) {
        args[i].nH = NH;
        args[i].idH = i;
        args[i].N = N;
        pthread_create(&hilos[i], NULL, mm_clasica, &args[i]);
    }

    for (int i = 0; i < NH; i++) {
        pthread_join(hilos[i], NULL);
    }

    gettimeofday(&stop, NULL); // Tiempo final

    printf("Tiempo transcurrido: %.2f ms\n", medir_tiempo());

    print_matrix(N, mC); //  si N es pequeño imprime la matriz 

    return 0;
}
