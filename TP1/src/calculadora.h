/*
 * calculadora.h
 *
 *  Created on: 8 sept. 2020
 *      Author: Alejandro Henestroza
 */

#ifndef CALCULADORA_H_
#define CALCULADORA_H_

/**
 * @brief Despliega el menu de opciones y lee la opcion ingresada por el usuario
 *
 * @return int correspondiente a la opcion ingresada por el usuario
 */
int desplegarMenu();

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
long int calcularFactorial(int num1);

#endif /* CALCULADORA_H_ */