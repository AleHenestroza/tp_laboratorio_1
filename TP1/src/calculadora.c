/*
 * calculadora.c
 *
 *  Created on: 8 sept. 2020
 *      Author: Alejandro Henestroza
 */
#include <stdio.h>

int desplegarMenu(int num1, int num2, int num1Ingresado, int num2Ingresado) {
	int opcion;

	if(num1Ingresado == 0) {
		printf("1. Ingresar 1er operando ( A = x ) \n");
	} else {
		printf("1. Ingresar 1er operando ( A = %d ) \n", num1);
	}

	if(num2Ingresado == 0) {
		printf("2. Ingresar 2do operando ( B = y ) \n");
	} else {
		printf("1. Ingresar 2do operando ( B = %d ) \n", num2);
	}

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
	fflush(stdin);
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

long long int calcularFactorial(int num1) {
	long long int resultado = 1;

	if(num1 > 0) {
		for (int i = num1; i > 0; i--) {
			resultado = resultado * i;
		}
	}

	if(num1 < 0) {
		resultado = -1;
	}

	return resultado;
}

void mostrarResultados(int suma, int resta, int divisionValida, float division, int producto, long long int factorialA, long long int factorialB) {
	printf("El resultado de A+B es: %d\n", suma);
	printf("El resultado de A-B es: %d\n", resta);
	if(divisionValida == 1) {
		printf("El resultado de A/B es: %f\n", division);
	} else {
		printf("No es posible dividir por cero\n");
	}
	printf("El resultado de A*B es: %d\n", producto);
	if(factorialA != -1) {
		printf("El factorial de A es: %I64d\n", factorialA);
	} else {
		printf("No se puede calcular el factorial de A, ya que es un numero negativo\n");
	}
	if (factorialB != -1) {
		printf("El factorial de B es: %I64d\n", factorialB);
	} else {
		printf("No se puede calcular el factorial de B, ya que es un numero negativo\n");
	}
}

