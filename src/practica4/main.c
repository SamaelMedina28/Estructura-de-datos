#include "laberinto.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i;

  unsigned char **lab;
  lab = crear_laberinto();

  Coordenada punto = {10, 13};

  lab[punto.x][punto.y] = 'o';
  imprimirLab(lab);
  Movimientos mov = movimientosPosibles(lab, punto);
  imprimirMovimientos(mov);

  printf("\n");
  // ARRIBA
  if (mov.up == 1)
  {
    lab[punto.x][punto.y] = '.';
    punto = (Coordenada){punto.x - 1, punto.y};
  }
  // ABAJO
  else if (mov.down == 1)
  {
    lab[punto.x][punto.y] = '.';
    punto = (Coordenada){punto.x + 1, punto.y};
  }
  // DERECHA
  else if (mov.right == 1)
  {
    lab[punto.x][punto.y] = '.';
    punto = (Coordenada){punto.x, punto.y + 1};
  }
  // IZQUIERDA
  else if (mov.left == 1)
  {
    lab[punto.x][punto.y] = '.';
    punto = (Coordenada){punto.x, punto.y - 1};
  }

  lab[punto.x][punto.y] = 'o';

  imprimirLab(lab);

  for (i = 0; i < REN; i++)
    free(lab[i]);
  free(lab);

  printf("\n\n");
  return 0;
}
