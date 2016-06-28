#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int minDistance(char* word1, char* word2) {
	int len1 = strlen(word1) + 1;
	int len2 = strlen(word2) + 1;
	int *record = malloc(sizeof(int) * (len1) * (len2));
	int i, j;

	memset(record, 0, (sizeof(int) * (len1) * (len2)));

	for (i = 1; i < len2; ++i) {
		for (j = 1; j < len1; ++j) {
			int max = record[(i - 1) * len1 + j];
			if (record[i * len1 + j - 1] > max)
				max = record[i * len1 + j - 1];
			if (word1[j - 1] == word2[i - 1])
				record[i * len1 + j] = max + 1;
			else
				record[i * len1 + j] = max;
//			record[i * len1 + j] = 0;
		}
	}

	for (i = 0; i < len2; i++) {
		for (j = 0; j < len1; j++) {
			printf("%d ", record[i * len1 + j]);
		}
		printf("\n");
		
	}
	
	int max = (record[len1 * len2 - 1]);
	int t1 = len1 - 1 - max;
	int t2 = len2 - 1 - max;
	int ret = len1 - ret + len2 - ret - 2;
	return ret;
}

int main(int argc, char *argv[])
{
    int ret = minDistance(argv[1], argv[2]);
	printf("ret = %d\n", ret);

    return 0;
}
