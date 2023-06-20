#include "linklist.h"

linknode_t *create_empty_linklist()
{
	linknode_t *head = (linknode_t*)malloc(sizeof(linknode_t));
	if(NULL == head)
	{
		printf("malloc is fail!\n");
		return NULL;
	}
	memset(head, 0, sizeof(linknode_t));
	// head->next = head; 单循环链表
	head->next = NULL;
	return head;
}

void insert_head_linklist(linknode_t *head, datatype_t data){
	linknode_t *temp = (linknode_t*)malloc(sizeof(linknode_t));
	if(NULL == temp){
		printf("malloc is fail!\n");
		return;
	}
	temp->data = data;
	temp->next = head->next;
	head->next = temp;
}

int is_empty_linklist(linknode_t *head)
{
	// return head == head->next; 单循环链表
	return NULL == head->next;
}

void printf_data_linklist(linknode_t *head)
{
	linknode_t *p = head;
	// head != p->next 单循环链表
	while(NULL != p->next){
		printf("%d ", p->next->data);
		p = p->next;
	}
	printf("\n");
}

void insert_tail_linklist(linknode_t *head, datatype_t data)
{
	linknode_t *temp = (linknode_t*)malloc(sizeof(linknode_t));
	if(NULL == temp)
	{
		printf("malloc is fail!\n");
		return;
	}
	linknode_t *p = head;
	while(NULL != p->next)
	{
		p = p->next;
	}
	temp->data = data;
	temp->next = p->next;
	p->next = temp;
}

void insert_order_linklist(linknode_t *head, datatype_t data)
{
	linknode_t *temp = (linknode_t*)malloc(sizeof(linknode_t));
	if(NULL == temp)
	{
		printf("malloc is fail!\n");
		return;
	}
	linknode_t *p = head;
	while(NULL != p->next && data > p->next->data)
	{
		p = p->next;
	}
	temp->data = data;
	temp->next = p->next;
	p->next = temp;
}

int delete_data_linklist(linknode_t *head, datatype_t data)
{
	if(is_empty_linklist(head))
	{
		return -1;
	}
	linknode_t *p = head;
	linknode_t *q = NULL;
	int flag = 0;
	while(NULL != p->next)
	{
		if(data == p->next->data){
			q = p->next;
			p->next = q->next;
			free(q);
			q = NULL;
			flag = 1;
		}else{
			p = p->next;
		}
	}
	if(flag == 0){
		return -2;
	}else{
		printf("delete %d is successful!\n", data);
		return 0;
	}
}

void reverse_data_linklist(linknode_t *head)
{
	linknode_t *p = head->next->next;
	head->next->next = NULL;
	linknode_t *q = NULL;
	while(NULL != p)
	{
		q = p->next;
		p->next = head->next;
		head->next = p;
		p = q;
	}
}

void clean_up_linklist(linknode_t *head)
{
	linknode_t *p = head;
	linknode_t *q = NULL;
	while(NULL != p)
	{
		q = p->next;
		printf_data_linklist(p);
		free(p);
		p = q;
	}
}
