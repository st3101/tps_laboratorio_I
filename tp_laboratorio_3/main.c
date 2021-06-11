#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);

    int option = 0;
    int flag=0;


    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	utn_getInt(&option, "1)Cargar Texto (data.cvs)\n2)Cargar binario (data.bin)\n3)Alta\n4)Modificar\n5)Eliminar\n6)Mostrar\n7)Ordenar\n8)Guardar Texto (data.cvs)\n9)Guardar binario (data.bin)\n10)Salir\nOpcion: ", "Error, ");
        switch(option)
        {
            case 1:
				if(flag==0 && !controller_loadFromText("data.csv",listaEmpleados))
				{
					printf("-----------------------\nSe cargo exitosamente!\n-----------------------\n");
					flag=1;
				}
				else
				{
					printf("-----------------------\nNo se pudo cargar!\n-----------------------\n");
				}
                break;
            case 2:
            	if(flag==0 && !controller_loadFromBinary("data.bin", listaEmpleados))
            	{
            		printf("-----------------------\nSe cargo exitosamente!\n-----------------------\n");
            		flag=1;
            	}
            	else
            	{
            		printf("-----------------------\nNo se pudo cargar!\n-----------------------\n");
            	}
            	break;
            case 3:
            	if(!controller_addEmployee(listaEmpleados))
            	{
            		printf("-----------------------\nSe cargo exitosamente!\n-----------------------\n");
            	}
            	else
            	{
            		printf("-----------------------\nNo se pudo cargar!\n-----------------------\n");
            	}
            	break;
            case 4:
            	if(!controller_editEmployee(listaEmpleados))
            	{
            	printf("-----------------------\nSe edito exitosamente!\n-----------------------\n");
            	}
            	else
            	{
            		printf("-----------------------\nNo se pudo editar!\n-----------------------\n");
            	}
            	break;
            case 5:
            	if(!controller_removeEmployee(listaEmpleados))
            	{
            		printf("-----------------------\nSe elimino exitosamente!\n-----------------------\n");
            	}
            	else
            	{
            		printf("-----------------------\nNo se pudo eliminar!\n-----------------------\n");
            	}
            	break;
            case 6:
            	if(!controller_ListEmployee(listaEmpleados))
            	{
            		printf("-----------------------\nSe listo exitosamente!\n-----------------------\n");
            	}
            	else
            	{
            		printf("-----------------------\nNo se pudo listar!\n-----------------------\n");
            	}
            	break;

            case 7:
            	if(!controller_sortEmployee(listaEmpleados))
            	{
					printf("-----------------------\nSe ordeno exitosamente!\n-----------------------\nn");
				}
				else
				{
					printf("-----------------------\nNo se pudo ordenar!\n-----------------------\n");
				}
            	break;

            case 8:
            	if(!controller_saveAsText("data.csv", listaEmpleados))
            	{
            		printf("-----------------------\nSe guardo exitosamente!\n-----------------------\n");
            	}else
            	{
            		printf("-----------------------\nNo se pudo guardar!\n-----------------------\n");
            	}
            	break;
            case 9:
            	if(!controller_saveAsBinary("data.bin", listaEmpleados))
            	{
            		printf("-----------------------\nSe guardo exitosamente!\n-----------------------\n");
            	}else
            	{
            		printf("-----------------------\nNo se pudo guardar!\n-----------------------\n");
            	}
            	break;
        }
    }while(option != 10);
    return 0;
};
