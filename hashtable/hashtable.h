#ifndef __HASH_H__
#define __HASH_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
#define NULL_KEY -1
typedef int datatype_t;
typedef struct
{
	datatype_t *elem_p;
	int n;
}hashtable_t;
extern hashtable_t *create_hashtable();
extern int is_full_hashtable(hashtable_t*);
extern void insert_data_hash(hashtable_t*, datatype_t);
extern void print_hash_table(hashtable_t*);
extern int search_hash_table(hashtable_t*, datatype_t);
#endif
