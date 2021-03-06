#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//#define printf

typedef struct data__
{
	unsigned long long *l1;
	unsigned long long *l2;
	unsigned char len;
	unsigned char l_len;
} data;

data **g_data;

int get_data_len(int len)
{
	int ret = len / 8;
	if (len % 8 != 0)
		++ret;
	return ret;
}

data *alloc_data(char *s)
{
	int len = strlen(s);
	data *ret = malloc(sizeof(data));
	int data_len = get_data_len(len);
	int i;
	
	ret->len = len;
	ret->l_len = data_len;
	ret->l1 = malloc(sizeof(long long) * data_len);
	ret->l2 = malloc(sizeof(long long) * data_len);
	memset(ret->l1, 0, sizeof(long long) * data_len);
	memset(ret->l2, 0, sizeof(long long) * data_len);	

	char *head = &s[0], *tail = &s[len - 1];
	char *l1 = (char *)ret->l1;
	char *l2 = (char *)ret->l2;
	int j;
	l1 += 7;
	l2 += 7;
	for (i = 0, j = 0; i < len; i++, j++) {
		if (j == 8) {
			j = 0;
			l1 += 15;
			l2 += 15;
		}
		*l1 = *head;
		*l2 = *tail;
		++head;
		--tail;
		--l1;
		--l2;
	}
	
	return ret;
}

int get_op_index(int len1, int len2, int index)
{
	return (len1 + len2 - index - 1);
}

int get_last_index(int len1, int len2)
{
	return (len1 + len2) / 2 - 1;
}

char get_c(char *a, int len1, char *b, int index)
{
	if (index < len1)
		return a[index];
	return b[index - len1];
}

//0 成功
//1 继续下一个
//-1 结束
int check_palindrome(char *a, char *b)
{
	int len1 = strlen(a);
	int len2 = strlen(b);
	int last_index = get_last_index(len1, len2);
	int i;
	for (i = 0; i <= last_index; i++) {
		int op_index = get_op_index(len1, len2, i);
		char c1 = get_c(a, len1, b, i);
		char c2 = get_c(a, len1, b, op_index);
		if (c1 != c2) {
			if (i >= len1 || i >= len2)
				return 1;
			if (c1 > c2)
				return 1;
			return -1;
//			return 1;
		}
	}
	
	return 0;
}

char **g_words;
static int comp1(const void *p1, const void *p2)
{
	char *w1 = g_words[*(int *)p1];
	char *w2 = g_words[*(int *)p2];
	while (*w1 && *w2) {
		if (*w1 > *w2)
			return 1;
		if (*w2 > *w1)
			return -1;
		++w1;
		++w2;
	}

	if (!*w1 && !*w2)
		return 0;
	if (!*w1)
		return -1;
	return 1;
}

static int comp2(const void *p1, const void *p2)
{
	char *w1 = g_words[*(int *)p1];
	char *w2 = g_words[*(int *)p2];
	int len1 = strlen(w1);
	int len2 = strlen(w2);
	int i;
	for (i = 0; i < len1 && i < len2; i++) {
		if (w1[len1 - i - 1] > w2[len2 - i - 1])
			return 1;
		if (w1[len1 - i - 1] < w2[len2 - i - 1])
			return -1;		
	}
	if (len1 == len2)
		return (0);
	if (len1 > len2)
		return 1;
	return -1;
}

void sort_words(int size, int **sort1, int **sort2)
{
	int i;
	*sort1 = malloc(sizeof(int) * size);
	*sort2 = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++) {
		(*sort1)[i] = i;
		(*sort2)[i] = i;
	}


	qsort(*sort1, size, sizeof(int), comp1);
	qsort(*sort2, size, sizeof(int), comp2);	
}

/**
 *  * Return an array of arrays of size *returnSize.
 *   * The sizes of the arrays are returned as *columnSizes array.
 *    * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 *     */
int** palindromePairs(char** words, int wordsSize, int** columnSizes, int* returnSize) {
	int i, j;
	int t;
	g_words = words;
	int **ret = malloc(sizeof(int *) * 8000);
	(*columnSizes) = malloc(sizeof(int*) * 8000);
	*returnSize = 0;
	int *sort1, *sort2;
	sort_words(wordsSize, &sort1, &sort2);

	for (i = 0; i < wordsSize; i++) {
		
	}

	for (i = 0; i < wordsSize; ++i) {
		for (j = 0; j < wordsSize; ++j) {
			if (sort1[i] == sort2[j])
				continue;
			t = check_palindrome(words[sort1[i]], words[sort2[j]]);
//			if (check_palindrome(words[i], words[j])) {
			if (t == 0) {
				ret[*returnSize] = malloc(sizeof(int) * 2);
				ret[*returnSize][0] = sort1[i];
				ret[*returnSize][1] = sort2[j];

				(*columnSizes)[*returnSize] = 2;
				
				++(*returnSize);
			}
			if (t < 0)
				break;
		}
	}
		
	return ret;
}

int main(int argc, char *argv[])
{
	data *data = alloc_data(argv[1]);
	printf("len = %d, l_len = %d\n", data->len, data->l_len);
	int iii;
	for (iii = 0; iii < data->l_len; iii++) {
		printf("%llx ", data->l1[iii]);
	}
	printf("\n");
	for (iii = 0; iii < data->l_len; iii++) {
		printf("%llx ", data->l2[iii]);
	}
	printf("\n");
	return (0);
	
	int *column;
	int ret_size;
	printf("argc = %d\n", argc);
	int **ret = palindromePairs(&argv[1], argc - 1, &column, &ret_size);
	int i;
	for (i = 0; i < ret_size; i++) {
		printf("[%d, %d]\n", ret[i][0], ret[i][1]);
	}
/*	
	int i;
	g_words = &argv[1];
	int *sort1, *sort2;
	for (i = 0; i < argc - 1; i++) {
		printf("%d: %s\n", i, argv[i+1]);
	}
	
	sort_words(argc - 1, &sort1, &sort2);
	for (i = 0; i < argc - 1; i++) {
		printf("%d ", sort1[i]);
	}
	printf("\n");
	for (i = 0; i < argc - 1; i++) {
		printf("%d ", sort2[i]);
	}
	printf("\n");	
	return (0);
*/
/*	
    if (check_palindrome(argv[1], argv[2]))
		printf("true\n");
	else
		printf("false\n");
*/		
    return 0;
}

/*
Example 1:
	Given words = ["bat", "tab", "cat"]
	Return [[0, 1], [1, 0]]
	The palindromes are ["battab", "tabbat"]
Example 2:
	Given words = ["abcd", "dcba", "lls", "s", "sssll"]
	Return [[0, 1], [1, 0], [3, 2], [2, 4]]
	The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/
