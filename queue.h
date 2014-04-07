#ifndef QUEUE_H
#define QUEUE_H

#include "graph.h"

typedef struct Element
{
	Vertex *value;
	struct Element *next;
} Element;

typedef struct Queue
{
	Element *head;
	Element *tail;
} Queue;

// написать const где можно

Queue *queueInit(void);
void queuePush(Queue *theQueue, Vertex *value);
Vertex *queuePop(Queue *theQueue);
void queueDelete(Queue *theQueue);
int queueIsEmpty(Queue *theQueue);

#endif