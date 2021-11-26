#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/// @fn LinkedList ll_filter*(LinkedList*, int(*)(void*))
/// @brief crea una nueva lista filtrando elementos de una lista que se pase por parametro
///
/// @param this
/// @param pFunc
/// @return devuelve lista nueva
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* newList = NULL;
	void* element;
	int condicion;
	int i;
	int len = ll_len(this);

	if(this != NULL && pFunc != NULL && len > -1)
	{
		newList = ll_newLinkedList();

		if(newList != NULL)
		{
			for(i=0 ; i<len ; i++)
			{
				element = ll_get(this, i);
				condicion = pFunc(element);

				if(condicion == 0)
				{
					ll_add(newList, element);
				}
			}
		}
	}
	return newList;
}

/// @fn int ll_map(LinkedList*, int(*)(void*))
/// @brief modifica los elementos de la lista
///
/// @param this
/// @param pFunc
/// @return si los pudo modificar devuelve [0], caso contrario [-1]
int ll_map(LinkedList* this, int(*pFunc)(void*))
{
	int retorno = -1;
	void* element;
	int i;
	int len = ll_len(this);

	if(this != NULL && pFunc != NULL && len > -1)
	{
		for(i=0 ; i<len ; i++)
		{
			element = ll_get(this, i);
			retorno = pFunc(element);
		}
	}
	return retorno;
}

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int i;
	int len = ll_len(this);
	Node* nodeAux = NULL;

	if(this != NULL && nodeIndex > -1 && nodeIndex < len)
	{
		nodeAux = this->pFirstNode;

		for(i=0 ; i<nodeIndex ; i++)
		{
			nodeAux = nodeAux->pNextNode;
		}
	}
    return nodeAux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;
	int len = ll_len(this);
	Node* node = NULL;
	Node* nodeAnterior = NULL;
	Node* nodeSiguiente = NULL;
	node = malloc(sizeof(Node));


    if(this != NULL && nodeIndex >= 0 && nodeIndex <= len && node != NULL)
    {
		this->size++;

		if(nodeIndex == 0)		// PRIMERO
		{
			nodeSiguiente = getNode(this, 0);
			this->pFirstNode = node;
	    	node->pElement = pElement;
	    	node->pNextNode = nodeSiguiente;
		}
		else if(this->size == len)		// ULTIMO
		{
			nodeAnterior = getNode(this, nodeIndex-1);
			nodeAnterior->pNextNode = node;
			node->pElement = pElement;
			node->pNextNode = NULL;
		}
		else		// MEDIO
		{
			nodeAnterior = getNode(this, nodeIndex -1);
			nodeSiguiente = getNode(this, nodeIndex +1);
			nodeAnterior->pNextNode = node;
			node->pElement = pElement;
			node->pNextNode = nodeSiguiente;
		}

    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = addNode(this, this->size, pElement);
    }
    return returnAux;
}

/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado. Verificando que el
 *		puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la
 *		verificación falla la función retorna (NULL) y si tiene éxito retorna el elemento.
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
	int len = ll_len(this);
	Node* nodeAux = NULL;
	nodeAux = getNode(this, index);

    if(this != NULL && index > -1 && index <= len && nodeAux != NULL)
    {
    	returnAux = nodeAux->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
	int len = ll_len(this);
	Node* nodeAux = NULL;
	nodeAux = getNode(this, index);

    if(this != NULL && index > -1 && index <= len && nodeAux != NULL)
    {
    	nodeAux->pElement = pElement;
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len = ll_len(this);
    Node* nodeAnterior;
    Node* node;

    if(this != NULL && index > -1 && index < len && len > 0){

        if(index == 0)
        {
        	node = getNode(this, index);
            this->pFirstNode = node->pNextNode;
            free(node);
            node = NULL;
        }
        else
        {
        	node = getNode(this, index);
        	nodeAnterior = getNode(this, index -1);
        	nodeAnterior->pNextNode = node->pNextNode;
            free(node);
            node = NULL;
        }

        this->size--;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
	int len = ll_len(this);

    if(this != NULL && len > -1)
    {
    	for(i=len ; i>-1 ; i--)
    	{
    		ll_remove(this, i);
    	}
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL && ll_clear(this) == 0)
    {
    	free(this);
    	this = NULL;
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
	int len = ll_len(this);

    if(this != NULL && len > -1)
    {
    	for(i=0 ; i<len ; i++)
    	{
    		if(pElement == ll_get(this, i))
    		{
    			returnAux = i;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(this->size == 0)
    	{
			returnAux = 1;
    	}
    	else
    	{
			returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
	int len = ll_len(this);

    if(this != NULL && index > -1 && index < len+1)
    {
    	addNode(this, index, pElement);
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
	int len = ll_len(this);

    if(this != NULL && index > -1 && index < len+1)
    {
    	returnAux = ll_get(this, index);
    	ll_remove(this, index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_indexOf(this, pElement) != -1)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int returnAux = -1;
    int i;
	int len2 = ll_len(this2);
    void* pElement = NULL;

    if(this != NULL && this2 != NULL && len2 > -1)
    {
    	returnAux = 1;

    	for(i=0 ; i<len2 ; i++)
		{
    		pElement = ll_get(this2, i);

    		if(ll_contains(this, pElement) != 1)
			{
    			returnAux = 0;
				break;
			}
		}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this, int from, int to)
{
    LinkedList* cloneArray = NULL;
    void* pElementAux = NULL;
	int len = ll_len(this);
	int i;

    if(this != NULL && from > -1 && to < len+1 && from <= to)
    {
    	cloneArray = (LinkedList*)ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
    		for(i=from ; i<to ; i++)
    		{
    			pElementAux = ll_get(this, i);
    			ll_add(cloneArray, pElementAux);
    		}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
	int len = ll_len(this);

    if(this != NULL && len > -1)
    {
    	cloneArray = ll_subList(this, 0, len);

    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
   	int i;
	int flagSwap;
	void* pAux;
	void* pSwaper1;
	void* pSwaper2;
	int criterio;
	int len = ll_len(this);
	int nuevoLimite = len -1;

    if(this != NULL && (order == 1 || order == 0) && len > 0 && pFunc != NULL)
    {
		do{
			flagSwap = 0;

			for(i=0; i<nuevoLimite; i++)
			{
				pSwaper1 = ll_get(this, i);
				pSwaper2 = ll_get(this, i+1);

				criterio = pFunc(pSwaper1,pSwaper2);

				if(order == 0 && criterio == -1 )
				{
					pAux = pSwaper1;
					ll_set(this, i, pSwaper2);
					ll_set(this, i+1, pAux);
					flagSwap = 1;
				}
				else if(order == 1 && criterio == 1 )
				{
					pAux = pSwaper1;
					ll_set(this, i, pSwaper2);
					ll_set(this, i+1, pAux);
					flagSwap = 1;
				}
			}
			nuevoLimite--;

		}while(flagSwap);

		returnAux = 0;
    }
    return returnAux;
}
