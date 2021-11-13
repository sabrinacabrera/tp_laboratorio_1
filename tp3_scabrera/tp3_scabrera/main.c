#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "menu.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout,NULL);
	char confirm = 'n';
	char salir = 'n';
	int flagTexto = 0;
	int flagBin = 0;


	LinkedList* listaEmpleados = ll_newLinkedList();

	do{
		system("cls");
		switch(menu())
		{
			case 1:
				if(flagBin != 1 && flagTexto == 0)//si no fue cargado como binario
				{
					if(controller_loadFromText("data.csv",listaEmpleados) == 0)
					{
						flagTexto = 1; //se cargo como texto
					}
				}
				else
				{
					printf("El archivo ya fue cargado.\n");
				}
				break;
			case 2:
				if(flagTexto != 1 && flagBin == 0)//si no fue cargado como texto
				{
					if(!controller_loadFromBinary("data.bin", listaEmpleados))
					{
						flagBin = 1; //se cargo como binario
					}
				}
				else
				{
					printf("El archivo ya fue cargado.\n");
				}
				break;
			case 3:
				if(flagTexto == 1 || flagBin == 1)
				{
					controller_addEmployee(listaEmpleados);
				}
				else
				{
					printf("Error.No se cargo ningun archivo.\n");
				}
				break;
			case 4:
				if(flagTexto == 1 || flagBin == 1)
				{
					controller_editEmployee(listaEmpleados);
				}
				else
				{
					printf("Error.No se cargo ningun archivo.\n");
				}
				break;
			case 5:
				if(flagTexto == 1 || flagBin == 1)
				{
					controller_removeEmployee(listaEmpleados);
				}
				else
				{
					printf("Error.No se cargo ningun archivo.\n");
				}
				break;
			case 6:
				if(flagTexto == 1 || flagBin == 1)
				{
					controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("Error.No se cargo ningun archivo.\n");
				}
				break;
			case 7:
				if(flagTexto == 1 || flagBin == 1)
				{
					controller_sortEmployee(listaEmpleados);
				}
				else
				{
					printf("Error.No se cargo ningun archivo.\n");
				}
				break;
				break;
			case 8:
				if(flagTexto == 1 || flagBin == 1)
				{
					controller_saveAsText("data.csv", listaEmpleados);
				}
				else
				{
					printf("Error.No se cargo ningun archivo.\n");
				}
				break;
			case 9:
				if(flagTexto == 1 || flagBin == 1)
				{
					controller_saveAsBinary("data.bin", listaEmpleados);
				}
				else
				{
					printf("Error.No se cargo ningun archivo.\n");
				}
				break;
			case 10:
				printf("Desea salir? s/n: ");
				fflush(stdin);
				scanf("%c", &confirm);
				if(confirm == 's')
				{
					salir = 's';
					ll_deleteLinkedList(listaEmpleados);
				}
				break;
		}

	}while(salir == 'n');
	return 0;
}


