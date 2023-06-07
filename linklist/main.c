#include "linklist.h"

void main(int args, const char* argv[])
{
	linknode_t *head = create_empty_linklist();
	datatype_t data = 0;
	int n = 0;
	printf("please input you want insert data number : ");
	scanf("%d", &n);
	printf("please input %d data : ", n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &data);
		//insert_head_linklist(head, data);
		insert_tail_linklist(head, data);
		//insert_order_linklist(head, data);
	}
	reverse_data_linklist(head);
	printf_data_linklist(head);
	printf("============================================\n");
	printf("please input delete data : ");
	scanf("%d", &n);
	int ret = delete_data_linklist(head, n);
	if(ret < 0){
		printf("not find delete data %d\n", n);
		return;
	}
	printf_data_linklist(head);
	clean_up_linklist(head);
}
