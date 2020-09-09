/*
 ============================================================================
 Name        : TP1.c
 Author      : Alejandro Henestroza
 Version     :
 Copyright   : Your copyright notice
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int main(void) {
	setbuf(stdout, NULL);

	int num1;
	int num2;
	int suma;
	int resta;
	float division;
	int producto;
	long int factorialA;
	long int factorialB;
	int salida = 0;
	int operacionesRealizadas = 0;
	int num1Ingresado = 0;
	int num2Ingresado = 0;
	int divisionValida = 1;

	do {
		system("cls");
		if(num1Ingresado == 1) {
			printf("El primer numero es: %d\n", num1);
		}

		if(num2Ingresado == 1) {
			printf("El segundo numero es: %d\n", num2);
		}

		printf("\nElija la opcion\n\n");

		switch(desplegarMenu()) {
			case 1:
				num1 = ingresarNumero();
				num1Ingresado = 1;
				break;

			case 2:
				num2 = ingresarNumero();
				num2Ingresado = 1;
				break;

			case 3:
				if(num1Ingresado != 0 && num2Ingresado != 0) {

					suma = sumar(num1, num2);

					resta = restar(num1, num2);

					if(num2 != 0) {
						division = dividir(num1, num2);
					} else {
						divisionValida = 0;
					}

					producto = multiplicar(num1, num2);

					if(num1 >= 0) {
						factorialA = calcularFactorial(num1);
					} else {
						factorialA = -1;
					}

					if (num2 >= 0) {
						factorialB = calcularFactorial(num2);
					} else {
						factorialB = -1;
					}
					operacionesRealizadas = 1;
					printf("Operaciones realizadas con exito, en el proximo menu elija la opcion 4 para mostrar los resultados.\n");
				} else {
					printf("Debe haber dos numeros ingresados para realizar las operaciones\n");
				}
				break;

			case 4:

				if(operacionesRealizadas == 1) {
					printf("El resultado de A+B es: %d\n", suma);
					printf("El resultado de A-B es: %d\n", resta);
					if(divisionValida == 1) {
						printf("El resultado de A/B es: %f\n", division);
					} else {
						printf("No es posible dividir por cero\n");
					}
					printf("El resultado de A*B es: %d\n", producto);
					if(factorialA != -1) {
						printf("El factorial de A es: %ld\n", factorialA);
					} else {
						printf("No se puede calcular el factorial de A, ya que es un numero negativo\n");
					}
					if (factorialB != -1) {
						printf("El factorial de B es: %ld\n", factorialB);
					} else {
						printf("No se puede calcular el factorial de B, ya que es un numero negativo\n");
					}

				} else {
					printf("Debe realizar las operaciones antes de mostrar los resultados\n");
				}
				break;

			case 5:
				salida = 1;
				break;

			default:
				printf("Ingrese una opcion valida");
				break;
		}

		system("pause");

	} while(salida == 0);


	return EXIT_SUCCESS;
}
















































