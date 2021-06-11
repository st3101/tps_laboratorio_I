#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int employee_printAll(LinkedList* this)
{
	Employee* aux;
	int retorno=1;

	if(this != NULL)
	{
		for(int i=0;i<ll_len(this);i++)
		{
			aux = ll_get(this, i);

			if(aux != NULL)
			{
				employee_printOne(aux);
				retorno=0;
			}

		}
	}
	return retorno;
}

Employee* employee_findById(LinkedList* this,int idBuscar)
{
	Employee* aux = NULL;
	int idAux;
	int flagError;

	if(this != NULL && idBuscar >= 0)
	{
		for(int i=0;i < ll_len(this);i++)
		{

			aux=ll_get(this, i);


			if( aux != NULL)
			{
				idAux = employee_getId(aux, &flagError);

				if(idAux >= 0 && idAux == idBuscar)
				{
					break;
				}
			}

			aux = NULL;
		}
	}

	return aux;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retono = 1;
	FILE* pFile = fopen(path,"r");
	if(path != NULL && pArrayListEmployee != NULL && pFile != NULL)
	{
		if(!parser_EmployeeFromText(pFile,pArrayListEmployee))
		{
			retono = 0;
		}
	}
	fclose(pFile);

    return retono;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retono=1;
	FILE* pFile = fopen(path,"rb");
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		retono = 0;
	}
	fclose(pFile);
    return retono;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmpleado=NULL;
	int retono=1;

	char bufferId[64];
	char bufferNombree[64];
	char bufferHorasTrabajadas[64];
	char bufferSueldo[64];

	if(pArrayListEmployee != NULL)
	{

		employee_addIdFree("id.txt",bufferId);

		if(bufferId >= 0)
		{
			if(!utn_getSringConReintentos(bufferNombree, "Ingrese el nombre: ", "Error, ", 3) && !utn_getStringNumeroChar(bufferHorasTrabajadas, "Ingrese el horas trabajadas: ", "Error, ", 3) && !utn_getStringNumeroChar(bufferSueldo, "Ingresel el sueldo: ", "Error, ", 3))
			{
				pEmpleado = employee_newParametros(bufferId, bufferNombree, bufferHorasTrabajadas, bufferSueldo);
				if( pEmpleado != NULL)
				{
					ll_add(pArrayListEmployee, pEmpleado);
					retono=0;
				}
			}
		}
	}
	return retono;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmpleado=NULL;

	int id=-1;
	int retorno=1;
	int opcion;
	int salir=1;

	char bufferNombre[364];
	char bufferHorasTranbajas[364];
	char bufferSueldo[364];


	if(pArrayListEmployee != NULL)
	{
		if(!employee_printAll(pArrayListEmployee))
		{
			if(!utn_getSoloNumeroEntero(&id, "Ingrese el ID a modificar: ", "Error, ", 3))
			{
				pEmpleado=employee_findById(pArrayListEmployee,id);
				if(pEmpleado != NULL)
				{
					do
					{
						utn_getInt(&opcion, "Modificar\n1)Nombre\n2)Horas trabajadas\n3)Sueldo\n4)Salir\nOPCION: ", "Error, ");

						switch (opcion) {
							case 1:

								if(!utn_getSoloLetras(bufferNombre, "Ingrese el nuevo nombre: ", "Error,  ",3))
									if(!employee_setNombre(pEmpleado, bufferNombre))
										retorno=0;
								break;
							case 2:
								if(!utn_getStringNumeroChar(bufferHorasTranbajas, "Ingrese las horas trabajadas: ", "Error, " , 3))
									if(!employee_setHorasTrabajadas(pEmpleado, bufferHorasTranbajas))
										retorno=0;
								break;
							case 3:
								if(!utn_getStringNumeroChar(bufferSueldo, "Ingrese el sueldo: ", "Error ", 3))
									if(!employee_setSueldo(pEmpleado, bufferSueldo))
										retorno=0;
								break;
							case 4:
								salir=0;
								break;
							default:
								printf("Ingrese una opcion valida, ");
								break;
						}
					}while(salir==1);
				}
			}
		}

	}
	 return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int id=-1;
	int retorno=1;
	Employee* pEmpleado=NULL;


	if(pArrayListEmployee != NULL)
	{
		if(!employee_printAll(pArrayListEmployee))
		{
			if(!utn_getSoloNumeroEntero(&id, "Ingrese el ID a modificar: ", "Error, ", 3))
			{
				pEmpleado=employee_findById(pArrayListEmployee,id);
				if(pEmpleado != NULL)
				{
					id=ll_indexOf(pArrayListEmployee, pEmpleado);
					if(id >= 0)
					{
						ll_remove(pArrayListEmployee, id);
						free(pEmpleado);
						retorno=0;
					}
				}
			}
		}
	}
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=1;
	if(pArrayListEmployee != NULL)
	{
		retorno = employee_printAll(pArrayListEmployee);
	}

	return retorno;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 1;

	if(pArrayListEmployee != NULL)
	{
		if(!ll_sort(pArrayListEmployee, employee_CompareByName,1))
		{
			retorno=0;
		}

	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	Employee* pEmpleado;
	FILE* pFile = fopen(path,"w");

	int flagErrorId;
	int flagErrorNombre;
	int flagErrorHoras;
	int flagErrorSueldo;

	int bufferId;
	char* bufferNombre[64];
	int bufferHoras;
	int bufferSueldo;

	int retorno = 1;

	if(pArrayListEmployee != NULL  && pFile != NULL)
	{
		for(int i=0;i<ll_len(pArrayListEmployee);i++)
		{
			pEmpleado = ll_get(pArrayListEmployee, i);

			if(pEmpleado != NULL)
			{
				bufferId=employee_getId(pEmpleado, &flagErrorId);
				*bufferNombre=employee_getNombre(pEmpleado, &flagErrorNombre);
				bufferHoras=employee_getHorasTrabajadas(pEmpleado, &flagErrorHoras);
				bufferSueldo=employee_getSueldo(pEmpleado, &flagErrorSueldo);

				if(!flagErrorId && !flagErrorNombre && !flagErrorHoras && !flagErrorSueldo)
				{
					if(retorno)
					{
						fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
					}

					fprintf(pFile,"%d,%s,%d,%d\n",bufferId,*bufferNombre,bufferHoras,bufferSueldo);

					retorno=0;
				}
			}
		}
	}

	fclose(pFile);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
    Employee* pEmpleado;

    int len;
    int i;

    int retorno = 1;

    pArchivo=fopen(path,"wb");

    if(pArchivo!=NULL && pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);

        for(i=0; i<len; i++)
        {
            pEmpleado=ll_get(pArrayListEmployee,i);
            fwrite(pEmpleado,sizeof(Employee),1,pArchivo);
            retorno=0;
        }
    }

    fclose(pArchivo);
    return retorno;
}


