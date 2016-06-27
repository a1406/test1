#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_NUMS 20

bool check_unique(int *prev, int prev_size, int now, int **ret, int ret_size)
{
	int i;
	for (i = 0; i < ret_size; ++i)
	{
		if (ret[i][prev_size] != now)
			continue;
		if (memcmp(&ret[i][0], prev, sizeof(int) * prev_size) == 0)
			return false;
	}
	return true;
}

void set_nums(int *nums, int size, int *prev, int prev_size, int **ret, int *ret_size)
{
	int i, j;
	int next_nums[MAX_NUMS];
	int next_prev[MAX_NUMS];

	if (size == 1)
	{
//		if (check_unique(prev, prev_size, nums[0], ret, *ret_size))
		{
			ret[*ret_size] = malloc(sizeof(int) * (prev_size + 1));
			memcpy(&ret[*ret_size][0], prev, sizeof(int) * prev_size);
			ret[*ret_size][prev_size] = nums[0];
/*
			printf("[ ");
			for (i = 0; i <= prev_size; ++i)
			{
				printf("%d ", ret[*ret_size][i]);
			}
			printf("]\n");			
*/			
			*ret_size = *ret_size + 1;
		}
		return;
	}
	
	memcpy(next_prev, prev, sizeof(int) * prev_size);
	for (i = 0; i < size; ++i)
	{
		if (i != 0 && nums[i] == nums[i-1])
			continue;
		int *p = &next_nums[0];
		for (j = 0; j < size; ++j)
		{
			if (j == i)
				continue;
			*p = nums[j];
			++p;
		}
		next_prev[prev_size] = nums[i];
		set_nums(next_nums, size - 1, next_prev, prev_size + 1, ret, ret_size);
	}
}

static int compint(const void *p1, const void *p2)
{
	return bcmp(p1, p2, sizeof(int));
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize) {
	int i;
	*returnSize = 1;
	for (i = 2; i <= numsSize; ++i)
		*returnSize *= i;
	int **ret = malloc(sizeof(int *) * (*returnSize));

	qsort(nums, numsSize, sizeof(int), compint);

	int ret_size = 0;
	set_nums(nums, numsSize, NULL, 0, ret, &ret_size);
	*returnSize = ret_size;
//	assert(*returnSize == ret_size);

	return ret;
}

int main(int argc, char *argv[])
{
	int num_size = argc - 1;
    int *nums = malloc(sizeof(int) * num_size);

	int i, j;
	int return_size;
	for (i = 1; i < argc; i++)
	{
		nums[i - 1] = atoi(argv[i]);
	}
	
	int **return_num = permuteUnique(nums, num_size, &return_size);
	for (i = 0; i < return_size; ++i)
	{
		for (j = 0; j < num_size; ++j)
			printf("%d ", return_num[i][j]);
		printf("\n");
	}
	printf("total num = %d\n", return_size);

    return 0;
}
