#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 13
typedef int datatype_t;
typedef struct
{
	datatype_t buf[MAX];
	int top;
}seqstack_t;
extern seqstack_t *create_empty_seqstack();
extern void push_seqstack(seqstack_t *, datatype_t);
extern int is_full_seqstack(seqstack_t *);
extern int is_empty_seqstack(seqstack_t *);
extern datatype_t pop_seqstack(seqstack_t *);
extern datatype_t get_top_seqstack(seqstack_t *);
#endif
