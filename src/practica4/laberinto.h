#ifndef LABERINTO_H
#define LABERINTO_H

#define ARRIBA 1
#define ABAJO 2
#define DERECHA 4
#define IZQUIERDA 8

#define REN 27
#define COL 26

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char **Laberinto;

typedef struct
{
  int x, y;
} Coordenada;

typedef struct
{
  int up, down, left, right;
} Movimientos;

Laberinto crear_laberinto(void);
void imprimirLab(unsigned char **lab);

Coordenada *crearCoordenada(int x, int y);
int compararCoordenada(void *a, void *b);
void imprimirCoordenada(void *dato);

unsigned char alternativas(unsigned char **lab, Coordenada *coordenada);
void imprimirPosibles(unsigned char);

Movimientos movimientosPosibles(unsigned char **lab, Coordenada punto);
void imprimirMovimientos(Movimientos movimientos);


// Prueba para cambiar de coordenadas en el laberinto
void setOrigen(Laberinto lab, Coordenada origen);
void setDestino(Laberinto lab, Coordenada destino);
void setAoB(Laberinto lab, Coordenada punto, char caracter);
#endif
