/*
 * ArrayEmployees.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "input.h"
#define EMPLOYEES_LIST_LEN 1000
#define NAME_AND_LASTNAME_LEN 51

//static functions prototypes
static int getAnEmptyIndex(Employee list[], int len, int* pEmptyPosition);

int employee_initEmployees(Employee list[], int len)
{
	int status = -1;
	int index;

	if (list != NULL && len > 0)
	{
		status = 0;
		for (index = 0; index < len; index++)
		{
			list[index].isEmpty = 1;
		}
	}
	return status;
}

int employee_addEmployee(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector)
{
	int status = -1;
	int emptyIndex;
	if (list != NULL && len > 0)
	{
		if (getAnEmptyIndex(list, len, &emptyIndex) == 0)
		{
			status = 0;
			Employee newEmployee;
			newEmployee.id = id;
			strncpy(newEmployee.name, name, NAME_AND_LASTNAME_LEN);
			strncpy(newEmployee.lastName, lastName, NAME_AND_LASTNAME_LEN);
			newEmployee.salary = salary;
			newEmployee.sector = sector;
			list[emptyIndex] = newEmployee;
		}
	}
	return status;
}

int employee_findEmployeeById(Employee list[], int len, int id)
{
	int employeeIndex = -1;
	int index;
	if (list != NULL && len > 0 && id > 0)
	{
		for (index = 0; index < len; index++)
		{
			if (list[index].isEmpty != 1)
			{
				if (list[index].id == id)
				{
					employeeIndex = index;
					break;
				}
			}
		}
	}
	return employeeIndex;
}

int employee_removeEmployee(Employee* list, int len, int id)
{
	int status = -1;
	if (list != NULL && len > 0 && id > 0)
	{
		int foundEmployeeIndex = employee_findEmployeeById(list, len, id);
		if (foundEmployeeIndex > -1)
		{
			status = 0;
			list[foundEmployeeIndex].isEmpty = 1;
		}
	}
	return status;
}


static int getAnEmptyIndex(Employee list[], int len, int* pEmptyIndex)
{
	int index;
	int status = -1;
	if (list != NULL && len > 0)
	{
		*pEmptyIndex = -1;
		status = 0;
		for (index = 0; index < len; index++)
		{
			if (list[index].isEmpty == 1)
			{
				*pEmptyIndex = index;
				break;
			}
		}
	}
	return status;
}

int employee_printEmployees(Employee list[], int len)
{
	int status = -1;
	int index;
	if (list != NULL && len > 0 )
	{
		for (index = 0; index < len; index++)
		{
			status = 0;
			if (list[index].isEmpty != 1)
			{
				printf("\n-----------");
				printf("\nID: %d", list[index].id);
				printf("\nNombre: %s",list[index].name);
				printf("\nApellido: %s",list[index].lastName);
				printf("\nSalario: %f", list[index].salary);
				printf("\nSector: %d", list[index].sector);
			}
		}
	}
	return status;
}

int employee_createId (void)
{
	static int idCounter = 0;
	idCounter++;
	return idCounter;
}

int employee_modifyName (Employee* pEmployee)
{
	int status = -1;
	char auxiliarName[NAME_AND_LASTNAME_LEN];

	if (pEmployee != NULL)
	{
		if (input_getText(auxiliarName, NAME_AND_LASTNAME_LEN, 2, "Ingrese el nombre", "Error") == 1)
		{
			strncpy(pEmployee->name, auxiliarName, NAME_AND_LASTNAME_LEN);
			status = 1;
		}
	}
	return status;
}

int employee_modifyLastName (Employee* pEmployee)
{
	int status = -1;
	char auxiliarLastName[NAME_AND_LASTNAME_LEN];

	if (pEmployee != NULL)
	{
		if (input_getText(auxiliarLastName, NAME_AND_LASTNAME_LEN, 2, "Ingrese el apellido", "Error") == 1)
		{
			strncpy(pEmployee->lastName, auxiliarLastName, NAME_AND_LASTNAME_LEN);
			status = 1;
		}
	}
	return status;
}

int employee_modifySalary (Employee* pEmployee)
{
	int status = -1;
	float auxiliarSalary;

	if (pEmployee != NULL)
	{
		if (input_getFloat(10000, 300000, 2, "Ingrese el salario", &auxiliarSalary, "Error") == 1)
		{
			pEmployee->salary = auxiliarSalary;
			status = 1;
		}
	}
	return status;
}

int employee_modifySector (Employee* pEmployee)
{
	int status = -1;
	int auxiliarSector;

	if (pEmployee != NULL)
	{
		if (input_getInt(1, 3, 2, "Ingrese el sector", &auxiliarSector, "Error") == 1)
		{
			pEmployee->sector = auxiliarSector;
			status = 1;
		}
	}
	return status;
}

/*int sortEmployees(Employee list[], int len, int order)
{
	int status = -1;
	int index;
	if (list != NULL && len > 0 && order > -1 && order < 2)
	{
		for (index = 0; index < len; index++)
		{

		}
	}


	return status;
}*/

