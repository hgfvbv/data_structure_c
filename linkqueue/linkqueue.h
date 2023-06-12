#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int datatype_t;
typedef struct node
{
	datatype_t data;
	struct node *next;
}linknode_t;
typedef struct
{
	struct node *front;
	struct node *rear;
}linkqueue_t;
extern linkqueue_t *create_empty_linkqueue();
extern int is_empty_linkqueue(linkqueue_t*);
extern void enter_linkqueue(linkqueue_t*, datatype_t);
extern datatype_t delete_linkqueue(linkqueue_t*);
#endif
