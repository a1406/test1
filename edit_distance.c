#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int minDistance(char* word1, char* word2) {
	int len1 = strlen(word1);
	int len2 = strlen(word2);
	int *record = malloc(sizeof(int) * len1 * len2);
	int i, j;
	for (i = 0; i < len1; ++i) {
		for (j = 0; j < len2; ++j) {
			
		}
	}
	return (0);
}

int main(int argc, char *argv[])
{
    int ret = minDistance(argv[1], argv[2]);
	printf("ret = %d\n", ret);

    return 0;
}
