/*
 * mathFunctions.c
 *
 *  Created on: 7 sep. 2021
 *      Author: Leandro
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * \brief: Recibe dos números de tipo float y los suma
 * 			Retorna su resultado

 * \param primerNumero: número de tipo float
 * \param segundoNumero: número de tipo float
 * \return float suma
 */
float mathFunctions_sumarDosNumeros (float primerNumero, float segundoNumero) {
	float suma;
	suma = primerNumero + segundoNumero;
	return suma;
}

/**
 * \brief: Recibe dos números de tipo float y los resta
 * 			Retorna su resultado

 * \param primerNumero: número de tipo float
 * \param segundoNumero: número de tipo float
 * \return float resta
 */
float mathFunctions_restarDosNumeros (float primerNumero, float segundoNumero) {
	float resta;
	resta = primerNumero - segundoNumero;
	return resta;
}

/**
 * \brief: Recibe dos números de tipo float y los multiplica
 * 			Retorna su resultado

 * \param primerNumero: número de tipo float
 * \param segundoNumero: número de tipo float
 * \return float multiplicacion
 */
float mathFunctions_multiplicarDosNumeros (float primerNumero, float segundoNumero) {
	float multiplicacion;
	multiplicacion = primerNumero * segundoNumero;
	return multiplicacion;
}

/**
 * \brief: Recibe dos números de tipo float, valida que se puede realizar la división y
 * 		guarda el resultado en la dirección en memoria que recibe por parametro
 * 			Retorna 1 si fue exitosa la operación y -1 si no lo fue

 * \param primerNumero: número de tipo float
 * \param segundoNumero: número de tipo float
 * \param *pResultado: dirección en memoria donde debe guardarse el resultado (float)
 * \return int estado
 */
int mathFunctions_division (float dividendo, float divisor, float* pResultado) {
	int estado = 1;
	float division;
	if (divisor == 0) {
		estado = -1;
	} else {
		division = dividendo / divisor;
		*pResultado = division;
	}
	return estado;
}

/**
 * \brief: Recibe un número de tipo float, valida que se puede realizar operación y
 * 		guarda el resultado en la dirección en memoria que recibe por parametro
 * 			Retorna 1 si fue exitosa la operación y 0 si no lo fue

 * \param numero: número de tipo float
 * \param *pResultado: dirección en memoria donde debe guardarse el resultado (float)
 * \return int estado
 */
int mathFunctions_calcularFactorial (float numero, int* pResultado) {
	int estado = 1;
	int numeroEntero = (int)numero;
	if (numero == numeroEntero && numeroEntero > 0) {
		int multiplicador;
		long auxiliar = 1;
		for (multiplicador = 1; multiplicador <= numeroEntero; multiplicador++) {
			auxiliar = auxiliar * multiplicador;
		}
		*pResultado = auxiliar;
	} else {
		estado = 0;
	}
	return estado;
}

