/*
 ============================================================================
 Name        : TP2.c
 Author      : AlejandroHenestroza
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"

#define LEN 1000
#define ASC 0
#define DESC 1

int main(void) {
	setbuf(stdout, NULL);

	Employee lista[LEN];
	int id = 10001;
	int salida = 0;
	int input = 0;
	int e = -1;
	char name[51];
	char lastName[51];
	float salary = 0;
	int sector = 0;
	int inputId;

	printf("Bienvenid@\n\n");
	printf("Antes de comenzar a utilizar el Sistema de ABM, es necesario inicializar la lista de empleados.\n\n");
	system("pause");

	e = initEmployees(lista, LEN);
	if(!e) {
		printf("\nLista inicializada con exito.\n\n");
		system("pause");
		do {
			system("cls");
			switch(showMenu()) {
				case 1:
					e = setData(name, lastName, &salary, &sector);
					if(!e) {
						e = addEmployee(lista, LEN, id, name, lastName, salary, sector);
						if(!e) {
							printf("\nCarga exitosa.\n\n");
							id++;
						} else {
							printf("\nHubo un error en la carga, revise que los parametros sean correctos.\n\n");
						}
					} else {
						printf("\nAlgunos de los datos ingresados no son correctos.\n\n");
					}
					break;
				case 2:
					printEmployees(lista, LEN);
					printf("\nIngrese el ID del empleado a modificar: ");
					scanf("%d", &inputId);
					e = modifyEmployee(lista, LEN, inputId);
					if(!e) {
						printf("\nEmpleado modificado con exito.\n\n");
					} else {
						printf("\nHubo un error en la modificacion.\n\n");
					}
					break;
				case 3:
					printEmployees(lista, LEN);
					printf("\n\nIngrese el ID del empleado a eliminar: ");
					scanf("%d", &inputId);
					// Si bien la funcion removeEmployee efectua un findEmployeeById, de esta forma se puede solicitar confirmacion al usuario antes de eliminar
					e = findEmployeeById(lista, LEN, inputId);
					if(!e) {
						printf("\n\nConfirma que desea eliminar?\n"
								"1: SI | 2: NO\n\n"
								"Confirma: ");
						scanf("%d", &input);
						if(input) {
							e = removeEmployee(lista, LEN, inputId);
							if(!e) {
								printf("\nEmpleado eliminado.\n\n");
							} else {
								printf("\nHubo un error al eliminar.\n\n");
							}
						} else if(input == 2){
							printf("\nOperacion cancelada por el usuario.\n\n");
						} else {
							printf("\nIngrese una opcion valida. Operacion cancelada.\n\n");
						}
					} else {
						printf("\nNo se encontro un empleado con ese ID.\n\n");
					}
					break;
				case 4:
					e = printEmployees(lista, LEN);
					if(e == -1) {
						printf("\nNo hay empleados para mostrar.\n\n");
					}
					break;
				case 5:
					printf("\nComo desea ordenar la lista?\n"
							"0: ASCENDENTE | 1: DESCENDENTE\n\n"
							"Orden: ");
					scanf("%d", &input);
					if(input) {
						e = sortEmployees(lista, LEN, DESC);
					} else if(!input) {
						e = sortEmployees(lista, LEN, ASC);
					} else {
						printf("\nIngrese una opcion valida.\n\n");
						e = -1;
					}
					if(!e) {
						printf("\nLista ordenada exitosamente.\n\n");
					} else {
						printf("\nError al ordenar la lista.\n\n");
					}
					break;
				case 6:
					printf("\nConfirma salida?\n"
							"1: SI  |  0: NO\n"
							"Confirma: ");
					scanf("%d", &input);
					if(input) {
						salida = 1;
					}
					break;
				default:
					printf("\nIngrese una opcion valida.\n\n");
					break;
			}
			system("pause");
		} while(!salida);

	} else {
		printf("\nHubo un error en la inicializacion de la lista.\n\n");
	}

	return EXIT_SUCCESS;
}
