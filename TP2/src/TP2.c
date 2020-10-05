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
#include "Employee.h"
#include "utn.h"
#define LEN 1000
#define ASC 0
#define DESC 1

int main(void) {
	setbuf(stdout, NULL);
	Employee lista[LEN];
	int camposEmployee = 4;
	int id = 10001;
	int salida = 0;
	int e;
	int input = 0;
	char name[51];
	char lastName[51];
	float salary = 0;
	int sector = 0;
	int inputId;

	printf("Bienvenid@\n\n");
	printf("Antes de comenzar a utilizar el Sistema de ABM, es necesario inicializar la lista de empleados.\n\n");
	system("pause");

	if(!initEmployees(lista, LEN)) {
		printf("\nLista inicializada con exito.\n\n");
		system("pause");
	}

	while(!salida) {
		system("cls");
		switch(showMenu()) {
		case 1:
			system("cls");
			printf("\nNuevo ingreso\n");
			e = 0;
			for(int i = 0; i < camposEmployee; i++) {
				switch(i) {
				case 0:
					printf("\nIngrese el nombre: ");
					fflush(stdin);
					gets(name);
					e = validateString(name);
					break;
				case 1:
					printf("\nIngrese el apellido: ");
					fflush(stdin);
					gets(lastName);
					e = validateString(lastName);
					break;
				case 2:
					printf("\nIngrese el sueldo: ");
					scanf("%f", &salary);
					e = validateSalary(salary);
					break;
				case 3:
					printf("\n1: GERENCIA"
							"\n2: ADMINISTRACION"
							"\n3: PROYECTOS"
							"\n4: SOPORTE"
							"\nIngrese el sector: ");
					scanf("%d", &sector);
					e = validateSector(sector);
					break;
				}
				if(e == -1) {
					break; // Break del for
				}
			}
			if(!e) {
				addEmployee(lista, LEN, id, name, lastName, salary, sector);
				id++;
				printf("\nCarga exitosa.\n\n");
			} else {
				printf("\nError al cargar nuevo empleado, verifique que los datos ingresados sean validos.\n\n");
			}
			break;
		case 2:
			if(!printEmployees(lista, LEN)) {
				printf("\nIngrese el ID del empleado a modificar: ");
				scanf("%d", &inputId);
				if(!modifyEmployee(lista, LEN, inputId)) {
					printf("\nEmpleado modificado con exito.\n\n");
				} else {
					printf("\nHubo un error en la modificacion.\n\n");
				}
			} else {
				printf("\nNo hay empleados para modificar.\n\n");
			}
			break;
		case 3:
			if(!printEmployees(lista, LEN)) {
				printf("\n\nIngrese el ID del empleado a eliminar: ");
				scanf("%d", &inputId);
				if(!findEmployeeById(lista, LEN, inputId)) {
					printf("\n\nConfirma que desea eliminar?\n"
							"1: SI | 2: NO\n\n"
							"Confirma: ");
					scanf("%d", &input);
					if(input) {
						if(!removeEmployee(lista, LEN, inputId)) {
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
			} else {
				printf("\nNo hay empleados para eliminar.\n\n");
			}
			break;
		case 4:
			if(!printEmployees(lista, LEN)) {
				if(informSalary(lista, LEN) == -1) {
					printf("\nError al informar datos de sueldos.\n\n");
				}
			} else {
				printf("\nNo hay empleados para mostrar.\n\n");
			}
			break;
		case 5:
			if(!printEmployees(lista, LEN)) {
				printf("\nComo desea ordenar la lista?\n"
						"0: ASCENDENTE | 1: DESCENDENTE\n\n"
						"Orden: ");
				scanf("%d", &input);
				if(input == DESC) {
					e = sortEmployees(lista, LEN, DESC);
				} else if(input == ASC) {
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
			} else {
				printf("\nLa lista esta vacia y no se puede ordenar.\n\n");
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
	}
	return EXIT_SUCCESS;
}
