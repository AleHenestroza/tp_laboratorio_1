#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int option = 0;
    int flagData = 0;
    int idMax;
    char c; // Esta variable me sirve para usar getchar() para "pausar" la aplicación tras cada loop del do/while [en Linux parece que no se puede usar system("pause")]
    char salida = 'n';
    LinkedList* listaEmpleados = ll_newLinkedList();

    do {
    	printf("Menu:\n"
			 "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
			 "2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
			 "3. Alta de empleado\n"
			 "4. Modificar datos de empleado\n"
			 "5. Baja de empleado\n"
			 "6. Listar empleados\n"
			 "7. Ordenar empleados\n"
			 "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
			 "9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
			"10. Salir\n");
    	printf("\nIngrese opcion: ");
    	__fpurge(stdin); // No se por qué hace falta este fpurge, ya que no pido caracteres, pero si no lo incluyo, el menu se muestra en momentos que no debería mostrarse
    	scanf("%d", &option);
    	if(option < 1 || option > 10) {
    		option = 0;
    	}
        switch(option) {
            case 1:
                idMax = controller_loadFromText("data.csv",listaEmpleados);
                if(idMax == -1) {
                    printf("Error en la carga de datos.\n");
                } else {
                    printf("Carga de datos exitosa.\n");
                    printf("\nID MAX: %d\n", idMax);
                    flagData = 1;
                }
                break;
            case 2:
                printf("Proximamente disponible! :)");
            	break;
            case 3:
            	if(!flagData || controller_addEmployee(listaEmpleados)) {
            		printf("Error en carga de empleado.\n");
            	} else {
            		printf("Carga exitosa.\n");
            	}
            	break;
            case 4:
                if(!flagData) {
                    printf("No se inicializo la lista de empleados, cargue los datos del archivo.\n");
                } else {
                    system("clear");
                    controller_ListEmployee(listaEmpleados);
                    printf("\n");
                    switch(controller_editEmployee(listaEmpleados)) {
                        case -1:
                            printf("\nModificacion cancelada por el usuario/\n");
                            break;
                        case 0:
                            printf("\nModificacion exitosa.\n");
                            break;
                        case 1:
                            printf("\nError en la modificacion.\n");
                            break;
                    }
                }
            	break;
            case 5:
                if(!flagData) {
                    printf("No se inicializo la lista de empleados, cargue los datos del archivo.\n");
                } else {
                    system("clear");
                    controller_ListEmployee(listaEmpleados);
                    printf("\n");
                    if(!controller_removeEmployee(listaEmpleados)) {
                        printf("\nBaja exitosa.\n");
                    } else {
                        printf("\nError en la baja.\n");
                    }
                }
            	break;
            case 6:
                if(!flagData) {
                    printf("No se inicializo la lista de empleados, cargue los datos del archivo.\n");
                } else {
                    system("clear");
                    controller_ListEmployee(listaEmpleados);
                }
            	break;
            case 7:
                if(!flagData) {
                    printf("No se inicializo la lista de empleados, cargue los datos del archivo.\n");
                } else {
                    controller_sortEmployee(listaEmpleados);
                }
            	break;
            case 8:
                controller_saveAsText("data2.csv", listaEmpleados);
            	break;
            case 9:
                printf("Proximamente disponible! :)");
            	break;
            case 10:
            	system("clear");
            	printf("Confirma que desea salir? ");
            	__fpurge(stdin);
                scanf("%c", &salida);
            	break;
            default:
                system("clear");
                printf("Opcion invalida.\n");
            	break;

        }
        printf("\n\nPresione una tecla para continuar.\n\n");
        __fpurge(stdin);
        c = getchar();
        printf("%c", c); // Esta linea no se va a mostrar, pero de lo contrario, el programa tendría un warning por no utilizar la variable c, cuyo único fin es pausar la aplicación
        system("clear");
    } while(salida != 's');
    ll_deleteLinkedList(listaEmpleados);
    return EXIT_SUCCESS;
}

