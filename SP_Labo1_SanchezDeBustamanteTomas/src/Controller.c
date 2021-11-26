
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


int controller_loadFromBinary(char* path , LinkedList* pArrayListPerritos)
{
	int retorno = 0;
	FILE* pFile = fopen(path, "rb");

	if(path != NULL && pArrayListPerritos != NULL && pFile != NULL)
	{
		parser_PerritoFromBinary(pFile, pArrayListPerritos);
		fclose(pFile);
		retorno = 1;
	}
    return retorno;
}

/*

int controller_addPerrito(LinkedList* pArrayListPerritos)
{
	int retorno = 0;
	ePerrito* pPerrito = perrito_new();
	int id;

	if(pArrayListPerritos != NULL && pPerrito != NULL)
	{

		if(employee_requestNewEmployee(pEmployeeAux, &id) != -1)
		{
			// CONFIRMAR
			employee_printTopMenu();
			employee_printEmployee(*pEmployeeAux);
			if(input_confirmacion("Confirmar alta de empleado [si/no]: ", "ERROR. Confirmar alta de empleado [si/no]: ") != -1)
			{
				ll_add(pArrayListPerritos, pEmployeeAux);
				employee_setUltimoId(id);
				input_limpiarPantalla();
				printf("Empleado agregado con exito! \n");
				input_systemPause();
				retorno = 1;
			}
			else
			{
				input_limpiarPantalla();
				printf("Alta cancelada! \n");
				input_systemPause();
			}
		}

	}
    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int id;
	int ultimoId;
	int indice;
	int option;
	Employee* pEmployee = NULL;
	Employee employeeAux;

	if(pArrayListEmployee != NULL)
	{
		if(controller_ListEmployee(pArrayListEmployee))
		{
			ultimoId = employee_getUltimoId();

			input_getNumero(&id, "Ingrese ID a modificar: ", "ERROR. Ingrese ID a modificar: ", 1, ultimoId);

			indice = employee_searchIndex(pArrayListEmployee, &id);

			if(indice != -1)
			{
				pEmployee = ll_get(pArrayListEmployee, indice);

				if(pEmployee != NULL)
				{
					do{
						employeeAux = *pEmployee;
						employee_printTopMenu();
						employee_printEmployee(employeeAux);
						input_getNumero(&option, 	"\n\n"
													"1. Modificar Nombre \n"
													"2. Modificar horas trabajadas \n"
													"3. Modificar sueldo \n"
													"4. Atras \n"
													"- - - - - - - - - - - - - - \n"
													"Ingrese opcion: ",
													"\n\n"
													"1. Modificar Nombre \n"
													"2. Modificar horas trabajadas \n"
													"3. Modificar sueldo \n"
													"4. Atras \n"
													"- - - - - - - - - - - - - - \n"
													"ERROR. Ingrese opcion: ", 1, 4);

						switch(option)
						{
							case 1:
								employee_askName(&employeeAux);

								employee_printTopMenu();
								employee_printEmployee(employeeAux);
								if(input_confirmacion("Confirmar cambio de nombre [si/no]: ", "ERROR. Confirmar cambio de nombre [si/no]: ") != -1)
								{
									*pEmployee = employeeAux;
									input_limpiarPantalla();
									printf("Empleado modificado! \n");
									input_systemPause();
									retorno = 1;
								}

								break;
							case 2:
								employee_askHorasTrabajadas(&employeeAux);

								employee_printTopMenu();
								employee_printEmployee(employeeAux);
								if(input_confirmacion("Confirmar cambio de horas trabajadas [si/no]: ", "ERROR. Confirmar cambio de horas trabajadas [si/no]: ") != -1)
								{
									*pEmployee = employeeAux;
									input_limpiarPantalla();
									printf("Empleado modificado! \n");
									input_systemPause();
									retorno = 1;
								}
								break;
							case 3:
								employee_askSueldo(&employeeAux);

								employee_printTopMenu();
								employee_printEmployee(employeeAux);
								if(input_confirmacion("Confirmar cambio de sueldo [si/no]: ", "ERROR. Confirmar cambio de sueldo [si/no]: ") != -1)
								{
									*pEmployee = employeeAux;
									input_limpiarPantalla();
									printf("Empleado modificado! \n");
									retorno = 1;
									input_systemPause();
								}
								break;
							case 4:
								input_limpiarPantalla();
								break;
						}

					} while(option != 4);
				}
				else
				{
					input_limpiarPantalla();
					printf("Error al cargar Empleado! \n");
					input_systemPause();
				}
			}
			else
			{
				input_limpiarPantalla();
				printf("ID no encontrado! \n");
				input_systemPause();
			}
		}
	}
    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	int id;
	int ultimoId;
	int indice;
	Employee* pEmployee = NULL;

	if(pArrayListEmployee != NULL)
	{
		if(controller_ListEmployee(pArrayListEmployee))
		{
			ultimoId = employee_getUltimoId();

			input_getNumero(&id, "Ingrese ID a eliminar: ", "ERROR. Ingrese ID a eliminar: ", 1, ultimoId);

			indice = employee_searchIndex(pArrayListEmployee, &id);

			if(indice != -1)
			{
				pEmployee = ll_get(pArrayListEmployee, indice);

				if(pEmployee != NULL)
				{
					employee_printTopMenu();
					employee_printEmployee(*pEmployee);
					if(input_confirmacion("Confirmar baja de empleado [si/no]: ", "ERROR. Confirmar baja de empleado [si/no]: ") != -1)
					{
						retorno = 1;
						ll_remove(pArrayListEmployee, indice);
						input_limpiarPantalla();
						printf("Empleado eliminado con exito! \n");
						input_systemPause();
					}
					else
					{
						input_limpiarPantalla();
						printf("Baja cancelada! \n");
						input_systemPause();
					}
				}
				else
				{
					input_limpiarPantalla();
					printf("Error al cargar Empleado! \n");
					input_systemPause();
				}
			}
			else
			{
				input_limpiarPantalla();
				printf("ID no encontrado! \n");
				input_systemPause();
			}
		}
	}
    return retorno;
}
*/

int controller_ListPerritos(LinkedList* pArrayListPerritos)
{
	int retorno = 0;
	int len = ll_len(pArrayListPerritos);
	int i;
	ePerrito* pPerrito = NULL;

	if(pArrayListPerritos != NULL && len > 0)
	{
		perrito_printTopMenu();

		for(i=0 ; i<len ; i++)
		{
			pPerrito = (ePerrito*) ll_get(pArrayListPerritos, i);
			perrito_printPerrito(*pPerrito);
		}
		retorno = 1;
	}

    return retorno;
}

int controller_sortPerritos(LinkedList* pArrayListPerritos)
{
	int retorno = 0;

	if(pArrayListPerritos != NULL)
	{
		input_limpiarPantalla();
		printf("Cargando... \n");

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


int controller_saveAsBinary(char* path , LinkedList* pArrayListPerritos)
{
	int retorno = 0;
	FILE* pFile = fopen(path, "wb");

	if(path != NULL && pArrayListPerritos != NULL && pFile != NULL)
	{
		parser_PerritoToBinary(pFile, pArrayListPerritos);
		fclose(pFile);
		retorno = 1;
	}
    return retorno;
}
