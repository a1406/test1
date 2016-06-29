#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_palindrome_index(int index, int size)
{
	return size - 1 - index;
}

int get_mid_index(int size)
{
	return (size - 2) / 2;
}

char *alloc_palindrome(char *s, int len, int mid)
{
	return NULL;
}


char* shortestPalindrome(char* s) {
	int len = strlen(s);

	int mid = get_mid_index(len);
	int tmp_len = len;
	while (mid > 0) {
		int i;
		for (i = 0; i < mid; ++i) {
			int index = get_palindrome_index(i, tmp_len);
			if (s[i] != s[index])
				break;
		}
		if (i == mid) {
			return alloc_palindrome(s, len, mid);
		}
		--tmp_len;
		--mid;
	}

	return alloc_palindrome(s, len, mid);
}

int main(int argc, char *argv[])
{
    char *ret = shortestPalindrome(argv[1]);
	printf("%s\n", ret);
    return 0;
}

