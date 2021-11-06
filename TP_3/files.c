/*
 * files.c
 *
 *  Created on: 6 nov. 2021
 *      Author: leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int files_loadEmployeesFromBinary (FILE* file, LinkedList* employeesList)
{
	int status = -1;
	Employee* auxEmployee;

	if (file != NULL && employeesList != NULL)
	{
		do
		{
			auxEmployee = employee_new();
			status = 1;

			if (fread(auxEmployee, sizeof(Employee), 1, file) == 1)
			{
				ll_add(employeesList, auxEmployee);
			}
			else
			{
				employee_delete(auxEmployee);
				break;
			}
		} while (feof(file) == 0);
	}
	return status;
}

int files_loadEmployeesFromText (FILE* file, LinkedList* employeesList)
{
	int status = -1;
	Employee* auxEmployee;
	char id[16];
	char name[128];
	char hours[16];
	char salary[16];

	if (file != NULL && employeesList != NULL)
	{
		fscanf(file, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, hours, salary);

		do
		{
			status = 1;

			if (fscanf(file, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, hours, salary) == 4)
			{
				auxEmployee = employee_newParametros(id, name, hours, salary);
				if (auxEmployee != NULL)
				{
					ll_add(employeesList, auxEmployee);
				}
			}
			else
			{
				employee_delete(auxEmployee);
				break;
			}
		} while (feof(file) == 0);
	}
	return status;
}

int files_saveEmployeesBinaryMode (FILE* file, LinkedList* employeesList)
{
	Employee* auxEmployee;
	int status = -1;
	int listLen;
	int index;

	if (file != NULL && employeesList != NULL)
	{
		listLen = ll_len(employeesList);
		status = 1;

		for (index = 0; index < listLen; index++)
		{
			auxEmployee = ll_get(employeesList, index);

			if (auxEmployee != NULL)
			{
				fwrite(auxEmployee, sizeof(Employee), 1, file);
			}
		}
	}
	return status;
}

int files_saveEmployeesTextMode (FILE* file, LinkedList* employeesList)
{
	Employee* auxEmployee;
	int status = -1;
	int listLen;
	int index;

	if (file != NULL && employeesList != NULL)
	{
		listLen = ll_len(employeesList);
		status = 1;
		fprintf(file, "id,nombre,horasTrabajadas,sueldo\n");

		for (index = 0; index < listLen; index++)
		{
			auxEmployee = ll_get(employeesList, index);

			if (auxEmployee != NULL)
			{
				fprintf(file, "%d,%s,%d,%d\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
			}
		}
	}

	return status;
}
