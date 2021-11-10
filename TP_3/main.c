#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"
#include "idFactory.h"

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
    int selectedOption;
    int employeesWereImported = -1;
    int hasEmployees = -1;

    LinkedList* employeesList = ll_newLinkedList();
    int maximumId = idFactory_getMaximumId("idFactory.txt", "data.csv");
    printf("\nEl id maximo es %d", maximumId);

    do{
    	menu_printMainMenu();
    	if (menu_selectAnOption(&selectedOption, 1, 10) == 1)
    	{
    		switch(selectedOption)
			{
				case 1:
					if (employeesWereImported == 1)
					{
						printf("\nYa cargaste la lista previamente");
					}
					else
					{
						if (controller_loadFromText("data.csv",employeesList) != 1)
						{
							printf("\nOcurrio un error");
						}
						else
							employeesWereImported = 1;
					}
					break;
				case 2:
					if (employeesWereImported == 1)
					{
						printf("\nYa cargaste la lista previamente");
					}
					else
					{
						if (controller_CheckIfBinaryFileExists("probando.txt") == 1)
						{
							if (controller_loadFromBinary("probando.txt", employeesList) != 1)
							{
								printf("\nOcurrio un error");
							}
							else
								employeesWereImported = 1;
						}
						else
							printf("\nNo hay nada en el archivo binario");
					}
					break;
				case 3:
					if (controller_addEmployee(employeesList, maximumId, "idFactory.txt") != 1)
					{
						printf("\nOcurrio un error");
					}
					else
						hasEmployees = 1;
					break;
				case 4:
					if (hasEmployees == 1 || employeesWereImported == 1)
					{
						if (controller_editEmployee(employeesList) != 1)
						{
							printf("\nOcurrio un error");
						}
					}
					else
						printf("\nNo hay empleados");
					break;
				case 5:
					if (hasEmployees == 1 || employeesWereImported == 1)
					{
						if (controller_removeEmployee(employeesList) != 1)
						{
							printf("\nOcurrio un error");
						}
					}
					else
						printf("\nNo hay empleados");
					break;
				case 6:
					if (hasEmployees == 1 || employeesWereImported == 1)
					{
						if (controller_ListEmployee(employeesList) != 1)
						{
							printf("\nOcurrio un error");
						}
					}
					else
						printf("\nNo hay empleados");
					break;
				case 7:
					if (hasEmployees == 1 || employeesWereImported == 1)
					{
						if (controller_sortEmployee(employeesList) != 1)
						{
							printf("\nOcurrio un error");
						}
					}
					else
						printf("\nNo hay empleados");
					break;
				case 8:
					if (hasEmployees == 1 && employeesWereImported == 1)
					{
						if (controller_saveAsText("data.csv", employeesList) != 1)
						{
							printf("\nOcurrio un error");
						}
					}
					else if (hasEmployees == 1)
					{
						if (controller_ConfirmLossEmployeesInFile() == 1)
						{
							if (controller_saveAsText("data.csv", employeesList) != 1)
							{
								printf("\nOcurrio un error");
							}
						}
					}
					else
						printf("\nNo hay empleados");
					break;
				case 9:
					if (hasEmployees == 1 && employeesWereImported == 1)
					{
						if (controller_saveAsBinary("probando.txt", employeesList) != 1)
						{
							printf("\nOcurrio un error");
						}
					}
					else if (hasEmployees == 1)
					{
						if (controller_ConfirmLossEmployeesInFile() == 1)
						{
							if (controller_saveAsBinary("probando.txt", employeesList) != 1)
							{
								printf("\nOcurrio un error");
							}
						}
					}
					else
						printf("\nNo hay empleados");
					break;
				case 10:
					printf("\nFinalizando programa...");
			}
    	}
    	else
		{
			printf("\nError al elegir la opcion. Finalizando programa...");
			exit(0);
		}
    }while(selectedOption != 10);
    return 0;
}

