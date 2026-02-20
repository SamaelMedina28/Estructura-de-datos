#include <stdio.h>
#include <pila.h>

void imprimirEntero(void *dato){
	printf("%d",*(int*)dato);
}

int compararNumeros(void *a, void*b){
	int *num1 = a;
	int *num2 = b;
	return *num1 - *num2;
}

int main(){
  Pila pila = {NULL,0,-1,imprimirEntero,NULL};
	int arreglo[7] = {8, 5, 6, 10, 2, 3, 9};
	for(int i=0; i<7;i++)
		pushDatoOrdenado(&pila, &arreglo[i], compararNumeros);

	imprimirPila(pila);
}
