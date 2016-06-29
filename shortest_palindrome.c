#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_palindrome_index(int index, int size)
{
	return size - 1 - index;
}


char* shortestPalindrome(char* s) {
	int len = strlen(s);
	char *ret = malloc(len);
	int mid = len / 2;
	
	return (ret);
}

int main(int argc, char *argv[])
{
    char *ret = shortestPalindrome(argv[1]);
	printf("%s\n", ret);
    return 0;
}

