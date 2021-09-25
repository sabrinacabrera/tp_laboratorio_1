/*
 * utn.c
 *
 *  Created on: 20 dic. 2020
 *      Author: gisel
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

    int suma_s(int numUno,int numDos)
    {
        return  numUno+numDos;
    }

    int resta_s(int numUno,int numDos)
    {
        return numUno-numDos;
    }

    float division_s(int numUno,int numDos)
    {
        return (float) numUno/numDos;
    }

    int multiplica_s(int numUno,int numDos)
    {
        return numUno*numDos;
    }

    int factorial_A(int numUno)
    {
        int resultadoA;
        if (numUno<=1)
            {
                resultadoA=1;
            }else
            {
                resultadoA= numUno*(factorial_A(numUno-1));
            }
        return resultadoA;
    }

