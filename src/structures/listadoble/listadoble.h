#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H

#include "../nodos/nododoble.h"

typedef struct
{
	NodoD *inicio;
	NodoD *fin;
	int cant;
	int (*comparar)(void *datoA,void *dataB);
	void (*imprimir)(void *datoA);
	void (*liberar)(void *datoA);
}ListaD;

// ListaD inicializarListaD(void);
// !Imprimir
void imprimirListaD(ListaD lista); //* Terminadas
void imprimirListaReversaD(ListaD lista); //* Terminadas

// !Eliminar
void eliminarListaD(ListaD *); //* Terminadas
int eliminarPorValorD(ListaD *lista,void* dato,int  (*comparar)(void*,void*)); //* Terminadas
int eliminarPorPosicionD(ListaD *lista,int pos); //* Terminadas
void eliminarInicioD(ListaD *lista); //* Terminadas
void eliminarFinalD(ListaD *lista); //* Terminadas

// !Remover
void *removerInicioD(ListaD *lista); //* Terminadas

// !Buscar
NodoD* buscarPorValorD(ListaD lista,void *dato,int  (*comparar)(void*,void*)); //* Terminadas
NodoD *buscarPorPosicionD(ListaD lista, int posicion); //* Terminadas

// !Agregar
void agregarEnOrdenD(ListaD *lista,void* dato);
void agregarInicioD(ListaD *lista,void* dato); //* Terminadas
void agregarFinalD(ListaD*,void*); //* Terminadas
int agregarEnPosicionD(ListaD *lista,void* dato,int pos); //* Terminadas

// !Reordenar
void reordenarD(ListaD *,int  (*)(void*,void*) );


#endif
