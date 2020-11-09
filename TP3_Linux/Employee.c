#include "Employee.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* employee_new() {
	Employee* emp = (Employee*) malloc(sizeof(Employee));
	if(emp == NULL) {
		free(emp);
		emp = NULL;
	}
	return emp;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr) {
	Employee* emp = employee_new();
	if(emp != NULL) {
		if(employee_setId(emp, atoi(idStr))
		|| employee_setNombre(emp, nombreStr)
		|| employee_setHorasTrabajadas(emp, atoi(horasTrabajadasStr))
		|| employee_setSueldo(emp, atoi(sueldoStr))) {
            printf("Error en la carga del empleado.\n");
            employee_delete(emp);
		}
	}
	return emp;
}
Employee* employee_newParametrosInt(int id,char* nombreStr,int horasTrabajadas, int sueldo) {
    Employee* emp = employee_new();
	if(emp != NULL) {
		if(employee_setId(emp, id)
		|| employee_setNombre(emp, nombreStr)
		|| employee_setHorasTrabajadas(emp, horasTrabajadas)
		|| employee_setSueldo(emp, sueldo)) {
            printf("Error en la carga del empleado.\n");
            employee_delete(emp);
		}
	}
	return emp;
}
void employee_delete(Employee* emp) {
	if(emp != NULL) {
		emp = NULL;
		free(emp);
	}
}
int employee_setId(Employee* this,int id) {
	int error = 1;
	if(this != NULL && id > 0 && id < 20000) {
		this->id = id;
		error = 0;
	}
	return error;
}
int employee_getId(Employee* this,int* id) {
	int error = 1;
	if(this != NULL && id != NULL) {
		*id = this->id;
		error = 0;
	}
	return error;
}

int employee_setNombre(Employee* this,char* nombre) {
	int error = 1;
	if(this != NULL && strlen(nombre) >= 2 && strlen(nombre) <= 128) {
		strcpy(this->nombre, nombre);
		error = 0;
	}
	return error;
}
int employee_getNombre(Employee* this,char* nombre) {
	int error = 1;
	if(this != NULL) {
		strcpy(nombre, this->nombre);
		error = 0;
	}
	return error;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas) {
	int error = 1;
	if(this != NULL && horasTrabajadas > 0 && horasTrabajadas < 1000) {
		this->horasTrabajadas = horasTrabajadas;
		error = 0;
	}
	return error;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas) {
	int error = 1;
	if(this != NULL && horasTrabajadas != NULL) {
		*horasTrabajadas = this->horasTrabajadas;
		error = 0;
	}
	return error;
}

int employee_setSueldo(Employee* this,int sueldo) {
	int error = 1;
	if(this != NULL && sueldo > 0) {
		this->sueldo = sueldo;
		error = 0;
	}
	return error;
}
int employee_getSueldo(Employee* this,int* sueldo) {
	int error = 1;
	if(this != NULL && sueldo != NULL) {
		*sueldo = this->sueldo;
		error = 0;
	}
	return error;
}
void mostrarEmpleado(Employee* this) {
    printf("%4d |  %20s  |   %3d   | %6d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
}
int mostrarEmpleados(void* listaEmployees, int tam) {
    int error = 1;
    Employee* emp;
    if(listaEmployees != NULL && tam > 0) {
        for(int i = 0; i < tam; i++) {
            emp = (Employee*) ll_get(listaEmployees, i);
            if(emp != NULL) {
                mostrarEmpleado(emp);
            }
        }
    }
    return error;
}
int employee_sortId(void* empA, void* empB) {
    int retorno = 0;
    Employee* empleadoA = (Employee*) empA;
    Employee* empleadoB = (Employee*) empB;
    if(empleadoA->id > empleadoB->id) {
        retorno = 1;
    } else if(empleadoA->id < empleadoB->id) {
        retorno = -1;
    }
    return retorno;
}
int employee_sortNombre(void* empA, void* empB) {
    int retorno = 0;
    Employee* empleadoA = (Employee*) empA;
    Employee* empleadoB = (Employee*) empB;
    if(strcmp(empleadoA->nombre, empleadoB->nombre) > 0) {
        retorno = 1;
    } else if(strcmp(empleadoA->nombre, empleadoB->nombre) < 0) {
        retorno = -1;
    }
    return retorno;
}
int employee_sortHorasTrabajadas(void* empA, void* empB) {
    int retorno = 0;
    Employee* empleadoA = (Employee*) empA;
    Employee* empleadoB = (Employee*) empB;
    if(empleadoA->horasTrabajadas > empleadoB->horasTrabajadas) {
        retorno = 1;
    } else if(empleadoA->horasTrabajadas < empleadoB->horasTrabajadas) {
        retorno = -1;
    }
    return retorno;
}
int employee_sortSueldo(void* empA, void* empB) {
    int retorno = 0;
    Employee* empleadoA = (Employee*) empA;
    Employee* empleadoB = (Employee*) empB;
    if(empleadoA->sueldo > empleadoB->sueldo) {
        retorno = 1;
    } else if(empleadoA->sueldo < empleadoB->sueldo) {
        retorno = -1;
    }
    return retorno;
}
