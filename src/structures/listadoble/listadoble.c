#include "listadoble.h"
#include <stdio.h>
#include "../nodos/nododoble.h"
// todo, borrar lista inicio y borrar lista completa, reordenar, buscar nodo, eliminar final, eliminar posicion, insertar en orden
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
void insertarFinalD(ListaD *lista, void *dato)
{
  NodoD *nuevo = crearNodoD(dato);
  // si la lista esta vacia
  if (lista->inicio == NULL)
  {
    insertarInicioD(lista, dato);
  }else{
    lista->fin->siguiente = nuevo;
    nuevo->anterior = lista->fin;
    lista->fin = nuevo;
    lista->cant++;
  }

}
void mostrarListaD(ListaD lista){
  printf("\n[%d] Lista", lista.cant);
  NodoD *actual = lista.inicio;
  while(actual != NULL){
    lista.imprimir(actual->dato);
    actual = actual->siguiente;
  }
  printf("\n");
}

void mostrarListaInversoD(ListaD lista)
{
  printf("\n");
  NodoD *actual = lista.fin;
  while(actual != NULL){
    lista.imprimir(actual->dato);
    actual = actual->anterior;
  }
  printf("\n");
}
void *buscarDatoD(ListaD lista, void *dato, int (*comparar)(void *, void *)){
  NodoD *actual = lista.inicio;
  while(actual != NULL){
    if(comparar(actual->dato, dato) == 0){
      return actual->dato;
    }
    actual = actual->siguiente;
  }
  return NULL;
}

void borrarListaD(ListaD *lista){
  NodoD *actual = lista->inicio;
  while(actual != NULL){
    NodoD *siguiente = actual->siguiente;
    lista->liberar(actual->dato);
    free(actual);
    actual = siguiente;
  }
  lista->inicio = NULL;
  lista->fin = NULL;
  lista->cant = 0;
}

void borrarInicio(ListaD *lista){

}
