#include <stdio.h>
#include <stdlib.h>
#include "../structures/listadoble/listadoble.h"
#include "Alumno.h"
int main()
{
	printf("Listas doblemente enlazadas\n");
	Alumno *a,*b,*c;
	a = crearAlumno();
	b = crearAlumno();
	c = crearAlumno();

	ListaD lista = {NULL,NULL,0,compararMatricula,imprimirAlumno,free};

	agregarInicioD(&lista, a);
	agregarInicioD(&lista, b);
	agregarInicioD(&lista, c);
	imprimirListaD(lista);
	eliminarPorPosicionD(&lista, 2);
	imprimirListaD(lista);

	return 0;
}
