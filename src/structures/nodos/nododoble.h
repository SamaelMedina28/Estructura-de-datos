#ifndef NODO_DOBLE_H
#define NODO_DOBLE_H


#include <stdlib.h>

typedef struct nodo
{
	void *dato;
	struct nodo *siguiente;
	struct nodo *anterior;
}NodoD;

NodoD* crearNodoD(void *dato);

#endif
