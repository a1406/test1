#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define printf

int get_palindrome_index(char *s, int begin, int end)
{
	if (s[begin] != s[end])
		return get_palindrome_index(s, begin, end - 1);
	return (0);
}

unsigned int *count_dup_num(char *s, int len)
{
	unsigned int *ret = malloc(sizeof(int) * len);
	int begin = 0;
	int num = 0;
	int i;
	for (i = 1; i < len; i++) {
		if (s[i] == s[i - 1]) {
			++num;
		} else {
			ret[begin] = num;
			ret[i - 1] = num;			
			num = 0;
			begin = i;
		}
	}

	ret[begin] = num;
	ret[len - 1] = num;
	return ret;
}

char* shortestPalindrome(char* s) {
	int len = strlen(s);
	int last = get_palindrome_index(s, 0, len - 1);
	return NULL;
}

int main(int argc, char *argv[])
{
/*	
	unsigned int *dup = count_dup_num(argv[1], strlen(argv[1]));
	int i;
	for (i = 0; i < strlen(argv[1]); i++) {
		printf("%02d ", argv[1][i]);
	}
	printf("\n");
	
	for (i = 0; i < strlen(argv[1]); i++) {
		printf("%02d ", dup[i]);
	}
	printf("\n");	
	return (0);
*/	
    char *ret = shortestPalindrome(argv[1]);
	printf("%s\n", ret);
    return 0;
}

