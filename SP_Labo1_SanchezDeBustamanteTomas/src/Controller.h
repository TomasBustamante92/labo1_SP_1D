
#include <stdio_ext.h>
#include <stdlib.h>
#include "perrito.h"
#include "LinkedList.h"
#include "parser.h"

/// @fn int controller_loadFromText(char*, LinkedList*)
/// @brief Carga una lista de texto
///
/// @param path
/// @param pArrayListPerritos
/// @return si la pudo cargar devuelve [1] caso contrario [0]
int controller_loadFromText(char* path , LinkedList* pArrayListPerritos);

/// @fn int controller_saveAsText(char*, LinkedList*)
/// @brief Guarda una lista en formato texto
///
/// @param path
/// @param pArrayListPerritos
/// @return si pudo guardar devuelve [1] caso contrario [0]
int controller_saveAsText(char* path , LinkedList* pArrayListPerritos);

/// @fn int controller_ListPerritos(LinkedList*, int)
/// @brief Lista el array de perritos, si se le pasa opcion [1] Imprime lista simple, opcion [2] Imprime lista con comida agregado
///
/// @param pArrayListPerritos
/// @param opcion
/// @return si los pudo imprimir devuelve [1] caso contrario [0]
int controller_ListPerritos(LinkedList* pArrayListPerritos, int opcion);

/// @fn int controller_sortPerritos(LinkedList*, int)
/// @brief Ordena la lista de perritos, si se le pasa opcion [1] ordena por nombre, opcion [2] por ID
///
/// @param pArrayListPerritos
/// @param opcion
/// @return si los pudo ordenar devuelve [1] caso contrario [0]
int controller_sortPerritos(LinkedList* pArrayListPerritos, int opcion);

