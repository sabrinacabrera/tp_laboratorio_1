/*
 * utn.h
 *
 *  Created on: 8 oct. 2020
 *      Author: gisel
 */

#ifndef UTN_H_
#define UTN_H_

int menuABM();

int get_sector(eSector* list,int tamsec,int id,char* desc);

/**funcion look empty, busca un espacio vacio
 * recibe una estuctura de tipo array
 * recibe  un tamaño
 * devuelve -1 error,  sino retorna el lugar vacio 0
 */
int lookEmpty( eEmployee* list,int tam);

/**funcion get cadena
 * recibe un puntero
 * recibe  un limite
 * devuelve -1 error, 0 sino
 */
int getCadena(char* pAux, int limite);

int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError);
/** funcion get float
 * recibe un puntero float
 * devuelve -1 error, 0 sino
 *
 */
int getFloat(float*pAux);
/**  Función para pedir un número flotante  por consola
	* pFloat: Puntero a variable donde se escribirá el valor ingresado en el caso de ser correcto.
	* msg: Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola.
	* msgError: Puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido.
	*minimo: Valor mínimo admitido (inclusive)
	* maximo: Valor máximo admitido (inclusive)
	* retry: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error.
 */
int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max);

/**  Función para pedir un número entero  por consola
	* pEntero: Puntero a variable donde se escribirá el valor ingresado en el caso de ser correcto.
	* mensaje: Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola.
	* mensajeError: Puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido.
	*minimo: Valor mínimo admitido (inclusive)
	* maximo: Valor máximo admitido (inclusive)
	* reintentos: Cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error.
 */
int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max);


/** funcion que valida que sea numero entero
 *  *pAux: puntero del numero
 *  todoOK: devuelve -1 si hay error, 0 si es numero int
 */
int getInt(int* pAux);

/** Funcion que valida si es float
 * pAux: array
 * itsOK: devuelve -1 si hay error, 0 si es letra.
 */
int isFloat(char* pAux);
/** Funcion que valida si es letra
 * letra: array
 * itsOK: devuelve -1 si hay error, 0 si es letra.
 */
int isChar(char str[]);


/** funcion que valida que sea numero entero
 *  *pAux: puntero del numero
 *  todoOK: devuelve -1 si hay error, 0 si es numero int
 */
int isInt(char *pAux);


int normalizeStr(char* str);


#endif /* UTN_H_ */
