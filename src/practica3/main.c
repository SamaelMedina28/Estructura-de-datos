#include <stdio.h>
#include <pila.h>

void imprimirEntero(void *dato){
	printf("%d",*(int*)dato);
}

int main(){
  Pila pila = {NULL,0,6,imprimirEntero,NULL};
	int arreglo[6] = {1,5,4,3,5,9};
	for(int i=0; i<6;i++)
		pushDato(&pila,&arreglo[i]);
	
	imprimirPila(pila);
}