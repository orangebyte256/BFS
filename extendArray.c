#include "extendArray.h"
#include <stdlib.h>

ExtendArray *extendArrayInit(void)
{
	ExtendArray *temp = calloc(1, sizeof(ExtendArray));
	return temp;
}

void extendArrayPushVertex(ExtendArray *theExtendArray, int id)
{
	if (id > theExtendArray->size)
	{
		int i = 0;
		theExtendArray->array = realloc(theExtendArray->array, id * sizeof(Vertex));
		for (i = theExtendArray->size; i < id; i++)
		{
			theExtendArray->array[i].count = 0;
			theExtendArray->array[i].id = -1;
			theExtendArray->array[i].been = 0;
			theExtendArray->array[i].verteces = NULL;
		}
		theExtendArray->size = id;
	}
	if (theExtendArray->array[id - 1].id == -1)
		theExtendArray->array[id - 1].id = id;
	return;
}

void extendArrayPushEdge(ExtendArray *theExtendArray, int id, int idVertex)
{
	int i = 0;
	int isFind = 0;
	for (i = 0; i < theExtendArray->array[id - 1].count; i++)
	{
		if (theExtendArray->array[id - 1].verteces[i] == idVertex)
			isFind = 1;
	}
	if (isFind == 0)
	{
		theExtendArray->array[id - 1].verteces = realloc(theExtendArray->array[id - 1].verteces, (theExtendArray->array[id - 1].count + 1) * sizeof(int));
		theExtendArray->array[id - 1].verteces[theExtendArray->array[id - 1].count] = idVertex;
		theExtendArray->array[id - 1].count++;
	}
}

int extendArrayGetSize(ExtendArray *theExtendArray)
{
	return theExtendArray->size;
}

void extendArrayDelete(ExtendArray *theExtendArray)
{
	int i = 0;
	for (i = 0; i < theExtendArray->size; i++)
	{
		if (theExtendArray->array[i].count > 0)
			free(theExtendArray->array[i].verteces);
	}
	free(theExtendArray->array);
	free(theExtendArray);
}
