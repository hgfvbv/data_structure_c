#include "hashtablelink.h"

hashtablelink_t **create_hashtablelink()
{
	hashtablelink_t **h = NULL;
	h = (hashtablelink_t**)malloc(MAX * sizeof(hashtablelink_t*));
	if(NULL == h)
	{
		printf("malloc is fail!\n");
		return NULL;	
	}
	memset(h, 0, sizeof(MAX * sizeof(hashtablelink_t*)));
	for(int i = 0; i < MAX; ++i)
	{
		h[i] = NULL;	
	}
	return h;
}

void insert_data_hashtablelink(hashtablelink_t ** h, datatype_t key)
{
	int index = key % MAX;
	hashtablelink_t **p = NULL;
	for(p = &(h[index]); NULL != *p; p = &((*p)->next))
	{
		if((*p)->data > key)
			break;	
	}
	hashtablelink_t *temp = (hashtablelink_t*)malloc(sizeof(hashtablelink_t*));
	temp->data = key;
	temp->next = *p;
	*p = temp;
}

void print_hashtablelink(hashtablelink_t **h)
{
	for(int i = 0; i < MAX; ++i)
	{
		printf("index = %d : ", i);
		for(hashtablelink_t **p = &(h[i]); NULL != *p; p = &((*p)->next))
		{
			printf("%d ", (*p)->data);	
		}	
		putchar('\n');
	}
}

hashtablelink_t *search_hashtablelink(hashtablelink_t **h, datatype_t key)
{
	int index = key % MAX;
	for(hashtablelink_t **p = &(h[index]); NULL != *p; p = &((*p)->next))
	{
		if((*p)->data == key)
		{
			return *p;	
		}	
	}	
	return NULL;
}
