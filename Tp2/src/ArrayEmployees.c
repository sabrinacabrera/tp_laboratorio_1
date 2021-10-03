/*
 * ArrayEmployees.c
 *
 *  Created on: 8 oct. 2020
 *      Author: gisel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "utn.h"


int initEmployees(eEmployee list[], int tam)
{
	if(list != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			list[i].isEmpty = 1;
		}
		return 0;
	}
	else
	{
		return -1;
	}
}


void showEmployee(eEmployee x ,eSector* list,int tamsec)
{
	char descripcion[30];

	get_sector(list,tamsec,x.idSector,descripcion);

	printf( "%d %s %s %.2f %s \n",x.id ,x.lastName,x.name,x.salary,descripcion);
}


void showEmployeeS(eEmployee* list ,eSector* listSec,int tam,int tamsec)
{
	printf("id     Apellido    Nombre  Salario    Sector\n");

	for(int i=0; i<tam;i++)
	{
		if(list[i].isEmpty==0){
			showEmployee(list[i],listSec,tamsec);
		}
	}

}


int addEmployee(eEmployee list[], int tam, int id, char nombre[], char apellido[], float salario, int sector, int index)
{
	int isOk = -1;

	if(list != NULL && nombre != NULL && apellido != NULL && tam > 0)
	{
		normalizeStr(nombre);
		normalizeStr(apellido);

		list[index].id = id;
		strcpy(list[index].name, nombre);
		strcpy(list[index].lastName, apellido);
		list[index].salary = salario;
		list[index].idSector = sector;
		list[index].isEmpty = 0;
		isOk = 0;
	}
	return isOk;
}

int findEmployeeById(eEmployee list[], int tam, int id)
{
	int exists = -1;

	if(list != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(id == list[i].id)
			{
				exists = i; //devuelve el legajo
				break;
			}
		}
	}
	return exists;
}

int removeEmployee(eEmployee*list, int tam, int id, eSector* sectors, int tamsec)
{
	int index;
	char confirm;
	int todoOK = -1;

	if(list != NULL && tam > 0)
	{
		index = findEmployeeById(list, tam, id);

		if(index < 0)
		{
			printf("ERROR. El id ingresado no existe.\n");
		}
		else
		{
			printf("El id %d corresponde al empleado: \n", id);
			showEmployee(list[index], sectors, tamsec);
			printf("Esta seguro de que desea eliminarlo? s/n: ");
			fflush(stdin);
			scanf("%c", &confirm);

			if(confirm == 's')
			{
				printf("El empleado ha sido eliminado.\n");
				list[index].isEmpty = 1;
				todoOK = 0;
			}
			else if (confirm == 'n')
			{
				printf("No se realizaron cambios.\n");
				todoOK = 0;
			}
			else
			{
				printf("La opcion ingresada no es valida.\n");
			}
		}
	}

	return todoOK;
}

int sortEmployees(eEmployee* list, int tam, int order)
{
	//agrupar por sector y ordenar por apellido
	int isOk = -1;
	eEmployee auxEmployee;

	if(list != NULL)
	{
		for(int i = 0; i < tam -1; i++)
		{
			for(int j = i + 1; j < tam; j ++)
			{
				isOk = 0;

				if(list[i].isEmpty == 0 && list[j].isEmpty == 0) //solo hace el burbujeo si no estan vacias las posiciones
				{

					switch(order)
					{
						case 0:
							if(list[i].idSector < list[j].idSector || (list[i].idSector == list[j].idSector && (strcmp(list[i].lastName, list[j].lastName)) < 0)) //de mayor a menor sector (agrupa) y apellido (ordena)
							{
								auxEmployee = list[i];
								list[i] = list[j];
								list[j] = auxEmployee;
							}
							break;
						case 1:
							if(list[i].idSector > list[j].idSector || (list[i].idSector == list[j].idSector && (strcmp(list[i].lastName, list[j].lastName)) > 0)) //de menor a mayor sector (agrupa) y apellido (ordena)
							{
								auxEmployee = list[i];
								list[i] = list[j];
								list[j] = auxEmployee;
							}
							break;
						default:
							printf("No es un orden valido.\n");
					}
				}
			}
		}
	}
	return isOk;
}


void hardCodearEmpleados(eEmployee* list, int tam)
{
    eEmployee empleados [13]= {
    {100, "harry", "potter",  19994 , 2,1},
    {101, "ronald", "weasley", 6584, 2,1},
    {102, "hermione", "granger",39995 ,3,1},
    {103, "luna", "lovegood",45610 , 4,1},
    {104, "draco", "malfoy", 15550 , 1,1},
    {105, "tom ", "riddle", 28480, 1,1},
    {106, "sirius", "black", 30000 , 2,1},
    {107, "albus", "dumbledore", 43000 , 5,1},
    {108, "rita", "skeeter",  16000 , 4,1},
    {109, "rubeous", "hagrid", 25000 , 1,1},
    {110, "ginny", "weasley", 30000 , 2,1},
    {111, "lucious", "malfoy",  4000, 4,1}};

    for(int i=0;i<tam;i++)
    {
        list[i]= empleados[i];
    }

}

int menuModificar(eEmployee *list,int tam ,eSector* sector,int tamsec)
{
	int isOk = -1;
	int auxId;
	int opcion;
	char confirm;
	char continueM;
	int index;
	char newName[51];
	char newLastname[51];
	float newSalary;
	int newSector;

	system("cls");
	printf("*****Menu  Modificaciones *****\n\n");

	showEmployeeS(list,sector,tam,tamsec);
	if(list != NULL && tam > 0 && utn_getEntero(&auxId, 3, "Ingrese ID de la persona a modificar: \n", "Error. No existe ID.\n", 1000, 2000) == 0 )
	{
		index = findEmployeeById(list, tam, auxId); //encuentra al empleado

		if(index == -1)
		{
			printf("No existe ese ID en el sistema.\n");
		}
		else
		{
			printf("El ID %d pertenece al siguiente empleado:\n", auxId);
			printf(" ID     Apellido      Nombre             Salario       Sector\n\n");
			showEmployee(list[index], sector, tamsec);
			utn_getCadena(&confirm, 2, 3, "Desea modificarla? s/n: ", "Error. No es una opcion valida.");

			if(confirm == 's')
			{
				do
				{
					printf("    1. Modificar nombre\n");
					printf("    2. Modificar apellido\n");
					printf("    3. Modificar salario\n");
					printf("    4. Modificar sector\n\n");
					utn_getEntero(&opcion, 3, "Ingrese opcion a modificar:\n ", "ERROR, no es una opcion valida\n", 1, 4);

					switch(opcion)
					{
						case 1:
							utn_getCadena(newName, 51, 5, "Ingrese nombre nuevo : \n", "ERROR, nombre invalido.\n");
							normalizeStr(newName);
							strcpy(list[index].name, newName);
							break;
						case 2:
							utn_getCadena(newLastname, 51, 5, "Ingrese nuevo apellido: \n", "ERROR, apellido invalido.\n");
							normalizeStr(newName);
							strcpy(list[index].lastName, newLastname);
							break;
						case 3:
							utn_getFlotante(&newSalary, 5, "Ingrese nuevo salario:\n", "ERROR, salario invalido.\n", 12000, 300000);
							list[index].salary = newSalary;
							break;
						case 4:
							utn_getEntero(&newSector, 5, "Ingrese nuevo sector: \n", "ERROR, sector invalido.\n", 1, 5);
							list[index].idSector = newSector;
							break;
						default:
							printf("No es una opcion valida.\n\n");
					}
					printf("Modificacion realizada con exito. \n");
					printf("ID    Apellido   Nombre     Salario        Sector\n");
					showEmployee(list[index], sector, tamsec);//muestro el empleado
					printf("Desea seguir modificando? s/n: ");
					fflush(stdin);
					scanf("%c", &confirm);
					if(confirm == 's')
					{
						continueM = 'n';
					}
				}while(continueM == 's');
			}
			else if(confirm == 'n')
			{
				printf("No se generaron modificaciones.\n");
			}
		}
		isOk = 0;
	}
	return isOk;
}

int informes(eEmployee* list, int tam, eSector *sector, int tamsec)
{
	int isOk = -1;
	char continueI = 's';
	char confirm;
	int ascDes;

	if(list != NULL && sector != NULL)
	{

		do
		{
			switch(menuInform()) //retorna la opcion
			{
				case 1:
					utn_getEntero(&ascDes, 300, "Ingrese 1 para listar de manera ascendente o 0 para descendente: \n", "Error. No es un ordenamiento posible.\n", 0, 1);
					printf("\n");
					sortEmployees(list, tam, ascDes);
					showEmployeeS(list,sector,  tam, tamsec);
					system("pause");
					isOk = 0;
					break;
				case 2:
					 totalAndPromedySalaries(list, tam);
					isOk = 0;
					break;
				case 3:
					printf("Confirma salida? s/n: ");
					fflush(stdin);
					scanf("%c", &confirm);
					if(confirm == 's')
					{
						continueI = 'n';
					}
					isOk = 0;
					break;
				default:
					printf("No es una opcionn valida.\n\n");
			}
		}while(continueI == 's');
	}
	return isOk;
}

int totalAndPromedySalaries(eEmployee* list, int tam)
{
	int isOk = -1;
	float accumSalaries = 0;
	int countEmployees = 0;
	float promedy;
	int countEmployeesHigher = 0;

	if(list != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(list[i].isEmpty == 0)
			{
				accumSalaries += list[i].salary;
				countEmployees++;
			}
		}

		promedy = (float) accumSalaries / countEmployees;

		for(int i = 0; i < tam; i++)
		{
			if(list[i].isEmpty == 0 && list[i].salary > promedy)
			{
				countEmployeesHigher++;
			}
		}
		isOk = 0;

		printf("El total de los salarios de los %d empleados en sistema es de: $ %.2f\n", countEmployees, accumSalaries);
		printf("El promedio de todos los salarios es de: $ %.2f\n", promedy);
		if(countEmployeesHigher == 1)
		{
			printf("Hay %d empleado que supera el salario promedio.\n\n", countEmployeesHigher);
		}
		else if(countEmployeesHigher < 1)
		{
			printf("No hay empleados que superen el salario promedio.\n\n");
		}
		else
		{
			printf("Hay %d empleados que superan el salario promedio.\n\n", countEmployeesHigher);
		}
		system("pause");
	}
	return isOk;
}

int menuInform()
{
	int opcion;

	system("cls");
	printf("\n***** Menu Informes *****\n\n");
	printf("1. Listar empleados ordenados alfabeticamente por Apellido y agrupados por Sector\n");
	printf("2. Total y promedio de los salarios\n");
	printf("3. Salir\n\n");
	utn_getEntero(&opcion, 300, "Ingrese la opcion elegida:\n ", "Error, no es una opcion valida.\n", 1, 3);

	return opcion;
}

void menuSectores()
	{
	 	printf("***** Menu sectores *****\n\n");
	    printf("1. RRHH\n");
	    printf("2. Sistemas\n");
	    printf("3. Legales\n");
	    printf("4. Ventas\n");
	    printf("5. Compras\n\n");
	}




int get_Data(eEmployee list[], int tam, int* nextId, char nombre[], char apellido[], float* salario, int* sector, int* index)
{
	int id = *nextId;
	int newId = id + 1;
	int isOk = -1;

	if(list != NULL && tam > 0 && nextId != NULL && nombre != NULL && apellido != NULL && salario != NULL && sector != NULL)
	{
		*index = lookEmpty(list, tam);

		if(index < 0) //si lookEmpty devolvio -1
		{
			printf("El sistema esta lleno.\n");
		}
		else
		{
			utn_getCadena(nombre, 51, 3, "Ingrese nombre: \n", "ERROR,El nombre ingresado es invalido.\n");
			utn_getCadena(apellido, 51, 3, "Ingrese apellido: \n ", "ERROR,El apellido ingresado es invalido.\n");
			utn_getFlotante(salario, 3, "Ingrese salario:\n ", "ERROR,El salario ingresado no es valido.\n", 20000.00, 500000.00);
			menuSectores();
			utn_getEntero(sector, 3, "Ingrese sector: \n", "ERROR,El sector ingresado no es valido.\n", 1, 5);

			*nextId = newId;

			isOk = 0;
		}
	}
	return isOk;
}
