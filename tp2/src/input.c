/*
 * input.c
 *
 *  Created on: 7 sep. 2021
 *      Author: Leandro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myStr.h"
#include "ArrayEmployees.h"
#define NAME_AND_LASTNAME_LEN 51

int myGetS (char pCadena[], int lenCadena);
static int input_getName (char pName[], int len);
static int input_getLastname (char pLastName[], int len);
static int input_getSalary (float* pSalary);
static int input_getSector (int* pSector);

/**
 * \brief: Pide al usuario que ingrese un número de tipo float y lo valida.
 * 			Retorna 1 si fue exitoso y 0 si no lo fue
 * \param valorMinimo: float que representa el valor mínimo que puede ingresar el usuario
 * \param valorMaximo: float que representa el valor máximo que puede ingresar el usuario
 * \param intentos: int que representa la cantidad de reintentos permitidos
 * \param mensaje: string que se imprime por consola al usuario a modo informativo
 * \param *pNumero: puntero de la dirección en memoria donde se guardará el resultado
 * \param mensajeError: string que se imprime por consola al usuario cuando se cometieron todos los intentos permitidos
 * \return 1 si fue exitoso y 0 si no lo fue
 */
int input_getFloat (float minValue, float maxValue, int retries, char message[], float* pNumber, char errorMessage[])
{
	int counter;
	char number[64];
	float auxiliar;
	int status;
	int validationResult;
	if (minValue < maxValue && pNumber != NULL && retries > 0) {
		for (counter = 0; counter <= retries; counter++)
		{
			printf("%s \n", message);
			if (myGetS(number, sizeof(number)) == 1)
			{
				myStrIsFloat(number, &validationResult);
				if (validationResult == 1)
				{
					auxiliar = atof(number);
					if (auxiliar >= minValue && auxiliar <= maxValue)
					{
						*pNumber = auxiliar;
						status = 1;
						break;
					}
					else
					{
						status = 0;
						printf("\n%s \n", errorMessage);
					}
				}
				else
				{
					status = 0;
					printf("\n%s \n", errorMessage);
				}
			} else {
				status = 0;
				printf("\n%s \n", errorMessage);
			}
		}
	} else {
		status = 0;
		printf("\nNo hay mas reintentos.");
	}
	return status;
}

/**
 * \brief: Pide al usuario que ingrese un número de tipo int y lo valida.
 * 			Retorna 1 si fue exitoso y 0 si no lo fue
 * \param valorMinimo: int que representa el valor mínimo que puede ingresar el usuario
 * \param valorMaximo: int que representa el valor máximo que puede ingresar el usuario
 * \param intentos: int que representa la cantidad de reintentos permitidos
 * \param mensaje: string que se imprime por consola al usuario a modo informativo
 * \param *pNumero: puntero de la dirección en memoria donde se guardará el resultado
 * \param mensajeError: string que se imprime por consola al usuario cuando se cometieron todos los intentos permitidos
 * \return 1 si fue exitoso y 0 si no lo fue
 */
int input_getInt (int minValue, int maxValue, int retries, char message[], int* pNumber, char messageError[]) {
	int counter;
	char number[16];
	int auxiliar;
	int status;
	int validationResult;
	if (minValue < maxValue && pNumber != NULL && retries > 0) {
		for (counter = 0; counter <= retries; counter++)
		{
			printf("\n%s \n", message);
			if (myGetS(number, sizeof(number)) == 1)
			{
				myStrIsOnlyNumbers(number, &validationResult);
				if (validationResult == 1)
				{
					auxiliar = atoi(number);
					if (auxiliar >= minValue && auxiliar <= maxValue)
					{
						*pNumber = auxiliar;
						status = 1;
						break;
					}
					else
					{
						status = -1;
						printf("\n%s \n", messageError);
					}
				}
				else
				{
					status = -1;
					printf("\n%s \n", messageError);
				}
			} else {
				status = -1;
				printf("\n%s \n", messageError);
			}
		}
	} else {
		status = -1;
		printf("\n%s \n", messageError);
	}
	return status;
}

/**
 * \brief: Pide al usuario que ingrese un número de tipo float y lo valida.
 * 			Retorna 1 si fue exitoso y 0 si no lo fue

 * \param mensaje: string que se imprime por consola al usuario a modo informativo
 * \param mensajeError: string que se imprime por consola al usuario cuando se cometieron todos los intentos permitidos
 * \param reintentos: int que representa la cantidad de reintentos permitidos
 * \param *pNumero: puntero de la dirección en memoria donde se guardará el resultado
 * \return 1 si fue exitoso y 0 si no lo fue
 */
