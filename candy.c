#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static int compint(const void *p1, const void *p2)
{
	return bcmp(p1, p2, sizeof(int));
}

int level_max(int size)
{
	return (1 + size) * size / 2;
}

int candy(int* ratings, int ratingsSize) {
	static int dup_num[1000];
	int dup_pos = 0;
    int ret = level_max(ratingsSize);
	int i;
	qsort(ratings, ratingsSize, sizeof(int), compint);
	dup_num[0] = 1;
	bool push_dup_pos = false;
    for (i = 1; i < ratingsSize; ++i)
    {	
		if (ratings[i] == ratings[i - 1])
		{
			dup_num[dup_pos]++;
			push_dup_pos = true;
		}
		else if (push_dup_pos)
		{
			++dup_pos;
			dup_num[dup_pos] = 1;
			push_dup_pos = false;
		}
    }

	if (push_dup_pos)
		++dup_pos;

	qsort(dup_num, dup_pos, sizeof(int), compint);
	int j;
	for (j = 1, i = dup_pos - 1; i >= 0; --i, ++j)
	{
		ret = ret - (ratingsSize - j);
		if (dup_num[i] - 2 > 0)
		{
			ret = ret - level_max(dup_num[i] - 2);
		}
	}
	
    return (ret);
}

int main(int argc, char *argv[])
{
	int *ratings = malloc(sizeof(int) * (argc - 1));
	for (int i = 1; i < argc; ++i)
	{
//		printf("%d\n", level_max(atoi(argv[i])));
		ratings[i-1] = atoi(argv[i]);
	}
	printf("%d\n", candy(ratings, argc - 1));
    return 0;
}

