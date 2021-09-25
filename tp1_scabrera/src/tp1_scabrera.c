/*
 ============================================================================
 Name        : Tp1_laboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
	setbuf(stdout,NULL);

    int opcion;
    int numUno;
    int numDos;
    int flagA=0;
    int flagB=0;
    int flagOp3=0;
    int flagOp4=0;

    do
    {
        system("cls");
        printf("\n*** Menu de Opciones ***\n");
 //con flagA solo se actualiza cuando se ingresó un numero, al igual que flagB
         if(flagA==1)
            {
                printf("1-Primer operando ingresado  A=%d\n",numUno);

            }else
            {
              printf("1- Ingresar primer operando (A=x)\n");
            }
        if(flagB==1)
            {
              printf("2-Segundo operando ingresado  B=%d\n",numDos);

            }else
            {
             printf("2- ingresar segundo operando( B=y)\n");

            }

            printf("3- calcular todas las operaciones\n");

            /*si se ingresaron las variables en op 1 y 2,se actualiza este menu con los valores ingresados(case 1),
            sino se muestra uno generico(case 0), case 3 y cuatro se inicializa cuando se ejecuta alguna opcion sin haber
            ingresado todos los valores necesarios para mostrar resultados*/
            switch(flagOp3)
            {
          case 0:
            printf("a)Calcular suma (A+B)\n");
            printf("b)calcular resta (A-B)\n");
            printf("c)Calcular division (A/B)\n");
            printf("d)Calcular multiplicacion(A*B)\n");
            printf("e)Calcular factorial (A!) y (B!)\n");
            break;
          case 1:
            printf("a)Calculada suma (%d+%d)\n",numUno,numDos);
            printf("b)Calculada resta (%d-%d)\n",numUno,numDos);
            printf("c)Calculada division (%d/%d)\n",numUno,numDos);
            printf("d)Calculada multiplicacion(%d*%d)\n",numUno,numDos);
            printf("e)Calculada factorial (%d!) y (%d!)\n",numUno,numDos);
            break;
          case 2:
              printf("Debe ingresar B=Y.\n");

            break;
            case 3:
              printf("Debe ingresar A=x.\n");

            break;
            case 4:
              printf("Debe ingresar A=x y B=Y.\n");

            break;
            }
            printf("4- informar resultados\n");
            /*si flag tiene un valor de uno muestra generico, si tiene valor dos se hacen las operaciones,si se aprieta opcion cuatro
            sin previamente haberse ejecutdo la opcion 3, muestra case 2 */
            switch(flagOp4){

            case 0:
                 printf("a)El resultado A+B es :r\n");
                printf("b)El resultado A-B es : r\n");
                printf("c)El resultado A/B es : r\n");
                printf("d)El resultado A*B es : r\n");
                printf("e) El factorial de A es :r1 y El factorial de B es: r2\n");
                break;
                case 1:
                printf("a)El resultado de (%d + %d )es : %d\n",numUno,numDos,suma_s(numUno,numDos));
                printf("b)El resultado de (%d - %d )es : %d\n",numUno,numDos,resta_s(numUno,numDos));
                if(numDos==0)
                    {
                        printf("c)No es posible dividir por cero.\n ");
                    }else{
                        printf("c) El resultado de (%d/%d) es: %.2f\n",numUno,numDos,division_s(numUno,numDos));
                         }

                printf("d)El resultado de (%d*%d) es : %d\n",numUno,numDos,multiplica_s(numUno,numDos));

                if(numUno>=0 && numDos>=0)
                    {
                        printf("e)El resultado de (%d!) y (%d!)es : %.2d y %.2d\n",numUno,numDos,factorial_A(numUno),factorial_A(numDos));
                    }else{
                        if(numUno<0 && numDos<0)
                            {
                               printf("e)El factorial de (%d!), y el factorial de (%d) no se pudo calcular por ser NEGATIVO\n",numUno,numDos);
                            }else{
                                if(numUno<0 && numDos>=0)
                                {
                                   printf("e)El resultado de (%d!) no se pudo calcular por ser NEGATIVO, y (%d!) es: %.2d\n",numUno,numDos,factorial_A(numDos));
                                }else{
                                        printf("e)El resultado de (%d!)es %d, y el factorial de (%d) no se pudo calcular por ser NEGATIVO\n",numUno,factorial_A(numUno),numDos);
                                     }
                            }

                         }

                break;
                case 2:
                    printf("Debe calcular las operaciones en op 3 primero.\n ");
                    break;
             }

            printf("5- Salir\n");
            printf("\nIngrese opcion: ");
            scanf("%d",&opcion);
       /*
       Este switch cambia el estado de las banderas segun las opciones elegidas
       */
        switch(opcion)
        {
        case 1:
            printf("1-Ingrese valor de A:");
            scanf("%d",&numUno);
            flagA=1;

            flagOp3=0;
            break;
        case 2:
            printf("2-Ingrese valor de B:");
            scanf("%d",&numDos);
            flagB=1;
            flagOp3=0;


            break;

        case 3:
              if(flagA==1 && flagB==1)
                {
                    flagOp3=1;
                    flagOp4=0;
                }else{
                     if (flagA==1 && flagB==0)
                      {
                        flagOp3=2;
                      }
                      if (flagA==0 && flagB==1)
                      {
                        flagOp3=3;
                      }
                      if(flagA==0 && flagB==0)
                        {
                          flagOp3=4;
                        }

                     }

            break;

        case 4:
            if(flagA==0 && flagB==0&&flagOp3==0)
                    {
                      flagOp4=0;
                    }else{
                       if(flagA==1 && flagB==1 && flagOp3==1)
                            {
                             flagOp4 =1;
                            }
                        if(flagA==1&&flagB==1&&flagOp3==0)
                            {
                                flagOp4=2;
                            }
                    }




            break;
        case 5:
            printf("5-opcion salir");
            system("cls");
            break;
        default:
            printf("ingrese opcion valida ");

        }

    }while(opcion !=5);

    return 0;
}
