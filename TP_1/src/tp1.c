/*
 ============================================================================
 Name        : tp1.c
 Author      : Leandro Rosa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "mathFunctions.h"
#include "input.h"
#include "menuFunctions.h"

int main(void) {
	setbuf(stdout, NULL);
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	int estadoDivision;
	int resultadoFactorial;
	int estadoFactorial;
	int opcionElegida;
	float primerOperando;
	float segundoOperando;
	int primerOperandoFueIngresado = 0;
	int segundoOperandoFueIngresado = 0;
	int operacionesFueronCalculadas = 0;
	int resultadosFueronMostrados = 0;

	do
	{
		imprimirMenu(primerOperandoFueIngresado, segundoOperandoFueIngresado, primerOperando, segundoOperando);
		if(input_pedirNumeroInt(1, 5, 2, "\nElija la opción\n", &opcionElegida, "Error") == 1)
		{
			switch (opcionElegida)
			{
			case 1:
				if (primerOperandoFueIngresado == 1)
				{
					printf("\nYa ingresaste el primer operando. Este es %f\n", primerOperando);
				}
				else
				{
					if (input_pedirNumeroFloatSinRango("\nIngrese el primer operando", "Error",
							2, &primerOperando) == 0)
					{
						printf("\nDemasiados errores. Finalizando programa...");
						exit(0);
					}
					printf("\nIngresaste %f", primerOperando);
					primerOperandoFueIngresado = 1;
				}
				break;
			case 2:
				if (segundoOperandoFueIngresado == 1)
				{
					printf("\nYa ingresaste el segundo operando. Este es %f\n", segundoOperando);
				}
				else
				{
					if (input_pedirNumeroFloatSinRango("\nIngrese el segundo operando", "Error",
							2, &segundoOperando) != 1)
					{
						printf("\nDemasiados errores. Finalizando programa...");
						exit(0);
					}
					printf("\n Ingresaste %f", segundoOperando);
					segundoOperandoFueIngresado = 1;
				}
				break;
			case 3:
				if (primerOperandoFueIngresado == 0 || segundoOperandoFueIngresado == 0)
				{
					printf("\nNo se pueden realizar los cálculos sin ingresar ambos operandos\n");
				}
				else
				{
					if(operacionesFueronCalculadas == 1)
					{
						printf("\nYa calculaste las operaciones. Presione 4 para informar resultados\n");
					}
					else
					{
						resultadoSuma = mathFunctions_sumarDosNumeros(primerOperando, segundoOperando);
						resultadoResta = mathFunctions_restarDosNumeros(primerOperando, segundoOperando);
						resultadoMultiplicacion = mathFunctions_multiplicarDosNumeros(primerOperando, segundoOperando);
						estadoDivision = mathFunctions_division(primerOperando, segundoOperando, &resultadoDivision);
						estadoFactorial = mathFunctions_calcularFactorial(primerOperando, &resultadoFactorial);
						operacionesFueronCalculadas = 1;
						printf("\nLas operaciones fueron calculadas\n");
					}
				}
				break;
			case 4:
				if (operacionesFueronCalculadas == 0)
				{
					printf("\nNo se pueden informar los resultados porque no fueron calculadas las operaciones\n");
				}
				else
				{
					printf("\nEl resultado de la suma es: %f", resultadoSuma);
					printf("\nEl resultado de la resta es: %f", resultadoResta);
					printf("\nEl resultado de la multiplicación es: %f", resultadoMultiplicacion);
					if(estadoDivision == 1)
					{
						printf("\nEl resultado de la división es: %f", resultadoDivision);
					}
					else
					{
						printf("\nNo fue posible calcular la división ya que intentaste dividir por 0");
					}
					if (estadoFactorial == 1)
					{
						printf("\nEl factorial de %f es:  %d", primerOperando, resultadoFactorial);
					}
					else
					{
						printf("\nNo es posible calcular el factorial de un número con parte fraccionaria distinta de 0");
					}
					printf("\n\n¡Gracias por utilizar nuestro programa!");
					resultadosFueronMostrados = 1;
				}
				break;
			case 5:
				printf("\n\n¡Gracias por utilizar nuestro programa!");
				break;
			}
		}
		else
		{
			printf("\nDemasiados errores. Finalizando programa...");
			exit(0);
		}
	} while(opcionElegida != 5 && resultadosFueronMostrados != 1);
	return EXIT_SUCCESS;
}



