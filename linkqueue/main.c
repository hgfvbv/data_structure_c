#include "linkqueue.h"

void main(int argc, const char* argv[])
{
	linkqueue_t *l = create_empty_linkqueue();
	for(int i = 0; i < 10; ++i)
	{
		enter_linkqueue(l, i);	
	}
	while(!is_empty_linkqueue(l))
	{
		printf("%d ", delete_linkqueue(l));	
	}
	printf("\n");
}
