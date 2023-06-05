#include "seqlist.h"

seqlist_t *create_empty_seqlist()
{
	seqlist_t *l = (seqlist_t*)malloc(sizeof(seqlist_t));
	if(NULL == l)
	{
		printf("\033[41;1;5mmalloc is fail!\033[0m\n");
		return NULL;
	}
	memset(l, 0, sizeof(seqlist_t));
	l->n = 0;
	return l;
}

void insert_data_seqlist(seqlist_t *l, datatype_t data)
{
	l->buf[l->n++] = data;
}

int is_full_seqlist(seqlist_t *l)
{
	return MAX == l->n;
}

void printf_data_seqlist(seqlist_t *l)
{
	for(int i = 0; i < l->n; ++i)
	{
		printf("%d ", l->buf[i]);
	}
	printf("\n");
}

int is_empty_seqlist(seqlist_t *l)
{
	return 0 == l->n;
}

int delete_data_seqlist(seqlist_t *l, datatype_t data)
{
	if(is_empty_seqlist(l))
	{
		return -1;
	}
	int i = 0, j = 0;
	for(i = 0; i < l->n; ++i)
	{
		if(l->buf[i] != data)
		{
			l->buf[j++] = l->buf[i];
		}
	}
	l->n = j;
	if(i == j)
	{
		return -2;
	}else{
		printf("\033[42;1;5mdelete %d is successful!\033[0m\n", data);
		return 0;
	}
}
