#include <stdio.h>

void output(int *p, int count)
{
	for(int i = 0; i < count; ++i)
	{
		printf("%d ", p[i]);	
	}
	printf("\n");
}

void bubble_sort(int *p, int count)
{
	int n = count - 1;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n - i; ++j)
		{
			if(p[j] > p[j + 1])
			{
				p[j] ^= p[j + 1];
				p[j + 1] ^= p[j];
				p[j] ^= p[j + 1];	
			}	
		}	
	}
}

void select_sort(int *p, int count) // 简单排序
{
	int k = 0;
	for(int i = 0; i < count; ++i)
	{
		k = i;
		for(int j = k + 1; j < count; ++j)
		{
			if(p[j] < p[k])
			{
				k = j;	
			}	
		}	
		if(k != i)
		{
			p[i] ^= p[k];
			p[k] ^= p[i];
			p[i] ^= p[k];	
		}
	}	
}

void direct_insert_sort(int *p, int count) // 直接插入法
{
	int temp = 0, j = 0;
	for(int i = 1; i < count; ++i)
	{
		if(p[i] < p[i - 1])
		{
			temp = p[i];
			for(j = i - 1; j >= 0 && temp < p[j]; --j)
			{
				p[j + 1] = p[j];	
			}	
			p[j + 1] = temp;
		}	
	}
}

void shell_sort(int *p, int count) // 希尔排序
{
	int j = 0;
	for(int k = count / 2; k >= 1; k = k / 2)
	{
		for(int i = k; i < count; ++i)
		{
			int temp = p[i];
			for(j = i - k; j >= 0 && p[j] > temp; j = j - k)
			{
				p[j + k] = p[j];	
			}
			p[j + k] = temp;
		}		
	}
}

void quick_sort(int *p, int low, int high) // 快速排序
{
	int i = low, j = high;
	int key = p[low];
	while(i < j)
	{
		while(i < j && p[j] >= key)
			--j;
		if(i < j)
		{
			p[i] = p[j];	
		}	
		while(i < j && p[i] <= key)
			++i;
		if(i < j)
		{
			p[j] = p[i];	
		}
	}
	p[i] = key;
	if(j - 1 > low)
	{
		quick_sort(p, low, j - 1);	
	}
	if(i + 1 < high)
	{
		quick_sort(p, i + 1, high);	
	}
}

void swap_data(int *x, int *y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

void heap_adjust(int *arr, int start, int end) // 堆排序 大顶堆
{
	int father_node = start;
	int son_node = father_node * 2 + 1;
	while(son_node <= end)
	{
		if(son_node + 1 <= end && arr[son_node] < arr[son_node + 1])
			++son_node;
		if(arr[father_node] > arr[son_node])
		{
			return;
		}else{
			swap_data(&arr[father_node], &arr[son_node]);	
			father_node = son_node;
			son_node = father_node * 2 + 1;
		}	
	}
}

void heap_min_adjust(int *arr, int start, int end) // 堆排序 小顶堆
{
	int father_node = start;
	int son_node = father_node * 2 + 1;
	while(son_node <= end)
	{
		if(son_node + 1 <= end && arr[son_node] > arr[son_node + 1])
			++son_node;
		if(arr[father_node] < arr[son_node])
		{
			return;	
		}else{
			swap_data(&arr[father_node], &arr[son_node]);
			father_node = son_node;
			son_node = father_node * 2 + 1;	
		}	
	}
}

void heap_sort(int *arr, int len)
{
	for(int i = len / 2 - 1; i >= 0; --i)
	{
		// heap_adjust(arr, i, len - 1);	
		heap_min_adjust(arr, i, len - 1);
	}
	for(int i = len - 1; i > 0; --i)
	{
		swap_data(&arr[0], &arr[i]);	
		// heap_adjust(arr, 0, i - 1);
		heap_min_adjust(arr, 0, i - 1);
	}
}

void main(int argc, const char* argv[])
{
	int a[] = {50, 36, 66, 76, 36, 12, 25, 95};
	int a_count = sizeof(a) / sizeof(a[0]);
	output(a, a_count);
	// bubble_sort(a, a_count);
	// select_sort(a, a_count);
	// direct_insert_sort(a, a_count);
	// shell_sort(a, a_count);
	// quick_sort(a, 0, a_count - 1);
	heap_sort(a, a_count);
	output(a, a_count);
}
