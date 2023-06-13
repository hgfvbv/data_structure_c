#include "head.h"

linkqueue_t *create_empty_linkqueue()
{
	linkqueue_t *l = NULL;
	l = (linkqueue_t*)malloc(sizeof(linkqueue_t));
	linknode_t *head = NULL;
	head = (linknode_t*)malloc(sizeof(linknode_t));
	if(NULL == l || NULL == head)
	{
		printf("linkqueue malloc is fail!\n");
		return NULL;	
	}
	head->next = NULL;
	head->data = 0;
	l->front = l->rear = head;
	return l;
}

int is_empty_linkqueue(linkqueue_t *l)
{
	return l->rear == l->front ? 1 : 0;
}

void enter_linkqueue(linkqueue_t *l, datatype_t data)
{
	linknode_t *node = NULL;
	node = (linknode_t*)malloc(sizeof(linknode_t));
	node->data = data;
	node->next = l->rear->next;
	l->rear->next = node;
	l->rear = node;
}

datatype_t delete_linkqueue(linkqueue_t *l)
{
	linknode_t *node = NULL;
	datatype_t data = 0;
	node = l->front->next;
	data = node->data;
	l->front->next = node->next;
	free(node);
	node = NULL;
	if(NULL == l->front->next)
	{
		l->rear = l->front;	
	}
	return data;
}
