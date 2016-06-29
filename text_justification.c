#include <stdio.h>
#include <stdlib.h>

/**
 *  * Return an array of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
	*returnSize = 0;
	return NULL;
}

int main(int argc, char *argv[])
{
	int size;
	int maxWidth = atoi(argv[1]);
    char **ret = fullJustify(&argv[2], argc - 2, maxWidth, &size);
	int i;
	for (i = 0; i < size; ++i) {
		printf("[%s]\n", ret[i]);
	}
    return 0;
}

