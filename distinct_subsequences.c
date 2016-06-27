#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//把S变少
//1 s[0] = t[0]
//2 s[last] = t[last]
//3 s中每个字符都是t中包含的
char *reset_s(char *s, char *t)
{
	if (!t || !*t)
		return NULL;
	int len_t = strlen(t);
	while (*s && *s != t[0]) {
		++s;
	}
	if (!*s)
		return NULL;
	int len_s = strlen(s);
	
	char *ret = malloc(len_s);
	char *p = ret;
	int i;
	while (*s) {
		for (i = 0; i < len_t; i++) {
			if (*s == t[i]) {
				*p = *s;
				++p;
			}
		}
		++s;
	}
	while (*p != t[len_t - 1] && p != ret) {
		*p = '\0';
	}
	if (p == ret)
		return NULL;
	return ret;
}

int numDistinct(char* s, char* t) {
    s = reset_s(s, t);
	
}

int main(int argc, char *argv[])
{
	int ret = numDistinct(argv[1], argv[2]);
	printf("ret = %d\n", ret);
    return 0;
}
