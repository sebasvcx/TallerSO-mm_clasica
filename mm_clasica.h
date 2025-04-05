/**************************************************************
      Pontificia Universidad Javeriana
        Autor: Sebastian Vargas Casquete
        Fecha: Abril 2025
        Materia: Sistemas Operativos
        Tema: Taller de Evaluación de Rendimiento
        Fichero: mm_clasica.h
        Descripcion: Interfaz del módulo de multiplicación de matrices NxN
                     usando hilos POSIX
****************************************************************/

#ifndef MM_CLASICA_H
#define MM_CLASICA_H

#include <sys/time.h>

extern double *mA, *mB, *mC;
extern struct timeval start, stop;

struct parametros {
    int nH;  // Número de hilos
    int idH; // ID del hilo actual
    int N;   // Dimensión de la matriz
};

void llenar_matriz(int SZ);
void print_matrix(int sz, double *matriz);
void* mm_clasica(void *args);
double medir_tiempo();

#endif