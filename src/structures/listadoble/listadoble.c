#include "listadoble.h"
#include <stdio.h>
#include "../nodos/nododoble.h"
// todo, borrar lista inicio y borrar lista completa, reordenar, buscar nodo, eliminar final, eliminar posicion, insertar en orden
// *Imprimir
void imprimirListaD(ListaD lista)
{
  if (lista.inicio == NULL)
  {
    printf("\nLa lista esta vacia");
  }
  else
  {
    printf("\n[%d] Lista", lista.cant);
    NodoD *actual = lista.inicio;
    while (actual != NULL)
    {
      lista.imprimir(actual->dato);
      actual = actual->siguiente;
    }
  }
  printf("\n");
}
void imprimirListaReversaD(ListaD lista)
{
  printf("\n");
  NodoD *actual = lista.fin;
  while (actual != NULL)
  {
    lista.imprimir(actual->dato);
    actual = actual->anterior;
  }
  printf("\n");
}

// *Eliminar
void eliminarListaD(ListaD *lista)
{
  while (lista->inicio)
  {
    eliminarInicioD(lista);
  }
}
int eliminarPorValorD(ListaD *lista, void *dato, int (*comparar)(void *, void *))
{
  NodoD *nodoRemover = buscarPorValorD(*lista, dato, comparar);
  if (nodoRemover)
  {
    if (nodoRemover == lista->inicio)
    {
      eliminarInicioD(lista);
    }
    else if (nodoRemover == lista->fin)
    {
      eliminarFinalD(lista);
    }
    else
    {
      nodoRemover->anterior->siguiente = nodoRemover->siguiente;
      nodoRemover->siguiente->anterior = nodoRemover->anterior;
      if (lista->liberar)
        lista->liberar(nodoRemover->dato);
      free(nodoRemover);
      lista->cant--;
    }
    return 1;
  }
  return 0;
}
int eliminarPorPosicionD(ListaD *lista, int pos)
{
  // Casos posibles:
  NodoD *nodoRemover = buscarPorPosicionD(*lista, pos);
  // Solo seria null si la posicion que ingresamos no es valida
  if (nodoRemover)
  {
    if (nodoRemover == lista->inicio)
    {
      eliminarInicioD(lista);
    }
    else if (nodoRemover == lista->fin)
    {
      eliminarFinalD(lista);
    }
    else
    {
      nodoRemover->anterior->siguiente = nodoRemover->siguiente;
      nodoRemover->siguiente->anterior = nodoRemover->anterior;
      if (lista->liberar)
        lista->liberar(nodoRemover->dato);
      free(nodoRemover);
      lista->cant--;
    }
    return 1;
  }
  return 0;
}
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
void *removerInicioD(ListaD *lista)
{
  if (!lista->inicio)
  {
    return NULL;
  }
  void *dato = lista->inicio->dato;
  eliminarInicioD(lista);
  return dato;
}

// *Buscar
NodoD *buscarPorValorD(ListaD lista, void *dato, int (*comparar)(void *, void *))
{
  NodoD *nodoActual = lista.inicio;
  while (nodoActual)
  {
    if (comparar(dato, nodoActual->dato) == 0)
      return nodoActual;
    nodoActual = nodoActual->siguiente;
  }
  return NULL;
}
NodoD *buscarPorPosicionD(ListaD lista, int posicion)
{
  int i = 0;
  NodoD *nodoActual = lista.inicio;
  while (nodoActual)
  {
    if (posicion == i)
      return nodoActual;
    nodoActual = nodoActual->siguiente;
    i++;
  }
  return NULL;
}

// *Agregar
void agregarEnOrdenD(ListaD *lista, void *dato)
{
  NodoD *nodoCreado = crearNodoD(dato);
  if (!lista->inicio)
  {
    lista->inicio = lista->fin = nodoCreado;
  }
  else
  {
    NodoD *nodoActual = lista->inicio;
    while (nodoActual)
    {
      // si el nodo que creamos es menor
      if (lista->comparar(nodoCreado->dato, nodoActual->dato) < 0)
      {
        if (nodoActual == lista->inicio)
        {
          nodoCreado->siguiente = nodoActual;
          nodoActual->anterior = nodoCreado;
          lista->inicio = nodoCreado;
        }
        else
        {
          nodoActual->anterior->siguiente = nodoCreado;
          nodoCreado->anterior = nodoActual->anterior;
          nodoCreado->siguiente = nodoActual;
          nodoActual->anterior = nodoCreado;
        }
        break;
      }
      else if (nodoActual == lista->fin)
      {
        nodoActual->siguiente = nodoCreado;
        nodoCreado->anterior = nodoActual;
        lista->fin = nodoCreado;
        break;
      }
      nodoActual = nodoActual->siguiente;
    }
  }
  lista->cant++;
}
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
int agregarEnPosicionD(ListaD *lista, void *dato, int pos)
{
  if (lista->cant == pos) // SI no tiene nodos o si se quiere agregar al final
  {
    agregarFinalD(lista, dato);
    return 1;
  }
  else
  {
    NodoD *nodoEnPosicion = buscarPorPosicionD(*lista, pos);
    if (!nodoEnPosicion)
      return 0;
    if (nodoEnPosicion == lista->inicio)
    {
      agregarInicioD(lista, dato);
      return 1;
    }
    else
    {
      NodoD *nodoCreado = crearNodoD(dato);
      nodoCreado->anterior = nodoEnPosicion->anterior;
      nodoEnPosicion->anterior->siguiente = nodoCreado;
      nodoCreado->siguiente = nodoEnPosicion;
      nodoEnPosicion->anterior = nodoCreado;
      lista->cant++;
      return 1;
    }
  }
}
