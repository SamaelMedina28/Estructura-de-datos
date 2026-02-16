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
    printf("\nSe elimino con exito el alumno en la posicion 3:");
    imprimirListaD(lista);
  }
  else
  {
    printf("\nNo se encontro la posicion a eliminar");
  }

  Alumno alumnoFiltro;
  alumnoFiltro.promedio=95.5;

  se_elimino = eliminarPorValorD(&lista, &alumnoFiltro, compararPromedio);
  if (se_elimino)
  {
    printf("\nSe elimino con exito el alumno de promedio 95.5:");
    imprimirListaD(lista);
  }
  else
  {
    printf("\nNo se encontro el alumno a eliminar");
  }

  return 0;
}
