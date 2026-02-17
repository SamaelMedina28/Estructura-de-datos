#include <stdio.h>
#include <stdlib.h>
#include <listadoble.h>
#include "Alumno.h"
int main()
{
  printf("Listas doblemente enlazadas\n");
  Alumno *a, *b, *c;
  a = crearAlumno();
  b = crearAlumno();
  c = crearAlumno();

  ListaD lista = {NULL, NULL, 0, compararMatricula, imprimirAlumno, free};

  agregarEnOrdenD(&lista, a);
  agregarEnOrdenD(&lista, b);
  agregarEnOrdenD(&lista, c);
  imprimirListaD(lista);

  reordenarD(&lista, compararPromedio);
  imprimirListaD(lista);

  return 0;
}
