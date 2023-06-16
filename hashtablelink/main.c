#include "hashtablelink.h"

void main(int argc, const char* argv[])
{
	hashtablelink_t **h = NULL;
	h = create_hashtablelink();
	datatype_t data[MAX] = {10,22,13,11,24,7,14};
	for(int i = 0; i < MAX; ++i)
	{
		insert_data_hashtablelink(h, data[i]);	
	}
	print_hashtablelink(h);
	printf("please input you want to find value : ");
	datatype_t value = 0;
	scanf("%d", &value);
	hashtablelink_t *node = search_hashtablelink(h, value);
	if(NULL == node)
	{
		printf("no such data in the hash_table!\n");	
	}else{
		printf("find data is -> %p : %d\n", node, node->data);	
	}
}
