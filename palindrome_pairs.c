#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//#define printf

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
	g_words = words;
	int **ret = malloc(sizeof(int *) * 4000);
	(*columnSizes) = malloc(sizeof(int*) * 4000);
	*returnSize = 0;
	int *sort1, *sort2;
	sort_words(wordsSize, &sort1, &sort2);	

	int i, j;
	int t;
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
	int *column;
	int ret_size;
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
