#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "persona.h"
#include "LinkedList.h"
#include "utn.h"
int main()
{
    int nextId;
    LinkedList* lista1 = ll_newLinkedList();
    LinkedList* lista2;
    LinkedList* sublista;
    ePersona* personaAux;

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
    if(!modificarElemento(lista1)) {
        printf("Modificacion exitosa!\n");
    }
    print_personas(lista1);
    printf("\n\nClonando lista...\n\n");
    lista2 = ll_clone(lista1);
    if(lista2 != NULL) {
        printf("Clonado exitoso.\n\n");
    }
    printf("\nPresione una tecla para continuar\n");
    __fpurge(stdin);
    getchar();

    printf("Vaciando primera lista.\n\n");
    ll_clear(lista1);
    if(ll_isEmpty(lista1)) {
        printf("\nLa lista esta vacia.\n\n");
    }
    print_personas(lista1);

    printf("\nPresione una tecla para continuar\n");
    __fpurge(stdin);
    getchar();

    system("clear");
    print_personas(lista2);
    printf("Lista 2, clonada de la primera.\n");

    printf("\nEliminando de memoria la primera lista...\n");
    ll_deleteLinkedList(lista1);

    printf("\nPresione una tecla para continuar\n");
    __fpurge(stdin);
    getchar();

    printf("Ingrese dos numeros para realizar una sublista:");
    int num1, num2;

    scanf("%d %d", &num1, &num2);
    sublista = ll_subList(lista2, num1, num2);
    print_personas(sublista);

    printf("Agregue un elemento en la mitad de la sublista\n\n");
    personaAux = crearPersona(nextId);
    ll_push(sublista, ll_len(sublista) / 2, personaAux);
    print_personas(sublista);


    free(lista2);
    return 0;
}


