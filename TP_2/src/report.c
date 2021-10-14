/*
 * report.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "menu.h"
#include "input.h"

static float calculateAverageSalary (float salaries, int quantityOfEmployees);
static int calculateEmployeesOverAverageSalary (Employee employeeList[], int listLen, float averageSalary);
static void printReports (float totalSalaries, float averageSalary, int employeesOverAverageSalary);

int reportSalaries (Employee employeeList[], int listLen)
{
	int status = -1;
	int index;
	float totalSalaries = 0;
	int employeesCounter = 0;
	float averageSalary;
	int employeesOverAverageSalary;

	if (employeeList != NULL && listLen > 0)
	{
		for (index = 0; index < listLen; index++)
		{
			if (employeeList[index].isEmpty != 1)
			{
				totalSalaries += employeeList[index].salary;
				employeesCounter++;
			}
		}
		averageSalary = calculateAverageSalary(totalSalaries, employeesCounter);
		employeesOverAverageSalary = calculateEmployeesOverAverageSalary(employeeList, listLen, averageSalary);
		printReports(totalSalaries, averageSalary, employeesOverAverageSalary);
		status = 1;
	}
	return status;
}

static float calculateAverageSalary (float salaries, int quantityOfEmployees)
{
	float averageSalary;
	averageSalary = salaries / quantityOfEmployees;
	return averageSalary;
}

static int calculateEmployeesOverAverageSalary (Employee employeeList[], int listLen, float averageSalary)
{
	int quantityOfEmployees = 0;
	int index;

	for (index = 0; index < listLen; index++)
	{
		if (employeeList[index].isEmpty != 1)
		{
			if (employeeList[index].salary > averageSalary)
			{
				quantityOfEmployees++;
			}
		}
	}
	return quantityOfEmployees;
}

static void printReports (float totalSalaries, float averageSalary, int employeesOverAverageSalary)
{
	printf("\n----------------------------------------------------------------------");
	printf("\nEl total de salarios es: %f", totalSalaries);
	printf("\nEl promedio de salarios es: %f", averageSalary);
	printf("\nLa cantidad de empleados que superan el salario promedio es: %d", employeesOverAverageSalary);
	printf("\n----------------------------------------------------------------------");
}
