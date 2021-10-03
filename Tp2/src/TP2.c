/*
 ============================================================================
 Name        : TP2.c
 Author      : Sabrina Cabrera
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo práctico numero 2 de la materia Laboratorio 1, curso 1E
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define TAM 3
#define TAMSEC 5

int main(void) {
	setbuf(stdout,NULL);
	char salir;
	int nextId = 999;
	int i=0;
	int cantidad;
	int index;
	//Variables escritas por get_Data y luego leidas por addEmployee:
	char auxName[51];
	char auxLastname[51];
	float auxSalary;
	int auxSector;
	int flagOp1=0;
	int auxId;

	eSector sectores[TAMSEC]={{1,"RRHH"},{2,"SISTEMAS"},{3,"LEGALES"},{4,"VENTAS"},{5,"COMPRAS"}};
	eEmployee list[TAM];

	initEmployees(list,TAM);

	hardCodearEmpleados(list,TAM);

	do{
		system("cls");

		switch(menuABM())
		{
		case 1:
			printf("****MENU ALTAS ****\n");
			utn_getEntero(&cantidad, 3, "Cuantos empleados ingresa ?:\n", "Error, la cantidad ingresada es incorrecta.\n", 1, 1000);

			do{
				i++;
				if(get_Data(list, TAM, &nextId, auxName, auxLastname, &auxSalary, &auxSector, &index)==0 && addEmployee(list, TAM, nextId, auxName, auxLastname, auxSalary, auxSector, index) == 0)
					{
						flagOp1 = 1;
					}
			}while(i < cantidad);
			i = 0;
			break;
		case 2:
				if (flagOp1==1)
				{
					menuModificar(list,TAM,sectores,TAMSEC);
				}else
					{
						printf("error,debe cargar empleados.\n");
					}
			break;
		case 3:
			if(flagOp1 == 1)
							{
								printf("\n***** Menu Bajas *****\n\n ");
								do
								{
									showEmployeeS(list, sectores, TAM, TAMSEC);
									if(utn_getEntero(&auxId, 3, "Ingrese ID del empleado a eliminar: \n", "Error, no es un numero de ID.\n", 1000, 2000) == 0)
									{
										removeEmployee(list, TAM, auxId, sectores, TAMSEC);
									}
									printf("Desea continuar eliminando? s/n: ");
									fflush(stdin);
									scanf("%c", &salir);
								}while(salir != 'n');
							}
							else
							{
								printf("Primero debe cargar empleados.\n");
							}

							break;
			break;
		case 4:
			if(flagOp1 == 1)
							{
								informes(list, TAM, sectores, TAMSEC);
							}
							else
							{
								printf("Primero debe cargar empleados.\n");
							}
			break;
		case 5:
			system("cls");
			printf("\n***** Salir *****\n\n ");
			printf("Segur@ desea salir? s/n: \n");
			fflush(stdin);
		    scanf("%c", &salir);
			break;
		default:
			system("cls");
			printf("Ingrese opción valida");
		}
		system("pause");
	}while(salir!='s');
	return 0;
}







