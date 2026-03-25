#include"arbol.h"

void insertarArbolOrdenado(NodoA *raiz, void *dato, int (*comparar)(void *, void *))
{
  // si el dato que queremos agregar es menor o igual a la raiz
  if (comparar(dato, raiz->dato) <= 0)
  {
    // IZQUIERDA
    if (!raiz->izq)
      raiz->izq = crearNodoA(dato);
    else if (!raiz->dch && comparar(dato, raiz->dato) == 0)
      raiz->dch = crearNodoA(dato);
    else
      insertarArbolOrdenado(raiz->izq, dato, comparar);
  }
  // si el dato que queremos agregar es mayor a la raiz
  else
  {
    // DERECHA
    if (raiz->dch)
      insertarArbolOrdenado(raiz->dch, dato, comparar);
    else
      raiz->dch = crearNodoA(dato);
  }
}

void insertarArbol(Arbol *arbol, void *dato)
{
  if (!arbol->raiz)
    arbol->raiz = crearNodoA(dato);
  else
    insertarArbolOrdenado(arbol->raiz, dato, arbol->comparar);
  arbol->cantidad++;
}

void imprimir_arbol(NodoA *nodo, int nivel, void (*imprimir)(void *))
{
  int i;
  if (nodo != NULL)
  {
    printf(" ");
    imprimir(nodo->dato);
    if (nodo->dch)
    {
      printf("\n");
      for (i = 0; i < nivel + 1; i++)
      {
        if (i == nivel)
          printf(" |____R ");
        else
          printf(" |      ");
      }
      imprimir_arbol(nodo->dch, nivel + 1, imprimir);
    }
    if (nodo->izq)
    {
      printf("\n");
      for (i = 0; i < nivel + 1; i++)
      {
        printf(" |      ");
        // printf(" |      ");
      }
      printf("\n");
      for (i = 0; i < nivel + 1; i++)
      {
        if (i == nivel)
          printf(" |____L ");
        else
          printf(" |      ");
      }
      imprimir_arbol(nodo->izq, nivel + 1, imprimir);
    }
  }
}

void imprimirArbol(Arbol arbol)
{
  imprimir_arbol(arbol.raiz, 0, arbol.imprimir);
}

void preorden(NodoA *raiz, void (*imprimir)(void *))
{
  if (!raiz)
    return;
  printf(" ");
  imprimir(raiz->dato);
  preorden(raiz->izq, imprimir);
  preorden(raiz->dch, imprimir);
}

void orden(NodoA *raiz, void (*imprimir)(void *))
{
  if (!raiz)
    return;
  orden(raiz->izq, imprimir);
  printf(" ");
  imprimir(raiz->dato);
  orden(raiz->dch, imprimir);
}

void inverso(NodoA *raiz, void (*imprimir)(void *))
{
  if (!raiz)
    return;
  inverso(raiz->dch, imprimir);
  printf(" ");
  imprimir(raiz->dato);
  inverso(raiz->izq, imprimir);
}

void postorden(NodoA *raiz, void (*imprimir)(void *))
{
  if (!raiz)
    return;
  postorden(raiz->izq, imprimir);
  postorden(raiz->dch, imprimir);
  printf(" ");
  imprimir(raiz->dato);
}

void imprimirOrden(Arbol arbol, int opcion)
{
  switch (opcion)
  {
  case PREORDEN:
    preorden(arbol.raiz, arbol.imprimir);
    break;
  case ORDEN:
    orden(arbol.raiz, arbol.imprimir);
    break;
  case INVERSO:
    inverso(arbol.raiz, arbol.imprimir);
    break;
  case POSTORDEN:
    postorden(arbol.raiz, arbol.imprimir);
    break;
  }
}

void eliminar_NodosA(NodoA *raiz, void (*liberar)(void *))
{
  if (!raiz)
    return;
  eliminar_NodosA(raiz->izq, liberar);
  eliminar_NodosA(raiz->dch, liberar);
  // LIBERAR
  if (liberar)
    liberar(raiz->dato);
  free(raiz);
}

void eliminarArbol(Arbol *arbol)
{
  eliminar_NodosA(arbol->raiz, arbol->liberar);
  arbol->raiz = NULL;
  arbol->cantidad = 0;
}


void invertirRamas(NodoA *raiz)
{
    if (!raiz)
        return;

    NodoA *aux = raiz->izq;
    raiz->izq = raiz->dch;
    raiz->dch = aux;

    invertirRamas(raiz->izq);
    invertirRamas(raiz->dch);
}

void invertirArbol(Arbol *arbol)
{
    invertirRamas(arbol->raiz);
}
void* buscarEnArbol(Arbol arbol, void *dato)
{
    NodoA *raiz = arbol.raiz;

    while (raiz)
    {
        int cmp = arbol.comparar(raiz->dato, dato);

        if (cmp == 0)
            return raiz->dato;

        else if (cmp > 0)
            raiz = raiz->izq;

        else
            raiz = raiz->dch;
    }

    return NULL;
}
NodoA *eliminarNodo(NodoA *raiz, void *dato, int (*comparar)(void *, void *), int *eliminado)
{
  if (!raiz)
    return NULL;

  int cmp = comparar(dato, raiz->dato);

  if (cmp < 0)
  {
    raiz->izq = eliminarNodo(raiz->izq, dato, comparar, eliminado);
  }
  else if (cmp > 0)
  {
    raiz->dch = eliminarNodo(raiz->dch, dato, comparar, eliminado);
  }
  else
  {
    *eliminado = 1;

    // Caso 1: sin hijos o un hijo
    if (!raiz->izq)
    {
      NodoA *temp = raiz->dch;
      free(raiz->dato);
      free(raiz);
      return temp;
    }
    else if (!raiz->dch)
    {
      NodoA *temp = raiz->izq;
      free(raiz->dato);
      free(raiz);
      return temp;
    }

    // Caso 2: dos hijos - encontrar el sucesor inorden (mínimo del subárbol derecho)
    NodoA *temp = raiz->dch;
    while (temp->izq)
    {
      temp = temp->izq;
    }

    // Copiar los datos del sucesor al nodo actual
    void *nuevoDato = (int *)malloc(sizeof(int));
    *(int *)nuevoDato = *(int *)temp->dato;
    free(raiz->dato);
    raiz->dato = nuevoDato;

    // Eliminar el sucesor
    raiz->dch = eliminarNodo(raiz->dch, temp->dato, comparar, eliminado);
  }

  return raiz;
}
// Función para calcular altura de un árbol
int calcularAltura(NodoA *raiz)
{
  if (!raiz)
    return 0;

  int alturaIzq = calcularAltura(raiz->izq);
  int alturaDer = calcularAltura(raiz->dch);

  return (alturaIzq > alturaDer ? alturaIzq : alturaDer) + 1;
}
