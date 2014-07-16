#include <stdio.h>
#include <stdlib.h>

int ball(int argc, char* argv[])
{
	int height = 0;
	scanf("%d", &height);

	double tour = 0.0;
	tour += height;
	tour += height;
	tour += 0.5 * (double)height;
	tour += 0.25 * (double)height;
	tour += 0.125 * (double)height;

	double rev = 0.03125 * (double)height;

	printf("%g\n", tour);
	printf("%g", rev);

	return 0;
}