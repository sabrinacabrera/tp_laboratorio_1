#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int respuesta = 1;
	int nextId = 0;
	char id[200];
	char nombre[200];
	char horas[200];
	char sueldo[200];


	Employee* pEmpleado= employee_new();

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, sueldo) == 4)
			{
				//lee mientras fscanf devuelva 4
				pEmpleado = employee_newParametros(id, nombre, horas, sueldo);

				if(pEmpleado != NULL)//pudo cargar
				{
					ll_add(pArrayListEmployee, pEmpleado);
					respuesta = 0;
				}
			}
			else
			{
				break;
			}
		}while(feof(pFile) == 0); //lee todo el archivo
		respuesta = nextId;//retorno el nextId
	}
	return respuesta;
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
	int respuesta = 1;
	Employee* pEmpleado;

	if(pFile != NULL)
	{
		do
		{
			pEmpleado = employee_new(); //reservo lugar para un empleado
			//lectura fantasma
			if(fread(pEmpleado, sizeof(Employee), 1, pFile) == 1) //leo datos binarios y valido si me leyo 1
			{
				ll_add(pArrayListEmployee, pEmpleado);
				respuesta = 0;//ok
			}
		}while(!feof(pFile));//mientras no sea el final del archivo
	}

	return respuesta;
}
