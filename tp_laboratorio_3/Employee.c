#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"
#include "parser.h"

Employee* employee_new()
{
	return (Employee*)malloc(sizeof(Employee));
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* suledoStr)
{
	Employee* pEmployee = employee_new();

	if(pEmployee != NULL)
	{
		if(employee_setId(pEmployee,idStr) || employee_setNombre(pEmployee, nombreStr) || employee_setHorasTrabajadas(pEmployee, horasTrabajadasStr) || employee_setSueldo(pEmployee, suledoStr))
		{
			employee_delete(pEmployee);
			pEmployee = NULL;
		}
	}

	return pEmployee;
}
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int employee_setId(Employee* this,char* id)
{
	int retono = 1;
	int idAux;

	if(this != NULL && !utn_validarNumero(id))
	{
		idAux=atoi(id);

		if(idAux >= 0)
		{
			this->id=idAux;
			retono=0;
		}
	}

	return retono;
}

int employee_getId(Employee* this,int* flagError)
{
	int idAux = -1;
	*flagError = 1;

	if(this != NULL)
	{
		idAux=this->id;
		*flagError = 0;
	}

	return idAux;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = 1;

	if(this != NULL && !utn_validarLetra(nombre))
	{
		strcpy(this->nombre,nombre);
		retorno = 0;
	}

	return retorno;
}
char* employee_getNombre(Employee* this,int* flagError)
{
	*flagError = 1;
	char* nombreAux;

	if(this != NULL)
	{
		nombreAux=this->nombre;
		*flagError = 0;
	}

	return nombreAux;
}
int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas)
{
	int retorno = 1;
	int horaAux=-1;

	if(this != NULL && !utn_validarNumero(horasTrabajadas))
	{
		horaAux=atoi(horasTrabajadas);

		if(horaAux >= 0)
		{
			this->horasTrabajadas=horaAux;
			retorno = 0;
		}
	}

	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* flagError)
{
	*flagError = 1;
	int horasTrabajadasAux=-1;

	if(this != NULL)
	{
		horasTrabajadasAux=this->horasTrabajadas;
		*flagError = 0;
	}

	return horasTrabajadasAux;
}
int employee_setSueldo(Employee* this,char* sueldo)
{
	int retorno = 1;
	int sueldoAux;

	if(this != NULL && !utn_validarNumero(sueldo))
	{
		sueldoAux=atoi(sueldo);

		if(sueldoAux>0)
		{
			this->sueldo=sueldoAux;
			retorno = 0;
		}
	}

	return retorno;
}
int employee_getSueldo(Employee* this,int* flagError)
{
	*flagError = 1;
	int suledoAux;

	if(this != NULL)
	{
		suledoAux = this->sueldo;
		*flagError = 0;
	}

	return suledoAux;
}

int employee_getIdArchivo(char* nameFile,char* id)
{
	int retorno = 1;
	FILE* pFile = fopen(nameFile,"r");

	if(nameFile != NULL)
	{

		if(!parse_idEmployeeFromText(pFile,id))
		{
			retorno=0;
		}
	}
	fclose(pFile);
	return retorno;
}

int employee_setIdArchivo(char* nameFile,int id)
{
	int retorno=1;

	FILE* pFile = fopen(nameFile,"w");

	if(pFile != NULL && id >= 0)
	{
		fprintf(pFile,"%d\n",id);
		retorno = 0;
	}

	fclose(pFile);
	return retorno;
}

int employee_addIdFree(char* nameFile,char* id)
{
	int retorno=-1;
	int idAux=0;

	if(nameFile != NULL)
	{
		if(!employee_getIdArchivo(nameFile, id))
		{
			idAux=atoi(id);

			if(idAux >-1 )
			{
				idAux++;

				if(!employee_setIdArchivo(nameFile, idAux))
				{
					retorno = 0;
				}

			}
		}
	}

	return retorno;
}



int employee_printOne(Employee* this)
{
	int flagError=1;
	if(this != NULL)
	{
		printf("%-15d%-15s%-15d%-15d\n",employee_getId(this, &flagError),employee_getNombre(this, &flagError),employee_getHorasTrabajadas(this, &flagError),employee_getSueldo(this, &flagError));
		flagError=0;
	}

	return flagError;
}

int employee_CompareByName(void* elemento1, void* elemento2)
{
	Employee* pEmpleado1;
	Employee* pEmpleado2;

	char* nombre1[64];
	char* nombre2[64];

	int flagError1;
	int flagError2;

	int retorno;

	pEmpleado1 = (Employee*)elemento1;
	pEmpleado2 = (Employee*)elemento2;

	*nombre1=employee_getNombre(pEmpleado1, &flagError1);
	*nombre2=employee_getNombre(pEmpleado2, &flagError2);

	if(!flagError2 && !flagError1)
	{
		retorno = strcmp(*nombre1,*nombre2);
	}

	return retorno;
}
