#include "listadoble.h"
#include <stdio.h>
#include "../nodos/nododoble.h"

void insertarInicioD(ListaD *lista, void *dato)
{
  NodoD *nuevo = crearNodoD(dato);
  // Si la lista esta vacia
  if(lista->inicio == NULL){
    lista->inicio = nuevo;
    lista->fin = nuevo;
  }else{
  // Si la lista ya tiene un nodo
    lista->inicio->anterior = nuevo;
    nuevo->siguiente = lista->inicio;
    lista->inicio = nuevo;
  }
  lista->cant++;
}

void mostrarListaD(ListaD lista){
  printf("\n");
  NodoD *actual = lista.inicio;
  while(actual != NULL){
    lista.imprimir(actual->dato);
    actual = actual->siguiente;
  }
  printf("\n");
}