int input_getFloatWithoutRange (char message[], char errorMessage[], int retries, float* pNumber) {
	int remainingAttempts;
	int counter;
	int status;
	float auxiliar;
	for (counter = 0; counter <= retries; counter++)
	{
		printf("\n%s \n", message);
		fflush(stdin);
		if (scanf("%f", &auxiliar) == 1) {
			*pNumber = auxiliar;
			status = 1;
			break;
		} else {
			status = 0;
			remainingAttempts = retries - counter;
			printf("Error, te quedan %d intentos", remainingAttempts);
		}
	}
	return status;
}

int input_getText (char pString[], int len, int retries, char message[], char errorMessage[]) {
	int status;
	int isOnlyText;
	int counter;

	for (counter = 0; counter <= retries; counter++)
	{
		printf("\n%s \n", message);
		fflush(stdin);
		if (myGetS(pString, len) == 1)
		{
			myStrIsOnlyText(pString, &isOnlyText);
			if (isOnlyText == 1)
			{
				status = 1;
				break;
			}
			else
			{
				printf("\nSólo se permite ingresar texto");
			}
		}
	}
	return status;
}

int myGetS (char pString[], int len)
{
	int status;
	int finalIndex;
	fflush(stdin);
	if (fgets(pString, len, stdin) != NULL) {
		finalIndex = myStrLen(pString) - 1;
		if (pString[finalIndex] == '\n')
		{
			pString[finalIndex] = '\0';
		}
		status = 1;
	} else {
		status = -1;
	}
	return status;
}

int input_getEmployeeFields (char pName[], char pLastName[], float* pSalary, int* pSector)
{
	int status = -1;
	char auxiliarName[NAME_AND_LASTNAME_LEN];
	char auxiliarLastName[NAME_AND_LASTNAME_LEN];
	float auxiliarSalary;
	int auxiliarSector;
	if (pName != NULL && pLastName != NULL && pSalary != NULL && pSector != NULL)
	{
		if (input_getName(auxiliarName, NAME_AND_LASTNAME_LEN) == 0)
		{
			if (input_getLastname(auxiliarLastName, NAME_AND_LASTNAME_LEN) == 0)
			{
				if (input_getSalary(&auxiliarSalary) == 0)
				{
					if (input_getSector(&auxiliarSector) == 0)
					{
						printf("\nLos datos fueron ingresados correctamente");
						strncpy(pName, auxiliarName, NAME_AND_LASTNAME_LEN);
						strncpy(pLastName, auxiliarLastName, NAME_AND_LASTNAME_LEN);
						*pSalary = auxiliarSalary;
						*pSector = auxiliarSector;
						status = 1;
					}
				}
			}
		}
	}
	return status;
}

static int input_getName (char pName[], int len)
{
	int status = -1;
	char auxiliarName[len];
	if (pName != NULL)
	{
		if (input_getText(auxiliarName, len, 2,"Ingrese el nombre del empleado", "Valor incorrecto") == 1)
		{
			status = 0;
			strncpy(pName, auxiliarName, len);
		}
	}
	return status;
}

static int input_getLastname (char pLastName[], int len)
{
	int status = -1;
	char auxiliarLastName[len];
	if (pLastName != NULL)
	{
		if (input_getText(auxiliarLastName, len, 2, "Ingrese el apellido del empleado", "Valor incorrecto") == 1)
		{
			status = 0;
			strncpy(pLastName, auxiliarLastName, len);
		}
	}
	return status;
}

static int input_getSalary (float* pSalary)
{
	int status = -1;
	float auxiliarSalary;
	if (pSalary != NULL)
	{
		if (input_getFloat(10000, 200000, 2, "Ingrese el salario", &auxiliarSalary, "Valor incorrecto") == 1)
		{
			status = 0;
			*pSalary = auxiliarSalary;
		}
	}
	return status;
}

static int input_getSector (int* pSector)
{
	int status = -1;
	int auxiliarSector;
	if (pSector != NULL)
	{
		if (input_getInt(1, 5, 2, "Ingrese el sector", &auxiliarSector, "Valor incorrecto") == 1)
		{
			status = 0;
			*pSector = auxiliarSector;
		}
	}
	return status;
}



