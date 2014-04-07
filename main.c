#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <stdlib.h>

#include "extendArray.h"
#include "queue.h"


void show(const ExtendArray *theExtendArray)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < theExtendArray->size; i++)
	{
		if (theExtendArray->array[i].id != -1)
		{
			printf("Vertex: %d ", theExtendArray->array[i].id);
			printf("Neighbors: ");
			for (j = 0; j < theExtendArray->array[i].count; j++)
				printf("%d ", theExtendArray->array[i].verteces[j]);
			printf("\n");
		}
	}
}

void addVertexWithEdge(ExtendArray *theExtendArray, int first, int second)
{
	extendArrayPushVertex(theExtendArray, first);
	extendArrayPushVertex(theExtendArray, second);
	extendArrayPushEdge(theExtendArray, first, second);
	extendArrayPushEdge(theExtendArray, second, first);
}



void readFile(const char *name, ExtendArray *theExtendArray)
{
	int first = 0;
	int second = 0;
	FILE *f = fopen(name, "r");
	if (f == NULL)
		return;
	while (fscanf(f, "%d %d", &first, &second) != EOF)
	{
		if ((first > 0) && (second > 0))
			addVertexWithEdge(theExtendArray, first, second);
	}
	fclose(f);
}

void bfs(ExtendArray *theExtendArray, int id)
{
	int i = 0;
	Vertex *vertex = NULL;
	Queue *queue = queueInit();
	queuePush(queue, &theExtendArray->array[id - 1]);
	while (!queueIsEmpty(queue))
	{
		vertex = queuePop(queue);
		if (vertex->been == 1)
			continue;
		vertex->been = 1;
		printf("%d ", vertex->id);
		for (i = 0; i < vertex->count; i++)
		{
			queuePush(queue, &theExtendArray->array[vertex->verteces[i] - 1]);
		}
	}
	queueDelete(queue);
}

int main(void)
{
	ExtendArray *vertex = extendArrayInit();
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int *p = calloc(1, 1);
	readFile("input.txt", vertex);
	if (extendArrayGetSize(vertex) > 0)
		bfs(vertex, 1);
	extendArrayDelete(vertex);
	return 0;
}
