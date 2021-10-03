/*
 * ArrayEmployees.h
 *
 *  Created on: 8 oct. 2020
 *      Author: gisel
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
    int idSector;
    char nombreSector[21];
} eSector;

typedef struct{

	int id;
	char name[51];
	char lastName[51];
	float salary;
	int idSector;
	int isEmpty;

} eEmployee;

/** \brief Indicates that all positions of the array are empty, setting the isEmpty flag in TRUE in all array positions
    *
    * \param list employee* Pointer to array of employees
    * \param tam int Array length
    * \return Return -1 if error (NULL or invalid), 0 if no error
    *
    */
int initEmployees(eEmployee list[], int tam);


/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list eEmployee*
 * \param tam int
 * \param id int
 * \param nombre[] char
 * \param apellido[] char
 * \param salario float
 * \param sector int
 * \param index int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(eEmployee list[], int tam, int id, char nombre[], char apellido[], float salario, int sector, int index);

/** \brief print the content of one employee in employees array.
     * \param list eEmployee* Pointer to array of employees
     * \param list eSector* Pointer to array sector
     * \param tamsec int Array length
     * \return void.
     */
void showEmployee(eEmployee x ,eSector* list,int tamsec);


/** \brief print the content of eEmployees array.
    * \param list eEmployee* Pointer to array of employees
    * \param list eSector* Pointer to array sector
    * \param tam int Array length
    * \param tamsec int Array length
    * \return void.
    */
void showEmployeeS(eEmployee* list ,eSector listSec[],int tam,int tamsec);


/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list eEmployee*
 * \param tam int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(eEmployee list[], int tam, int id);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list eEmployee*
 * \param tam int
 * \param id int
 * \param sectors eSector*
 * \param tamsec
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(eEmployee*list, int tam, int id, eSector* sectors, int tamsec);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list eEmployee*
 * \param tam int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int sortEmployees(eEmployee* list, int tam, int order);

/**
 * \brief Colecta la informacion del empleado a pasarle a addEmployee
 * \param  list eEmployee*
 * \param tam int
 * \param  *ID int
 *\param Vec nombre
 * \param Vec apellido
 * \param *salario
 * \param *sector auxiliar
 *\param * index
 * \return 0 si pudo colectar la informacion con exito, y -1 si no.
 */
int get_Data(eEmployee list[], int tam, int* nextId, char nombre[], char apellido[], float* salario, int* sector, int* index);


/**
   * \brief shows the menu of modifications
   * \param list eEmployee* Pointer to array employees
   * \param tam int Array length
   * \param list eSector* Pointer to array sector
   * \param tamsec int Array length
 * \return int.
 */
int menuModificar(eEmployee *list,int tam ,eSector* sector,int tamsec);

/** \brief Show informes

   * \param list eEmployee* Pointer to array employees
   * \param tam int Array length
   * \param list eSector* Pointer to array sector
   * * \param tamsec int Array length
   * \return void
   */
int informes(eEmployee list[], int tam, eSector sector[], int tamsec);


/** \brief Shows the total amount of salaries,the average of salaries and all employees with salaries over than the average
     *
     * \param list Employee* Pointer to array of employees
     * \param tam int Array length
     * \return void
     *
     */
int totalAndPromedySalaries(eEmployee* list, int tam);


/**
   * \brief prints the menu of informs
 * \return int.
 */
int menuInform();


/**
   * \brief prints the menu of sectors
 * \return int.
 */
void menuSectores();


void hardCodearEmpleados(eEmployee* list, int tam);
#endif /* ARRAYEMPLOYEES_H_ */
