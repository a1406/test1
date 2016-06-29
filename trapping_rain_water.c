#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum trap_state
{
	FIND_TOP_LEFT,   //初始状态，寻找左侧最高点，
	FIND_TOP_RIGHT,   //寻找右侧最高点，或者高过左侧最高点的点
};

typedef void (*trap_func)(int *height, int index);
void find_top_left_func(int *height, int index);
void find_top_right_func(int *height, int index);

trap_func g_func;
int g_ret;
int max_left;
int max_right;
int max_index_left;
int max_index_right;

void count_trap(int *height)
{
	int i;
	for (i = max_index_left + 1; i < max_index_right; i++) {
		if (max_right > height[i])
			g_ret += max_right - height[i];
	}
	printf("%s: g_ret = %d, max_right = %d index[%d][%d]\n", __FUNCTION__, g_ret, max_right, max_index_left, max_index_right);
}

void init_trap()
{
	max_left = max_right = 0;
}

void find_top_left_func(int *height, int index)
{
		//小于前一个点
	if (height[index] < height[index - 1]) {
		max_left = height[index - 1];
		max_index_left = index - 1;
		g_func = find_top_right_func;
	}
}


void find_top_right_func(int *height, int index)
{
	printf("%s: index = %d, max_left = %d max_right = %d\n", __FUNCTION__, index, max_left, max_right);
	if (height[index] >= max_left) {
		max_right = max_left;
		max_index_right = index;
		g_func = find_top_left_func;
		count_trap(height);
		init_trap();
		return;
	}

	if (height[index] >= max_right) {
		max_right = height[index];
		max_index_right = index;
	}
	
}


int trap(int* height, int heightSize) {
	g_func = find_top_left_func;
	g_ret = 0;
	int ret = 0;
	init_trap();
	int i;
	for (i = 1; i < heightSize; ++i) {
		g_func(height, i);
	}
	ret = g_ret;	
	if (g_func == find_top_right_func && max_index_right > max_index_left + 1) {
		count_trap(height);
		ret = g_ret;
		ret += trap(&height[max_index_right], heightSize - max_index_right);
	}
	return (ret);
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
	
	int ret = trap(nums, num_size);
	printf("ret = %d\n", ret);
    
    return 0;
}
