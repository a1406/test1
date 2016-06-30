#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

bool check_palindrome(char *a, char *b)
{
	int len1 = strlen(a);
	int len2 = strlen(b);
	int last_index = get_last_index(len1, len2);
	int i;
	for (i = 0; i <= last_index; i++) {
		int op_index = get_op_index(len1, len2, i);
		if (get_c(a, len1, b, i) != get_c(a, len1, b, op_index))
			return false;
	}
	
	return true;
}

/**
 *  * Return an array of arrays of size *returnSize.
 *   * The sizes of the arrays are returned as *columnSizes array.
 *    * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 *     */
int** palindromePairs(char** words, int wordsSize, int** columnSizes, int* returnSize) {
	return NULL;
}

int main(int argc, char *argv[])
{
    if (check_palindrome(argv[1], argv[2]))
		printf("true\n");
	else
		printf("false\n");
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
