/*
 * idFactory.c
 *
 *  Created on: 10 nov. 2021
 *      Author: leandro
 */

#include <stdio.h>
#include <stdlib.h>

int idFactory_getMaximumId (char* idPath, char* textFilePath)
{
	int maximumId = 1000;
	FILE* pIdFile = fopen(idPath, "r");

	if (pIdFile != NULL)
	{
		fread(&maximumId, sizeof(int), 1, pIdFile);
	}

	return maximumId;
}

int idFactory_getNewId (int maxId, char* path)
{
	int newId;
	FILE* idFile;

	newId = maxId + 1;
	idFile = fopen(path, "w");

	if (idFile != NULL)
	{
		fwrite(&newId, sizeof(int), 1, idFile);
		fclose(idFile);
	}

	return newId;
}
