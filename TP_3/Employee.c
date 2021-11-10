#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "myStr.h"
#include "LinkedList.h"

#define NAME_LEN 128

//privates prototypes
static int validateId (int id);

Employee* employee_new()
{
	Employee* pEmployee = malloc(sizeof(Employee));

	return pEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pEmployee = employee_new();

	int internalStatus;
	int id;
	int workedHours;
	int salary;

	if (myStrIsOnlyNumbers(idStr, &internalStatus) == 1)
	{
		id = atoi(idStr);
		if (validateId(id) == 1)
		{
			if (myStrIsOnlyText(nombreStr, &internalStatus) == 1)
			{
				if (myStrIsOnlyNumbers(horasTrabajadasStr, &internalStatus) == 1)
				{
					workedHours = atoi(horasTrabajadasStr);
					if (myStrIsOnlyNumbers(sueldoStr, &internalStatus) == 1)
					{
						salary = atoi(sueldoStr);

						employee_setId(pEmployee, id);
						employee_setNombre(pEmployee, nombreStr);
						employee_setSueldo(pEmployee, salary);
						employee_setHorasTrabajadas(pEmployee, workedHours);
					}

				}
			}
		}
	}
	return pEmployee;
}

static int validateId (int id)
{
	int status = -1;

	if (id > 0)
	{
		status = 1;
	}

	return status;
}

int employee_findById(LinkedList* listOfEmployees, int id)
{
	int foundPosition = -1;
	int listIndex;
	int listLen;
	int idToCompare;
	Employee* pEmployee;

	if (listOfEmployees != NULL && id > 0)
	{
		listLen = ll_len(listOfEmployees);

		for (listIndex = 0; listIndex < listLen; listIndex++)
		{
			pEmployee = ll_get(listOfEmployees, listIndex);

			if (employee_getId(pEmployee, &idToCompare) == 1)
			{
				if (idToCompare == id)
				{
					foundPosition = listIndex;
					break;
				}
			}
		}
	}
	return foundPosition;
}

int employee_setId(Employee* this,int id)
{
	int status = -1;

	if (this != NULL)
	{
		this->id = id;
		status = 1;
	}
	return status;
}

int employee_getId(Employee* this,int* id)
{
	int status = -1;

	if (this != NULL)
	{
		*id = this->id;
		status = 1;
	}
	return status;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int status = -1;

	if (this != NULL)
	{
		strncpy(this->nombre, nombre, NAME_LEN);
		status = 1;
	}
	return status;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int status = -1;

	if (this != NULL)
	{
		strncpy(nombre, this->nombre, NAME_LEN);
		status = 1;
	}
	return status;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int status = -1;

	if (this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		status = 1;
	}
	return status;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int status = -1;

	if (this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		status = 1;
	}
	return status;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int status = -1;

	if (this != NULL)
	{
		this->sueldo = sueldo;
		status = 1;
	}
	return status;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int status = -1;

	if (this != NULL)
	{
		*sueldo = this->sueldo;
		status = 1;
	}
	return status;
}

void employee_delete(Employee* this)
{
	if (this != NULL)
	{
		free(this);
	}
}

void employee_printList(LinkedList* listOfEmployees)
{
	int listLen;
	int index;
	Employee* pEmployee;
	int id;
	char name[NAME_LEN];
	int hours;
	int salary;

	listLen = ll_len(listOfEmployees);

	for (index = 0; index < listLen; index++)
	{
		pEmployee = ll_get(listOfEmployees, index);

		if (pEmployee != NULL)
		{
			employee_getId(pEmployee, &id);
			employee_getNombre(pEmployee, name);
			employee_getHorasTrabajadas(pEmployee, &hours);
			employee_getSueldo(pEmployee, &salary);

			printf("\n---------------EMPLEADO---------------");
			printf("\nID: %d", id);
			printf("\nNOMBRE: %s", name);
			printf("\nHORAS TRABAJADAS: %d", hours);
			printf("\nSUELDO: %d", salary);
			printf("\n--------------------------------------");
		}
	}
}

void employee_print (Employee* pEmployee)
{
	int id;
	char name[NAME_LEN];
	int hours;
	int salary;

	if (pEmployee != NULL)
	{
		employee_getId(pEmployee, &id);
		employee_getNombre(pEmployee, name);
		employee_getHorasTrabajadas(pEmployee, &hours);
		employee_getSueldo(pEmployee, &salary);

		printf("\n---------------EMPLEADO---------------");
		printf("\nID: %d", id);
		printf("\nNOMBRE: %s", name);
		printf("\nHORAS TRABAJADAS: %d", hours);
		printf("\nSUELDO: %d", salary);
		printf("\n--------------------------------------");
	}
}

int employee_sort(void* firstItem, void* secondItem)
{
	int value = 0;
	Employee* firstEmployee;
	Employee* secondEmployee;
	int firstSalary;
	int secondSalary;
	firstEmployee = (Employee*) firstItem;
	secondEmployee = (Employee*) secondItem;

	if (employee_getSueldo(firstEmployee, &firstSalary) == 1 && employee_getSueldo(secondEmployee, &secondSalary) == 1)
	{
		if (firstSalary > secondSalary)
		{
			value = 1;
		}
		else if (secondSalary > firstSalary)
		{
			value = -1;
		}
	}
	return value;
}





