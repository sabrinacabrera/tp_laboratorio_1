#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Controller.h"
#include "LinkedList.h"
#include "menu.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
int employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);



int employee_buscarPorId(LinkedList* pArrayListEmployee, int id);
int employee_imprimirEmpleado(LinkedList* pArrayListEmployee, int index);


int employee_cambiarNombre(LinkedList* pArrayListEmployee, int index);
int employee_modifHoras(LinkedList* pArrayListEmployee, int index);
int employee_modifSueldo(LinkedList* pArrayListEmployee, int index);
int employee_maxId(LinkedList* pArrayListEmployee);
int employee_Ordenar(LinkedList* pArrayListEmployee);
int employee_ordenarPorId(void* firstEmployee, void* secondEmployee);
int employee_ordenarPorNombre(void* firstEmployee, void* secondEmployee);
int employee_ordenarPorHoras(void* firstEmployee, void* secondEmployee);
int employee_ordenarPorSueldo(void* firstEmployee, void* secondEmployee);

#endif // employee_H_INCLUDED
