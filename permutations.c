#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_NUMS 20

void set_nums(int *nums, int size, int *prev, int prev_size, int **ret, int *return_size)
{
	int i, j;
	int next_nums[MAX_NUMS];
	int next_prev[MAX_NUMS];
	memcpy(next_prev, prev, sizeof(int) * prev_size);
	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size - 1; ++j)
		{
			
		}
		next_prev[prev_size] = nums[i];
		set_nums(next_nums, size - 1, next_prev, prev_size + 1, ret, return_size);
	}
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

	int ret_size = 0;
	set_nums(nums, numsSize, NULL, 0, ret, &ret_size);
	assert(*returnSize == ret_size);

	return ret;
}

int main(int argc, char *argv[])
{
	int num_size = argc - 1;
    int *nums = malloc(sizeof(int) * num_size);

	int return_size;
	int **return_num = permuteUnique(nums, num_size, &return_size);
	int i, j;
	for (i = 0; i < return_size; ++i)
	{
		for (j = 0; j < num_size; ++j)
			printf("%d ", return_num[i][j]);
		printf("\n");
	}

    return 0;
}
