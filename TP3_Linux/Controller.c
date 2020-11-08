#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	if(path != NULL && pArrayListEmployee != NULL) {
		FILE* f = fopen(path, "r");
		retorno = parser_EmployeeFromText(f, pArrayListEmployee);
		fclose(f);
	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int error = 1;
	if(path != NULL && pArrayListEmployee != NULL) {
		FILE* f = fopen(path, "rb");
		if(!parser_EmployeeFromText(f, pArrayListEmployee)) {
			error = 0;
		}
		fclose(f);
	}
    return error;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int error = 1;
	if(pArrayListEmployee != NULL) {
        system("clear");
		Employee* emp = NULL;
        int len = ll_len(pArrayListEmployee) + 1;
        char idStr[50], nombre[128], horasTrabajadasStr[50], sueldoStr[50];
        sprintf(idStr, "%d", len);
        printf("Ingrese el nombre: ");
        scanf("%s", nombre);
        printf("Ingrese las horas trabajadas: ");
        scanf("%s", horasTrabajadasStr);
        printf("Ingrese el sueldo: ");
        scanf("%s", sueldoStr);
        emp = employee_newParametros(idStr, nombre, horasTrabajadasStr, sueldoStr);
        if(emp != NULL) {
            ll_add(pArrayListEmployee, emp);
            error = 0;
        }
	}
    return error;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    Employee* empAux = NULL;
    int idAux;
    int opc;
    char c;
    char stringAux[128];
    int ingresoError = 1;
    int salida = 0;
    if(pArrayListEmployee != NULL) {
        printf("\nIngrese el ID del empleado a modificar: ");
        scanf("%d", &idAux);
        empAux = (Employee*) ll_get(pArrayListEmployee, idAux-1);
        if(empAux != NULL) {
            error = 0;
            while(!salida) {
                system("clear");
                printf("\nEmpleado encontrado.\n\n");
                mostrarEmpleado(empAux);
                printf("\n\n1: Nombre\n"
                        "2: Horas trabajadas\n"
                        "3: Sueldo\n"
                        "4: Cancelar\n");
                printf("\nIngrese la opcion que desea modificar: ");
                scanf("%d", &opc);
                switch(opc) {
                    case 1:
                        printf("\nIngrese el nombre: ");
                        __fpurge(stdin);
                        fgets(stringAux, sizeof(stringAux), stdin);
                        stringAux[strcspn(stringAux, "\n")] = 0;
                        ingresoError = employee_setNombre(empAux, stringAux);
                        break;
                    case 2:
                        printf("\nIngrese las horas trabajadas: ");
                        __fpurge(stdin);
                        fgets(stringAux, sizeof(stringAux), stdin);
                        stringAux[strcspn(stringAux, "\n")] = 0;
                        ingresoError = employee_setHorasTrabajadas(empAux, atoi(stringAux));
                        break;
                    case 3:
                        printf("\nIngrese el sueldo: ");
                        __fpurge(stdin);
                        fgets(stringAux, sizeof(stringAux), stdin);
                        stringAux[strcspn(stringAux, "\n")] = 0;
                        ingresoError = employee_setSueldo(empAux, atoi(stringAux));
                        break;
                    case 4:
                        error = -1;
                        salida = 1;
                        break;
                    default:
                        printf("\nOpcion invalida.\n");
                        break;
                }
                if(!ingresoError) {
                    salida = 1;
                }
                printf("\n\nPresione una tecla para continuar.\n\n");
                __fpurge(stdin);
                c = getchar();
                printf("%c", c);
                system("clear");
            }
        }
    }
    return error;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    int id;
    Employee* empAux;
    if(!ll_isEmpty(pArrayListEmployee)) {
        printf("\nIndique el ID del empleado a eliminar: ");
        scanf("%d", &id);
        id = id - 1;
        empAux = ll_get(pArrayListEmployee, id);
        if(empAux != NULL) {
            ll_remove(pArrayListEmployee, id);
            error = 0;
        } else {
            printf("No se encontro un empleado con ese ID.\n");
        }
    }
    return error;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    if(pArrayListEmployee != NULL) {
        mostrarEmpleados(pArrayListEmployee, ll_len(pArrayListEmployee));
        error = 0;
    }
    return error;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    int opcion;
    int orden;
    if(pArrayListEmployee != NULL) {
        error = 0;
        system("clear");
        printf("\nProximamente disponible! :) \n\n");
        printf("Como quiere ordenar la lista?\n"
               "1: Por ID\n"
               "2: Por nombre\n"
               "3: Por horas trabajadas\n"
               "4: Por sueldos\n");
        printf("Ingrese el criterio: ");
        scanf("%d", &opcion);
        printf("\nOrden\n"
               "0: Descendente\n"
               "1: Ascendente");
        printf("Ingrese el orden: ");
        scanf("%d", &orden);
        switch(opcion) {
            case 1:
                ll_sort(pArrayListEmployee, employee_sortId, orden);
                break;
            case 2:
                ll_sort(pArrayListEmployee, employee_sortNombre, orden);
                break;
            case 3:
                ll_sort(pArrayListEmployee, employee_sortHorasTrabajadas, orden);
                break;
            case 4:
                ll_sort(pArrayListEmployee, employee_sortSueldo, orden);
                break;
            default:
                printf("\nOpcion invalida.\n");
                break;
        }
    }
    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int error = 1;
    int tam = ll_len(pArrayListEmployee);
    Employee* emp = (Employee*) malloc(sizeof(Employee));
    if(pArrayListEmployee != NULL && tam > 0) {
        FILE* f = fopen(path, "w");
        for(int i = 0; i < tam; i++) {
            emp = ll_get(pArrayListEmployee, i);
            if(emp != NULL) {
                fprintf(f,"%d,%s,%d,%d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
            }
        }
        free(emp);
        fclose(f);
    }

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

