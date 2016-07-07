#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int is_have_one(int num)
{
	int i;
	int ret = 0;
	for (i = 0; i < 3; i++) {
		if (num % 10 == 1)
			++ret;
		num = num / 10;
	}
	return ret;
}

int main(int argc, char *argv[])
{
    int i;
	int num = 0;
	for (i = 0; i < 1000; i++) {
		num += is_have_one(i);
		printf("%d, ", num);
	}
	printf("\n");
	
    return 0;
}
