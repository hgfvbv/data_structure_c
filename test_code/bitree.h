#ifndef __BITREE_H__
#define __BITREE_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 6
typedef char data_t;
typedef struct bitree
{
	int n;
	data_t data;
	struct bitree *lchild;
	struct bitree *rchild;
}bitree_t;
extern bitree_t *create_binary_tree(int);
extern void pre_order(bitree_t*);
extern void pre_order1(bitree_t*);
extern void in_order(bitree_t*);
extern void in_order1(bitree_t*);
extern void post_order(bitree_t*);
extern void post_order1(bitree_t*);
#endif
