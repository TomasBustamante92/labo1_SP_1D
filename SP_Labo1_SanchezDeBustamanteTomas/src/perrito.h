/*
 * perrito.h
 *
 *  Created on: Nov 25, 2021
 *      Author: user
 */

#ifndef PERRITO_H_
#define PERRITO_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include "input.h"
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[21];
    float peso;
    int edad;
    char raza[21];

}ePerrito;


// ---- COMENTAAAAR ---- //

int perrito_setPeso(ePerrito* this,int peso);
int perrito_getPeso(ePerrito* this,int* peso);
void perrito_printPerrito(ePerrito perrito);
void perrito_printTopMenu(void);
ePerrito* perrito_newParametros(char* idStr,char* nombreStr, char* pesoStr, char* edadStr, char* razaStr);
int perrito_setNombre(ePerrito* this,char* nombre);
int perrito_getNombre(ePerrito* this,char* nombre);
int perrito_setEdad(ePerrito* this,int edad);
int perrito_getEdad(ePerrito* this,int* edad);
int perrito_setRaza(ePerrito* this,char* raza);
int perrito_getRaza(ePerrito* this,char* raza);
int perrito_sortByName(void* perrito1,void* perrito2);
int employee_sortByEdad(void* perrito1, void* perrito2);
int perrito_getUltimoId(void);
int perrito_setUltimoId(int ultimoId);



/// @fn void perrito_delete(ePerrito*)
/// @brief elimina un perrito
///
/// @param this
void perrito_delete(ePerrito* this);

/// @fn ePerrito perrito_new*()
/// @brief crea un nuevo perrito en memoria
///
/// @return devuelve puntero a nuevo perrito
ePerrito* perrito_new();

/// @fn int perrito_setId(ePerrito*, int)
/// @brief Transfiere el contenido de ID al perrito
///
/// @param this
/// @param id
/// @return si salio bien devuelve [0] caso contrario [-1]
int perrito_setId(ePerrito* this,int id);

/// @fn int perrito_getId(ePerrito*, int*)
/// @brief Transfiere el contenido de un perrito al ID y lo devuelve
///
/// @param this
/// @param id
/// @return si salio bien devuelve [0] caso contrario [-1]
int perrito_getId(ePerrito* this,int* id);

#endif /* PERRITO_H_ */
