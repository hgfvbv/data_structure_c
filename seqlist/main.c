#include "seqlist.h"

void main(int args, const char* argv[])
{
	seqlist_t *l = create_empty_seqlist();
	datatype_t data;
	printf("please input %d number : ", MAX);
	while(!is_full_seqlist(l))
	{
		scanf("%d", &data);
		insert_data_seqlist(l, data);
	}
	printf_data_seqlist(l);
	printf("===============================\n");
	printf("please input you want to delete data : ");
	scanf("%d", &data);
	int ret = delete_data_seqlist(l, data);
	if(ret < 0)
	{
		printf("\033[47;34;1;5mseqlist is empty or data is not exist!\033[0m\n");
		return;
	}
	printf_data_seqlist(l);
	free(l);
	l = NULL;
}
