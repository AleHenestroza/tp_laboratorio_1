/*
 * calculadora.h
 *
 *  Created on: 8 sept. 2020
 *      Author: Alejandro Henestroza
 */

#ifndef CALCULADORA_H_
#define CALCULADORA_H_

#endif /* CALCULADORA_H_ */

/**
 * @brief Despliega el menu de opciones y lee la opcion ingresada por el usuario. Si ya hay numeros ingresados, los muestra en el menu
 *
 * @param num1 Primer numero ingresado
 * @param num2 Segundo numero ingresado
 * @param num1Ingresado Bandera para comprobar si hay un numero ingresado
 * @param num2Ingresado Bandera para comprobar si hay un numero ingresado
 * @return int correspondiente a la opcion ingresada por el usuario
 */
int desplegarMenu(int num1, int num2, int num1Ingresado, int num2Ingresado);

/**
 * @brief Pide el ingreso de un numero y lo retorna.
 *
 * @return El numero ingresado
 */
int ingresarNumero();

/**
 * @brief Recibe dos numeros enteros como parametros y retorna la suma
 *
 * @param num1 Primer numero
 * @param num2 Segundo numero
 * @return Resultado de la suma de num1 y num2
 */
int sumar(int num1, int num2);

/**
 * @brief Recibe dos numeros enteros como parametros y retorna la resta
 *
 * @param num1 Primer numero
 * @param num2 Segundo numero
 * @return Resultado de la resta de num1 y num2
 */
int restar(int num1,int num2);

/**
 * @brief Recibe dos numeros enteros como parametros y retorna su division
 *
 * @param num1 Primer numero
 * @param num2 Segundo numero
 * @return Resultado de la division
 */
float dividir(int num1, int num2);

/**
 * @brief Recibe dos numeros enteros como parametros, los castea a float y retorna su producto como un float
 *
 * @param num1 Primer numero
 * @param num2 Segundo numero
 * @return Producto de los dos numeros
 */
int multiplicar(int num1, int num2);

/**
 * @brief Recibe un numero como parametro y retorna su factorial
 *
 * @param num1 Numero ingresado
 * @return Factorial del numero ingresado
 */
long long int calcularFactorial(int num1);

/**
 * @brief Toma los resultados de las operaciones y los muestra por consola
 *
 * @param suma
 * @param resta
 * @param divisionValida
 * @param division
 * @param producto
 * @param factorialA
 * @param factorialB
 */
void mostrarResultados(int suma, int resta, int divisionValida, float division, int producto, long long int factorialA, long long int factorialB);
