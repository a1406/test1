#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#define printf

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

bool check_palindrome(char *s, unsigned int *dup, int len)
{
	int i;
	for (i = 0; i <= len / 2; i++) {
		if (s[i] != s[len - 1 - i]) 
			return false;
		if (dup[i] != dup[len - 1 - i])
			return false;
		i += dup[i];
	}
	return true;
}

char* shortestPalindrome(char* s) {
	int len = strlen(s);
	unsigned int *dup = count_dup_num(s, len);
	check_palindrome(s, dup, len);

	return NULL;
}

int main(int argc, char *argv[])
{

	unsigned int *dup = count_dup_num(argv[1], strlen(argv[1]));
	if (check_palindrome(argv[1], dup, strlen(argv[1])))
		printf("yes\n");
	else
		printf("no\n");
	return;
/*	
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

