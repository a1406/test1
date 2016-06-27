#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

int jump(int* nums, int numsSize) {
	if (numsSize <= 1)
		return (0);
	int cur_pos = 0;
	int start_pos = 0;
	int end_pos = cur_pos + nums[cur_pos];
	int ret = 0;
	while (cur_pos < numsSize - 1)
	{
		int i;
		int max_pos = 0;
		for (i = start_pos; i <= end_pos; ++i)
		{
			if (i + nums[i] > max_pos)
			{
				cur_pos = i;
				max_pos = i + nums[i];
			}
		}
//		cur_pos = max_pos;
		start_pos = end_pos + 1;
		end_pos = cur_pos + nums[cur_pos];
		++ret;
		printf("%d: cur[%d] start[%d] end[%d]\n", ret, cur_pos, start_pos, end_pos);
		if (start_pos > numsSize - 1)
			return ret;
		if (end_pos > numsSize - 1)
			return ret+1;
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
