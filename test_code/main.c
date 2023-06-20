#include "linklist.h"
#include "bitree.h"
int get_profundity()
{
	int i = 1;
	while(1)
	{
		if(1 == MAX)
			break;
		int pre = pow(2, i - 1) - 1;
		if(pre < 1)
		{
			pre = 1;	
		}	
		int next = pow(2, i) - 1;
		if(MAX > pre && MAX <= next)
		{
			break;	
		}
		i++;
	}
	return i;
}
void sort_linklist(linknode_t *head)
{
	linknode_t *cur = NULL;
	linknode_t *nx = NULL;
	for(cur = head->next; NULL != cur->next; cur = cur->next)
	{
		for(nx = cur->next; NULL != nx; nx = nx->next)
		{
			if(cur->data > nx->data)
			{
				cur->data ^= nx->data;
				nx->data ^= cur->data;	
				cur->data ^= nx->data;
			}	
		}	
	}
}
linknode_t *and_linklist(linknode_t *head1, linknode_t *head2)
{
	linknode_t *p = NULL;
	for(p = head2; NULL != p->next; p = p->next)
	{
		insert_head_linklist(head1, p->next->data);	
	}
	printf_data_linklist(head1);
	sort_linklist(head1);
	return head1;
}
void main(int argc, const char* argv[])
{
	// bitree_t *root = NULL;
	// root = create_binary_tree(1);
	int num_arr1[] = {1, 3, 5, 7, 9};
	int num_arr2[] = {2, 4, 6, 8, 10};
	int num_arr1_len = sizeof(num_arr1) / sizeof(num_arr1[0]);
	int num_arr2_len = sizeof(num_arr2) / sizeof(num_arr2[0]);
	linknode_t *head = create_empty_linklist();
	linknode_t *head2 = create_empty_linklist();
	for(int i = 0; i < num_arr1_len; ++i)
	{
		insert_head_linklist(head, num_arr1[i]);	
	}	
	for(int i = 0; i < num_arr2_len; ++i)
	{
		insert_head_linklist(head2, num_arr2[i]);	
	}
	printf("链表冒泡 : \n");
	printf_data_linklist(head);
	sort_linklist(head);
	printf_data_linklist(head);
	printf("链表合并排序 : \n");
	linknode_t *res = and_linklist(head, head2);
	printf_data_linklist(res);
	printf("总节点 : %d  深度 : %d\n", MAX, get_profundity());	
}
