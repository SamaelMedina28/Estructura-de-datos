#include "pila.h"

// VERIFICIACION
int pilaVacia(Pila pila) { return pila.cima == NULL || pila.cantidad == 0; }

int pilaLlena(Pila pila) { return pila.cantidad == pila.capacidad; }

// DATOS
void pushDato(Pila *pila, void *dato)
{
  if (pilaLlena(*pila))
  {
    printf("\nOVERFLOW");
    return;
  }
  Nodo *nodoCreado = crearNodo(dato);
  nodoCreado->sig = pila->cima;
  pila->cima = nodoCreado;
  pila->cantidad++;
}

void *popDato(Pila *pila)
{
  void *dato = NULL;
  if (pilaVacia(*pila))
  {
    printf("\nUNDERFLOW");
    return dato;
  }
  Nodo *cimaVieja = pila->cima;
  pila->cima = pila->cima->sig;
  dato = cimaVieja->dato;
  free(cimaVieja);
  pila->cantidad--;
  return dato;
}

// NODOS
void pushNodo(Pila *pila, Nodo *nodo)
{
  if (pilaLlena(*pila))
  {
    printf("\nOVERFLOW");
    return;
  }
  nodo->sig = pila->cima;
  pila->cima = nodo;
  pila->cantidad++;
}

void pushDatoOrdenado(Pila *pila, void *dato, int (*comparar)(void *, void *))
{
  if (pilaLlena(*pila))
    return;

  Pila aux = {NULL, 0, pila->capacidad, pila->liberar, pila->imprimir};

  while (!pilaVacia(*pila) && comparar(pila->cima->dato, dato) > 0)
  {
    pushDato(&aux, popDato(pila));
  }

  pushDato(pila, dato);

  while (!pilaVacia(aux))
  {
    pushDato(pila, popDato(&aux));
  }
}

Nodo *popNodo(Pila *pila)
{
  Nodo *cimaVieja = NULL;
  if (pilaVacia(*pila))
  {
    printf("\nUNDERFLOW");
    return cimaVieja;
  }
  cimaVieja = pila->cima;
  pila->cima = pila->cima->sig;
  pila->cantidad--;
  cimaVieja->sig = NULL;
  return cimaVieja;
}

// VACIAR/ELIMINAR PILA
void vaciarPila(Pila *pila)
{
  while (!pilaVacia(*pila))
  {
    popDato(pila);
  }
}

void eliminarPila(Pila *pila)
{
  while (!pilaVacia(*pila))
  {
    void *dato = popDato(pila);
    if (pila->liberar)
      pila->liberar(dato);
  }
}

// IMPRIMIR RESPETAR LIFO
void imprimirPila(Pila pila)
{
  Pila aux = {NULL, 0, -1, NULL, NULL};
  printf("\n[%d]PILA:", pila.cantidad);
  while (!pilaVacia(pila))
  {
    printf("\n");
    pila.imprimir(pila.cima->dato);
    pushNodo(&aux, popNodo(&pila));
  }
  while (!pilaVacia(aux))
  {
    pushNodo(&pila, popNodo(&aux));
  }
}

// ORDENAR
void ordenarPila(Pila *pila, int (*comparar)(void *, void *))
{
  if (pilaVacia(*pila))
    return;

  Pila aux = {NULL, 0, pila->capacidad, pila->liberar, pila->imprimir};

  while (!pilaVacia(*pila))
  {
    void *dato = popDato(pila);

    // Solo insertamos en la pila auxiliar  si el dato que pasamos de la pila original a la cima de la pila auxiliar es menor que el ultimo dato de la pila original
    while (!pilaVacia(aux) && comparar(aux.cima->dato, dato) < 0)
    {
      pushDato(pila, popDato(&aux));
    }

    pushDato(&aux, dato);
  }

  // Transferir de vuelta a pila principal
  while (!pilaVacia(aux))
  {
    pushDato(pila, popDato(&aux));
  }
}
// Verificar si una cadena es palindromo
int esPalindromo(char *cadena){
  Pila pila = {NULL,0,-1,NULL,NULL};
  for(int i =0; cadena[i]!='\0';i++)
    pushDato(&pila, &cadena[i]);
  for (int i = 0; cadena[i] != '\0'; i++)
  {
    char *letra = popDato(&pila);
    if (*letra!=cadena[i])
      return 0;
  }
  return 1;
}
