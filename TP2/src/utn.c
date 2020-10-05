/*
 * utn.c
 *
 *  Created on: 29 sept. 2020
 *      Author: Alejandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#define ASC 0
#define DESC 1

int showMenu() {
	int opc = -1;
	int input;

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
	fflush(stdin);
	scanf("%d", &input);
	if(input > 0 && input < 7) {
		opc = input;
	}
	return opc;
}
int validateSalary(float salary) {
	int error = -1;
	if(salary > 0) {
		error = 0;
	}
	return error;
}
int validateSector(int sector) {
	int error = -1;
	if(sector > 0 && sector < 5) {
		error = 0;
	}
	return error;
}
int validateString(char* string) {
	int error = -1;
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
		error = 0;
	}
	return error;
}
