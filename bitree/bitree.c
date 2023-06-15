#include "bitree.h"
#include "linkstack.h"

bitree_t *create_binary_tree(int n)
{
	bitree_t *root = NULL;
	root = (bitree_t*)malloc(sizeof(bitree_t));
	if(NULL == root)
	{
		printf("malloc is fail!\n");
		return NULL;	
	}	
	memset(root, 0, sizeof(bitree_t));
	root->n = n;
	root->lchild = root->rchild = NULL;
	printf("Input %d node data : ", n);
	scanf("%c", &(root->data));
	while('\n' != getchar());

	if(MAX >= 2 * n)
	{
		root->lchild = create_binary_tree(2 * n);	
	}
	if(MAX >= 2 * n + 1)
	{
		root->rchild = create_binary_tree(2 * n + 1);	
	}
	return root;
}	

void pre_order(bitree_t *root)
{
	if(NULL == root)
	{
		return;	
	}
	printf("(%d : %c) ", root->n, root->data);
	pre_order(root->lchild);
	pre_order(root->rchild);
}

void pre_order1(bitree_t *root)
{
	if(NULL == root)
	{
		return;	
	}
	linkstack_t *l = NULL;
	l = create_empty_linkstack();
	bitree_t *temp = root;
	while(NULL != temp || !is_empty_linkstack(l))
	{
		while(NULL != temp)
		{
			printf("(%d : %c) ", temp->n, temp->data);
			push_linkstack(l, temp);
			temp = temp->lchild;
		}	
		if(!is_empty_linkstack(l))
		{
			temp = pop_linkstack(l);
			temp = temp->rchild;	
		}
	}
	free(l);
}

void in_order(bitree_t *root)
{
	if(NULL == root)
	{
		return;	
	}
	in_order(root->lchild);
	printf("(%d : %c) ", root->n, root->data);
	in_order(root->rchild);
}

void in_order1(bitree_t *root)
{
	if(NULL == root)
	{
		return;	
	}
	linkstack_t *l = NULL;
	l = create_empty_linkstack();
	bitree_t *temp = root;
	while(NULL != temp || !is_empty_linkstack(l))
	{
		while(NULL != temp)
		{
			push_linkstack(l, temp);
			temp = temp->lchild;
		}	
		if(!is_empty_linkstack(l))
		{
			temp = pop_linkstack(l);
			printf("(%d : %c) ", temp->n, temp->data);
			temp = temp->rchild;	
		}
	}
	free(l);
}

void post_order(bitree_t *root)
{
	if(NULL == root)
	{
		return;	
	}
	post_order(root->lchild);
	post_order(root->rchild);
	printf("(%d : %c) ", root->n, root->data);
}

void post_order1(bitree_t *root)
{
	if(NULL == root)
	{
		return;	
	}
	linkstack_t *s = NULL;
	s = create_empty_linkstack();
	push_linkstack(s, root);	
	bitree_t *cur = NULL;
	bitree_t *pre = NULL;
	while(!is_empty_linkstack(s))
	{
		cur = get_top_linkstack(s);
		if((NULL == cur->lchild && NULL == cur->rchild) || (NULL != pre && (cur->lchild == pre || cur->rchild == pre)))
		{
			printf("(%d : %c) ", cur->n, cur->data);
			pop_linkstack(s);
			pre = cur;
		}else
		{
			if(NULL != cur->rchild)
			{
				push_linkstack(s, cur->rchild);	
			}	
			if(NULL != cur->lchild)
			{
				push_linkstack(s, cur->lchild);	
			}
		}
	}
	free(s);
}
