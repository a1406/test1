#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#define printf

bool isSelfCrossing(int* x, int xSize) {
	int north = 0, south = 0;
	int west = 0, east = 0;

	int i;
	for (i = 0; i < xSize; i += 4) {
		north += x[i];
	}
	for (i = 2; i < xSize; i += 4) {
		south += x[i];
	}
	if (south > north)
		return false;
	
	for (i = 1; i < xSize; i += 4) {
		west += x[i];
	}
	for (i = 3; i < xSize; i += 4) {
		east += x[i];
	}
	if (west > east)
		return false;

	printf("%d %d %d %d\n", north, south, west, east);
	return true;
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

	if (isSelfCrossing(nums, num_size))
		printf("true\n");
	else
		printf("false\n");
    return 0;
}
