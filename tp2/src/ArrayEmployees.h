/*
 * Employee.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Leandro
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
struct Employee
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
};
typedef struct Employee Employee;
int employee_initEmployees(Employee list[], int len);
int employee_addEmployee(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector);
int employee_removeEmployee(Employee* list, int len, int id);
int employee_printEmployees(Employee list[], int len);
int employee_createId (void);
int employee_findEmployeeById(Employee list[], int len, int id);
int employee_modifyName (Employee* pEmployee);
int employee_modifyLastName (Employee* pEmployee);
int employee_modifySalary (Employee* pEmployee);
int employee_modifySector (Employee* pEmployee);
#endif /* ARRAYEMPLOYEES_H_ */
