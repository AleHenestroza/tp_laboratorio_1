/*
 * Employee.h
 *
 *  Created on: 29 sept. 2020
 *      Author: Alejandro
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} Employee;

#endif /* EMPLOYEE_H_ */

/**
 * @brief 			Goes through an Employee array, initializing each isEmpty flag with 1
 *
 * @param list		Employee* Pointer to the array of employees
 * @param len		Array length
 * @return			Returns -1 if error, 0 if OK
 */
int initEmployees(Employee* list, int len);

/**
 * @brief 			Adds the parameters to the first free item of a list of employees
 *
 * @param list		Employee* Pointer to the array of employees
 * @param len		Array length
 * @param id		The id is autogenerated by the system
 * @param name		Name of the employee
 * @param lastName	Last Name of the employee
 * @param salary	The salary, must be greater than 0
 * @param sector	The sector, must be greater than 0
 * @return			-1 if Error (invalid parameters or full array), 0 if OK
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);

/**
 * @brief 			Searches an array of Employees and return the position of the employee with the id passed as parameter
 *
 * @param list		Employee* Pointer to the array of employees
 * @param len		Array length
 * @param id		The ID searched for
 * @return			Returns -1 if Error or the index of the employee
 */
int findEmployeeById(Employee* list, int len, int id);

/**
 * @brief 			Removes an Employee by Id by setting the flag isEmpty to 1
 *
 * @param list		Employee* Pointer to the array of employees
 * @param len		Array length
 * @param id		The id of the employee to be removed
 * @return			Returns -1 if Error and 0 if OK
 */
int removeEmployee(Employee* list, int len, int id);

/**
 * @brief 			Sorts all the elements of an Employee Array by lastName and Sector
 *
 * @param list		Employee* Pointer to the array of employees
 * @param len		Array length
 * @param order		1 indicates ASCENDING ORDER and 0 indicates DESCENDING ORDER
 * @return			Returns -1 if Error and 0 if OK
 */
int sortEmployees(Employee* list, int len, int order);

/**
 * @brief 			Prints all the employees of the array which flag isEmpty == 0
 *
 * @param list		Employee* Pointer to the array of employees
 * @param len		Array length
 * @return			Returns -1 if Error and 0 if OK
 */
int printEmployees(Employee* list, int len);

/**
 * @brief 			Finds an employee by it's ID, and then modifies a single field.
 *
 * @param list		Employee* Pointer to the array of employees
 * @param id		Array length
 * @return			Returns -1 if Error and 0 if OK
 */
int modifyEmployee(Employee* list, int len, int id);