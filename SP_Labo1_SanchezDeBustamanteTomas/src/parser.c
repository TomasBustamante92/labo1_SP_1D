
#include "parser.h"


int parser_PerritosFromText(FILE* pFile , LinkedList* pArrayListPerritos)
{
	int retorno = 0;
	char id[10];
	char nombre[128];
	char peso[128];
	char edad[10];
	char raza[128];
	ePerrito* pPerrito = NULL;

	if(pFile != NULL && pArrayListPerritos != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", id, nombre, peso, edad, raza);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]", id, nombre, peso, edad, raza);
			pPerrito = perrito_newParametros(id, nombre, peso, edad, raza);

			if(feof(pFile))
			{
				break;
			}
			ll_add(pArrayListPerritos, pPerrito);
			pPerrito = NULL;
		}

		retorno = 1;
	}

    return retorno;
}


int parser_PerritoFromBinary(FILE* pFile , LinkedList* pArrayListPerritos)
{
	int retorno = 0;
	ePerrito* pPerrito = NULL;


	if(pFile != NULL && pArrayListPerritos != NULL)
	{
		while(!feof(pFile))
		{
			fread(pPerrito, sizeof(ePerrito), 1, pFile);
			pPerrito = perrito_new();

			if(feof(pFile))
			{
				break;
			}
			ll_add(pArrayListPerritos, pPerrito);
			pPerrito = NULL;
		}

		retorno = 1;
	}

    return retorno;
}


int parser_PerritoToText(FILE* pFile , LinkedList* pArrayListPerritos)
{
	int retorno = 0;
	int i;
	int len = ll_len(pArrayListPerritos);
	ePerrito* pPerrito = NULL;
	int id;
	char nombre[128];
	float peso;
	int edad;
	char raza[128];
	float cantidadComidaRacion;

	if(pFile != NULL && pArrayListPerritos != NULL && len > 0)
	{
		fprintf(pFile, "%s,%s,%s,%s,%s,%s\n", "ID", "Nombre", "Peso", "Edad", "Raza","cantidadComidaRacion");
		for(i=0 ; i<len ; i++)
		{
			pPerrito = (ePerrito*)ll_get(pArrayListPerritos, i);

			perrito_getId(pPerrito, &id);
			perrito_getNombre(pPerrito, nombre);
			perrito_getPeso(pPerrito, &peso);
			perrito_getEdad(pPerrito, &edad);
			perrito_getRaza(pPerrito, raza);
			perrito_getCantidadComidaRacion(pPerrito, &cantidadComidaRacion);

			fprintf(pFile, "%d,%s,%f,%d,%s,%f\n", id, nombre, peso, edad, raza, cantidadComidaRacion);
			pPerrito = NULL;
		}

		retorno = 1;
	}

    return retorno;
}


int parser_PerritoToBinary(FILE* pFile , LinkedList* pArrayListPerritos)
{
	int retorno = 0;
	int i;
	int len = ll_len(pArrayListPerritos);
	ePerrito* pPerrito;

	if(pFile != NULL && pArrayListPerritos != NULL && len > 0)
	{
		for(i=0 ; i<len ; i++)
		{
			pPerrito = (ePerrito*)ll_get(pArrayListPerritos, i);
			fwrite(pPerrito, sizeof(ePerrito), 1, pFile);
			pPerrito = NULL;
		}

		retorno = 1;
	}

    return retorno;
}
