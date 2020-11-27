#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "persona.h"
#include "LinkedList.h"
#include "utn.h"
int main()
{
    int opcion;
    int nextId;
    LinkedList* lista1 = ll_newLinkedList();
    LinkedList* lista2;
    LinkedList* sublista;
    ePersona* personaAux;
    int salida = 0;

    printf("Cargando datos desde archivo.\n\n");
    if(cargaDatos(lista1)) {
        printf("No se pudieron cargar datos desde archivos. El programa se puede seguir utilizando, pero se deberan cargar manualmente.\n\n");
    } else {
        printf("Lista cargada.\n");
        imprimirTamanio(lista1);
    }
    nextId = ll_len(lista1) + 1;
    if(!cargaNuevoElemento(lista1, nextId)) {
        nextId++;
        printf("\nCarga exitosa.\n\n");
    }

    printf("*** Modificacion de elemento ***\n\n");
    printf("Persona en indice 3:\n");
    print_persona(ll_get(lista, 3));

    free(lista1);
    return 0;
}


