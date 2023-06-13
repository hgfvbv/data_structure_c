#include "head.h"

linkstack_t *create_empty_linkstack()
{
	linkstack_t *l = NULL;
	l = (linkstack_t*)malloc(sizeof(linkstack_t));
	if(NULL == l)
	{
		printf("linkstack malloc is fail!\n");
		return NULL;	
	}
	memset(l, 0, sizeof(linkstack_t));
	l->top = NULL;
	l->n = 0;
	return l;
}

int is_empty_linkstack(linkstack_t *l)
{
	return 0 == l->n ? 1 : 0;
}

void push_linkstack(linkstack_t *l, datatype_t data)
{
	linknode_t *node = NULL;
	node = (linknode_t*)malloc(sizeof(linknode_t));
	node->data = data;
	node->next = l->top;
	l->top = node;
	++l->n;
}

datatype_t pop_linkstack(linkstack_t *l)
{
	datatype_t data = 0;
	linknode_t *node = NULL;
	node = l->top;
	data = node->data;
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
