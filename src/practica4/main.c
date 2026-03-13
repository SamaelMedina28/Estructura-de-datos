#include "laberinto.h"
#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i, j;
  Laberinto lab = crear_laberinto();

  Coordenada* nuevoOrigen = crearCoordenada(3,13);
  Coordenada* nuevoDestino = crearCoordenada(20,1);
  setOrigen(lab, *nuevoOrigen);
  setDestino(lab, *nuevoDestino);

  Coordenada inicio = {-1, -1};
  for (i = 0; i < REN; i++) {
    for (j = 0; j < COL; j++) {
      if (lab[i][j] == 'A') {
        inicio.x = i;
        inicio.y = j;
        break;
      }
    }
  }

  if (inicio.x == -1) {
    printf("No se encontro el inicio 'A'\n");
    return 1;
  }

  Pila pila = {NULL, 0, -1, imprimirCoordenada, free};

  Coordenada *actual = crearCoordenada(inicio.x, inicio.y);
  pushDato(&pila, actual);

  int encontrado = 0;

  // auxiliares para aumento o disminucion de coordenadas
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  while (!pilaVacia(pila)) {
    actual = (Coordenada *)pila.cima->dato;

    if (lab[actual->x][actual->y] == 'B') {
      encontrado = 1;
      break;
    }

    // bandera para saber si nos movimos o si entramos a un callejon sin salida
    int movido = 0;

    for (int k = 0; k < 4; k++) {
      int nx = actual->x + dx[k];
      int ny = actual->y + dy[k];

      if (nx >= 0 && nx < REN && ny >= 0 && ny < COL) {
        // encontramos un espacio libre o la meta
        if (lab[nx][ny] == '*' || lab[nx][ny] == 'B') {
          if (lab[nx][ny] == '*') {
            lab[nx][ny] = '.'; // marcamos como visitado y parte del recorrido actual
          }
          pushDato(&pila, crearCoordenada(nx, ny));
          movido = 1;
          break;
        }
      }
    }

    // si no pudimos movernos, estamos en un camino sin salida
    if (!movido) {
      actual = (Coordenada *)popDato(&pila);
      if (lab[actual->x][actual->y] == '.') {
        lab[actual->x][actual->y] = '/'; // 'o' indica que ya pasamos por aquí pero no lleva a la salida
      }
      free(actual);
    }
  }

  imprimirLab(lab);

  if (encontrado) {
    printf("\n\nSalida encontrada\n");
  } else {
    printf("\n\nNo se encontro salida.\n");
  }

  eliminarPila(&pila);
  for (i = 0; i < REN; i++)
    free(lab[i]);
  free(lab);

  printf("\n");
  return 0;
}
