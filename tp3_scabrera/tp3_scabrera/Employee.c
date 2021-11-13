#include "Employee.h"

#define TAMNOMBRE 30



/* \brief Pide memoria c/malloc
 * \return Retorna un puntero a empleado
 */
Employee* employee_new()
{
	return (Employee*) malloc(sizeof(Employee));
}

/*
 * \brief Llama a los setters que cargan los campos del empleado
 * \param idStr id del empleado como string, nombreStr nombre del empleado como string
 *\ horasTrabajadasStr cantidad de hs trabajadas como string, sueldoStr sueldo del empleado como string
 * \return Retorna un puntero a empleado
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* this = NULL;
	this = employee_new();

	if(this != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL)
	{
		//si estas dan error(1), no existe el empleado, por eso llamo a delete
		if(employee_setId(this, atoi(idStr)) == 1 ||
		   employee_setNombre(this, nombreStr) == 1 ||
		   employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)) == 1 ||
		   employee_setSueldo(this, atoi(sueldoStr)) == 1)
		{
			employee_delete(this);
			this = NULL; //libero el puntero queda apuntando a null
		}
	}
	return this;
}

/* \brief Elimina un empleado
 * \param this: puntero a empleado
 * \return 1 en caso de error, 0 sino
 */
int employee_delete(Employee* this)
{
	int respuesta = 1;
	if(this != NULL)
	{
		free(this);
		this = NULL;
		respuesta = 0;
	}
	return respuesta;
}

/*
 * \brief Valida y carga el id en el campo del empleado
 * \param this: puntero a empleado, id: id a validar y cargar
 * \return 1 en caso de error, 0 sino
 */
int employee_setId(Employee* this,int id)
{
	int respuesta = 1;

	if(this != NULL && id >= 0)
	{
		this->id = id;//guarda en el id de this el id que le paso por param
		respuesta = 0;
	}
	return respuesta;
}


/*
 * \brief Carga el id del empleado en el puntero que pasemos por parametros
 * \param this puntero a empleado, id puntero a la variable en la que la funcion cargara el id
 * \return 1 en caso de error, 0 sino
 */
int employee_getId(Employee* this,int* id)
{
	int respuesta = 1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;//me guarda en el puntero a id lo que hay en this id
		respuesta = 0;
	}
	return respuesta;
}

/*
 * \brief Valida y carga el nombre en el campo del empleado
 * \param this puntero a empleado, nombre nombre a validar y cargar
 * \return 1 en caso de error,0 sino
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int respuesta = 1;

	if(this != NULL && nombre != NULL)
	{
		if(isValidName(nombre, TAMNOMBRE))//verifico que este bien
		{
			strncpy(this->nombre, nombre, TAMNOMBRE);
			respuesta = 0;
		}
	}
	return respuesta;
}


/*
 * \brief Carga el nombre del empleado en el puntero que pasemos por parametros
 * \param this puntero a empleado, nombre cadena de caracteres en la que la funcion cargara el nombre
 * \return 1 en caso de error, 0 sino
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int respuesta = 1;

	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre, TAMNOMBRE);
		respuesta = 0;
	}
	return respuesta;
}


/*
 * \brief Valida y carga las horas trabajadas en el campo del empleado
 * \param this puntero a empleado, horasTrabajadas horas a validar y cargar
 * \return 1 en caso de error, 0 sino
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int respuesta = 1;

	if(this != NULL && horasTrabajadas >= 0)
	{
		this->horasTrabajadas = horasTrabajadas;//me guarda en horasTrabajadas de this las horas que le paso por parametros
		respuesta = 0;
	}
	return respuesta;
}


/*
 * \brief Carga las horas trabajadas del empleado en el puntero que pasemos por parametros
 * \param this puntero a empleado, horasTrabajadas puntero a la variable en la que la funcion cargara las horas trabajadas
 * \return 1 en caso de error,0 sino
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int respuesta = 1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;//me guarda en el puntero a horasTrabajadas lo que hay en this horasTrabajadas
		respuesta = 0;
	}
	return respuesta;
}

/*
 * \brief Valida y carga el sueldo en el campo del empleado
 * \param this puntero a empleado, sueldo sueldo a validar y cargar
 * \return 1 en caso de error,0 sino
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int respuesta = 1;

	if(this != NULL && sueldo >= 0)
	{
		this->sueldo = sueldo;//me guarda en sueldo de this el que le paso por parametros
		respuesta = 0;
	}
	return respuesta;
}


/*
 * \brief Carga el sueldo del empleado en el puntero que pasemos por parametros
 * \param this: puntero a empleado, sueldo: puntero a la variable en la que la funcion cargara el sueldo
 * \return 1 en caso de error,0 sino
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int respuesta = 1;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;//me guarda en el puntero a sueldo lo que hay en this sueldo
		respuesta = 0;
	}

	return respuesta;
}



/*
 * \brief Busca un empleado por id
 * \param pArrayListEmployee: LinkedList, id: id a buscar en la lista
 * \return 1 en caso de error, o el index del empleado en caso de exito
 */
