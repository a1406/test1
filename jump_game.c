#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

int jump(int* nums, int numsSize) {
	int cur_pos = 0;
	int next_pos = nums[0];
	int max_pos = nums[0];
	int ret = 0;
	while (next_pos < numsSize - 1)
	{
		int i;
		for (i = cur_pos; i < next_pos; ++i)
		{
			if (i + nums[i] > max_pos)
				max_pos = i + nums[i];
		}
		cur_pos = max_pos;
		next_pos = max_pos = cur_pos + nums[cur_pos];
		++ret;
	}
	return ret;
}

int main(int argc, char *argv[])
{
	int num_size = argc - 1;
    int *nums = malloc(sizeof(int) * num_size);

	int i;
	for (i = 1; i < argc; i++)
	{
		nums[i - 1] = atoi(argv[i]);
	}
	
	int ret = jump(nums, num_size);
	printf("ret = %d\n", ret);
    return 0;
}
