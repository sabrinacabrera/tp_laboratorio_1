#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "parser.h"
#include "menu.h"

#define TAMNAME 40
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int respuesta = 1;
	FILE* pFile;
	pFile = fopen(path,"r");

	if(pFile != NULL)
	{
		if(parser_EmployeeFromText(pFile,pArrayListEmployee) == 0)
		{
			printf("Archivo de texto cargado correctamente\n");
			respuesta = 0;
		}
		else
		{
			printf("ERROR, id \n");
		}
		fclose(pFile);
	}
	else
	{
		printf("ERROR,null \n");
	}

	return respuesta;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int respuesta = 1;
	FILE* pFile;

	pFile = fopen(path, "rb");

	if(pFile != NULL)
	{
		if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee))
		{
			respuesta = 0; //todo ok
			printf("Archivo de texto cargado correctamente\n");
		}
		else
		{
			printf("Error\n");
		}
	}
	else
	{
		printf("Error\n");
	}
	fclose(pFile);
    return respuesta;
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

	int retorno = 1;
	char auxNombre[TAMNAME];
	int auxHora;
	int auxSueldo;
	int nextId;
	Employee* pEmployee = employee_new();//malloc

	if(pArrayListEmployee != NULL && pEmployee != NULL)
	{

		if(utn_getNombre(auxNombre, 40, "Ingrese nombre: \n", "Error, nombre invalido,Ingrese nombre: \n", 3)==0 &&
		   utn_getNumero(&auxHora, "Ingrese cantidad de horas trabajadas:\n ",  "Error, cantidad invalida\n", 0, 10000, 3)==0 &&
		   utn_getNumero(&auxSueldo, "Ingrese sueldo de 20000 a 50000: \n", "Error, sueldo invalido\n", 20000, 50000, 3)==0)
		{
			normalizeStr(auxNombre);

			nextId = employee_maxId(pArrayListEmployee) + 1;//lo que retorne la funcion + 1

			if(employee_setId(pEmployee, nextId)==0 &&
			   employee_setNombre(pEmployee, auxNombre)==0 &&
			   employee_setHorasTrabajadas(pEmployee, auxHora)==0 &&
			   employee_setSueldo(pEmployee, auxSueldo)==0)
				{
					ll_add(pArrayListEmployee, pEmployee);
					printf("Alta exitosa!!\n");
				}else
					{
						free(pEmployee);
					}
		}
		else
		{
			free(pEmployee);//libero el espacio
		}
	}
    return retorno;
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
	Employee* pEmpleado;
	int auxId;
	int ultId;
	int respuesta = 1;
	int index;
	int salir = 0;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);//imprimo los empleados

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmpleado = ll_get(pArrayListEmployee, i);

			employee_getId(pEmpleado, &auxId);
			if(auxId >= ultId)
			{
				ultId = auxId;//el ultimo id va a ser el mas grande
			}
		}

		if(utn_getNumero(&auxId, "Ingrese ID de empleado a modificar.\n", "Error, ID invalido\n", 0, ultId, 3)==0)
		{
			index = employee_buscarPorId(pArrayListEmployee, auxId);
			if(index > -1)
			{

				printf("\n    ID       Nombre     Horas Trabajadas   Sueldo\n\n");
				employee_imprimirEmpleado(pArrayListEmployee, index);

				do
				{
					switch(menuEditar())
					{
						case 1:

							if(employee_cambiarNombre(pArrayListEmployee, index) == 0)
							{
								printf("Nombre modificado!!\n");
								employee_imprimirEmpleado(pArrayListEmployee, index);
							}
							else
							{
								printf("ERROR. No se pudo moficar\n");
							}
							break;
						case 2:

							if(employee_modifHoras(pArrayListEmployee, index) == 0)
							{
								printf("Horas actualizadas con exito!!\n");
								employee_imprimirEmpleado(pArrayListEmployee, index);
							}
							else
							{
								printf("ERROR.No se pudo actualizar las horas\n");
							}
							break;
						case 3:

							if(employee_modifSueldo(pArrayListEmployee, index) == 0)
							{
								printf("Sueldo modificado!!\n");
								employee_imprimirEmpleado(pArrayListEmployee, index);
							}
							else
							{
								printf("Error. No se pudo modificar el sueldo\n");
							}
							break;
						case 4:
							salir = 1;
							break;

					}
				}while(salir == 0);
			}
		}
	}
	return respuesta;
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
	int respuesta = 1;
	int auxId;
	int ultId;
	Employee* pEmpleado;
	int index;
	char confirma;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);//imprimo  empleados

		ultId = employee_maxId(pArrayListEmployee);//me devuelve el max id

		if(utn_getNumero(&auxId, "Ingrese ID de empleado a eliminar del sistema.\n",  "Error, ID invalido\n", 0, ultId, 3)==0)
		{
			index = employee_buscarPorId(pArrayListEmployee, auxId);
			if(index > -1)
			{
				pEmpleado = ll_get(pArrayListEmployee, index);

				printf("\n ID    Nombre   Horas Trabajadas   Sueldo\n\n");
				employee_imprimirEmpleado(pArrayListEmployee, index);//imprimo el empleado elegido

				printf("Confirma la baja del empleado? y/n: \n");
				scanf("%c", &confirma);
				if(confirma == 'y')
				{
					ll_remove(pArrayListEmployee, index);//elimino el empleado en ese index
					if(employee_delete(pEmpleado)==0) //elimino el punt aux que me cree
					{
						printf("Baja realizada!!!\n");
						respuesta = 0;
					}
				}
			}
		}
	}
	return respuesta;
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

	int respuesta = 1;
	if(pArrayListEmployee != NULL)
	{
		printf("\n    ID       Nombre     Horas Trabajadas  Sueldo\n\n");
		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			employee_imprimirEmpleado(pArrayListEmployee, i);

		}
		respuesta=0;
	}
	else
	{
		printf("No hay empleados cargados!!\n");
	}

    return respuesta;
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
	int respuesta = 1;

	if(pArrayListEmployee != NULL)
	{
		if(employee_Ordenar(pArrayListEmployee) == 0)
		{
			printf("Empleados ordenados correctamente!!\n");
		}
		respuesta=0;
	}
	else
	{
		printf("Error,no se pudo ordenar!!\n");
	}

	    return respuesta;
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
	int retorno = 1;
	FILE* pFile;
	int auxId;
	char auxNombre[TAMNAME];
	int auxHoras;
	int auxSueldo;
	Employee* pEmpleado= employee_new();
	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			retorno = 0;
			//por cada elemento del array lo escribo en el archivo, desde la posicion 1
			for(int i = 0; i < ll_len(pArrayListEmployee); i++)
			{
				pEmpleado = ll_get(pArrayListEmployee, i);
				//utilizo los getter para traerme la data
				if(employee_getId(pEmpleado, &auxId) ==0 &&
				   employee_getNombre(pEmpleado, auxNombre)==0 &&
				   employee_getHorasTrabajadas(pEmpleado, &auxHoras)==0 &&
				   employee_getSueldo(pEmpleado, &auxSueldo)==0)
					{
						fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxNombre, auxHoras, auxSueldo);
					}
			}
			fclose(pFile);
			printf("Archivo guardado!!\n");
		}
	}
	return retorno;
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
	int respuesta = 1;
	FILE* pFile;
	Employee* pEmpleado = employee_new();

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "wb");
		//desde la primera posicion
		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(pEmpleado, sizeof(Employee), 1, pFile);
		}
		printf("Archivo guardado!\n");
		fclose(pFile);
		respuesta = 0;
	}

	return respuesta;
}

