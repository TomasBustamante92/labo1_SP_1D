
#include <stdio_ext.h>
#include <stdlib.h>
#include "perrito.h"
#include "LinkedList.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPerritos);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPerritos);
int controller_ListPerritos(LinkedList* pArrayListPerritos, int opcion);
int controller_sortPerritos(LinkedList* pArrayListPerritos, int opcion);
int controller_saveAsText(char* path , LinkedList* pArrayListPerritos);

