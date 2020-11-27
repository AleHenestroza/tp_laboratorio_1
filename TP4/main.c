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
    personaAux = NULL;

    printf("\nPresione una tecla para continuar\n");
    __fpurge(stdin);
    getchar();
    system("clear");

    printf("Remover un elemento de la lista, sin borrarlo de memoria.\n");
    print_personas(sublista);
    printf("\nIngrese el ID: ");
    int id;
    scanf("%d", &id);
    personaAux = ll_pop(sublista, get_persona_ID(sublista, id));

    if(personaAux != NULL) {
        print_personas(sublista);
        printf("\nElemento extraido:\n\n");
        print_persona(personaAux);
    }

    printf("\nPresione una tecla para continuar\n");
    __fpurge(stdin);
    getchar();
    system("clear");

    printf("Revisar si la sublista esta contenida en la lista.\n");
    if(ll_containsAll(lista2, sublista)) {
        printf("Todos los elementos de la sublista estan contenidos en la Lista mas grande.\n\n");
    } else {
        printf("Hay elementos en la sublista no contenidos en la lista mas grande.\n\n");
    }

    printf("\nPresione una tecla para continuar\n");
    __fpurge(stdin);
    getchar();
    system("clear");

    printf("Ordenar la sublista\n\n");
    int opcion;
    printf("Elija ordenar por:\n1: ID\n2: Nombre\n3: Altura\n4: Sexo\n\n");
    scanf("%d", &opcion);

    int orden;
    printf("Elija el orden:\n1: Ascendente  -  0: Descendente\n");
    scanf("%d", &orden);

    if(orden == 1 || orden == 0) {
        switch(opcion) {
            case 1:
            ll_sort(sublista, sort_id_persona, 1);
            break;

            case 2:
            ll_sort(sublista, sort_nombre_persona, 1);
            break;

            case 3:
            ll_sort(sublista, sort_altura_persona, 1);
            break;

            case 4:
            ll_sort(sublista, sort_sexo_persona, 1);
            break;

            default:
            printf("Ingreso una opcion invalida\n");
            break;
        }

        print_personas(sublista);
    }

    printf("\nPresione una tecla para continuar\n");
    __fpurge(stdin);
    getchar();

    free(lista2);
    return 0;
}


