#ifndef __HASHTABLELINK_H__
#define __HASHTABLELINK_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 7
typedef int datatype_t;
typedef struct node
{
	datatype_t data;
	struct node *next;
}hashtablelink_t;
extern hashtablelink_t **create_hashtablelink();
extern void insert_data_hashtablelink(hashtablelink_t**, datatype_t);
extern void print_hashtablelink(hashtablelink_t**);
extern hashtablelink_t *search_hashtablelink(hashtablelink_t**, datatype_t);
#endif
