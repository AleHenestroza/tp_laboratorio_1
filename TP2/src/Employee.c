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
	int index = -1;
	if(list != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if(list[i].id == id) {
				index = i;
				break;
			}
		}
	}
	return index;
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
				// Orden alfabetico
				if( ( strcmp(list[i].lastName, list[j].lastName) < 0 && order ) || ( strcmp(list[i].lastName, list[j].lastName) > 0 && !order ) ) {
					tmp = list[i];
					list[i] = list[j];
					list[j] = tmp;
				} else if( ( strcmp(list[i].lastName, list[j].lastName) == 0 ) && ( ( list[i].sector < list[j].sector && order ) || ( list[i].sector > list[j].sector && !order ) ) ) {
					// Orden por sector en caso de misma letra
					tmp = list[i];
					list[i] = list[j];
					list[j] = tmp;
				}
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
	/* Creo variables temporales para no modificar los campos del Empleado directamente.
	 * Si bien la funcion valida los datos ingresados, lo hace luego de solicitarlos por
	 * lo que podria llegar a asignar un valor invalido.
	 * Asignandolos a variables temporales, puedo revisar si el retorno de las funciones
	 * fue un error o no y, en base a eso, asignar el nuevo valor */
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
float getTotalSalary(Employee* list, int len) {
	float total = -1;
	if(list != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if(!list[i].isEmpty) {
				total += list[i].salary;
			}
		}
	}
	// Para compensar por el hecho de inicializar el total en -1 (de lo contrario el total no seria exacto)
	if(total > -1) {
		total++;
	}
	return total;
}
float getAverageSalary(Employee* list, int len, float totalSalary) {
	float promedio = -1;
	int count = 0;
	if(list != NULL && len > 0) {
		for(int i = 0; i < len; i++) {
			if(!list[i].isEmpty) {
				count++;
			}
		}
		if(count > 0) {
			promedio = totalSalary / count;
		}
	}
	return promedio;
}
int getAboveAverageSalaryEmployeesCount(Employee* list, int len, float avgSalary) {
	int count = 0;
	if(list != NULL && len > 0 && avgSalary > -1) {
		for(int i = 0; i < len; i++) {
			if(!list[i].isEmpty && list[i].salary >= avgSalary) {
				count++;
			}
		}
	}
	return count;
}
int informSalary(Employee* list, int len) {
	int error = -1;
	float totalSalary;
	float avgSalary;
	int count;
	if(list != NULL && len > 0) {
		totalSalary = getTotalSalary(list, len);
		if(totalSalary > -1) {
			avgSalary = getAverageSalary(list, len, totalSalary);
			count = getAboveAverageSalaryEmployeesCount(list, len, avgSalary);
		} else {
			printf("\nError al calcular el total de sueldos.\n\n");
		}

		if(count > 0) {
			printf("\n\nEl sueldo total es de: %.2f\n", totalSalary);
			printf("El sueldo promedio es de: %.2f\n", avgSalary);
			if(count == 1) {
				printf("Hay %d solo empleado en la lista.\n\n", count);
			} else {
				printf("Hay %d empleados que cobran por encima del sueldo promedio.\n\n", count);
			}
			error = 0;
		}
	}
	return error;
}

