/*
 * utn.h
 *
 *  Created on: 29 sept. 2020
 *      Author: Alejandro
 */


#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */

/**
 * @brief 			Show the main menu, asks for an input from the user and returns it
 *
 * @return			Returns the input from the user, the value is checked in the main()
 */
int showMenu();

/**
 * @brief 			Takes a float as parameter and checks if it's greater than 0
 *
 * @param salary	float
 * @return			Returns a boolean value (0 = false | 1 = true)
 */
int validateSalary(float salary);

/**
 * @brief 			Takes an int as parameter and checks if it's between 1 and 4
 *
 * @param sector	int
 * @return			Returns a boolean value (0 = false | 1 = true)
 */
int validateSector(int sector);

/**
 * @brief 			Takes a string as parameter and checks if it contains any number by comparing to their ASCII values (48 - 57)
 *
 * @param string	char* array
 * @return			Returns a boolean value (0 = false | 1 = true)
 */
int validateString(char* string);

/**
 * @brief 			Asks the user for a string and validates it
 *
 * @param name		Pointer to the string
 * @return			Returns -1 if the input is invalid, 0 if OK
 */
int setName(char* name);

/**
 * @brief 			Asks the user for a string and validates it
 *
 * @param lastName	Pointer to the string
 * @return			Returns -1 if the input is invalid, 0 if OK
 */
int setLastName(char* lastName);

/**
 * @brief 			Asks the user for a float and validates it
 *
 * @param salary	Pointer to the float number
 * @return			Returns -1 if the input is less than 0, returns 0 if OK
 */
int setSalary(float * salary);

/**
 * @brief			Asks the user for an int and validates it
 *
 * @param sector	Pointer to the int number
 * @return			Returns -1 if invalid, 0 if OK
 */
int setSector(int * sector);

/**
 * @brief 			Takes 4 pointers as parameters, and executes the setName, setLastName, setSalary and setSector functions
 * 					on them to set their values
 *
 * @param name		Pointer to the name string
 * @param lastName	Pointer to the lastName string
 * @param salary	Pointer to the salary
 * @param sector	Pointer to the sector
 * @return			Returns -1 if any of the functions failed to execute (invalid input by the user), and 0 if OK
 */
int setData(char* name, char* lastName, float * salary, int * sector);

/**
 * @brief 			Switch para el menu principal, era demasiado largo para dejarlo en la funcion main, por lo que fue
 * 					refactorizado para que sea su propia funcion. Recibe los punteros al Id, a la bandera de salida del
 * 					programa y a la variable de error. Puede modificar el valor del id y de la bandera de salida. El puntero
 * 					al error es para no crear mas variables innecesariamente
 *
 * @param lista		Puntero al array de empleados
 * @param len		Longitud del array
 * @param id		Puntero al Id asignado por el sistema (para autoincrementarlo)
 * @param salida	Puntero a la bandera de salida (para modificarla en caso de querer cerrar el programa)
 * @param e			Puntero a la variable de error (para no crear una nueva variable innecesaria)
 */
void menuSwitch(Employee* lista, int len, int * id, int * salida, int * e);
