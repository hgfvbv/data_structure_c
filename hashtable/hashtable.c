#include "hashtable.h"

hashtable_t *create_hashtable()
{
	hashtable_t *h = NULL;
	h = (hashtable_t*)malloc(sizeof(hashtable_t));
	if(NULL == h)
	{
		printf("malloc is fail!\n");
		return NULL;	
	}	
	h->n = 0;
	h->elem_p = (datatype_t*)malloc(MAX * sizeof(datatype_t));
	memset(h->elem_p, NULL_KEY, MAX * sizeof(datatype_t));
	return h;
}

int is_full_hashtable(hashtable_t *h)
{
	return MAX == h->n ? 1 : 0;
}

void insert_data_hash(hashtable_t *h, datatype_t key)
{
	int index = 0;	
	if(is_full_hashtable(h))
	{
		printf("hash table is full!\n");
		return;	
	}
	index = key % MAX;
	while(NULL_KEY != h->elem_p[index])
	{
		index = (index + 1) % MAX;	
	}
	h->elem_p[index] = key;
	++h->n;
}

void print_hash_table(hashtable_t *h)
{
	for(int i = 0; i < MAX; ++i)
	{
		printf("%d ", h->elem_p[i]);	
	}
	putchar('\n');
}

int search_hash_table(hashtable_t *h, datatype_t key)
{
	int index = key % MAX;
	while(h->elem_p[index] != key)
	{
		index = (index + 1) % MAX;
		if(NULL_KEY == h->elem_p[index] || index == key % MAX)
		{
			return -1;	
		}
	}
	return index;
}
