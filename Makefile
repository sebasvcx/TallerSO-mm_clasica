#**************************************************************
#      Pontificia Universidad Javeriana
#        Autor: Sebastian Vargas Casquete
#        Fecha: Abril 2025
#        Materia: Sistemas Operativos
#        Tema: Taller de Evaluación de Rendimiento
#        Fichero: Makefile
#        Descripción: Compila el programa modular de multiplicación de
#                     matrices con pthreads.
#**************************************************************

CC = gcc
CFLAGS = -Wall -pthread

all: mm_clasica

mm_clasica: main.c mm_clasica.c mm_clasica.h
	$(CC) $(CFLAGS) -o mm_clasica main.c mm_clasica.c

clean:
	rm -f mm_clasica