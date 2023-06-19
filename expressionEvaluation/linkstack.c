#include "linkstack.h"

linkstack_t *create_empty_linkstack()
{
	linkstack_t *l = (linkstack_t*)malloc(sizeof(linkstack_t));
	if(NULL == l)
	{
		printf("malloc is fail!\n");
		return NULL;
	}
	memset(l, 0, sizeof(linkstack_t));
	l->top = NULL;
	return l;
}

void push_linkstack(linkstack_t *l, datatype_t data)
{
	linknode_t *node = (linknode_t*)malloc(sizeof(linknode_t));
	if(NULL == node)
	{
		printf("malloc is fail!\n");
		return;
	}	
	node->data = data;
	node->next = l->top;
	l->top = node;
	++l->n;
}

int is_empty_linkstack(linkstack_t *l)
{
	return NULL == l->top ? 1 : 0;	
}

datatype_t pop_linkstack(linkstack_t *l)
{
	linknode_t *node = l->top;
	datatype_t data = node->data;
	l->top = node->next;
	free(node);
	node = NULL;
	--l->n;
	return data;
}

datatype_t get_top_linkstack(linkstack_t *l)
{
	return l->top->data;
}
