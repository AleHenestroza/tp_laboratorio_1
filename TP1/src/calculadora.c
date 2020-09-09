/*
 * calculadora.c
 *
 *  Created on: 8 sept. 2020
 *      Author: Alejandro Henestroza
 */
#include <stdio.h>

int desplegarMenu() {
	int opcion;

	printf("1. Ingresar 1er operando ( A = x ) \n");
	printf("2. Ingresar 2do operando ( B = y ) \n");
	printf("3. Calcular todas las operaciones \n");
	printf("4. Informar resultados \n");
	printf("5. Salir \n");

	fflush( stdin );
	scanf("%d", &opcion);

	return opcion;
}

int ingresarNumero() {
	int numero;

	printf("Ingrese el numero: ");
	scanf("%d", &numero);

	return numero;
}

int sumar(int num1, int num2) {
	int resultado;

	resultado = num1 + num2;

	return resultado;
}

int restar(int num1, int num2) {
	int resultado;

	resultado = num1 - num2;

	return resultado;
}

float dividir(int num1, int num2) {
	float resultado = 0;

	resultado = (float)num1 / (float)num2;

	return resultado;
}

int multiplicar(int num1, int num2) {
	int resultado;

	resultado = num1 * num2;

	return resultado;
}

long int calcularFactorial(int num1) {
	long int resultado = 1;

	if(num1 > 0) {
		for (int i = num1; i > 0; i--) {
			resultado = resultado * i;
		}
	}

	return resultado;
}

