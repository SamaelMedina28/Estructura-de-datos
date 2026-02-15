#include <stdio.h>
#include <stdlib.h>
#include "../structures/listadoble/listadoble.h"
#include "Alumno.h"
// * *//
int compararEnteros(void *a, void *b);
void imprimirEnteros(void *a);
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
	agregarFinalD(&lista, c);
	imprimirListaD(lista);
	imprimirListaReversaD(lista);
	eliminarInicioD(&lista);
	imprimirListaD(lista);
	eliminarFinalD(&lista);
	imprimirListaD(lista);

	return 0;
}
