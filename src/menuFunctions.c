/*
 * menuFunctions.c
 *
 *  Created on: 21 sep. 2021
 *      Author: Leandro
 */

#include <stdio.h>
#include <stdlib.h>

void imprimirMenuBasico (void)
{
	printf("\n//////////////////////////////////////////");
	printf("\n1. Ingresar primer operando (A = X)\n");
	printf("2. Ingresar segundo operando (B= X)\n");
	printf("3. Calcular todas las operaciones\n");
	printf("4. Informar resultados\n");
	printf("5. Salir\n");
	printf("//////////////////////////////////////////");
}

void imprimirMenuPrimerOperando (float primerOperando)
{
	printf("\n//////////////////////////////////////////");
	printf("\n1. Ingresar primer operando (A = %f)\n", primerOperando);
	printf("2. Ingresar segundo operando (B= X)\n");
	printf("3. Calcular todas las operaciones\n");
	printf("4. Informar resultados\n");
	printf("5. Salir\n");
	printf("//////////////////////////////////////////");
}

void imprimirMenuSegundoOperando (float segundoOperando)
{
	printf("\n//////////////////////////////////////////");
	printf("\n1. Ingresar primer operando (A = X)\n");
	printf("2. Ingresar segundo operando (B= %f)\n", segundoOperando);
	printf("3. Calcular todas las operaciones\n");
	printf("4. Informar resultados\n");
	printf("5. Salir\n");
	printf("//////////////////////////////////////////");
}

void imprimirMenuCompleto (float primerOperando, float segundoOperando)
{
	printf("\n//////////////////////////////////////////");
	printf("\n1. Ingresar primer operando (A = %f)\n", primerOperando);
	printf("2. Ingresar segundo operando (B= %f)\n", segundoOperando);
	printf("3. Calcular todas las operaciones\n");
	printf("4. Informar resultados\n");
	printf("5. Salir\n");
	printf("//////////////////////////////////////////");
}

void imprimirMenu (int primerOperandoFueIngresado, int segundoOperandoFueIngresado, float primerOperando, float segundoOperando)
{
	if (primerOperandoFueIngresado == 0 && segundoOperandoFueIngresado == 0)
	{
		imprimirMenuBasico();
	}
	else if (segundoOperandoFueIngresado == 0)
	{
		imprimirMenuPrimerOperando(primerOperando);
	}
	else if (primerOperandoFueIngresado == 0)
	{
		imprimirMenuSegundoOperando(segundoOperando);
	}
	else
	{
		imprimirMenuCompleto(primerOperando, segundoOperando);
	}
}