int employee_buscarPorId(LinkedList* pArrayListEmployee, int id)
{
	int respuesta = 1;
	int idAux;
	Employee* pEmpleado;

	for(int index = 0; index < ll_len(pArrayListEmployee); index++)
	{
		pEmpleado = ll_get(pArrayListEmployee, index);

		if(employee_getId(pEmpleado, &idAux) == 0 && idAux == id)
		{
			respuesta = index;//devuelvo la posicion del empleado
		}
	}
	return respuesta;
}

/*
 * \brief Imprime un empleado
 * \param pArrayListEmployee LinkedList, index indice donde se encuentra el empleado
 * \return 1 en caso de error, o 0 sino
 */
int employee_imprimirEmpleado(LinkedList* pArrayListEmployee, int index)
{
	int respuesta = 1;
	Employee* pEmpleado;
	int auxId;
	int auxHoras;
	int auxSueldo;
	char auxNombre[TAMNOMBRE];

	if(pArrayListEmployee != NULL && index >= 0)
	{
		pEmpleado = ll_get(pArrayListEmployee, index);
		if(employee_getId(pEmpleado, &auxId) == 0 &&
		   employee_getNombre(pEmpleado, auxNombre) ==0 &&
		   employee_getHorasTrabajadas(pEmpleado, &auxHoras) == 0 &&
		   employee_getSueldo(pEmpleado, &auxSueldo) == 0)
			{
				printf("%5d    %10s    %10d    %10d\n", auxId, auxNombre, auxHoras, auxSueldo);
			}
			else
			{
				printf("Error,no se pudo imprimir!\n");
			}
		respuesta=0;

	}
	return respuesta;
}

/*
 * \brief Cambia el nombre de un empleado
 * \param pArrayListEmployee: LinkedList, index indice donde se encuentra el empleado
 * \return 1 en caso de error,0 sino
 */
int employee_cambiarNombre(LinkedList* pArrayListEmployee, int index)
{
	int respuesta = 1;
	char nuevoNombre[TAMNOMBRE];
	Employee* pEmpleado;

	pEmpleado = ll_get(pArrayListEmployee, index);

	if(utn_getNombre(nuevoNombre, TAMNOMBRE,"Ingrese nuevo nombre:\n","Error, nombre invalido.\n", 3) == 0)
	{
		normalizeStr(nuevoNombre);
		employee_setNombre(pEmpleado, nuevoNombre);
		respuesta = 0;
	}

	return respuesta;
}

/*
 * \brief Actualiza las horas trabajadas de un empleado
 * \param pArrayListEmployee: LinkedList, index: indice donde se encuentra el empleado
 * \return 1 en caso de error,0 sino
 */
int employee_modifHoras(LinkedList* pArrayListEmployee, int index)
{
	int respuesta = 1;
	int auxHoras;
	Employee* pEmpleado;

	pEmpleado = ll_get(pArrayListEmployee, index);

	if(utn_getNumero(&auxHoras, "Ingrese actualizacion de horas:\n ", "Error,numero invalido.\n", 0, 10000, 3) == 0)
	{
		employee_setHorasTrabajadas(pEmpleado, auxHoras);
		respuesta = 0;
	}
	return respuesta;
}


/*
 * \brief Cambia el salario de un empleado
 * \param pArrayListEmployee LinkedList, index indice donde se encuentra el empleado
 * \return 1 en caso de error, 0 sino
 */
int employee_modifSueldo(LinkedList* pArrayListEmployee, int index)
{
	int respuesta = 1;
	int auxSueldo;
	Employee* pEmpleado;

	pEmpleado = ll_get(pArrayListEmployee, index);

	if(	utn_getNumero(&auxSueldo,"Ingrese nuevo sueldo de 20000 aa 500000:\n","Error,sueldo invalido.\n", 20000, 500000,3) == 0)
	{
		employee_setHorasTrabajadas(pEmpleado, auxSueldo);
		respuesta = 0;
	}
	return respuesta;
}

/*
 * \brief Devuelve el id max de la lista
 * \param pArrayListEmployee LinkedList
 * \return 1 en caso de error, o el id mas alto en caso de exito
 */
int employee_maxId(LinkedList* pArrayListEmployee)
{
	Employee* pEmpleado;
	int len = ll_len(pArrayListEmployee);
	int auxId;
	int maxId = 0;
	int flag = 0;

	if(pArrayListEmployee != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			pEmpleado = (Employee*) ll_get(pArrayListEmployee,i);
			employee_getId(pEmpleado, &auxId);

			if(auxId > maxId || flag == 0)
			{
				maxId = auxId;
				flag = 1;
			}
		}
	}
	return maxId;
}

/*
 * \brief Switchea entre los cases de ordenamiento
 * \param pArrayListEmployee: LinkedList
 * \return 1 en caso de error,0 sino
 */
