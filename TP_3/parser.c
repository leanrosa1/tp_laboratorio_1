#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

#define NAME_LEN 128

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int status = -1;
	Employee* auxEmployee;
	char id[16];
	char name[128];
	char hours[16];
	char salary[16];

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, hours, salary);

		do
		{
			status = 1;

			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, hours, salary) == 4)
			{
				auxEmployee = employee_newParametros(id, name, hours, salary);
				if (auxEmployee != NULL)
				{
					ll_add(pArrayListEmployee, auxEmployee);
				}
			}
			else
			{
				employee_delete(auxEmployee);
				break;
			}
		} while (feof(pFile) == 0);
	}
	return status;
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
	int status = -1;
	Employee* auxEmployee;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			auxEmployee = employee_new();
			status = 1;

			if (fread(auxEmployee, sizeof(Employee), 1, pFile) == 1)
			{
				ll_add(pArrayListEmployee, auxEmployee);
			}
			else
			{
				employee_delete(auxEmployee);
				break;
			}
		} while (feof(pFile) == 0);
	}
	return status;
}

int parser_TextFromEmployee (FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int status = -1;
	int listLen;
	int index;
	int id;
	char name[NAME_LEN];
	int hours;
	int salary;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		listLen = ll_len(pArrayListEmployee);
		status = 1;
		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

		for (index = 0; index < listLen; index++)
		{
			auxEmployee = ll_get(pArrayListEmployee, index);

			if (auxEmployee != NULL)
			{
				employee_getId(auxEmployee, &id);
				employee_getNombre(auxEmployee, name);
				employee_getHorasTrabajadas(auxEmployee, &hours);
				employee_getSueldo(auxEmployee, &salary);

				fprintf(pFile, "%d,%s,%d,%d\n", id, name, hours, salary);
			}
		}
	}
	return status;
}

int parser_BinaryFromEmployee (FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int status = -1;
	int listLen;
	int index;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		listLen = ll_len(pArrayListEmployee);
		status = 1;

		for (index = 0; index < listLen; index++)
		{
			auxEmployee = ll_get(pArrayListEmployee, index);

			if (auxEmployee != NULL)
			{
				fwrite(auxEmployee, sizeof(Employee), 1, pFile);
			}
		}
	}
	return status;
}
