#include "linkstack.h"

void main(int args, const char* argv[])
{
	linkstack_t *l = create_empty_linkstack();
	datatype_t array[] = {'a','n','i','h','c'};
	int arrayCount = sizeof(array) / sizeof(array[0]);
	for(int i = 0; i < arrayCount; ++i)
	{
		push_linkstack(l, array[i]);
	}
	printf("Top data = %c\n", get_top_linkstack(l));
       while(!is_empty_linkstack(l))
       {
	       printf("%c", pop_linkstack(l));
       }	       
       printf("\n");
}
