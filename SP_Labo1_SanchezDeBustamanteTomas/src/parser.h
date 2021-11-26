
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "perrito.h"


int parser_PerritosFromText(FILE* pFile , LinkedList* pArrayListPerritos);
int parser_PerritoFromBinary(FILE* pFile , LinkedList* pArrayListPerritos);
int parser_PerritoToText(FILE* pFile , LinkedList* pArrayListPerritos);
int parser_PerritoToBinary(FILE* pFile , LinkedList* pArrayListPerritos);
