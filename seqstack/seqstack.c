#include "seqstack.h"

seqstack_t *create_empty_seqstack()
{
	seqstack_t *s = (seqstack_t*)malloc(sizeof(seqstack_t));
	if(NULL == s)
	{
		printf("malloc is fail!\n");
		return NULL;
	}
	memset(s, 0, sizeof(seqstack_t));
	s->top = -1;
	return s;
}

void push_seqstack(seqstack_t *s, datatype_t data)
{
	s->buf[++s->top] = data;
}

int is_full_seqstack(seqstack_t *s)
{
	return MAX - 1 == s->top;
}

int is_empty_seqstack(seqstack_t *s)
{
	return -1 == s->top;
}

datatype_t pop_seqstack(seqstack_t *s)
{
	return s->buf[s->top--];
}

datatype_t get_top_seqstack(seqstack_t *s)
{
	return s->buf[s->top];
}
