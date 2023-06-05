#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
typedef int datatype_t;
typedef struct{
	datatype_t buf[MAX];
	int n;
}seqlist_t;
extern seqlist_t *create_empty_seqlist();
extern void insert_data_seqlist(seqlist_t*, datatype_t);
extern int is_full_seqlist(seqlist_t*);
extern void printf_data_seqlist(seqlist_t*);
extern int is_empty_seqlist(seqlist_t*);
extern int delete_data_seqlist(seqlist_t*, datatype_t);
#endif
