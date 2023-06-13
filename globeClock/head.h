#ifndef __HEAD_H__
#define __HEAD_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 27
typedef int datatype_t;
typedef struct node
{
	datatype_t data;
	struct node* next;
}linknode_t;
typedef struct
{
	struct node* top;
	int n;
}linkstack_t;
typedef struct
{
	struct node* front;
	struct node* rear;
}linkqueue_t;

extern linkstack_t *create_empty_linkstack();
extern int is_empty_linkstack(linkstack_t *);
extern void push_linkstack(linkstack_t *, datatype_t);
extern datatype_t pop_linkstack(linkstack_t *);
extern datatype_t get_top_linkstack(linkstack_t *);

extern linkqueue_t *create_empty_linkqueue();
extern int is_empty_linkqueue(linkqueue_t *);
extern void enter_linkqueue(linkqueue_t *, datatype_t);
extern datatype_t delete_linkqueue(linkqueue_t *);

extern int ball_clock();
extern void print_linkqueue(linknode_t *);
extern int is_original_queue(linkqueue_t *);
#endif
