/*
 * arrayEmployees.c
 *
 *  Created on: 15 may. 2021
 *      Author: santi
 */

#ifndef ARRAYEMPLOYEES_C_
#define ARRAYEMPLOYEES_C_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utn.h"

#define BORRADO 2
#define CARGADO 1
#define LIBRE 0
/** \brief indica que todas la posiciones de la lista estas vacias,
*
*
* \param list Employee* puntero de la lista de empleado
* \param len int cantidad de lementod de la lista
* \return int retorna (-1) si hay un error y 0 si funciona correctamente
*
*/
int initEmployees(Employee* list,int len)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty=LIBRE;
		}
		retorno = 0;
	}

	return retorno;
}
/** \brief busca un elemento de la lista
*
*
* \param list Employee* puntero de la lista de empleado
* \param len int cantidad de lementod de la lista
* \param id int id a buscar en la lista
* \return int retorna (-1) si hay un error y 0 si funciona correctamente
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
	int retorto =-1;

	if(list != NULL && len > 0 && id >= 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].id==id && list[i].isEmpty==CARGADO)
			{
				retorto = i;
				break;
			}
		}
	}

	return retorto;
}
/** \brief busca lugar libre
*
*
* \param list Employee* puntero de la lista de empleado
* \param len int cantidad de lementod de la lista
* \return int retorna (-1) si hay un error y 0 si funciona correctamente
*
*/
int findFree(Employee* list,int len)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty==LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/** \brief Elimina un elemento de la lista de manera logica
*
*
* \param list Employee* puntero de la lista de empleado
* \param len int cantidad de lementod de la lista
* \return int retorna (-1) si hay un error y 0 si funciona correctamente
*
*/
int removeEmployee(Employee* list, int len)
{
	int retorno=-1;
	int indice=-1;



	if(list != NULL && len > 0)
	{
		if(!printEmployees(list, len))
		{
			if(!utn_getSoloNumeroEntero(&indice, "Ingrese el id a borrar: ", "Error, ", 3))
			{
				indice = findEmployeeById(list, len, indice);


				if(indice >= 0)
				{
					list[indice].isEmpty=BORRADO;
					retorno = 0;
				}
				else
				{
					printf("Indice incorrecto\n");
				}
			}
		}
	}

	return retorno;
}
/** \brief Muestra un empleado de la lista
*
*
* \param this Employee  un empleado de la lista
* \param len int cantidad de lementod de la lista
* \return int retorna (-1) si hay un error y 0 si funciona correctamente
*
*/
int printUnEmployee(Employee this)
{
	printf("%-15d%-15s%-15s%-15.2f%-15d",this.id,this.name,this.lastName,this.salary,this.sector);
	return 0;
}
/** \brief Muestra todos los empleado de la lista
*
*
* \param list Employee* puntero de la lista de empleado
* \param len int cantidad de lementod de la lista
* \return int retorna (-1) si hay un error y 0 si funciona correctamente
*
*/
int printEmployees(Employee* list, int len)
{
	int retorno =-1;

	if(list != NULL && len > 0)
	{

		for(int i=0;i<len;i++)
		{

			if(list[i].isEmpty==CARGADO)
			{
				if(retorno==-1)
				{
					printf("%-15s%-15s%-15s%-15s%-15s\n","ID","NOMBRE","APELLIDO","SALARIO","SECTOR");

				}
				retorno = printUnEmployee(list[i]);
				printf("\n");

			}
		}
	}
	return retorno;
}
/** \brief Agrega un empleado a la lista
*
*
* \param list Employee* puntero de la lista de empleado
* \param len int cantidad de lementod de la lista
* \return int retorna (-1) si hay un error y 0 si funciona correctamente
*
*/
int addEmployee(Employee* list, int len)
{
	int retorno = -1;
	Employee aux;

	if(list != NULL && len > 0)
	{
		aux.id = findFree(list, len);

		if(aux.id >= 0)
		{
			if(!utn_getSoloLetras(aux.name, "Ingrese el nombre: ", "Error, ", 3))
			{
				if(!utn_getSoloLetras(aux.lastName, "Ingrese el apellido: ", "Error, ", 3))
				{
					if(!utn_getSoloNumeroFloatEntreMaxMin(&aux.salary, 9999999, 0, "Ingrese el salario: ", "Error, " , 3))
					{
						if(!utn_getSoloNumeroEnteroMaxMin(&aux.sector, 99999999, 0, "Ingrese el sector: ", "Error, ", 3))
						{
							list[aux.id]=aux;
							list[aux.id].isEmpty=CARGADO;
							retorno=0;
						}
					}
				}
			}
		}
	}

	return retorno;
}
/** \brief Modifica el nombre o el apellido de un empleado
*
*
* \param list Employee* puntero de la lista de empleado
* \param len int cantidad de lementod de la lista
* \return int retorna (-1) si hay un error y 0 si funciona correctamente
*
*/
int modifyEmployee(Employee* list,int len)
{
	int retorno = -1;
	int opcion;
	int salir;
	Employee aux;




		if(list != NULL && len > 0)
		{
			if(!printEmployees(list, len))
			{
				if(!utn_getSoloNumeroEntero(&aux.id, "Ingrese el id a modificar: ", "Error, ", 3))
				{
					aux.id = findEmployeeById(list, len, aux.id);

					if(aux.id >= 0)
					{
						aux=list[aux.id];
						do
						{
							utn_getInt(&opcion, "MODIFICAR\n1)Nombre\n2)Apellido\n3)Salir\nOPCION: ", "Error, ");

							switch (opcion) {
								case 1:
									if(!utn_getSoloLetras(aux.name, "Ingrese el nuevo nombre: ", "Error, ", 3))
										retorno =0;
									else
										retorno =-2;
									break;
								case 2:
									if(!utn_getSoloLetras(aux.lastName, "Ingrese el nuevo apellido: ", "Error, ", 3))
										retorno =0;
									else
										retorno =-2;
									break;
								case 3:
									salir = 0;
									break;
								default:
									printf("Ingrese una opcion valida\n");
									break;
								}

							if(retorno==0)
								list[aux.id]=aux;

						}while(salir==-1);
					}
					else
					{
						printf("Indice incorrecto\n");
					}
				}
			}
		}
		return retorno;
}
/** \brief Informa odenada mento los empleado el promedio salarios los que lo superan y la suma total de sueldo
*
*
* \param list Employee* puntero de la lista de empleado
* \param len int cantidad de lementod de la lista
* \return int retorna (-1) si hay un error y 0 si funciona correctamente
*
*/
int reportsEmployees(Employee* list,int len)
{
	int retorno=-1;

	if(!sortEmployees(list, len))
	{
		if(!printEmployees(list, len))
		{
			if(!salaryCalculations(list,len))
			{
				retorno=0;
			}
		}
	}
	return retorno;
}
/** \brief ordena los empleados
*
*
* \param list Employee* puntero de la lista de empleado
* \param len int cantidad de lementod de la lista
* \return int retorna (-1) si hay un error y 0 si funciona correctamente
*
*/
int sortEmployees(Employee* list, int len)
{
	Employee aux;
	int retorno=-1;

	if(list != NULL && len > 0)
	{

		for(int i=0;i<len-1;i++)
		{
			if(list[i].isEmpty==1)
			{
				retorno=0;
				for(int j=i+1;j<len;j++)
				{
					if(list[j].isEmpty==1)
					{
						if(strcmp(list[j].name,list[i].name) < 0 )
						{
							aux=list[i];
							list[i]=list[j];
							list[j]=aux;
						}
						else if(strcmp(list[j].name,list[i].name) == 0)
						{
							if(list[j].sector<list[i].sector)
							{
								aux=list[i];
								list[i]=list[j];
								list[j]=aux;

							}
						}
					}
				}
			}
		}
	}
	return retorno;
}
/** \brief calcula y muestra calculos de empleado
*
*
* \param list Employee* puntero de la lista de empleado
* \param len int cantidad de lementod de la lista
* \return int retorna (-1) si hay un error y 0 si funciona correctamente
*
*/
int salaryCalculations(Employee* list,int len)
{
	int i;
	int retorno=-1;
	float acumulador=0;
	int iteraciones=0;
	float resulatado;
	int contadorSalariosMayPromedio=0;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==CARGADO)
			{
				acumulador+=list[i].salary;
				iteraciones++;
				retorno = 0;
			}
		}

		resulatado=acumulador/(float)iteraciones;

		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==CARGADO && resulatado < list[i].salary)
			{
				contadorSalariosMayPromedio++;
			}
		}
		printf("El total de los salarios es: %.2f\nEl promedio de salario es: %.2f\nLa cantidad de empleados que superan el salario promedio es: %d\n",acumulador,resulatado,contadorSalariosMayPromedio);



	}

	return retorno;
}

#endif /* ARRAYEMPLOYEES_C_ */
