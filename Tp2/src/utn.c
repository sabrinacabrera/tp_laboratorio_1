/*
 * utn.c
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

int menuABM()
{
    int opcion;

    system("cls");
    printf("***** Menu ABM *****\n\n");
    printf("1. Altas.\n");
    printf("2. Modificar.\n");
    printf("3. Bajas.\n");
    printf("4. Informar.\n");
    printf("5. Salir.\n\n");
    printf("Ingresar opcion: \n");
    scanf("%d",&opcion);

    return opcion;
}


int lookEmpty( eEmployee* list,int tam){
	int index=-1; //retorna -1 si NO hay lugares vacios

	for(int i=0; i < tam;i++)
	{
		if (list[i].isEmpty ==1)
		{
			index= i; //retorna el primer subindice vacio
			break;
		}
	}

	return index;

}



int getCadena(char* pAux, int limite)
{
    char auxString[4000];
    int isOk = -1;

    if (pAux != NULL && limite > 0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);

        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limite)
        {
            strncpy(pAux, auxString, limite);
            isOk=0; //ok
        }
    }

    return isOk;
}

int utn_getCadena(char *pAux, int limit, int retry, char* msg, char* msgError)
{
	int isOk = -1;
    char auxString[limit];

    if(pAux != NULL && msg != NULL && msgError != NULL && limit > 0 && retry >= 0){
        do{
        	printf("%s", msg);

            if(getCadena(auxString, limit) == 0 && isChar(auxString) == 0)
            {
                strncpy(pAux, auxString, limit);
                isOk = 0; //todoOK
                break;
            }else
            {
            	printf("%s", msgError);
            }
            retry--;

        }while(retry>=0);
    }

    return isOk;

}

int isFloat(char* pAux)
{
    int todoOk = -1;
    int i = 0;
    int dotCount=0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) == '.')
        {
            dotCount++;
            if(dotCount == 2)
            {
                break;
            }
        }
        else if(*(pAux + i) < '0'|| *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }while (i < stringLong);

    if(i == stringLong)
    {
    	todoOk = 0; //ok
    }
    return todoOk;
}

int getFloat(float*pAux)
{
    char auxString[200];
    int todoOK =-1;

    if(getCadena(auxString,200) == 0 && isFloat(auxString) == 0)
    {
        *pAux = atof(auxString); //to float
        todoOK = 0; //ok
    }
    return todoOK;
}

int utn_getFlotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max)
{
    int todoOK = -1;
    float auxFloat;

    if(pFloat != NULL&& msg != NULL && msgError != NULL && min <= max && retry >= 0)
    {
        do
        {
            retry--;
            printf("%s",msg);
            if(getFloat(&auxFloat) == 0 && auxFloat >= min && auxFloat <= max)
            {
                *pFloat= auxFloat;
                todoOK = 0; //ok
                break;
            }
            else
            {
                printf("%s",msgError);
            }
        }
        while(retry >= 0);
    }
    return todoOK;
}


int utn_getEntero(int* pEntero, int retry, char* msg, char*msgError, int min, int max)
{
    int isOk = -1;
    int auxInt;

    if(pEntero != NULL && msg != NULL && msgError != NULL && min <= max && retry >= 0)
    {
        do
        {
            retry--;
            printf("%s", msg);

            if(getInt(&auxInt) == 0 && auxInt >= min && auxInt <= max)
            {
                *pEntero = auxInt;
                isOk = 0;
                break;
            }
            else
            {
                printf("%s", msgError);
            }
        }
        while(retry >= 0);
    }
    return isOk;
}


int isChar(char str[])
{

	int isOk = 0; //todoOK

	for(int i = 0; str[i] != '\0'; i++)
	{
		//si no es espacio, si es menor a 'a' o may a 'z', si es men a 'A' o may a 'Z', NO es letra:
		if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
		{
			isOk = -1;
		}
	}

	return isOk;

}


int isInt(char *pAux)
{
    int isOk = -1;
    int i = 0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) < '0' || *(pAux + i) > '9')
        {
            break;
        }
        i++;

    }while (i < stringLong);

    if(i == stringLong)
    {
        isOk = 0;
    }
    return isOk;
}

int getInt(int* pAux)
{
    char auxString[400];
    int isOk = -1;

    if(getCadena(auxString, sizeof(auxString)) == 0 && isInt(auxString ) == 0)
    {
        *pAux = atoi(auxString); //to integer
        isOk = 0;
    }
    return isOk;
}


int normalizeStr(char* str)
{
	int isOk = -1;
	int i = 0;

	if(str != NULL)
	{
		strlwr(str);
		str[0] = toupper(str[0]);

		while(str[i] != '\0')
		{
			if(str[i] == ' ')
			{
				str[i + 1] = toupper(str[i + 1]);
				isOk = 0;
			}
			i++;
		}
	}
	return isOk;
}


int get_sector(eSector* list,int tamsec,int id,char* desc)
{
	int itsOK=0;
	for(int i=0; i<tamsec;i++)
	{
		if(list[i].idSector == id)
		{
			strcpy(desc,list[i].nombreSector);
			itsOK=1;
			break;
		}
	}
	return itsOK;
}




