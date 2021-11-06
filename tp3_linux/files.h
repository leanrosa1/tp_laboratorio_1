/*
 * files.h
 *
 *  Created on: 6 nov. 2021
 *      Author: leandro
 */

#ifndef FILES_H_
#define FILES_H_
int files_saveEmployeesBinaryMode (FILE* file, LinkedList* employeesList);
int files_saveEmployeesTextMode (FILE* file, LinkedList* employeesList);

int files_loadEmployeesFromText (FILE* file, LinkedList* employeesList);
int files_loadEmployeesFromBinary (FILE* file, LinkedList* employeesList);

#endif /* FILES_H_ */
