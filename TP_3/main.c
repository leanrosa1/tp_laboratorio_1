#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

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

    LinkedList* employeesList = ll_newLinkedList();

    do{
    	menu_printMainMenu();
    	if (menu_selectAnOption(&selectedOption, 1, 10) == 1)
    	{
    		switch(selectedOption)
			{
				case 1:
					printf("\nCargar empleados texto");
					//controller_loadFromText("data.csv",employeesList);
					break;
				case 2:
					printf("\nCargar empleados binario");
					//controller_loadFromText("data.csv",employeesList);
					break;
				case 3:
					printf("\nAlta empleado");
					//controller_loadFromText("data.csv",employeesList);
					break;
				case 4:
					printf("\nModificar empleado");
					//controller_loadFromText("data.csv",employeesList);
					break;
				case 5:
					printf("\nBaja empleado");
					//controller_loadFromText("data.csv",employeesList);
					break;
				case 6:
					printf("\nListar empleados");
					//controller_loadFromText("data.csv",employeesList);
					break;
				case 7:
					printf("\nOrdernar empleados");
					//controller_loadFromText("data.csv",employeesList);
					break;
				case 8:
					printf("\nGuardar empleados texto");
					//controller_loadFromText("data.csv",employeesList);
					break;
				case 9:
					printf("\nGuardar empleados binario");
					//controller_loadFromText("data.csv",employeesList);
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

