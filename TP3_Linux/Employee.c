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
            emp = ll_get(listaEmployees, i);
            if(emp != NULL) {
                mostrarEmpleado(emp);
            }
        }
    }
    return error;
}
int employee_sortId(void* empA, void* empB) {
    int retorno = 0;
    int id[2];
    if(empA != NULL && empB != NULL) {
        if(employee_getId((Employee*) empA, &id[0])
        && employee_getId((Employee*) empB, &id[1])) {
            if(id[0] > id[1]) {
                retorno = 1;
            } else {
                retorno = -1;
            }
        }
    }
    return retorno;
}
int employee_sortNombre(void* empA, void* empB) {
    int retorno = 0;
    char buffer[2][128];
    if(empA != NULL && empB != NULL) {
        if(employee_getNombre((Employee*) empA, buffer[0])
        && employee_getNombre((Employee*) empB, buffer[1])) {
            retorno = strcmp(buffer[0], buffer[1]);
        }
    }
    return retorno;
}
int employee_sortHorasTrabajadas(void* empA, void* empB) {
    int retorno = 0;
    int horas[2];
    if(empA != NULL && empB != NULL) {
        if(employee_getHorasTrabajadas((Employee*) empA, &horas[0])
        && employee_getHorasTrabajadas((Employee*) empB, &horas[1])) {
            if(horas[0] > horas[1]) {
                retorno = 1;
            } else {
                retorno = -1;
            }
        }
    }
    return retorno;
}
int employee_sortSueldo(void* empA, void* empB) {
    int retorno = 0;
    int sueldo[2];
    if(empA != NULL && empB != NULL) {
        if(employee_getSueldo((Employee*) empA, &sueldo[0])
        && employee_getSueldo((Employee*) empB, &sueldo[1])) {
            if(sueldo[0] > sueldo[1]) {
                retorno = 1;
            } else {
                retorno = -1;
            }
        }
    }
    return retorno;
}
