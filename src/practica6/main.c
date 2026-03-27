#include "../iostring/iostring.h"
#include "../structures/pila/pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int obtenerPrecedencia(char operador);
int esOperador(char c);
void imprimirCadena(void *dato) { printf("%s", (char *)dato); }

void infixAPostfix(char *cadena) {
  int tamCadena = strlen(cadena);
  char *postfix = malloc((tamCadena * 2 + 1) * sizeof(char));
  int j = 0;

  Pila pila = {NULL, 0, -1, imprimirCadena, &free};

  for (int i = 0; i < tamCadena; i++) {
    char c = cadena[i];

    // agregar directo al postfix
    if (!esOperador(c) && c != '(' && c != ')') {
      postfix[j++] = c;
    }
    // Paréntesis que abre: push a la pila
    else if (c == '(') {
      char *op = malloc(sizeof(char));
      *op = c;
      pushDato(&pila, op);
    }
    // Paréntesis que cierra: pop hasta encontrar '('
    else if (c == ')') {
      while (!pilaVacia(pila) && *(char *)pila.cima->dato != '(') {
        char *op = (char *)popDato(&pila);
        postfix[j++] = *op;
        free(op);
      }
      // Sacar el '(' sin agregarlo al postfix
      if (!pilaVacia(pila)) {
        char *op = (char *)popDato(&pila);
        free(op);
      }
    }
    // Operador
    else if (esOperador(c)) {
      // Push si la pila está vacía, hay '(' en cima, o mayor precedencia
      while (!pilaVacia(pila) && *(char *)pila.cima->dato != '(' &&
             obtenerPrecedencia(*(char *)pila.cima->dato) >=
                 obtenerPrecedencia(c)) {
        // Pop operadores de mayor o igual precedencia
        char *op = (char *)popDato(&pila);
        postfix[j++] = *op;
        free(op);
      }
      char *op = malloc(sizeof(char));
      *op = c;
      pushDato(&pila, op);
    }
  }

  // Vaciar la pila al postfix
  while (!pilaVacia(pila)) {
    char *op = (char *)popDato(&pila);
    postfix[j++] = *op;
    free(op);
  }

  postfix[j] = '\0';
  printf("Postfix: %s\n", postfix);
  free(postfix);
}

int main() {
  int opcion;
  do {
    printf("\n--- Menu ---\n");
    printf("1. Infix a Postfix\n");
    printf("2. Terminar\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    getchar(); // limpiar buffer

    switch (opcion) {
    case 1: {
      char *cadena;
      inputCadenaDinamica("Ingrese expresion infix: ", &cadena, 100);

      if (!verificarParentesis(cadena)) {
        printf("Error: parentesis invalidos.\n");
      } else {
        infixAPostfix(cadena);
      }
    //   free(cadena);
      break;
    }
    case 2:
      printf("Byes.\n");
      break;
    default:
      printf("Opcion invalida.\n");
    }
  } while (opcion != 2);

  return 0;
}

int obtenerPrecedencia(char operador) {
  switch (operador) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '^':
    return 3;
  default:
    return 0;
  }
}

int esOperador(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
