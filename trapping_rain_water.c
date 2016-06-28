#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trap(int* height, int heightSize) {
	return (0);
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
