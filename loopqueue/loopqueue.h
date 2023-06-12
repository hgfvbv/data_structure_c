#ifndef __LOOPQUEUE_H__
#define __LOOPQUEUE_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
typedef int datatype_t;
typedef struct
{
	datatype_t buf[MAX];
	int front;
	int rear;
}loopqueue_t;
extern loopqueue_t *create_empty_loopqueue();
extern int is_full_loopqueue(loopqueue_t *);
extern int is_empty_loopqueue(loopqueue_t *);
extern void enter_loopqueue(loopqueue_t *, datatype_t);
extern datatype_t delete_loopqueue(loopqueue_t *);
#endif
