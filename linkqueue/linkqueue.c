#include "linkqueue.h"

linkqueue_t *create_empty_linkqueue()
{
	linkqueue_t *l = (linkqueue_t*)malloc(sizeof(linkqueue_t));
	linknode_t *head = (linknode_t*)malloc(sizeof(linknode_t));
	if(NULL == l || NULL == head)
	{
		printf("malloc is fail!\n");
		return NULL;	
	}
	memset(l, 0, sizeof(linkqueue_t));
	memset(head, 0, sizeof(linknode_t));
	head->next = NULL;
	l->front = l->rear = head;
	return l;
}

int is_empty_linkqueue(linkqueue_t *l)
{
	return l->front == l->rear ? 1 : 0;
}

void enter_linkqueue(linkqueue_t *l, datatype_t data)
{
	linknode_t *node = (linknode_t*)malloc(sizeof(linknode_t));
	node->data = data;
	node->next = l->rear->next;
	l->rear->next = node;
	l->rear = node;
}

datatype_t delete_linkqueue(linkqueue_t *l)
{
	linknode_t *node = l->front->next;
	datatype_t data = node->data;
	l->front->next = node->next;
	free(node);
	node = NULL;
	if(NULL == l->front->next)
	{
		l->rear = l->front;	
	}
	return data;
}
