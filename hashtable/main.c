#include "hashtable.h"

void main(int argc, const char* argv[])
{
	hashtable_t *h = NULL;
	h = create_hashtable();
	datatype_t data[MAX] = {13,39,27,28,26,30,38,16,14,19};
	datatype_t value;
	int i = -1;
	while(!is_full_hashtable(h))
	{
		insert_data_hash(h, data[++i]);	
	}	
	print_hash_table(h);
	printf("please input you want find value : ");
	scanf("%d", &value);
	value = search_hash_table(h, value);
	if(value < 0)
	{
		printf("no such data in the hash tabled!\n");	
	}else{
		printf("hash table index is %d\n", value);	
	}
	free(h->elem_p);
	free(h);
	h = NULL;
}
