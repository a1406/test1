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
	return s;
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
