#include <stdio.h>
#include <stdlib.h>
#include "../structures/listadoble/listadoble.h"
// * *//
int compararEnteros(void *a, void *b);
void imprimirEnteros(void *a);
int main()
{
	printf("Listas doblemente enlazadas\n");
	/* Alumno *a,*b,*c;
	a = crearAlumno();
	b = crearAlumno();
	c = crearAlumno();

	Lista lista = {NULL,NULL,0,imprimirAlumno,compararNombre,free};
	agregarEnOrden(&lista,a);
	agregarEnOrden(&lista,b);
	agregarEnOrden(&lista,c);
	imprimirLista(lista);

	getchar();
	reordenar( &lista ,compararPromedio );
	imprimirLista(lista); */

	ListaD listaD = {NULL,NULL,0,compararEnteros,imprimirEnteros,free};

	insertarInicioD(&listaD, &(int){5});
	insertarInicioD(&listaD, &(int){10});

	mostrarListaD(listaD);
	mostrarListaInversoD(listaD);

	insertarFinalD(&listaD, &(int){15});
	mostrarListaD(listaD);

	return 0;
}
int compararEnteros(void *a, void *b)
{
	return *(int *)a - *(int *)b;
}

void imprimirEnteros(void *a)
{
	printf("%d ", *(int *)a);
}
