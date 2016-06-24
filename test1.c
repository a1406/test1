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

int count_oper_entry(char *entry, int len)
{
	int entry_len = get_oper_entry_len(len);
	return (0);
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
		int ret = count_oper_entry(entry, len);
		printf(" = %d\n", ret);
	}
}

int main(int argc, char *argv[])
{
	int i;
	int len;
	char *int_array;
	char *oper_array;
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









