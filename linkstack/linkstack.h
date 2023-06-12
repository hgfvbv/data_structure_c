#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char datatype_t;
typedef struct node
{
	datatype_t data;
	struct node *next;
}linknode_t;
typedef struct
{
	int n;
	linknode_t *top;
}linkstack_t;

extern linkstack_t *create_empty_linkstack();
extern void push_linkstack(linkstack_t *, datatype_t);
extern int is_empty_linkstack(linkstack_t *);
extern datatype_t pop_linkstack(linkstack_t *);
extern datatype_t get_top_linkstack(linkstack_t *);
#endif
