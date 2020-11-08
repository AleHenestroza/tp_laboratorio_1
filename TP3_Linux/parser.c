#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	if(pFile != NULL && pArrayListEmployee != NULL) {
		int cant;
		int salida = 0;
		Employee* empAux = NULL;
		char idStr[50], nombre[128], horasTrabajadasStr[50], sueldoStr[50];
		while(!salida){
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombre, horasTrabajadasStr, sueldoStr);
			if(strcmp(idStr, "id") == 0
			&& strcmp(nombre, "nombre") == 0
			&& strcmp(horasTrabajadasStr, "horasTrabajadas") == 0
			&& strcmp(sueldoStr, "sueldo") == 0) {
				continue;
			} else {
				if(cant == 4) {
					empAux = employee_newParametros(idStr, nombre, horasTrabajadasStr, sueldoStr);
					if(empAux != NULL) {
                        ll_add(pArrayListEmployee, empAux);
					}
				}
            }
            salida = feof(pFile);
        }
        retorno = atoi(idStr);
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
    Employee* empAux = NULL;
    if(pFile != NULL && pArrayListEmployee != NULL) {
        while(!feof(pFile)) {
            fread(&empAux, sizeof(Employee), 1000, pFile);
            ll_add(pArrayListEmployee, (void*) empAux);
            retorno = 0;
        }
    }
	return retorno;
}
