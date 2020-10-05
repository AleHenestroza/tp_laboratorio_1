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
	int e;

	printf("Bienvenid@\n\n");
	printf("Antes de comenzar a utilizar el Sistema de ABM, es necesario inicializar la lista de empleados.\n\n");
	system("pause");

	e = initEmployees(lista, LEN);
	if(!e) {
		printf("\nLista inicializada con exito.\n\n");
		system("pause");
		do {
			e = -1;
			system("cls");
			menuSwitch(lista, LEN, &id, &salida, &e);
			system("pause");
		} while(!salida);

	} else {
		printf("\nHubo un error en la inicializacion de la lista.\n\n");
	}

	return EXIT_SUCCESS;
}
