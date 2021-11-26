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
    float cantidadComidaRacion;

}ePerrito;


/// @fn int ePerrito_laQueFiltra(void*)
/// @brief filtra la lista de perritos por solo galgos flaquitos
///
/// @param pElement
/// @return si lo filtro devuelve [0] caso contrario devuelve [-1]
int ePerrito_laQueFiltra(void* pElement);

/// @fn int ePerrito_laQueMapea(void*)
/// @brief completa el campo de cantidadComidaRacion
///
/// @param
/// @return si lo completo devuelve [0] caso contrario devuelve [-1]
int ePerrito_laQueMapea(void*);

/// @fn void perrito_printPerritoConComida(ePerrito)
/// @brief Imprime la lista de perritos con el campo de cantidadComidaRacion
///
/// @param perrito
void perrito_printPerritoConComida(ePerrito perrito);

/// @fn void perrito_printTopMenuConComida(void)
/// @brief Imprime la informacion de la lista de perritos con el campo de cantidadComidaRacion
///
void perrito_printTopMenuConComida(void);

/// @fn void perrito_printPerrito(ePerrito)
/// @brief Imprime la lista de perritos
///
/// @param perrito
void perrito_printPerrito(ePerrito perrito);

/// @fn void perrito_printTopMenu(void)
/// @brief Imprime la informacion de la lista de perritos
///
void perrito_printTopMenu(void);

/// @fn ePerrito perrito_newParametros*(char*, char*, char*, char*, char*)
/// @brief Carga los datos a un perrito nuevo
///
/// @param idStr
/// @param nombreStr
/// @param pesoStr
/// @param edadStr
/// @param razaStr
/// @return si sale bien devuelve un perrito, caso contrario NULL
ePerrito* perrito_newParametros(char* idStr,char* nombreStr, char* pesoStr, char* edadStr, char* razaStr);

/// @fn int perrito_getCantidadComidaRacion(ePerrito*, float*)
/// @brief Transfiere el contenido de un perrito al canTidadComida y lo devuelve
///
/// @param this
/// @param cantidadComidaRacion
/// @return si salio bien devuelve [0] caso contrario [-1]
int perrito_getCantidadComidaRacion(ePerrito* this,float* cantidadComidaRacion);

/// @fn int perrito_setCantidadComidaRacion(ePerrito*, float)
/// @brief Transfiere el contenido de canTidadComida al perrito
///
/// @param this
/// @param cantidadComidaRacion
/// @return si salio bien devuelve [0] caso contrario [-1]
int perrito_setCantidadComidaRacion(ePerrito* this,float cantidadComidaRacion);

/// @fn int perrito_setPeso(ePerrito*, float)
/// @brief Transfiere el contenido de peso al perrito
///
/// @param this
/// @param peso
/// @return si salio bien devuelve [0] caso contrario [-1]
int perrito_setPeso(ePerrito* this,float peso);

/// @fn int perrito_getPeso(ePerrito*, float*)
/// @brief Transfiere el contenido de un perrito al peso y lo devuelve
///
/// @param this
/// @param peso
/// @return si salio bien devuelve [0] caso contrario [-1]
int perrito_getPeso(ePerrito* this,float* peso);

/// @fn int perrito_setNombre(ePerrito*, char*)
/// @brief Transfiere el contenido de nombre al perrito
///
/// @param this
/// @param nombre
/// @return si salio bien devuelve [0] caso contrario [-1]
int perrito_setNombre(ePerrito* this,char* nombre);

/// @fn int perrito_getNombre(ePerrito*, char*)
/// @brief Transfiere el contenido de un perrito al nombre y lo devuelve
///
/// @param this
/// @param nombre
/// @return si salio bien devuelve [0] caso contrario [-1]
int perrito_getNombre(ePerrito* this,char* nombre);

/// @fn int perrito_setEdad(ePerrito*, int)
/// @brief Transfiere el contenido de edad al perrito
///
/// @param this
/// @param edad
/// @return si salio bien devuelve [0] caso contrario [-1]
int perrito_setEdad(ePerrito* this,int edad);

/// @fn int perrito_getEdad(ePerrito*, int*)
/// @brief Transfiere el contenido de un perrito a la edad y lo devuelve
///
/// @param this
/// @param edad
/// @return si salio bien devuelve [0] caso contrario [-1]
int perrito_getEdad(ePerrito* this,int* edad);

/// @fn int perrito_setRaza(ePerrito*, char*)
/// @brief Transfiere el contenido de raza al perrito
///
/// @param this
/// @param raza
/// @return si salio bien devuelve [0] caso contrario [-1]
int perrito_setRaza(ePerrito* this,char* raza);

/// @fn int perrito_getRaza(ePerrito*, char*)
/// @brief Transfiere el contenido de un perrito a la raza y lo devuelve
///
/// @param this
/// @param raza
/// @return si salio bien devuelve [0] caso contrario [-1]
int perrito_getRaza(ePerrito* this,char* raza);

/// @fn int perrito_sortByName(void*, void*)
/// @brief Ordena la lista de perritos por nombre
///
/// @param perrito1
/// @param perrito2
/// @return si el perrito1 tiene un char que valga menos que perrito2 devuelve [-1] caso contrario [1]
int perrito_sortByName(void* perrito1,void* perrito2);

/// @fn int perrito_sortById(void*, void*)
/// @brief Ordena la lista de perritos por ID
///
/// @param perrito1
/// @param perrito2
/// @return si el perrito1 tiene un char que valga menos que perrito2 devuelve [-1] caso contrario [1]
int perrito_sortById(void* perrito1, void* perrito2);


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
