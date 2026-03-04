#include "laberinto.h"

Movimientos movimientosPosibles(unsigned char **lab, Coordenada punto)
{
  Movimientos movimientos = {0, 0, 0, 0};
  // ARRIBA
  if (lab[punto.x - 1][punto.y] == '*')
    movimientos.up = 1;
  // ABAJO
  if (lab[punto.x + 1][punto.y] == '*')
    movimientos.down = 1;
  // DERECHA
  if (lab[punto.x][punto.y + 1] == '*')
    movimientos.right = 1;
  // IZQUIERDA
  if (lab[punto.x][punto.y - 1] == '*')
    movimientos.left = 1;
  return movimientos;
}

void imprimirMovimientos(Movimientos movimientos)
{
  printf("\n");
  // ARRIBA
  if (movimientos.up == 1)
    printf(" ARRIBA");
  // ABAJO
  if (movimientos.down == 1)
    printf(" ABAJO");
  // DERECHA
  if (movimientos.right == 1)
    printf(" DERECHA");
  // IZQUIERDA
  if (movimientos.left == 1)
    printf(" IZQUIERDA");
}

unsigned char **crear_laberinto(void)
{
  int i, j;
  char *tmp =
      "xxxxxxxxxxxxxxxxxxxxxxxxxx\
xAx*****x****************x\
x*xxx*x*x*xxxxxxxxx*xxxx*x\
x*****x*x******x**x****x*x\
xxxxxxx*xxxxxx*xx*xxxx*xxx\
x*****x*x****x*x****xx***x\
x*xxx*x*xxxx*x*x*xxxxx*x*x\
x***x*x****x*****xxxxxxx*x\
xxx*x*xxxx*xxxxxxx****x**x\
x*x*x***xx****xx***xx*x*xx\
x*x*x*x*xxxxx**x*xxxx*x**x\
x*x*x*x***x*xx*x****x*xx*x\
x*x*x*xxx****x*x*xx*x****x\
x*x*x*xxxxxxxx*x**x*xxxx*x\
x***x********x*xx*x*x****x\
x*xxxxxxxxxx*x**xxx*x*xxxx\
x***x******x**x*****x**x*x\
xxx*x*xxxxxxx*xxxxxxxx*x*x\
x*x*x*******x****xx****x*x\
x*x*x*xxxxx*xxxx*xx*xxxx*x\
x*x*x****xx***x**xx*x****x\
x*x*xxxxxxx*x**x*xx*x*x*xx\
x*x*********xx*x*xx*xxx*xx\
x*xxxxxxxxxxx**x*********x\
x***x***x***x*xxxxxxxxxx*x\
x*x***x***x*************Bx\
xxxxxxxxxxxxxxxxxxxxxxxxxx\0";

  unsigned char **lab;
  lab = (unsigned char **)malloc(sizeof(unsigned char *) * REN);

  for (i = 0; i < REN; i++)
  {
    lab[i] = (unsigned char *)malloc(sizeof(unsigned char) * COL);
  }

  for (i = 0; i < REN; i++)
  {
    // printf("\n\r");
    for (j = 0; j < COL; j++)
    {
      // printf("%c",tmp[(i*COL)+j]);
      lab[i][j] = tmp[(i * COL) + j];
    }
  }
  return lab;
}

void imprimirLab(unsigned char **lab)
{
  int i, j;
  for (i = 0; i < REN; i++)
  {
    printf("\n\r");
    for (j = 0; j < COL; j++)
    {
      if (lab[i][j] == '*')
        printf("  ");
      else
        printf("%c ", lab[i][j]);
    }
  }
}

Coordenada *crearCoordenada(int x, int y)
{
  Coordenada *nueva = malloc(sizeof(Coordenada));
  nueva->x = x;
  nueva->y = y;
  return nueva;
}

void imprimirCoordenada(void *dato)
{
  Coordenada *a = dato;
  printf("[%-2d,%-2d]", a->x, a->y);
}

int compararCoordenada(void *a, void *b)
{
  Coordenada *aa = a, *bb = b;
  if (aa->x == bb->x && aa->y == bb->y)
    return 1;
  return 0;
}
