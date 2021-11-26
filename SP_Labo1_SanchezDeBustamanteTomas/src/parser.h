
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "perrito.h"

/// @fn int parser_PerritosFromText(FILE*, LinkedList*)
/// @brief Parsea los elementos del archivo a la estructura perritos
///
/// @param pFile
/// @param pArrayListPerritos
/// @return si pudo parsear devuelve [1], caso contrario [0]
int parser_PerritosFromText(FILE* pFile , LinkedList* pArrayListPerritos);

/// @fn int parser_PerritoToText(FILE*, LinkedList*)
/// @brief Parsea los elementos de la estructura perritos al archivo
///
/// @param pFile
/// @param pArrayListPerritos
/// @return si pudo parsear devuelve [1], caso contrario [0]
int parser_PerritoToText(FILE* pFile , LinkedList* pArrayListPerritos);
