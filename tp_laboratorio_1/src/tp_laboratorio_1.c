/*
 ============================================================================
 Name        : tp_laboratorio_1.c
 Author      : Santiago Leonardi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "calculos.h"

int main(void) {

	setbuf(stdout,NULL);

	float numero1=0;
	float numero2=0;

	int flag1=0;
	int flag2=0;
	int flag3=0;

	float rSuma;
	float rResta;
	float rDivision;
	float rMultiplicacion;
	float rFactorialNumero1;
	float rFactorialNumero2;

	int validacionDivicion;
	int validacionFactorial1;
	int validacionFactorial2;
	int salir=0;

	int opcion;

	do
	{
		 printf("------------- Calculadora -------------\n1)Ingrese el primer numero.  (A=%.2f)\n2)Ingrese el segundo numero. (B=%.2f)\n3)Calcular las operaciones.\n4)Informa resultados.\n5)Salir.\n---------------------------------------\nOpcion: ",numero1,numero2);
		 utn_getNumeroEntero(&opcion,"","Error", 2);

		 switch(opcion)
		{
		case 1:
			utn_getNumeroFloat(&numero1, "Ingrese el PRIMER numero: ", "Error", 3);
			flag1=1;
			break;

		case 2:
			utn_getNumeroFloat(&numero2, "Ingrese el SEGUNDO numero: ", "Error", 3);
			flag2=1;
			break;

		case 3:
			if(flag1==1 && flag2 ==1)
			{
				cal_suma(numero1, numero2, &rSuma);
				cal_resta(numero1, numero2, &rResta);
				cal_multiplicacion(numero1, numero2, &rMultiplicacion);
				validacionDivicion=cal_divicion(numero1, numero2, &rDivision);
				validacionFactorial1=cal_factorial(numero1, &rFactorialNumero1);
				validacionFactorial2=cal_factorial(numero2, &rFactorialNumero2);

				flag3=1;
			}
			else
			{
				printf("\n*** No se cargo algun numero ***\n\n");
			}
			break;

		case 4:
			if(flag3==1)
			{
				printf("\nEl resultado de A+B es: %.2f\n",rSuma);
				printf("El resultado de A-B es: %.2f\n",rResta);
				printf("El resultado de A*B es: %.2f\n",rMultiplicacion);

				if(validacionDivicion)
				{
					printf("El resultado de A/B es: %.2f\n",rDivision);
				}
				else
				{
					printf("No se puede divir por 0\n");
				}

				if(validacionFactorial1)
				{
					printf("El factorial de A es: %.2f\n",rFactorialNumero1);
				}
				else
				{
					printf("No se puede factorial el A\n");
				}

				if(validacionFactorial2)
				{
					printf("El factorial de A es: %.2f\n",rFactorialNumero2);
				}
				else
				{
					printf("No se puede factorial el B\n");
				}
			}
			else
			{
				printf("\n*** No se calcularon las operaciones ***\n\n");
			}
			break;

		case 5:
			printf("Saliendo.");
			salir=1;
			break;

		default:
			printf("Ingresae una opcion valida. \n");
		}

	}while(salir==0);

	return 0;
}
