#include "loopqueue.h"

loopqueue_t *create_empty_loopqueue()
{
	loopqueue_t *l = (loopqueue_t*)malloc(sizeof(loopqueue_t));
	if(NULL == l)
	{
		printf("malloc is fail!\n");
		return NULL;
	}
	memset(l, 0, sizeof(loopqueue_t));
	l->front = l->rear = 0;
	return l;
}

void enter_loopqueue(loopqueue_t *l, datatype_t data)
{
	l->buf[l->rear] = data;
	l->rear = (l->rear + 1) % MAX;
}

int is_full_loopqueue(loopqueue_t *l)
{
	return (l->front == (l->rear + 1) % MAX) ? 1 : 0;
}

int is_empty_loopqueue(loopqueue_t *l)
{
	return l->rear == l->front ? 1 : 0;	
}

datatype_t delete_loopqueue(loopqueue_t *l)
{
	datatype_t data = l->buf[l->front];
	l->front = (l->front + 1) % MAX;
	return data;
}
