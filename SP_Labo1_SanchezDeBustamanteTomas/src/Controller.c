
#include "Controller.h"


int controller_loadFromText(char* path , LinkedList* pArrayListPerritos)
{
	int retorno = 0;
	FILE* pFile = fopen(path, "r");

	if(path != NULL && pArrayListPerritos != NULL && pFile != NULL)
	{
		parser_PerritosFromText(pFile, pArrayListPerritos);
		fclose(pFile);
		retorno = 1;
	}
    return retorno;
}


int controller_ListPerritos(LinkedList* pArrayListPerritos, int opcion)
{
	int retorno = 0;
	int len = ll_len(pArrayListPerritos);
	int i;
	ePerrito* pPerrito = NULL;

	if(pArrayListPerritos != NULL && len > 0)
	{
		if(opcion == 1)
		{
			perrito_printTopMenu();
		}
		else if(opcion == 2)
		{
			perrito_printTopMenuConComida();
		}

		for(i=0 ; i<len ; i++)
		{
			pPerrito = (ePerrito*) ll_get(pArrayListPerritos, i);

			if(opcion == 1)
			{
				perrito_printPerrito(*pPerrito);
			}
			else if(opcion == 2)
			{
				perrito_printPerritoConComida(*pPerrito);
			}
		}
		retorno = 1;
	}

    return retorno;
}

int controller_sortPerritos(LinkedList* pArrayListPerritos, int opcion)
{
	int retorno = 0;

	if(pArrayListPerritos != NULL)
	{
		input_limpiarPantalla();
		printf("Cargando... \n");

		if(opcion == 1)
		{
			if(ll_sort(pArrayListPerritos, perrito_sortByName, 1) == 0)
			{
			retorno = 1;
			}
			else
			{
				input_limpiarPantalla();
				printf("Error al ordenar la lista! \n");
				input_systemPause();
			}
		}
		else if(opcion == 2)
		{
			if(ll_sort(pArrayListPerritos, perrito_sortById, 1) == 0)
			{
			retorno = 1;
			}
			else
			{
				input_limpiarPantalla();
				printf("Error al ordenar la lista! \n");
				input_systemPause();
			}
		}


	}
    return retorno;
}


int controller_saveAsText(char* path , LinkedList* pArrayListPerritos)
{
	int retorno = 0;
	FILE* pFile = fopen(path, "w");

	if(path != NULL && pArrayListPerritos != NULL && pFile != NULL)
	{
		parser_PerritoToText(pFile, pArrayListPerritos);
		fclose(pFile);
		retorno = 1;
	}
    return retorno;
}



