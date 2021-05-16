/*
 * arrayEmployees.h
 *
 *  Created on: 15 may. 2021
 *      Author: santi
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int addEmployee(Employee* list, int len);
int initEmployees(Employee* list,int len);
int findEmployeeById(Employee* list, int len,int id);
int findFree(Employee* list,int len);
int removeEmployee(Employee* list, int len);
int printEmployees(Employee* list, int len);
int printUnEmployee(Employee this);
int modifyEmployee(Employee* list,int len);
int reportsEmployees(Employee* list,int len);
int sortEmployees(Employee* list, int len);
int salaryCalculations(Employee* list,int len);
#endif /* ARRAYEMPLOYEES_H_ */
