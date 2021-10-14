/*
 * menu.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "ArrayEmployees.h"
#include "report.h"

#define EMPLOYEES_LIST_LEN 1000
#define NAME_AND_LASTNAME_LEN 51

void menu_printMainMenu (void)
{
	printf("\n");
	printf("\n---MENU---");
	printf("\n1. ALTAS");
	printf("\n2. MODIFICAR");
	printf("\n3. BAJA");
	printf("\n4. INFORMAR");
	printf("\n5. SALIR");
	printf("\n----------");
}

int menu_selectAnOption (int* selectedOption, int minValue, int maxValue)
{
	int status = -1;
	int auxiliarSelectedOption;
	if (input_getInt(minValue, maxValue, 2, "Seleccione una opción", &auxiliarSelectedOption, "Error") == 1)
	{
		status = 1;
		*selectedOption = auxiliarSelectedOption;
	}
	return status;
}

void menu_printModifyMenu (void)
{
	printf("\n----------");
	printf("\n1. Nombre");
	printf("\n2. Apellido");
	printf("\n3. Salario");
	printf("\n4. Sector");
	printf("\n----------");
}

int menu_optionOne (Employee employeesList[])
{
	int status = -1;
	char employeeName[NAME_AND_LASTNAME_LEN];
	char employeeLastName[NAME_AND_LASTNAME_LEN];
	float employeeSalary;
	int employeeSector;
	int id;

	if (input_getEmployeeFields(employeeName, employeeLastName, &employeeSalary, &employeeSector) == 1)
	{
		id = employee_createId();
		if (employee_addEmployee(employeesList, EMPLOYEES_LIST_LEN, id, employeeName, employeeLastName, employeeSalary, employeeSector) == 0)
		{
			printf("\nEmpleado creado con el id: %d \n", id);
			status = 1;
		}
		else
			printf("\nNo se pudo cargar el empleado");
	}
	else
	{
		printf("\nValores incorrectos");
	}
	return status;
}

void menu_optionTwo (Employee employeesList[], int quantityOfEmployees)
{
	int id;
	int employeeIndex;
	int selectedOption;

	if (quantityOfEmployees > 0)
	{
		if (employee_printEmployees(employeesList, EMPLOYEES_LIST_LEN) == 0)
		{
			if (input_getInt(1, 9999, 2, "Ingrese id del empleado a modificar", &id, "Error") == 1)
			{
				employeeIndex = employee_findEmployeeById(employeesList, EMPLOYEES_LIST_LEN, id);
				if (employeeIndex != -1)
				{
					menu_printModifyMenu();
					if (menu_selectAnOption(&selectedOption, 1, 4) == 1)
					{
						switch (selectedOption)
						{
							case 1:
								if (employee_modifyName(&employeesList[employeeIndex]) == 1)
								{
									printf("\nNombre modificado correctamente");
								}
								break;
							case 2:
								if (employee_modifyLastName(&employeesList[employeeIndex]) == 1)
								{
									printf("\nApellido modificado correctamente");
								}
								break;
							case 3:
								if (employee_modifySalary(&employeesList[employeeIndex]) == 1)
								{
									printf("\nSalario modificado correctamente");
								}
								break;
							case 4:
								if (employee_modifySector(&employeesList[employeeIndex]) == 1)
								{
									printf("\nSector modificado correctamente");
								}
								break;
						}
					}
				}
				else
					printf("\nEl id indicado no pudo ser localizado");
			}
		}
	}
	else
		printf("\nNo hay ningún empleado para modificar");
}

int menu_optionThree (Employee employeesList[], int quantityOfEmployees)
{
	int status = -1;
	int id;

	if (quantityOfEmployees > 0)
	{
		if (employee_printEmployees(employeesList, EMPLOYEES_LIST_LEN) == 0)
		{
			if (input_getInt(1, 9999, 2, "Ingrese id del empleado a borrar", &id, "Error") == 1)
			{
				if (employee_removeEmployee(employeesList, EMPLOYEES_LIST_LEN, id) == 0)
				{
					printf("\nEmpleado dado de baja correctamente");
					status = 1;
				}
				else
					printf("\nEl id no existe");
			}
		}
	}
	else
	{
		printf("\nNo hay ningún empleado para dar de baja");
	}
	return status;
}

void menu_optionFour (Employee employeesList[], int quantityOfEmployees)
{
	if (quantityOfEmployees > 0)
	{
		if (reportSalaries(employeesList, EMPLOYEES_LIST_LEN) != 1)
			printf("\nError en los parametros enviados");
	}
}


