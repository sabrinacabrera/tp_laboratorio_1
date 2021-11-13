/*
 * menu.c
 *
 *  Created on: 12 nov. 2021
 *      Author: gisel
 */
#include "menu.h"

/*  Menu principal
 * return Retorna opcion elegida
 */
int menu()
{
	int opcion;

	system("cls");

	printf("***** MENU *****\n\n");
	printf("  1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf("  2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
	printf("  3. Alta de empleado\n");
	printf("  4. Modificar datos de empleado\n");
	printf("  5. Baja de empleado\n");
	printf("  6. Listar empleados\n");
	printf("  7. Ordenar empleados\n");
	printf("  8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf("  9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
	printf("  10. Salir\n\n");

	utn_getNumero(&opcion,"Ingrese opcion: \n\n", "Error, no es una opcion valida\n", 1, 10, 3);

	return opcion;
}

/* Menu de edicion
 * \return Retorna la opcion elegida
 */
int menuEditar()
{
	int opcion;

	system("cls");

	printf("***** MODIFICAR *****\n\n");
	printf("  1. Nombre\n");
	printf("  2. Horas trabajadas\n");
	printf("  3. Sueldo\n");
	printf("  4. Salir\n\n");

	utn_getNumero(&opcion, "Ingrese opcion: \n\n", "Error, no es una opcion valida\n", 1, 4, 3);

	return opcion;
}


/* Menu de ordenamiento
 * \return Retorna la opcion elegida
 */
int menuOrdenar()
{
	int opcion;

	system("cls");

	printf("***** ORDENAR *****\n\n");
	printf("  1. Por ID\n");
	printf("  2. Por Nombre\n");
	printf("  3. Por Horas trabajadas\n");
	printf("  4. Por Sueldo\n\n");
	printf("  5. Salir\n\n");

	utn_getNumero(&opcion,"Ingrese opcion: \n\n", "Error, no es una opcion valida\n", 1, 5, 3);

	return opcion;

}
