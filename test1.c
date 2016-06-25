#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

enum OPER
{
	NONE,
	ADD,
	SUB,
	MUL,
	MERGE,
	MAX_OPER
};

static char oper_level[] =
{
	0,
	1,
	1,
	2,
	3,
	0
};

int get_oper_entry_len(int len)
{
//	return (len - 1) * 2 + 1;
	return len * 2 - 1;
}

int get_oper_entry_num(int len)
{
	int ret = 1;
	int i;
	for (i = 0; i < len - 1; ++i)
		ret *= 4;
	return ret;
}

char *alloc_all_oper_array(char *int_array, int len)
{
	int entry_len = get_oper_entry_len(len);
	int entry_num = get_oper_entry_num(len);
	char *ret = malloc(sizeof(char) * entry_len * entry_num);
	int i, j;
	for (i = 0; i < entry_num; ++i)
	{
		char *entry = ret + i * entry_len;
		for (j = 0; j < len; ++j)
		{
			entry[(j * 2)] = int_array[j];
		}
	}

//	num / (total / 4) % 4

	for (i = 0; i < entry_num; ++i)
	{
		char *entry = ret + i * entry_len;
		int base = 1;
		for (j = 0; j < len - 1; ++j)
		{
			base *= 4;
			entry[(j * 2) + 1] = i / (entry_num / base) % 4 + 1;
		}
	}
		
	return ret;
}

char *alloc_int_array(char *num, int len)
{
	int i;
	char *ret = malloc(sizeof(char) * len);
	for (i = 0; i < len; ++i)
	{
		(ret)[i] = num[i] - '0';
	}
	return (ret);
	
}

bool g_invalid_num = false; //不允许出现01  02这样0开头的数字，发现就过滤掉这一条

//从右到左算
int count_left(int *begin, int *end)
{
	int ret = end[0];
	do
	{
		switch (end[-1])
		{
			case ADD:
				ret = end[-2] + ret;
				break;
			case SUB:
				ret = end[-2] - ret;
				break;
			case MUL:
				ret = ret * end[-2];
				break;
			case MERGE:
				if (end[-2] == 0)
				{
					g_invalid_num = true;
					return (0);
				}
				ret = ret + end[-2] * 10;
				break;				
		}
		end -= 2;
	}
	while (begin != end);
	return ret;
}

int count_oper_entry(char *entry, int len)
{
//	int entry_len = get_oper_entry_len(len);
	int buf[100];// = {0};
	g_invalid_num = false;
	int *tmp_int_array = &buf[0];
	int tmp_int_pos = 1;  //总是指向下一个操作符
	tmp_int_array[0] = entry[0];
	char level1 = 0, level2;
	int i;
	int ret = 0;
	for (i = 1; i < len; ++i)
	{
		tmp_int_array[tmp_int_pos] = entry[i * 2 - 1];
		tmp_int_array[tmp_int_pos+1] = entry[i * 2];
		tmp_int_pos += 2;

		level2 = oper_level[entry[i * 2 - 1]];
		if (level2 > level1)
		{
			level1 = level2;
		}
		else
		{
				//计算begin_pos
				//end_pos = tmp_int_pos - 3
				//tmp_int_pos = begin_pos + 1
			int end_pos = tmp_int_pos - 3;
			int begin_pos = end_pos - 2;
			for (; begin_pos > 0;)
			{
				int left_level = oper_level[tmp_int_array[begin_pos - 1]];
				if (left_level < level2)
					break;
				begin_pos -= 2;
			}
			ret = count_left(&tmp_int_array[begin_pos], &tmp_int_array[end_pos]);
			if (g_invalid_num)
				return (0);
			tmp_int_pos = begin_pos + 3;
			tmp_int_array[begin_pos] = ret;
			tmp_int_array[begin_pos + 1] = entry[i * 2 - 1];
			tmp_int_array[begin_pos + 2] = entry[i * 2];
			level1 = level2;
			
			
//			ret = count_left(tmp_int_array, tmp_int_pos - 2);
//			tmp_int_array = tmp_int_array + tmp_int_pos - 3;
//			tmp_int_pos = 3;
//			tmp_int_array[0] = ret;
		}
	}

		//剩余的按从右到左算一遍
/*	
	while (tmp_int_pos != 1)
	{
		ret = count_left(&tmp_int_array[tmp_int_pos - 3], &tmp_int_array[tmp_int_pos - 1]);
		tmp_int_array[tmp_int_pos - 3] = ret;
		tmp_int_pos -= 2;
	}
*/	
	ret = count_left(&tmp_int_array[0], &tmp_int_array[tmp_int_pos - 1]);
	if (g_invalid_num)
		return (0);	
//	return (tmp_int_array[0]);
	return ret;
}