int employee_Ordenar(LinkedList* pArrayListEmployee)
{
	int respuesta = 1;
	int opcion;
	int salir;

	if(pArrayListEmployee != NULL)
	{
		do{
			switch(menuOrdenar())
			{
				case 1:
					//Id
					utn_getNumero(&opcion, "1 ascendente o 0 descendente:\n","Error,opcion invalida\n", 0, 1, 3);
					printf("Espere...\n");
					ll_sort(pArrayListEmployee, employee_ordenarPorId, opcion);
					controller_ListEmployee(pArrayListEmployee);
					respuesta = 0;
					break;
				case 2:
					//Nombre
					utn_getNumero(&opcion, "1 ascendente o 0 descendente:\n","Error,opcion invalida\n", 0, 1, 3);
					printf("Espere...\n");
					ll_sort(pArrayListEmployee, employee_ordenarPorNombre, opcion);
					controller_ListEmployee(pArrayListEmployee);
					respuesta = 0;
					break;
				case 3:
					//Horas
					utn_getNumero(&opcion, "1 ascendente o 0 descendente:\n","Error,opcion invalida\n", 0, 1, 3);
					printf("Espere...\n");
					ll_sort(pArrayListEmployee, employee_ordenarPorHoras, opcion);
					controller_ListEmployee(pArrayListEmployee);
					respuesta = 0;
					break;
				case 4:
					//Sueldo
					utn_getNumero(&opcion, "1 ascendente o 0 descendente:\n","Error,opcion invalida\n", 0, 1, 3);
					printf("Espere ...\n");
					ll_sort(pArrayListEmployee,employee_ordenarPorSueldo, opcion);
					controller_ListEmployee(pArrayListEmployee);
					respuesta = 0;
					break;
				case 5:
					salir=5;
					respuesta = 0;
					break;
				default:
					printf("No es una opcion valida\n\n");
					break;
			}
		}while(salir !=5);
	}
	return respuesta;
}

/*
 * \brief Compara los ids de dos empleados
 * \param firstEmployee: puntero a primer empleado a comprar, secondEmployee: puntero a segundo empleado a comprar
 * \return 1 si el id del primer empleado es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int employee_ordenarPorId(void* firstEmployee, void* secondEmployee)
{
	int respuesta = 0;//si son iguales
	int firstId;
	int secondId;

	employee_getId(firstEmployee, &firstId);
	employee_getId(secondEmployee, &secondId);

	if(firstId > secondId)
	{
		respuesta = 1;//si el id del primer empleado es mas alto
	}
	else if(firstId < secondId)
	{
		respuesta = -1;// si es mas bajo
	}

	return respuesta;
}

/*
 * \brief Compara los nombres de dos empleados
 * \param firstEmployee: puntero a primer empleado a comprar, secondEmployee: puntero a segundo empleado a comprar
 * \return 1 si el nombre del primer empleado esta antes en el alfabeto, -1 si esta despues y 0 si son iguales
 */
int employee_ordenarPorNombre(void* firstEmployee, void* secondEmployee)
{
	int respuesta = 0;//si son iguales
	char firstName[TAMNOMBRE];
	char secondName[TAMNOMBRE];

	employee_getNombre(firstEmployee, firstName);
	employee_getNombre(secondEmployee, secondName);

	if(strcmp(firstName, secondName) > 0)//el primero es mayor
	{
		respuesta = 1;
	}
	else if(strcmp(firstName, secondName) < 0)// el primero es menor
	{
		respuesta = -1;
	}

	return respuesta;
}

/*
 * \brief Compara las horas trabajadas de dos empleados
 * \param firstEmployee: puntero a primer empleado a comprar, secondEmployee: puntero a segundo empleado a comprar
 * \return 1 si las horas trabajadas del primer empleado son mas, -1 si son menos y 0 si son iguales
 */
int employee_ordenarPorHoras(void* firstEmployee, void* secondEmployee)
{
	int respuesta = 0;//si son iguales
	int firstHours;
	int secondHours;

	employee_getHorasTrabajadas(firstEmployee, &firstHours);
	employee_getHorasTrabajadas(secondEmployee, &secondHours);

	if(firstHours > secondHours)
	{
		respuesta = 1;
	}
	else if(firstHours < secondHours)
	{
		respuesta = -1;
	}

	return respuesta;
}


/*
 * \brief Compara los sueldos de dos empleados
 * \param firstEmployee: puntero a primer empleado a comprar, secondEmployee: puntero a segundo empleado a comprar
 * \return 1 si el sueldo del primer empleado es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int employee_ordenarPorSueldo(void* firstEmployee, void* secondEmployee)
{
	int respuesta = 0;
	int firstSalary;
	int secondSalary;

	employee_getSueldo(firstEmployee, &firstSalary);
	employee_getSueldo(secondEmployee, &secondSalary);

	if(firstSalary > secondSalary)
	{
		respuesta = 1;
	}
	else if(firstSalary < secondSalary)
	{
		respuesta = -1;
	}

	return respuesta;
}
