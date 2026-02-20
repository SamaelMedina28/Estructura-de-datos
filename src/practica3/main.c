#include <stdio.h>
#include <iostring.h>
#include <pila.h>

#define MAX 100

int palindromo(char *cadena);
// int verificarParentesis(char *cadena);
void quitarEspacios(char *);

int main(void)
{
  char *cadena = NULL;

  inputCadenaDinamica("\n Captura cadena: ", &cadena, MAX);
  printf(" Es palindromo: %s", palindromo(cadena) ? "SI" : "NO");

  // inputCadenaDinamica("\n\n Captura expresion: ", &cadena, MAX);
  // printf(" Parentesis correctos : %s", verificarParentesis(cadena) ? "SI" : "NO");

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

// int verificarParentesis(char *cadena)
// {
//   Pila pila = {NULL, 0, -1, NULL, NULL};
//   return 0;
// }
