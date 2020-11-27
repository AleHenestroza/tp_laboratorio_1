#include "menus.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include "parser.h"

void mostrar_menu() {
    printf(
     "Menu:\n"
     "1. Crear nueva LinkedList.\n"
     "2. Imprimir tamanio de LinkedList (debe estar creada primero).\n"
     "3. Agregar elemento a la LinkedList.\n"
     "4. Obtener elemento de la LinkedList.\n"
     "5. Modificar elemento de la LinkedList.\n"
     "6. Eliminar elemento de la LinkedList.\n"
     "7. Vaciar LinkedList.\n"
     "8. Eliminar LinkedList.\n"
     "9. Obtener indice de un elemento.\n"
    "10. Verificar si la LinkedList esta vacia.\n"
    "11. Agregar un nuevo elemento en una posicion determinada.\n"
    "12. Remover un elemento de una posicion determinada, sin eliminarlo completamente.\n"
    "13. Verifica que un elemento este contenido en la LinkedList.\n"
    "14. Verifica que una sublista este contenida dentro de la LinkedList.\n"
    "15. Genera una sublista con elementos de la LinkedList.\n"
    "16. Genera otra LinkedList, clonada de la primera.\n"
    "17. Ordena la LinkedList.\n"
    "18. Salir\n\n"
    );
    printf("Ingrese la opcion deseada: ");
}
int desplegar_menu() {
    int opcion;
    system("clear");
    mostrar_menu();
    __fpurge(stdin);
    scanf("%d", &opcion);
    if(!validar_opcion(opcion)) {
        opcion = -1;
    }
    return opcion;
}
int validar_opcion(int opcion) {
    int valido = 0;
    if(opcion > 0 && opcion <= 18) {
        valido = 1;
    }
    return valido;
}
