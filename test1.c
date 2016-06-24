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
};

int get_oper_entry_len(int len)
{
	return (len - 1) * 2 + 1;
}

int get_oper_entry_num(int len)
{
	int ret = 1;
	int i;
	for (i = 0; i < len - 1; ++i)
		ret *= 4;
	return ret;
}

char *alloc_all_oper_array(int len)
{
	char *ret = malloc(sizeof(char) * get_oper_entry_len(len) * get_oper_entry_num(len));
	return ret;
}

int *alloc_int_array(char *num, int len)
{
	int i;
	int *ret = malloc(sizeof(int) * len);
	for (i = 0; i < len; ++i)
	{
		(ret)[i] = num[i] - '0';
	}
	return (0);
	
}

int main(int argc, char *argv[])
{
	int i;
	int len;
	int *int_array;
	char *oper_array;
	for (i = 1; i < argc; ++i)
	{
		len = strlen(argv[i]);
		int_array = alloc_int_array(argv[i], len);
		oper_array = alloc_all_oper_array(len);
		
		free(int_array);
		free(oper_array);		
	}
	return (0);
}









