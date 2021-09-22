/*
 * input.c
 *
 *  Created on: 7 sep. 2021
 *      Author: Leandro
 */
#include <stdio.h>
#include <stdlib.h>

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
int input_pedirNumeroFloat (float valorMinimo, float valorMaximo, int intentos, char mensaje[], float* pNumero, char mensajeError[]) {
	int contador;
	float numero;
	int estado;
	int intentosRestantes;
	int retornoScanf;
	if (valorMinimo < valorMaximo && pNumero != NULL && intentos > 0) {
		for (contador = 0; contador <= intentos; contador++) {
			printf("%s \n", mensaje);
			fflush(stdin);
			retornoScanf = scanf("%f", &numero);
			if (retornoScanf == 1 && numero >= valorMinimo && numero <= valorMaximo) {
				*pNumero = numero;
				estado = 1;
				break;
			} else {
				estado = 0;
				intentosRestantes = intentos - contador;
				printf("Numero fuera de rango o tipo de dato incorrecto. Quedan %d intentos\n", intentosRestantes);
			}
		}
	} else {
		printf("%s \n", mensajeError);
		estado = 0;
	}
	return estado;
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
int input_pedirNumeroInt (int valorMinimo, int valorMaximo, int intentos, char mensaje[], int* pNumero, char mensajeError[]) {
	int contador;
	int numero;
	int estado;
	int intentosRestantes;
	if (valorMinimo < valorMaximo && pNumero != NULL && intentos > 0) {
		for (contador = 0; contador <= intentos; contador++) {
			printf("%s \n", mensaje);
			fflush(stdin);
			scanf("%d", &numero);
			if (numero >= valorMinimo && numero <= valorMaximo) {
				*pNumero = numero;
				estado = 1;
				break;
			} else {
				estado = 0;
				intentosRestantes = intentos - contador;
				printf("Numero fuera de rango. Quedan %d intentos\n", intentosRestantes);
			}
		}
	} else {
		printf("Error. Valor mínimo mayor a valor máximo");
		estado = 0;
	}
	return estado;
}

int input_pedirCaracter (int valorMinimo, int valorMaximo, int intentos, char mensaje[], char* pNumero, char mensajeError[]) {
	int contador;
	char numero;
	int estado;
	int intentosRestantes;
	if (valorMinimo < valorMaximo && pNumero != NULL && intentos > 0) {
		for (contador = 0; contador <= intentos; contador++) {
			printf("%s \n", mensaje);
			fflush(stdin);
			scanf("%c", &numero);
			if (numero >= valorMinimo && numero <= valorMaximo) {
				*pNumero = numero;
				estado = 1;
				break;
			} else {
				estado = 0;
				intentosRestantes = intentos - contador;
				printf("Numero fuera de rango. Quedan %d intentos\n", intentosRestantes);
			}
		}
	} else {
		printf("Error. Valor mínimo mayor a valor máximo");
		estado = 0;
	}
	return estado;
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
int input_pedirNumeroFloatSinRango (char mensaje[], char mensajeError[], int reintentos, float* pNumero) {
	int intentosRestantes;
	int contador;
	int estado;
	float auxiliar;
	for (contador = 0; contador <= reintentos; contador++)
	{
		printf("%s \n", mensaje);
		fflush(stdin);
		if (scanf("%f", &auxiliar) == 1) {
			*pNumero = auxiliar;
			estado = 1;
			break;
		} else {
			estado = 0;
			intentosRestantes = reintentos - contador;
			printf("Error, te quedan %d intentos", intentosRestantes);
		}
	}
	return estado;
}

