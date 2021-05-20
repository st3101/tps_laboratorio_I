/*
 * utn.c
 *
 *  Created on: 15 abr. 2021
 *      Author: santi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_getString(char* pResultado,char* mensaje,char* mensajeError)
{
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s",mensaje);

		fgets(pResultado,50,stdin);

			if(pResultado[strlen(pResultado)-1]==10)
			{
				pResultado[strlen(pResultado)-1] = 0;
				retorno = 1;
			}
	}
	else
	{
		printf("%s",mensajeError);
	}


	return retorno;
}

int utn_getInt(int* pEntero,char* mensaje,char* mensajeError)
{
	int retorno = -1;

	if(pEntero != NULL && mensaje != NULL && mensajeError != NULL)
	{

		printf("%s",mensaje);
		scanf("%d",pEntero);
		fflush(stdin);
		retorno = 1;
	}
	else
	{
		printf("%s",mensajeError);
	}

	return retorno;
}

int utn_getfloat(float* pFloat,char* mensaje,char* mensajeError)
{
	int retorno = -1;

	if(pFloat != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s",mensaje);
		scanf("%f",pFloat);
		retorno = 1;
	}
	else
	{
		printf("%s",mensajeError);
	}

	return retorno;
}


int utn_validarNumero(char* array)
{
	int i=0;
	int retorno = 1;

	if(array != NULL)
	{
		while(array[i] != '\0')
		{
			if(array[i] != '-')
			{
				if(array[i] < '0' || array[i] > '9')
				{
					retorno = 0;
					break;
				}
			}

			i++;
		}
	}
	return retorno;
}

int utn_validarFloat(char* array)
{
	int i=0;
	int retorno = 1;

	if(array != NULL)
	{
		while(array[i] != '\0')
		{
			if(array[i] != '.' && array[i] != '-')
			{
				if(array[i] < '0' || array[i] > '9')
				{

					retorno = 0;
					break;
				}
			}
			i++;
		}
	}
	return retorno;
}

int utn_getNumeroEntero(int* numero,char* mensaje, char* mensajeError,int reintetos)
{
	int i;
	char array[50];
	int retorno = 0;

	if(array != NULL && mensaje != NULL && mensajeError != NULL && reintetos >  0)
	{
		for(i=0;i<reintetos;i++)
		{
			if(utn_getString(array, mensaje, mensajeError))
			{
				if(utn_validarNumero(array))
				{
					*numero = atoi(array);
					retorno = 1;
					break;
				}
				else
				{
					printf("%s",mensajeError);
				}
			}
		}

	}

	return retorno;
}

int utn_getNumeroFloat(float* numero,char* mensaje, char* mensajeError,int reintetos)
{
	int i;
	char array[50];
	int retorno = 0;

	if(array != NULL && mensaje != NULL && mensajeError != NULL && reintetos >  0)
	{
		for(i=0;i<reintetos;i++)
		{
			if(utn_getString(array, mensaje, mensajeError))
			{
				if(utn_validarFloat(array))
				{
					*numero = atof(array);
					retorno = 1;
					break;
				}
				else
				{
					printf("%s, ",mensajeError);
				}
			}
		}

	}

	return retorno;
}
