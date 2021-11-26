/*
 ============================================================================

	Segundo Parcial de Laboratorio I
	Alumno: Tomas Sanchez de Bustamante
	Division: D
	OS: Linux

 ============================================================================
 */


#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "perrito.h"


int main()
{
	setbuf(stdout,NULL);
    int option = 0;

    LinkedList* listaPerritos = ll_newLinkedList();

    do{
    	input_getNumero(&option, 	"1. Cargar lista \n"
    								"2. Listar perritos \n"
    								"3. Calcular cantidad de comida \n"
    								"4. Listar perritos con raciones \n"
    								"5.  \n"
    								"6.  \n"
    								"7. Ordenar empleados \n"
    								"8. Guardar los datos de los empleados en el archivo data.csv (modo texto) \n"
    								"9. Guardar los datos de los empleados en el archivo data.bin (modo binario) \n"
    								"10. Salir \n"
    								"- - - - - - - - - - - - - - - - - - - \n"
    								"Ingrese opcion: ",
									"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto) \n"
									"2. Cargar los datos de los empleados desde el archivo data.bin (modo binario) \n"
									"3. Alta de empleado \n"
    								"4. Modificar datos de empleado \n"
    								"5. Baja de empleado \n"
    								"6. Listar empleados \n"
    								"7. Ordenar empleados \n"
    								"8. Guardar los datos de los empleados en el archivo data.csv (modo texto) \n"
    								"9. Guardar los datos de los empleados en el archivo data.bin (modo binario) \n"
    								"10. Salir \n"
    								"- - - - - - - - - - - - - - - - - - - \n"
    								"ERROR. Ingrese opcion: ", 1, 10);

        switch(option)
        {
            case 1:
            	if(controller_loadFromText("perritos.csv",listaPerritos))
            	{
            		input_limpiarPantalla();
            		printf("Lista cargada con exito! \n");
            		input_systemPause();
            	}
            	else
            	{
            		input_limpiarPantalla();
            		printf("Error al cargar la lista! \n");
            		input_systemPause();
            	}

            	break;

            case 2:
            	controller_sortPerritos(listaPerritos);
				if(controller_ListPerritos(listaPerritos,1))
				{
					input_systemPause();
				}
				else
				{
					input_limpiarPantalla();
					printf("No hay perritos cagados! \n");
					input_systemPause();
				}
            	break;

            case 3:
            	if(ll_map(listaPerritos, ePerrito_laQueMapea) != -1)
            	{
            		input_limpiarPantalla();
            		printf("Elemento agregado con exito! \n");
            		input_systemPause();
            	}
				else
				{
					input_limpiarPantalla();
					printf("Ups! \n");
					input_systemPause();
				}

            	break;

            case 4:
				if(controller_ListPerritos(listaPerritos,2))
				{
					input_systemPause();
				}
				else
				{
					input_limpiarPantalla();
					printf("No hay perritos cagados! \n");
					input_systemPause();
				}
            	break;

        }

    }while(option != 11);

    return 0;
}
