#include "listadoble.h"
#include <stdio.h>
#include "../nodos/nododoble.h"
// todo, borrar lista inicio y borrar lista completa, reordenar, buscar nodo, eliminar final, eliminar posicion, insertar en orden
// *Imprimir
void imprimirListaD(ListaD lista)
{
  printf("\n[%d] Lista", lista.cant);
  NodoD *actual = lista.inicio;
  while(actual != NULL){
    lista.imprimir(actual->dato);
    actual = actual->siguiente;
  }
  printf("\n");
}
void imprimirListaReversaD(ListaD lista)
{
  printf("\n");
  NodoD *actual = lista.fin;
  while(actual != NULL){
    lista.imprimir(actual->dato);
    actual = actual->anterior;
  }
  printf("\n");
}

// *Eliminar
void eliminarInicioD(ListaD *lista)
{
  if (lista->inicio)
  {
    NodoD *auxiliar = lista->inicio;
    // Si solo hay un nodo
    if (lista->inicio == lista->fin)
    {
      lista->inicio = lista->fin = NULL;
    }
    else
    {
      lista->inicio = auxiliar->siguiente;
      lista->inicio->anterior = NULL;
    }
    if (lista->liberar)
      lista->liberar(auxiliar->dato);
    free(auxiliar);
    lista->cant--;
  }
}
void eliminarFinalD(ListaD *lista)
{
  if (lista->inicio)
  {
    if (lista->inicio == lista->fin) // Significa que solo hay un nodo
    {
      eliminarInicioD(lista);
    }
    else
    {
      NodoD *auxiliar = lista->fin->anterior;
      auxiliar->siguiente = NULL;
      if (lista->liberar)
        lista->liberar(lista->fin->dato);
      free(lista->fin);
      lista->fin = auxiliar;
      lista->cant--;
    }
  }
}

// *Remover
void *removerInicioD(ListaD *lista){
  if(!lista->inicio){
    return NULL;
  }
  void *dato = lista->inicio->dato;
  eliminarInicioD(lista);
  return dato;
}

// *Buscar
NodoD *buscarPorValorD(ListaD lista, void *dato, int (*comparar)(void *, void *)){
  NodoD *nodoActual = lista.inicio;
  while (nodoActual)
  {
    if (comparar(dato, nodoActual->dato)==0)
    {
      return nodoActual;
    }
  }
  return NULL;
}

// *Agregar
void agregarInicioD(ListaD *lista, void *dato)
{
  NodoD *nuevo = crearNodoD(dato);
  // Si la lista esta vacia
  if (lista->inicio == NULL)
  {
    lista->inicio = nuevo;
    lista->fin = nuevo;
  }
  else
  {
    // Si la lista ya tiene un nodo
    lista->inicio->anterior = nuevo;
    nuevo->siguiente = lista->inicio;
    lista->inicio = nuevo;
  }
  lista->cant++;
}
void agregarFinalD(ListaD *lista, void *dato)
{
  NodoD *nuevo = crearNodoD(dato);
  // si la lista esta vacia
  if (lista->inicio == NULL)
  {
    agregarInicioD(lista, dato);
  }
  else
  {
    lista->fin->siguiente = nuevo;
    nuevo->anterior = lista->fin;
    lista->fin = nuevo;
    lista->cant++;
  }
}
