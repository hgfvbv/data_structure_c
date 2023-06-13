#include "head.h"

int ball_clock()
{
	linkstack_t *min_stack = NULL,
		    *min5_stack = NULL,
		    *hour_stack = NULL;
	linkqueue_t *ball_queue = NULL;
	int half_day = 0;
	int ball = 0;

	min_stack = create_empty_linkstack();
	min5_stack = create_empty_linkstack();
	hour_stack = create_empty_linkstack();

	ball_queue = create_empty_linkqueue();

	for(ball = 1; ball <= MAX; ++ball)
	{
		enter_linkqueue(ball_queue, ball);	
	}

	print_linkqueue(ball_queue->front);

	while(1)
	{
		ball = delete_linkqueue(ball_queue);
		if(min_stack->n < 4)
		{
			push_linkstack(min_stack, ball);
			continue;	
		}	

		while(!is_empty_linkstack(min_stack))
		{
			enter_linkqueue(ball_queue, pop_linkstack(min_stack));	
		}

		if(min5_stack->n < 11)
		{
			push_linkstack(min5_stack, ball);
			continue;	
		}

		while(!is_empty_linkstack(min5_stack))
		{
			enter_linkqueue(ball_queue, pop_linkstack(min5_stack));	
		}

		if(hour_stack->n < 11)
		{
			push_linkstack(hour_stack, ball);
			continue;	
		}

		while(!is_empty_linkstack(hour_stack))
		{
			enter_linkqueue(ball_queue, pop_linkstack(hour_stack));	
		}

		enter_linkqueue(ball_queue, ball);

		half_day++;

		if(is_original_queue(ball_queue))
			break;	
	}
	return half_day / 2;
}

void print_linkqueue(linknode_t *head)
{
	linknode_t *node = head->next;
	while(node)
	{
		printf("%-3d\t", node->data);
		node = node->next;	
	}
	putchar('\n');
}

int is_original_queue(linkqueue_t *lq)
{
	int i = 1;
	linknode_t *node = lq->front->next;
	for(i = 1; i <= MAX; ++i)
	{
		if(i != node->data)
			return 0;
		node = node->next;	
	}		
	return 1;
}
