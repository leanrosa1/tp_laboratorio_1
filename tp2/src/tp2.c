/*
 ============================================================================
 Name        : tp2.c
 Author      : Leandro Rosa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "menu.h"
#include "input.h"
#include "report.h"
#define EMPLOYEES_LIST_LEN 1000
#define NAME_AND_LASTNAME_LEN 51

int main(void) {

	setbuf(stdout,NULL);
	Employee employeesList[EMPLOYEES_LIST_LEN];
	int selectedOption;
	int quantityOfEmployees = 0;

	employee_initEmployees(employeesList, EMPLOYEES_LIST_LEN);
	do
	{
		menu_printMainMenu();
		if (menu_selectAnOption(&selectedOption, 1, 5) == 1)
		{
			switch (selectedOption)
			{
				case 1:
					if (menu_optionOne(employeesList) == 1)
						quantityOfEmployees++;
					break;
				case 2:
					menu_optionTwo(employeesList, quantityOfEmployees);
					break;
				case 3:
					if (menu_optionThree(employeesList, quantityOfEmployees) == 1)
						quantityOfEmployees--;
					break;
				case 4:
					menu_optionFour(employeesList, quantityOfEmployees);
					break;
				case 5:
					printf("\nFinalizando programa...");
					break;
			}
		}
		else
		{
			printf("\nError al elegir la opción. Finalizando programa...");
			exit(0);
		}
	} while (selectedOption != 5);
	return EXIT_SUCCESS;
}
