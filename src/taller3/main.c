
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdarg.h>
#include <time.h>
#include <iostring.h>
#include <arbol.h>

int *crearEntero(int);
int compararEntero(void *, void *);
void imprimirEntero(void *);

void myprintf(char *msg, char *formato, ...);

int main(void)
{
  Arbol arbol = {NULL, 0, &imprimirEntero, &compararEntero, &free};

  insertarArbol(&arbol, crearEntero(9));
  insertarArbol(&arbol, crearEntero(8));
  insertarArbol(&arbol, crearEntero(11));
  insertarArbol(&arbol, crearEntero(7));
  insertarArbol(&arbol, crearEntero(6));
  insertarArbol(&arbol, crearEntero(5));
  insertarArbol(&arbol, crearEntero(10));
  insertarArbol(&arbol, crearEntero(12));
  insertarArbol(&arbol, crearEntero(9));
  insertarArbol(&arbol, crearEntero(1));
  insertarArbol(&arbol, crearEntero(1));
  insertarArbol(&arbol, crearEntero(1));
  insertarArbol(&arbol, crearEntero(1));
  insertarArbol(&arbol, crearEntero(1));
  insertarArbol(&arbol, crearEntero(1));
  insertarArbol(&arbol, crearEntero(1));
  insertarArbol(&arbol, crearEntero(1));
  insertarArbol(&arbol, crearEntero(0));

  printf("\nArbol original:\n");
  imprimirArbol(arbol);

  int *valor = crearEntero(71);

  int *resultado = buscarEnArbol(arbol, valor);

  if (resultado)
    printf("\nEncontrado: %d\n", *resultado);
  else
    printf("\nNo encontrado\n");

  free(valor);
  invertirArbol(&arbol);

  printf("\n\nArbol invertido:\n");
  imprimirArbol(arbol);


  eliminarArbol(&arbol);
  printf("\n\n FIN DE PROGRAMA\n");
  return 0;
}

int *crearEntero(int dato)
{
  int *nuevo = malloc(sizeof(int));
  *nuevo = dato;
  return nuevo;
}

int compararEntero(void *a, void *b)
{
  int *aa = a, *bb = b;
  if (*aa == *bb)
    return 0;
  else if (*aa < *bb)
    return -1;
  else
    return 1;
}

void imprimirEntero(void *a)
{
  int *aa = a;
  printf("%d", *aa);
}
