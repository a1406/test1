#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSelfCrossing(int* x, int xSize) {
	if (x[0] > x[2])
		return false;
	if (x[1] > x[3])
		return false;
	return true;
}


int main(int argc, char *argv[])
{
    
    return 0;
}
