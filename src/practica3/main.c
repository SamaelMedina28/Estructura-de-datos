#include <stdio.h>
#include <iostring.h>
#include <pila.h>

#define MAX 100

int palindromo(char *cadena);
int verificarParentesis(char *cadena);
void quitarEspacios(char *);

int main(void)
{
  char *cadena = NULL;

  inputCadenaDinamica("\n Captura cadena: ", &cadena, MAX);
  printf(" Es palindromo: %s", palindromo(cadena) ? "SI" : "NO");

  inputCadenaDinamica("\n\n Captura expresion: ", &cadena, MAX);
  printf(" Parentesis correctos : %s", verificarParentesis(cadena) ? "SI" : "NO");

  free(cadena);
  printf("\n\n FIN DE PROGRAMA");
  return 0;
}

int palindromo(char *cadena)
{
  char *nuevaPalabra = cadena;
  quitarEspacios(nuevaPalabra);
  Pila pila = {NULL, 0, -1, NULL, NULL};
  for (int i = 0; nuevaPalabra[i] != '\0'; i++)
    pushDato(&pila, &nuevaPalabra[i]);
  for (int i = 0; nuevaPalabra[i] != '\0'; i++)
  {
    char *letra = popDato(&pila);
    if (*letra != nuevaPalabra[i])
      return 0;
  }
  return 1;
}

// Funcion para quitar espacios de una cadena de texto
void quitarEspacios(char *cadena)
{
  int j = 0;
  for (int i = 0; cadena[i] != '\0'; i++)
  {
    if (cadena[i] != ' ')
    {
      cadena[j++] = cadena[i];
    }
  }
  cadena[j] = '\0';
}

// Funcion de verificar parentesis
int verificarParentesis(char *cadena)
{
  Pila pila = {NULL, 0, -1, NULL, NULL};

  for (int i = 0; cadena[i] != '\0'; i++)
  {
    char signo = cadena[i];

    // Si es abre, lo metemos
    if (signo == '(' || signo == '{' || signo == '[')
    {
      pushDato(&pila, &cadena[i]);
    }
    // Si es cierra, verificamos que coincida con el tope
    else if (signo == ')' || signo == '}' || signo == ']')
    {
      if (pilaVacia(pila)) // pila vacía, no hay pareja
        return 0;

      char *cima = popDato(&pila);

      if (signo == ')' && *cima != '(')
        return 0;
      if (signo == '}' && *cima != '{')
        return 0;
      if (signo == ']' && *cima != '[')
        return 0;
    }
  }

  // Al final la pila debe estar vacía
  return pilaVacia(pila);
}
