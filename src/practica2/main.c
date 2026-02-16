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

  agregarInicioD(&lista, a);
  agregarInicioD(&lista, b);
  agregarInicioD(&lista, c);
  imprimirListaD(lista);
  int se_elimino = eliminarPorPosicionD(&lista, 3);
  if (se_elimino)
  {
    printf("\nSe elimino con exito:");
    imprimirListaD(lista);
  }
  else
  {
    printf("\nNo se encontro la posicion a eliminar");
  }

  return 0;
}
