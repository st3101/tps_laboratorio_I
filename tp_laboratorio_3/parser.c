#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile,LinkedList* pArrayListEmployee)
{
	Employee* pEmpleado;

	int retono = 1 ;
	int rs=0;

	char bufferId[64];
	char bufferNombre[64];
	char bufferHorasTrabajadas[64];
	char bufferSueldo[64];

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			rs=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);

			if(rs == 4)
			{
				pEmpleado=employee_newParametros(bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
				if(pEmpleado != NULL)
				{
					ll_add(pArrayListEmployee, pEmpleado);
					retono=0;
				}
				else
				{
					employee_delete(pEmpleado);
					pEmpleado=NULL;
				}
			}
			else
			{
				break;
			}
		}while(1);
	}

	return retono;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	 Employee* pEmployee;
	  int retorno = -1;

	    if(pFile != NULL && pArrayListEmployee != NULL)
	    {
	        while(!feof(pFile))
	        {
	        	pEmployee = employee_new();
	            fread(pEmployee,sizeof(Employee),1,pFile);
	            if(feof(pFile))
	            {
	                break;
	            }
	            ll_add(pArrayListEmployee,pEmployee);
	        }
	        retorno = 0;

	    }

	    return retorno;
}
int parse_idEmployeeFromText(FILE* pFile,char* id)
{
	char bufferId[32];
	int retorno=1;

	if(pFile != NULL)
	{

		if(fscanf(pFile,"%[^\n]\n",bufferId)==1)
		{
			strcpy(id,bufferId);
			retorno = 0;
		}

	}

	return retorno;
}
