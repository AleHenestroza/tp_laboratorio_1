/*
 * utn.c
 *
 *  Created on: 29 sept. 2020
 *      Author: Alejandro
 */

#include <stdio.h>
#include <string.h>
#include "Employee.h"

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

