#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"
#include "menu.h"
#include "idFactory.h"

#define NAME_LEN 128

//private prototypes
static Employee* selectEmployee (LinkedList* pArrayListEmployee);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int status = -1;
	FILE* file;

	file = fopen(path, "r");

	if (parser_EmployeeFromText(file, pArrayListEmployee) == 1)
	{
		fclose(file);
		employee_printList(pArrayListEmployee);
		status = 1;
	}

	return status;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int status = -1;
	FILE* file;

	file = fopen(path, "r");

	if (parser_EmployeeFromBinary(file, pArrayListEmployee) == 1)
	{
		fclose(file);
		employee_printList(pArrayListEmployee);
		status = 1;
	}

	return status;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int maxId, char* path)
{
	int status = -1;
	Employee* pEmployee;
	char name[NAME_LEN];
	int hours;
	int salary;
	int id;

	if (pArrayListEmployee != NULL)
	{
		pEmployee = employee_new();

		if (pEmployee != NULL)
		{
			if (input_getText(name, NAME_LEN, 2, "Ingrese el nombre", "Error") == 1)
			{
				if (input_getInt(20, 220, 2, "Ingrese horas trabajadas", &hours, "Error") == 1)
				{
					if (input_getInt(10000, 300000, 2, "Ingrese salario", &salary, "Error") == 1)
					{
						printf("\nDatos ingresados correctamente");

						id = idFactory_getNewId(maxId, path);
						employee_setId(pEmployee, id);

						employee_setNombre(pEmployee, name);
						employee_setHorasTrabajadas(pEmployee, hours);
						employee_setSueldo(pEmployee, salary);
						employee_print(pEmployee);
						ll_add(pArrayListEmployee, pEmployee);
						status = 1;
					}
				}
			}
		}
	}
    return status;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int status = -1;
    int selectedOption;
    char name[NAME_LEN];
	int hours;
	int salary;
    Employee* pEmployee;

    if (pArrayListEmployee != NULL)
    {
    	pEmployee = selectEmployee(pArrayListEmployee);

    	if (pEmployee != NULL)
    	{
    		menu_printEditMenu();
    		if (input_getInt(1, 3, 2, "Elija la opcion", &selectedOption, "Error") == 1)
			{
				switch (selectedOption)
				{
					case 1:
						if (input_getText(name, NAME_LEN, 2, "Ingrese el nombre", "Error") == 1)
						{
							employee_setNombre(pEmployee, name);
						}
						break;
					case 2:
						if (input_getInt(20, 220, 2, "Ingrese horas trabajadas", &hours, "Error") == 1)
						{
							employee_setHorasTrabajadas(pEmployee, hours);
						}
						break;
					case 3:
						if (input_getInt(10000, 300000, 2, "Ingrese salario", &salary, "Error") == 1)
						{
							employee_setSueldo(pEmployee, salary);
						}
						break;
				}
				printf("\nEmpleado modificado correctamente");
				employee_print(pEmployee);
				status = 1;
			}
    		else
    			printf("\nError al seleccionar opcion a modificar");
    	}
    	else
    		printf("\nEl empleado con id indicado no existe");
    }
    return status;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int status = -1;
    Employee* pEmployee;
    int index;

    if (pArrayListEmployee != NULL)
    {
    	pEmployee = selectEmployee(pArrayListEmployee);

    	if (pEmployee != NULL)
    	{
    		employee_delete(pEmployee);
    		index = ll_indexOf(pArrayListEmployee, pEmployee);
    		ll_remove(pArrayListEmployee, index);
    		printf("\nEmpleado eliminado correctamente");
    		status = 1;
    	}
    	else
    		printf("\nEl empleado con id indicado no existe");
    }
    return status;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int status = -1;

	if (pArrayListEmployee != NULL)
	{
		employee_printList(pArrayListEmployee);
		status = 1;
	}

	return status;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int status = -1;

    if (pArrayListEmployee != NULL)
    {
    	if (ll_sort(pArrayListEmployee, employee_sort, 0) == 0)
    	{
    		employee_printList(pArrayListEmployee);
    	}
    	status = 1;
    }

    return status;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int status = -1;
    FILE* file;

	file = fopen(path, "w");

    if (pArrayListEmployee != NULL)
    {
    	if (parser_TextFromEmployee(file, pArrayListEmployee) == 1)
    	{
    		fclose(file);
    		printf("\nDatos guardados correctamente");
    		status = 1;
    	}
    }
    return status;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int status = -1;
	FILE* file;

	file = fopen(path, "w");

	if (pArrayListEmployee != NULL)
	{
		if (parser_BinaryFromEmployee(file, pArrayListEmployee) == 1)
		{
			fclose(file);
			printf("\nDatos guardados correctamente");
			status = 1;
		}
	}
	return status;
}

static Employee* selectEmployee (LinkedList* pArrayListEmployee)
{
	int id;
	int index;
	Employee* pEmployee;

	if (pArrayListEmployee != NULL)
	{
		employee_printList(pArrayListEmployee);
		if (input_getInt(1, 9999999, 2, "Ingrese el ID del empleado", &id, "Error") == 1)
		{
			index = employee_findById(pArrayListEmployee, id);
			if (index != -1)
			{
				pEmployee = ll_get(pArrayListEmployee, index);
			}
		}
	}
	return pEmployee;
}

int controller_CheckIfBinaryFileExists(char* path)
{
	int exists = -1;

	FILE* pFile = fopen(path, "r");
	if (pFile != NULL)
	{
		exists = 1;
	}
	return exists;
}

int controller_ConfirmLossEmployeesInFile(void)
{
	int lossThem = 1;
	int answer;
	char message[100];

	strncpy(message, "Si no se carga la lista se perderan aquellos empleados. ¿Desea guardar de todas formas?\n0.NO\n1.SI", 100);

	if (input_getInt(0, 1, 2, message, &answer, "Error") == 1)
	{
		if (answer == 0)
		{
			lossThem = -1;
		}
	}
	return lossThem;
}

