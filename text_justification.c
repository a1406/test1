#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define printf 

static char *g_ret[100];

void fill_words(char *target, char **begin, int sum_words, int space, int extern_space, int max_len)
{
	int i, j;
	int target_len = 0;
	for (i = 0; i < sum_words - 1; i++) {
		int len = strlen(begin[i]);
		memcpy(&target[target_len], begin[i], len);
		target_len += len;
		for (j = 0; j < space; j++) {
			target[target_len] = ' ';
			++target_len;
		}
		if (extern_space) {
			target[target_len] = ' ';
			++target_len;			
			--extern_space;
		}
	}

	int len = strlen(begin[i]);
	memcpy(&target[target_len], begin[i], len);
	target_len += len;	
	
	for (i = target_len; i < max_len; i++) {
		target[target_len] = ' ';
		++target_len;			
	}
	target[target_len] = '\0';
}

/**
 *  * Return an array of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
	int i;
	char **begin;
	*returnSize = 0;
	int sum_words_len = 0;
	int sum_words = 0;
	begin = &words[0];
	
	for (i = 0; i < wordsSize; ++i) {
		int len = strlen(words[i]);
		sum_words_len += len;
		++sum_words;

		if (sum_words_len + sum_words - 1 > maxWidth) {
			sum_words_len -= len;
			--sum_words;
			int space, extern_space;
			if (sum_words <= 1) {
				space = 0;
				extern_space = 0;
			} else {
				space = (maxWidth - sum_words_len) / (sum_words - 1);
				extern_space = (maxWidth - sum_words_len) % (sum_words - 1);
			}
			printf("sum_word_len[%d] sum_words[%d] space[%d] extern_space[%d]\n", sum_words_len, sum_words, space, extern_space);
			
			g_ret[*returnSize] = malloc(maxWidth);
			fill_words(g_ret[*returnSize], begin, sum_words, space, extern_space, maxWidth);
			sum_words_len = 0;
			sum_words = 0;
			begin = &words[i];
			++(*returnSize);
			--i;
		}
	}
	
	g_ret[*returnSize] = malloc(maxWidth);
	fill_words(g_ret[*returnSize], begin, sum_words, 0, 0, maxWidth);
	++(*returnSize);
	return g_ret;
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

