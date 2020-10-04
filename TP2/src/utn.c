/*
 * utn.c
 *
 *  Created on: 29 sept. 2020
 *      Author: Alejandro
 */

#include <stdio.h>
#include <string.h>
#include "Employee.h"
#define ASC 0
#define DESC 1

int showMenu() {
	int opc = -1;

	printf("\n                          *** ABM Empleados *** \n\n");
	printf("\n                        Elija la opcion que desee.\n\n");
	printf("-------------------------------------------------------------------------------------\n\n");
	printf("1: ALTAS\n"
			"2: MODIFICAR\n"
			"3: BAJA\n"
			"4: INFORMAR\n"
			"5: ORDENAR\n"
			"6: SALIR\n");

	printf("\nIngrese el numero de la opcion deseada: ");
	scanf("%d", &opc);
	return opc;
}
int validateSalary(float salary) {
	int valid = 0;
	if(salary > 0) {
		valid = 1;
	}
	return valid;
}
int validateSector(int sector) {
	int valid = 0;
	if(sector > 0 && sector < 5) {
		valid = 1;
	}
	return valid;
}
int validateString(char* string) {
	int valid = 0;
	int flagInvalid = 0;
	int len = strlen(string);
	for(int i = 0; i < len; i++) {
		/* Valores ASCII:
		 * 65 = A
		 * 90 = Z
		 * 97 = a
		 * 122 = z */
		if(!((string[i] >= 65 && string[i] <= 90) || (string[i] >= 97 && string[i] <= 122))) {
			flagInvalid = 1;
			break;
		}
	}
	if(!flagInvalid) {
		valid = 1;
	}
	return valid;
}
int setName(char* name) {
	int error = -1;
	printf("Ingrese el nombre: ");
	fflush(stdin);
	gets(name);
	if(validateString(name)) {
		error = 0;
	} else {
		printf("\nEl nombre no puede contener numeros.\n\n");
	}
	return error;
}
int setLastName(char* lastName) {
	int error = -1;
	printf("Ingrese el apellido: ");
	fflush(stdin);
	gets(lastName);
	if(validateString(lastName)) {
		error = 0;
	} else {
		printf("\nEl apellido no puede contener numeros.\n\n");
	}
	return error;
}
int setSalary(float * salary) {
	int error = -1;
	printf("Ingrese el sueldo: ");
	scanf("%f", salary);
	if(validateSalary(*salary)) {
		error = 0;
	} else {
		printf("\nEl sueldo no puede ser caracteres o negativo.\n\n");
	}
	return error;
}
int setSector(int * sector) {
	int error = -1;
	printf("Ingrese el sector.\n"
			"1: GERENCIA\n"
			"2: ADMINISTRACION\n"
			"3: PROYECTOS\n"
			"4: MAESTRANZA\n");
	printf("Sector: ");
	scanf("%d", sector);
	if(validateSector(*sector)) {
		error = 0;
	} else {
		printf("\nEl sector debe ser un numero entre 1 y 4 inclusive.\n\n");
	}
	return error;
}
int setData(char* name, char* lastName, float * salary, int * sector) {
	int error = -1;
	int e = 0;

	for(int i = 0; i < 4; i++) {
		switch(i) {
			case 0:
				e = setName(name);
				break;
			case 1:
				e = setLastName(lastName);
				break;
			case 2:
				e = setSalary(salary);
				break;
			case 3:
				e = setSector(sector);
				break;
		}
		if(e == -1) {
			break;
		}
	}
	if(!e) {
		error = 0;
	}

	return error;
}
void menuSwitch(Employee* lista, int len, int * id, int * salida, int * e) {
	int input = 0;
	char name[51];
	char lastName[51];
	float salary = 0;
	int sector = 0;
	int inputId;

	switch(showMenu()) {
		case 1:
			*e = setData(name, lastName, &salary, &sector);
			if(!*e) {
				*e = addEmployee(lista, len, *id, name, lastName, salary, sector);
				if(!*e) {
					printf("\nCarga exitosa.\n\n");
					*id += 1;
				} else {
					printf("\nHubo un error en la carga, revise que los parametros sean correctos.\n\n");
				}
			} else {
				printf("\nAlgunos de los datos ingresados no son correctos.\n\n");
			}
			break;
		case 2:
			*e = printEmployees(lista, len);
			if(!*e) {
				printf("\nIngrese el ID del empleado a modificar: ");
				scanf("%d", &inputId);
				*e = modifyEmployee(lista, len, inputId);
				if(!*e) {
					printf("\nEmpleado modificado con exito.\n\n");
				} else {
					printf("\nHubo un error en la modificacion.\n\n");
				}
			} else {
				printf("\nNo hay empleados para modificar.\n\n");
			}
			break;
		case 3:
			*e = printEmployees(lista, len);
			if(!*e) {
				printf("\n\nIngrese el ID del empleado a eliminar: ");
				scanf("%d", &inputId);
				// Si bien la funcion removeEmployee efectua un findEmployeeById, de esta forma se puede solicitar confirmacion al usuario antes de eliminar
				*e = findEmployeeById(lista, len, inputId);
				if(!*e) {
					printf("\n\nConfirma que desea eliminar?\n"
							"1: SI | 2: NO\n\n"
							"Confirma: ");
					scanf("%d", &input);
					if(input) {
						*e = removeEmployee(lista, len, inputId);
						if(!*e) {
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
			*e = printEmployees(lista, len);
			if(!*e) {
				*e = informSalary(lista, len);
				if(*e == -1) {
					printf("\nError al informar datos de sueldos.\n\n");
				}
			} else {
				printf("\nNo hay empleados para mostrar.\n\n");
			}
			break;
		case 5:
			*e = printEmployees(lista, len);
			if(!*e) {
				printf("\nComo desea ordenar la lista?\n"
						"0: ASCENDENTE | 1: DESCENDENTE\n\n"
						"Orden: ");
				scanf("%d", &input);
				if(input) {
					*e = sortEmployees(lista, len, DESC);
				} else if(!input) {
					*e = sortEmployees(lista, len, ASC);
				} else {
					printf("\nIngrese una opcion valida.\n\n");
					*e = -1;
				}
				if(!*e) {
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
				*salida = 1;
			}
			break;
		default:
			printf("\nIngrese una opcion valida.\n\n");
			break;
	}
}
