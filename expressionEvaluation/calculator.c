#include "calculator.h"

int get_number(char *p)
{
	int data = 0;
	for(int i = 0; '\0' != p[i]; ++i)
	{
		data = data * 10 + p[i] - '0';	
	}
	return data;
}

int get_level(char operator)
{
        switch(operator)
        {
        	case '+':
        	case '-':
                	return 1;
        	case '*':
        	case '/':
                	return 2;
        	default:
                	printf("Invalid operator : %c.", operator);
                	return -1;
        }
}

int compute(linkstack_t *opd, linkstack_t *opt)
{
                int data,data1,data2;
                char c = 0;
                data2 = pop_linkstack(opd);
                data1 = pop_linkstack(opd);
                c = pop_linkstack(opt);
                switch(c)
                {
               		 case '+':
                         	data = data1 + data2;
                	 	break;
                         case '-':
				data = data1 - data2;
			 	break;	
			case '*':
				data = data1 * data2;
				break;
			case '/':
				data = data1 / data2;
				break;
                }
                push_linkstack(opd, data);
}
