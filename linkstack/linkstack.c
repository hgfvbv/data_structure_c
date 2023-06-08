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
	
}
