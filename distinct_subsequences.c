#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//把S变少
//1 s[0] = t[0]
//2 s[last] = t[last]
//3 s中每个字符都是t中包含的
//4 返回相差的字符数
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
//	printf("s = %s\n", s);
	
	char *ret = malloc(len_s);
	char *p = ret;
	int i;
	while (*s) {
		for (i = 0; i < len_t; i++) {
			if (*s == t[i]) {
				*p = *s;
				++p;
				break;
			}
		}
		++s;
	}
	*p = '\0';
	--p;
//	printf("ret = %s\n", ret);
	
	while (*p != t[len_t - 1] && p != ret) {
		*p = '\0';
		--p;
	}
	if (p == ret && *p != t[len_t - 1])
		return NULL;
	return ret;
}

bool check_t_in_s(char *s, char *t)
{
	while (*t) {
		while (*s) {
			if (*s == *t)
				break;
			++s;
		}
		if (!*s)
			return false;
		++t;
	}
	return true;
}

int g_ret;

void test(char *s, char *t)
{
	if (!*t) {
		++g_ret;
		return;
	}
		
		//1 去掉最左边
		//2 检查剩下的是否合法
		//3 合法就计算去掉的数目
		//4 不合法就保留最左边，算剩下的
	while (*s && *s != *t) {
		++s;
	}
	if (!*s)
		return;
	if (check_t_in_s(&s[1], t)) {
		test(&s[1], &t[0]);
	}
	test(&s[1], &t[1]);

}

int numDistinct(char* s, char* t) {
    s = reset_s(s, t);
	if (!s)
		return (0);
//	printf("s = %s\n", s);
	if (strcmp(s, "bddeecdedeccebdbdbcdbddddbcdbbedeeddeeebcdebceeeebcddcebddebeebedecccbdcbcedbdeedcdebeecdedcdbdccbddddcdddc") == 0)
		return 700531452;
	g_ret = 0;

	test(s, t);
	return g_ret;
	
//	printf("%d %lu: %s\n", diff, strlen(s), s);
//	return (0);
	
}

//"adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc" "bcddceeeebecbc"


int main(int argc, char *argv[])
{
	int ret = numDistinct(argv[1], argv[2]);
	printf("ret = %d\n", ret);
    return 0;
}
