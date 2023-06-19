#include "calculator.h"

void main(int argc, const char* argv[])
{
	char buf[1024] = {0};
	char num_buf[50] = {0};
	char *p = buf;
	int data = 0, i = 0, nbf = 0;
	int is_num = 0;
	linkstack_t *operand = create_empty_linkstack();
	linkstack_t *operator = create_empty_linkstack();
	printf("请输入计算表达式 : ");
	scanf("%s", p);
	while('\0' != *(p + i))
	{
		char ch = *(p + i);
		while(ch >= '0' && ch <= '9')
		{
			is_num = 1;
			num_buf[nbf] = ch;
			i++;
			nbf++;
			ch = *(p + i);
		}	

		if(1 == is_num)
		{
			data = get_number(num_buf);
			push_linkstack(operand, data);
		}
		is_num = 0;
		nbf = 0;
		memset(num_buf, 0, sizeof(num_buf) / sizeof(num_buf[0]));
		data = 0;
		if('+' == ch || '-' == ch || '*' == ch || '/' == ch || '(' == ch || ')' == ch)
		{
			if(')' == ch)
			{
				while(operator->n > 0 && get_top_linkstack(operator) != '(')
				{
					compute(operand, operator);	
				}	
				if(get_top_linkstack(operator) == '(')
				{
					pop_linkstack(operator);	
				
				}
			}else{
				while(operator->n > 0 && ch != '(' && get_top_linkstack(operator) != '(' && get_level(get_top_linkstack(operator)) >= get_level(ch))
				{
					compute(operand, operator);	
				}
				push_linkstack(operator, ch);
			}
		}
		i++;
	}

	while(!is_empty_linkstack(operator))
	{
		compute(operand, operator);	
	}
	printf("结果为 : %d\n", get_top_linkstack(operand));
	free(operand);
	free(operator);
}
