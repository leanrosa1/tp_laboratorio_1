/*
 * input.h
 *
 *  Created on: 7 sep. 2021
 *      Author: Leandro
 */

#ifndef INPUT_H_
#define INPUT_H_

int input_pedirNumeroFloat (float valorMinimo, float valorMaximo, int intentos, char mensaje[], float* pNumero, char mensajeError[]);
int input_dividir (float dividendo, float divisor, float* pResultado);
//int input_pedirNumeroFloat (float valorMinimo, float valorMaximo, int intentos, char mensaje[], int* pNumero, char mensajeError[]);
int input_pedirCaracter (int valorMinimo, int valorMaximo, int intentos, char mensaje[], char* pNumero, char mensajeError[]);
int input_pedirNumeroInt (int valorMinimo, int valorMaximo, int intentos, char* mensaje, int* pNumero, char* mensajeError);
int input_pedirNumeroFloatSinRango (char mensaje[], char mensajeError[], int reintentos, float* pNumero);
#endif /* INPUT_H_ */
