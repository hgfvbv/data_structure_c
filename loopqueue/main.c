#include "loopqueue.h"

void main(int argc, const char* argv[])
{
	loopqueue_t *l = create_empty_loopqueue();
	int i = 0;
	while(!is_full_loopqueue(l))
	{
		enter_loopqueue(l, i++);	
	}
	while(!is_empty_loopqueue(l))
	{
		printf("%d ", delete_loopqueue(l));	
	}
	printf("\n");
}
