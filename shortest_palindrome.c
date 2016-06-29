#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define printf

int get_palindrome_index(int index, int size)
{
	return size - 1 - index;
}

int get_mid_index(int size)
{
	return (size - 2) / 2;
}

char *alloc_palindrome(char *s, int len, int begin)
{
	int ret_len = len - begin + len + 1;
	char *ret = malloc(ret_len);
	ret[ret_len - 1] = '\0';
	printf("%s: begin = %d, ret_len = %d\n", __FUNCTION__, begin, ret_len - 1);

	int i, j;
	for (i = 0; i < len - begin; i++) {
		ret[i] = s[len - i - 1];
	}

	memcpy(&ret[len - begin], s, len);
//	
//	for (i = len - begin, j = 0; i < ret_len; i++, j++) {
//		ret[i] = s[j];
//	}
	return ret;
}

char *alloc_all_palindrome(char *s, int len)
{
	printf("%s\n", __FUNCTION__);
	char *ret = malloc(len + len + 1);
	ret[len + len] = '\0';
	int i;
	for (i = 0; i < len; i++) {
		ret[i] = s[len - i - 1];
	}
	memcpy(&ret[len], s, len);
	return ret;
}

char* shortestPalindrome(char* s) {
	int len = strlen(s);

	int mid;
	int tmp_len = len;
	while (tmp_len > 1) {
		int i;
		mid = get_mid_index(tmp_len);
		for (i = 0; i <= mid; ++i) {
			int index = get_palindrome_index(i, tmp_len);
			if (s[i] != s[index])
				break;
		}
		if (i > mid) {
			return alloc_palindrome(s, len, tmp_len);
		}
		--tmp_len;
	}

	return alloc_all_palindrome(s, len);
}

int main(int argc, char *argv[])
{
    char *ret = shortestPalindrome(argv[1]);
	printf("%s\n", ret);
    return 0;
}

