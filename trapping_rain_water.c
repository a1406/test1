#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum trap_state
{
	INIT,
	FIND_BOTTOM,
	FIND_TOP_RIGHT,
};

void init_func(int *height);
void find_bottom_func(int *height);
void find_top_right_func(int *height);

typedef void (*trap_func)(int *height);
trap_func g_func;
int g_ret;
int left_max, real_max;

void init_func(int *height)
{
	if (height[0] < height[-1]) {
		g_func = find_bottom_func;
		left_max = height[-1];
	}
}

void find_bottom_func(int *height)
{
	if (height[0] < height[1]) {
		g_func = find_top_right_func;
	}
}

void find_top_right_func(int *height)
{
	if (height[0] >= left_max) {
		g_func = init_func;
		real_max = left_max;
		return;
	}
	if (height[0] > height[1])
	{
		g_func = find_bottom_func;
		left_max = height[0];
		real_max = height[0];
	}
}

int trap(int* height, int heightSize) {
	g_func = init_func;
	g_ret = 0;
	int i;
	for (i = 1; i < heightSize - 1; ++i) {
		g_func(&height[i]);
	}
	return (g_ret);
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
