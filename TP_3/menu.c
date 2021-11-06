/*
 * menu.c
 *
 *  Created on: 6 nov. 2021
 *      Author: leandro
 */


#include <stdio.h>
#include <stdlib.h>
#include "input.h"

void menu_printMainMenu (void)
{
	printf("\n");
	printf("\n----------------MENU----------------");
	printf("\n1. CARGAR EMPLEADOS MODO TEXTO");
	printf("\n2. CARGAR EMPLEADOS MODO BINARIO");
	printf("\n3. ALTA DE EMPLEADO");
	printf("\n4. MODIFICAR EMPLEADO");
	printf("\n5. BAJA DE EMPLEADO");
	printf("\n6. LISTAR EMPLEADOS");
	printf("\n7. ORDENAR EMPLEADOS");
	printf("\n8. GUARDAR EMPLEADOS MODO TEXTO");
	printf("\n9. GUARDAR EMPLEADOS MODO BINARIO");
	printf("\n10. SALIR");
	printf("\n------------------------------------");
}

void menu_printEditMenu (void)
{
	printf("\n");
	printf("\n------------------------------------");
	printf("\n1. MODIFICAR NOMBRE");
	printf("\n2. MODIFICAR HORAS TRABAJADAS");
	printf("\n3. MODIFICAR SUELDO");
	printf("\n------------------------------------");
}

int menu_selectAnOption (int* selectedOption, int minValue, int maxValue)
{
	int status = -1;
	int auxiliarSelectedOption;

	if (input_getInt(minValue, maxValue, 2, "->Seleccione una opcion", &auxiliarSelectedOption, "Error") == 1)
	{
		status = 1;
		*selectedOption = auxiliarSelectedOption;
	}
	return status;
}
