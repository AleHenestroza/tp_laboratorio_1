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
