/*
 * perrito.c
 *
 *  Created on: Nov 25, 2021
 *      Author: user
 */

#include "perrito.h"

int perrito_filtrarPerritos(void* pElement)
{
	int retorno = -1;
	ePerrito* pPerrito = (ePerrito*)pElement;

	if(pElement != NULL)
	{

	}
	return retorno;
}

int perrito_getUltimoId(void)
{
	int ultimoId = -1;
	char ultimoIdStr[100];

	FILE* pFile = fopen("ultimoId.txt", "r");

	if(pFile != NULL)
	{
		fscanf(pFile, "%[^\n]", ultimoIdStr);
		ultimoId = atoi(ultimoIdStr);
	}
	fclose(pFile);

	return ultimoId;
}

int perrito_setUltimoId(int ultimoId)
{
	int retorno = -1;

	FILE* pFile = fopen("ultimoId.txt", "w");

	if(pFile != NULL)
	{
		fprintf(pFile, "%d \n", ultimoId);
		retorno = 0;
	}
	fclose(pFile);

	return retorno;
}


int perrito_sortByName(void* perrito1,void* perrito2)
{
	int retorno;
	ePerrito* perritoAux1 = (ePerrito*)perrito1;
	ePerrito* perritoAux2 = (ePerrito*)perrito2;
	char nombre1[128];
	char nombre2[128];

	if(perrito1 != NULL && perrito2 != NULL && perritoAux1 != NULL && perritoAux2 != NULL)
	{
		if(perrito_getNombre(perritoAux1, nombre1) == 0 && perrito_getNombre(perritoAux2, nombre2) == 0 )
		{
			retorno = strcmp(nombre1, nombre2);

			if(retorno < 0)
			{
				retorno = -1;
			}
			else if(retorno > 0)
			{
				retorno = 1;
			}
		}
	}

	return retorno;
}

int employee_sortByEdad(void* perrito1, void* perrito2)
{
	int retorno = 0;
	ePerrito* perritoAux1 = (ePerrito*)perrito1;
	ePerrito* perritoAux2 = (ePerrito*)perrito2;
	int edad1;
	int edad2;

	if(perritoAux1 != NULL && perritoAux2 != NULL)
	{
		if(perrito_getEdad(perritoAux1, &edad1) == 0 && perrito_getEdad(perritoAux2, &edad2) == 0)
		{
			if(edad1 > edad2)
			{
				retorno = 1;
			}
			else if(edad1 < edad2)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}


void perrito_printTopMenu(void)
{
	input_limpiarPantalla();
	printf("%-6s %-20s %-10s %-10s %-20s\n"
			"--------------------------------------------------------- \n","ID", "Nombre", "peso", "Edad", "Raza");
}

void perrito_printPerrito(ePerrito perrito)
{
	printf("%-6d %-20s %-10.2f %-10d %-20s \n", perrito.id, perrito.nombre, perrito.peso, perrito.edad, perrito.raza);
}

ePerrito* perrito_newParametros(char* idStr,char* nombreStr, char* pesoStr, char* edadStr, char* razaStr)
{
	ePerrito* perritoAux = NULL;
	int id;
	int peso;
	int edad;

	if(idStr != NULL && nombreStr != NULL && pesoStr != NULL && edadStr != NULL && razaStr != NULL)
	{
		perritoAux = perrito_new();

		if(perritoAux != NULL)
		{
			id = atoi(idStr);
			peso = atof(pesoStr);
			edad = atoi(edadStr);

			perrito_setId(perritoAux, id);
			perrito_setNombre(perritoAux, nombreStr);
			perrito_setPeso(perritoAux, peso);
			perrito_setEdad(perritoAux, edad);
			perrito_setRaza(perritoAux, razaStr);
		}
	}

	return perritoAux;
}

void perrito_delete(ePerrito* this)
{
	if(this != NULL)
	{
		free(this);
		this = NULL;
	}
}

ePerrito* perrito_new()
{
	return (ePerrito*) malloc(sizeof(ePerrito));
}

int perrito_setId(ePerrito* this,int id)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int perrito_getId(ePerrito* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int perrito_setPeso(ePerrito* this,int peso)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->peso = peso;
		retorno = 0;
	}
	return retorno;
}

int perrito_getPeso(ePerrito* this,int* peso)
{
	int retorno = -1;

	if(this != NULL && peso != NULL)
	{
		*peso = this->peso;
		retorno = 0;
	}
	return retorno;
}

int perrito_setNombre(ePerrito* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

int perrito_getNombre(ePerrito* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}


int perrito_setEdad(ePerrito* this,int edad)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->edad = edad;
		retorno = 0;
	}
	return retorno;
}

int perrito_getEdad(ePerrito* this,int* edad)
{
	int retorno = -1;

	if(this != NULL && edad != NULL)
	{
		*edad = this->edad;
		retorno = 0;
	}
	return retorno;
}

int perrito_setRaza(ePerrito* this,char* raza)
{
	int retorno = -1;

	if(this != NULL && raza != NULL)
	{
		strcpy(this->raza, raza);
		retorno = 0;
	}
	return retorno;
}

int perrito_getRaza(ePerrito* this,char* raza)
{
	int retorno = -1;

	if(this != NULL && raza != NULL)
	{
		strcpy(raza, this->raza);
		retorno = 0;
	}
	return retorno;
}

