int *count_oper_array(char *oper_array, int len)
{
	int entry_num = get_oper_entry_num(len);
	int entry_len = get_oper_entry_len(len);	
	int *ret = malloc(sizeof(int) * entry_num);
	int i;
	for (i = 0; i < entry_num; ++i)
	{
		char *entry = oper_array + i * entry_len;		
		ret[i] = count_oper_entry(entry, len);
	}
	return (0);
}

void print_oper_array(char *oper_array, int len)
{
	int i, j;
	int entry_len = get_oper_entry_len(len);
	int entry_num = get_oper_entry_num(len);
	int *result_array = malloc(sizeof(int) * entry_num);

	for (i = 0; i < entry_num; ++i)
	{
		char *entry = oper_array + i * entry_len;		
		result_array[i] = count_oper_entry(entry, len);
	}
	
	for (i = 0; i < entry_num; ++i)
	{
		bool b = true;
		char *entry = oper_array + i * entry_len;
		for (j = 0; j < entry_len; ++j)
		{
			if (b)
			{
				printf("%d", entry[j]);
			}
			else
			{
				switch (entry[j])
				{
					case ADD:
						printf(" + ");
						break;
					case SUB:
						printf(" - ");
						break;
					case MUL:
						printf(" * ");
						break;
				}
			}
			b = !b;
		}
//		int ret = count_oper_entry(entry, len);
		printf(" = %d\n", result_array[i]);
	}
}

/**
 *  * Return an array of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */
char** addOperators(char* num, int target, int* returnSize) {
	char *int_array;
	char *oper_array;
	int len = strlen(num);

	if (len == 0)
	{
		*returnSize = 0;
		return NULL;
	}
	
	int_array = alloc_int_array(num, len);
	oper_array = alloc_all_oper_array(int_array, len);

	int entry_len = get_oper_entry_len(len);
	int entry_num = get_oper_entry_num(len);

	int *result_array = malloc(sizeof(int) * entry_num);
	*returnSize = 0;

	static char *ret[300];
	int i;

	for (i = 0; i < entry_num; ++i)
	{
		char *entry = oper_array + i * entry_len;		
		result_array[i] = count_oper_entry(entry, len);
		if (result_array[i] == target && !g_invalid_num)
		{
			ret[*returnSize] = malloc(entry_len + 1);
			bool b = true;
			int j;
			char *p = ret[*returnSize];
			for (j = 0; j < entry_len; ++j)
			{
				if (b)
				{
					p += sprintf(p, "%d", entry[j]);
				}
				else
				{
					switch (entry[j])
					{
						case ADD:
							p += sprintf(p, "+");
							break;
						case SUB:
							p += sprintf(p, "-");							
							break;
						case MUL:
							p += sprintf(p, "*");							
							break;							
					}
				}
				b = !b;
			}
			++(*returnSize);
		}
	}

	free(result_array);
	free(int_array);
	free(oper_array);		
	return ret;
}

int main(int argc, char *argv[])
{
	int i;
	int len;
	char *int_array;
	char *oper_array;

	char test[] = {2,
				   4,1,
				   4,4,
				   4,7,
				   4,4,
				   4,8,
				   4,3,
				   4,6,
				   4,4,
				   4,8};
	len = 10;

	int ret = count_oper_entry(&test[0], len);
	printf("ret = %d\n", ret);
	return (0);

	if (argc == 3)
	{
		char **ret = addOperators(argv[1], atoi(argv[2]), &len);
		for (i = 0; i < len; ++i)
		{
			printf("%s\n", ret[i]);
		}
	}
	return (0);

	for (i = 1; i < argc; ++i)
	{
		len = strlen(argv[i]);
		int_array = alloc_int_array(argv[i], len);
		oper_array = alloc_all_oper_array(int_array, len);
		
		print_oper_array(oper_array, len);
		
		free(int_array);
		free(oper_array);		
	}
	return (0);
}
