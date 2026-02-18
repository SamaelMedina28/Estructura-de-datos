#include <stdio.h>
#include <stdlib.h>
#include <listadoble.h>
#include "Alumno.h"

void menu(void);

int main()
{

  ListaD lista = {NULL, NULL, 0, compararMatricula, imprimirAlumno, free};
  int opcion;

  do
  {
    menu();
    inputEntero("\nOpcion: ", &opcion);
    switch (opcion)
    {
    case 1:
    { /* Registrar alumno */
      Alumno *nuevo = crearAlumno();
      NodoD *r = buscarPorValorD(lista, nuevo, compararMatricula);
      if (r)
      {
        printf("\nYa existe un alumno con esa matricula. No se inserta.\n");
        if (lista.liberar)
          lista.liberar(nuevo);
      }
      else
      {
        agregarEnOrdenD(&lista, nuevo);
        printf("\nAlumno registrado correctamente.\n");
      }
      break;
    }
    case 2: /* Desplegar alumnos */
      imprimirListaD(lista);
      break;
    case 3:
    { /* Reordenar */
      int campo;
      printf("\nReordenar por:\n1) Matricula\n2) Nombre\n3) Semestre\n4) Promedio\n");
      inputEntero("Seleccione opcion: ", &campo);
      switch (campo)
      {
      case 1:
        reordenarD(&lista, compararMatricula);
        break;
      case 2:
        reordenarD(&lista, compararNombre);
        break;
      case 3:
        reordenarD(&lista, compararSemestre);
        break;
      case 4:
        reordenarD(&lista, compararPromedio);
        break;
      default:
        printf("Opcion invalida\n");
      }
      break;
    }
    case 4:
    { /* Buscar alumno */
      int campo;
      Alumno criterio = {0};
      int opcionValorInt;
      float opcionValorFloat;
      char cadena[LEN];

      printf("\nBuscar por:\n1) Matricula\n2) Nombre\n3) Semestre\n4) Promedio\n");
      inputEntero("Seleccione opcion: ", &campo);
      int (*cmp)(void *, void *) = NULL;
      switch (campo)
      {
      case 1:
        inputEntero("Matricula: ", &opcionValorInt);
        criterio.matricula = opcionValorInt;
        cmp = compararMatricula;
        break;
      case 2:
        inputCadena("Nombre: ", cadena, LEN);
        strcpy(criterio.nombre, cadena);
        cmp = compararNombre;
        break;
      case 3:
        inputEntero("Semestre: ", &opcionValorInt);
        criterio.semestre = opcionValorInt;
        cmp = compararSemestre;
        break;
      case 4:
        inputFloat("Promedio: ", &opcionValorFloat);
        criterio.promedio = opcionValorFloat;
        cmp = compararPromedio;
        break;
      default:
        printf("Opcion invalida\n");
      }
      if (cmp)
      {
        NodoD *res = buscarPorValorD(lista, &criterio, cmp);
        if (res)
        {
          printf("\nElemento encontrado:\n");
          imprimirAlumno(res->dato);
        }
        else
        {
          printf("No se encontró el elemento\n");
        }
      }
      break;
    }
    case 5:
    { /* Borrar alumno */
      int matricula;
      inputEntero("\nMatricula a eliminar: ", &matricula);
      Alumno criterio = {0};
      criterio.matricula = matricula;
      eliminarPorValorD(&lista, &criterio, compararMatricula);
      break;
    }
    case 6:
      printf("\nFinalizando programa.\n");
      break;
    default:
      printf("\nOpcion no valida, intente de nuevo.\n");
    }
  } while (opcion != 6);

  return 0;
}

void menu(void)
{
  printf("\n--- MENU ALUMNOS ---\n");
  printf("1. Registrar Alumno\n");
  printf("2. Desplegar Alumnos\n");
  printf("3. Reordenar\n");
  printf("4. Buscar Alumno\n");
  printf("5. Borrar Alumno\n");
  printf("6. Finalizar programa\n");
}

