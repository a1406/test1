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

bool check_palindrome(char *a, char *b)
{
	int len1 = strlen(a);
	int len2 = strlen(b);
	
	return false;
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
