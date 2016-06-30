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

//s[i] != s[j]   jump last dup num
//dup[0] > dup[j] jump last 2 dup num
//dup[i] > dup[j] jump last dup num
//dup[0] < dup[j] 
//dup[i] < dup[j] jump last dup num

int check_palindrome(char *s, unsigned int *dup, int len)
{
	int i;
	int ret = dup[len - 1] + 1;
	int success_ret = 0;
	for (i = 0; i <= len / 2; i++) {
		int	tmp_dup = dup[len - 1 - i];
			
		if (s[i] != s[len - 1 - i]) {
			return ret;
//			return false;
		}
		if (dup[i] > tmp_dup) {
			return ret;
//			return false;
		}
		if (dup[i] < tmp_dup) {
			if (i != 0) {
				return ret;
			} else {
				len = len - tmp_dup - dup[i];
				success_ret += tmp_dup - dup[i];
			}
//			return false;
		}
		
		i += dup[i];
	}
	return success_ret;
}

char *alloc_palindrome(char *s, int len, int end_index)
{
	char *ret = malloc(len - 1 - end_index + len + 1);

	int i = len - 1;
	int index = 0;
	while (i > end_index) {
		ret[index] = s[i];
		--i;
		++index;
	}
	for (i = 0; i < len; i++) {
		ret[index] = s[i];
		++index;
	}
	ret[index] = '\0';
	return ret;
}

char* shortestPalindrome(char* s) {
	int len = strlen(s);
	unsigned int *dup = count_dup_num(s, len);
//	check_palindrome(s, dup, len);
	int end_index = len - 1;
	while (end_index > 0) {
		int ret = check_palindrome(s, dup, end_index + 1);
		if (ret == 0) {
			return alloc_palindrome(s, len, end_index);
		}
		end_index -= (ret);//dup[end_index];
			//--end_index;
	}

	return alloc_palindrome(s, len, 0);
}

int main(int argc, char *argv[])
{
/*
	unsigned int *dup = count_dup_num(argv[1], strlen(argv[1]));
	int t1 = check_palindrome(argv[1], dup, strlen(argv[1]));
	printf("ret = %d\n", t1);
	return;
*/
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

