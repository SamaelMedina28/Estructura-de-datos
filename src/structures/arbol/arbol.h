#ifndef ARBOL_H
#define ARBOL_H

#include "../nodos/nodoarbol.h"
#include <stdio.h>

#define PREORDEN 1
#define ORDEN 2
#define POSTORDEN 3
#define INVERSO 4
#define IZQUIERDA 0
#define DERECHA 1

typedef struct
{
	NodoA *padre;
	NodoA *nodo;
	void *dato;
	int rama;
}Resultado;

typedef struct
{
	NodoA *raiz;
	int cantidad;
	void (*imprimir)(void*);
	int (*comparar)(void*,void*);
	void (*liberar)(void*);
}Arbol;

NodoA *eliminarNodo(NodoA *raiz, void *dato, int (*comparar)(void *, void *), int *eliminado);
// Función para calcular altura de un árbol
int calcularAltura(NodoA *raiz);

void eliminarArbol(Arbol *arbol);
void insertarArbol(Arbol *arbol,void *dato);
void imprimirArbol(Arbol arbol);
void imprimirOrden(Arbol arbol,int opcion);
void invertirArbol(Arbol *arbol);
void* buscarEnArbol(Arbol arbol, void* dato);
void eliminar_NodosA(NodoA *raiz, void (*liberar)(void *));
#endif
