/*
 * menu.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Leandro
 */

#ifndef MENU_H_
#define MENU_H_
void menu_printMainMenu (void);
int menu_selectAnOption (int* selectedOption, int minValue, int maxValue);
void menu_printModifyMenu (void);
int menu_optionOne (Employee employeesList[]);
void menu_optionTwo (Employee employeesList[], int quantityOfEmployees);
int menu_optionThree (Employee employeesList[], int quantityOfEmployees);
void menu_optionFour (Employee employeesList[], int quantityOfEmployees);
#endif /* MENU_H_ */
