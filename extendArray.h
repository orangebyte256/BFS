#ifndef EXTEND_ARRAY_H
#define EXTEND_ARRAY_H

#include "graph.h"
#include <memory.h>
#include <string.h>


typedef struct ExtendArray
{
	Vertex *array;
	int size;
} ExtendArray;

ExtendArray *extendArrayInit(void);
void extendArrayPushVertex(ExtendArray *theExtendArray, int id);
void extendArrayPushEdge(ExtendArray *theExtendArray, int id, int idVertex);
void extendArrayDelete(ExtendArray *theExtendArray);
int extendArrayGetSize(ExtendArray *theExtendArray);
#endif