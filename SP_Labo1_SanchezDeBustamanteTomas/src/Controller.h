
#include <stdio_ext.h>
#include <stdlib.h>
#include "perrito.h"
#include "LinkedList.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPerritos);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPerritos);
int controller_ListPerritos(LinkedList* pArrayListPerritos);
int controller_sortPerritos(LinkedList* pArrayListPerritos);
int controller_saveAsText(char* path , LinkedList* pArrayListPerritos);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPerritos);

int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
