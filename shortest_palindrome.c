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

char* shortestPalindrome(char* s) {
	int len = strlen(s);
	int last = get_palindrome_index(s, 0, len - 1);
	return NULL;
}

int main(int argc, char *argv[])
{
    char *ret = shortestPalindrome(argv[1]);
	printf("%s\n", ret);
    return 0;
}

