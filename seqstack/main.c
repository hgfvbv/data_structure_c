#include "seqstack.h"

void main(int args, const char* argv[])
{
	seqstack_t *s = create_empty_seqstack();
	char cs[MAX] = { '!', 'a', 'n' ,'i' ,'h', 'c', ' ', 'e', 'v', 'o', 'l', ' ', 'I' };
	int i = 0;
	while(!is_full_seqstack(s))
	{
		push_seqstack(s, cs[i++]);
	}
	printf("top : %c \n", get_top_seqstack(s));
	// printf("pop : %c \n", pop_seqstack(s));
	while(!is_empty_seqstack(s))
	{
		printf("%c ", pop_seqstack(s));
	}
	printf("\n");
}
