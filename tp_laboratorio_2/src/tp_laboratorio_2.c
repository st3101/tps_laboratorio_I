/*
 ============================================================================
 Name        : tp_laboratorio_2.c
 Author      : Santiago Tomas Leonardi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "arrayEmployees.h"

#define CAN_EMPLOYEE 1000

int main(void) {

	setbuf(stdout,NULL);
	int opcion=3;
	int salir=-1;

	Employee arrayEmployees[CAN_EMPLOYEE];
	initEmployees(arrayEmployees, CAN_EMPLOYEE);

	do
	{
		utn_getInt(&opcion, "1)Alta\n2)Modificar\n3)Baja\n4)Informes\n5)Mostrar Empleados\n6)Salir\nOPCION: ", "Error, ");

		switch (opcion) {
			case 1:
				if(addEmployee(arrayEmployees, CAN_EMPLOYEE))
					printf("No se pudo cargar\n");
				break;
			case 2:
				if(modifyEmployee(arrayEmployees, CAN_EMPLOYEE))
					printf("No se puede modificar\n");
				break;
			case 3:
				if(removeEmployee(arrayEmployees, CAN_EMPLOYEE))
					printf("No se puede borrar\n");
				break;
			case 4:
				if(reportsEmployees(arrayEmployees, CAN_EMPLOYEE))
					printf("No se pudo mostrar los informes\n");
				break;
			case 5:
				if(printEmployees(arrayEmployees, CAN_EMPLOYEE))
					printf("No se puede mostrar\n");
				break;
			case 6:
					salir=0;
				break;
			default:
				printf("opcion invalida\n");
				break;
		}
	}while(salir==-1);

	return EXIT_SUCCESS;
}
