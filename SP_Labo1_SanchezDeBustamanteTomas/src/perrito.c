/*
 * perrito.c
 *
 *  Created on: Nov 25, 2021
 *      Author: user
 */

#include "perrito.h"

int ePerrito_laQueMapea(void* pElement)
{
	int retorno = -1;
	ePerrito* pPerrito = (ePerrito*)pElement;
	float peso;

	if(pElement != NULL)
	{
		perrito_getPeso(pPerrito, &peso);
		perrito_setCantidadComidaRacion(pPerrito, peso*23);
		retorno = 0;
	}
	return retorno;
}

int ePerrito_laQueFiltra(void* pElement)
{
	int retorno = -1;
	ePerrito* pPerrito = (ePerrito*)pElement;
	char raza[128];
	int edad;
	float comida;

	if(pElement != NULL)
	{
		perrito_getRaza(pPerrito, raza);
		perrito_getEdad(pPerrito, &edad);
		perrito_getCantidadComidaRacion(pPerrito, &comida);

		if(strcmp(raza,"Galgo") == 0 && edad > 10 && comida < 200)
		{
			retorno = 0;
		}
	}
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

int perrito_sortById(void* perrito1, void* perrito2)
{
	int retorno = 0;
	ePerrito* perritoAux1 = (ePerrito*)perrito1;
	ePerrito* perritoAux2 = (ePerrito*)perrito2;
	int id1;
	int id2;

	if(perritoAux1 != NULL && perritoAux2 != NULL)
	{
		if(perrito_getId(perritoAux1, &id1) == 0 && perrito_getId(perritoAux2, &id2) == 0)
		{
			if(id1 > id2)
			{
				retorno = 1;
			}
			else if(id1 < id2)
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

void perrito_printTopMenuConComida(void)
{
	input_limpiarPantalla();
	printf("%-6s %-20s %-10s %-10s %-10s %-20s\n"
			"--------------------------------------------------------- \n","ID", "Nombre", "peso", "Edad", "Comida", "Raza");
}

void perrito_printPerritoConComida(ePerrito perrito)
{
	printf("%-6d %-20s %-10.2f %-10d %-10.2f %-20s \n", perrito.id, perrito.nombre, perrito.peso, perrito.edad, perrito.cantidadComidaRacion, perrito.raza);
}

ePerrito* perrito_newParametros(char* idStr,char* nombreStr, char* pesoStr, char* edadStr, char* razaStr)
{
	ePerrito* perritoAux = NULL;
	int id;
	float peso;
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

int perrito_setPeso(ePerrito* this,float peso)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->peso = peso;
		retorno = 0;
	}
	return retorno;
}

int perrito_getPeso(ePerrito* this,float* peso)
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
		raza[strlen(raza)-1] = '\0';
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



int perrito_setCantidadComidaRacion(ePerrito* this,float cantidadComidaRacion)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->cantidadComidaRacion = cantidadComidaRacion;
		retorno = 0;
	}
	return retorno;
}

int perrito_getCantidadComidaRacion(ePerrito* this,float* cantidadComidaRacion)
{
	int retorno = -1;

	if(this != NULL && cantidadComidaRacion != NULL)
	{
		*cantidadComidaRacion = this->cantidadComidaRacion;
		retorno = 0;
	}
	return retorno;
}













