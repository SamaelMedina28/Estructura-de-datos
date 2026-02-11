#include <stdio.h>
#include "../iostring/iostring.h"
#include "../structures/lista/lista.h"
#include "Alumno.h"

int main()
{
	printf("Listas enlazadas");
	Alumno *a,*b,*c;
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
	imprimirLista(lista);


	return 0;
}
