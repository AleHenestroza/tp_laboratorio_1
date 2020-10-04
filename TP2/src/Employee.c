/*
 * Employee.c
 *
 *  Created on: 29 sept. 2020
 *      Author: Alejandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"

int initEmployees(Employee* list, int len) {
	int error = -1;
	if(list != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			list[i].isEmpty = 1;
		}
		error = 0;
	}
	return error;
}
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector) {
	int error = -1;
	if(list != NULL && len > 0) {
		system("cls");
		for(int i = 0; i < len; i++) {
			if(list[i].isEmpty) {
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].salary = salary;
				list[i].sector = sector;
				list[i].isEmpty = 0;
				error = 0;
				break;
			}
		}
	}
	return error;
}
int findEmployeeById(Employee* list, int len, int id) {
	int posicion = -1;
	if(list != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if(list[i].id == id) {
				posicion = i;
				break;
			}
		}
	}
	return posicion;
}
int removeEmployee(Employee* list, int len, int id) {
	int error = -1;
	int index;
	if(list != NULL && len > 0) {
		index = findEmployeeById(list, len, id);
		if(index != -1) {
			list[index].isEmpty = 1;
			error = 0;
		}
	}
	return error;
}
int sortEmployees(Employee* list, int len, int order) {
	int error = -1;
	Employee tmp;
	if(list != NULL && len > 0 && (order == 1 || order == 0)) {
		error = 0;
		for(int i = 0; i < len - 1; i++) {
			for(int j = i+1; j < len; j++) {
				if( (strcmp(list[i].lastName, list[j].lastName) < 0 && order) || (strcmp(list[i].lastName, list[j].lastName) > 0 && !order) ) {
					tmp = list[i];
					list[i] = list[j];
					list[j] = tmp;
				} else if( (strcmp(list[i].lastName, list[j].lastName) == 0 ) && ((list[i].sector < list[j].sector && order) || (list[i].sector > list[j].sector && !order)) ) {
					tmp = list[i];
					list[i] = list[j];
					list[j] = tmp;
				}


//				if((list[i].sector > list[j].sector && order)) {
//					tmp = list[i];
//					list[i] = list[j];
//					list[j] = tmp;
//				} else if((list[i].sector < list[j].sector && !order)) {
//					tmp = list[i];
//					list[i] = list[j];
//					list[j] = tmp;
//				}
			}
		}
	}
	return error;
}
void printEmployee(Employee emp) {
	printf(" %5d     %15s      %15s         %5.2f    %5d\n", emp.id, emp.lastName, emp.name, emp.salary, emp.sector);
}
int printEmployees(Employee* list, int len) {
	int error = -1;
	if(list != NULL && len > 0) {
		system("cls");
		printf("                       *** Lista de Empleados *** \n");
		printf("------------------------------------------------------------------------------\n");
		printf("   ID    |       Apellido       |       Nombre       |   Sueldo   |   Sector\n");
		printf("------------------------------------------------------------------------------\n");

		for(int i = 0; i < len; i++) {
			if(!list[i].isEmpty) {
				printEmployee(list[i]);
				error = 0;
			}
		}
	}
	return error;
}
int modifyEmployee(Employee* list, int len, int id) {
	int error = -1;
	int index;
	int e; // Posible error en los inputs
	int opc; // Opcion del switch
	char name[51];
	char lastName[51];
	float salary;
	int sector;

	if(list != NULL && len > 0) {
		index = findEmployeeById(list, len, id);
		if(index != -1) {
			printEmployee(list[index]);

			printf("\nQue dato desea modificar?\n");
			printf("1: NOMBRE\n"
					"2: APELLIDO\n"
					"3: SUELDO\n"
					"4: SECTOR\n");
			printf("\nIngrese el numero de la opcion deseada: ");
			scanf("%d", &opc);
			switch(opc) {
				case 1:
					e = setName(name);
					if(!e) {
						strcpy(list[index].name, name);
						error = 0;
					}
					break;
				case 2:
					e = setLastName(lastName);
					if(!e) {
						strcpy(list[index].lastName, lastName);
						error = 0;
					}
					break;
				case 3:
					e = setSalary(&salary);
					if(!e) {
						list[index].salary = salary;
						error = 0;
					}
					break;
				case 4:
					e = setSector(&sector);
					if(!e) {
						list[index].sector = sector;
						error = 0;
					}
					break;
				default:
					printf("\nIngrese una opcion valida.\n");
					break;
			}
		} else {
			printf("No se encontro un empleado con ese ID.\n\n");
		}
	}
	return error;
}
