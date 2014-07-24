#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <exception>


using namespace std;



bool dEqual(long double x1, float x2)
{
	if (x1 - x2 < 0.0000001f && x1 - x2 > -0.0000001f)
		return true;

	else
		return false;
}


double powerWithUnsigned(double x, unsigned int n)
{
	assert(n > 0);

	if (n == 1)
		return x;

	if (n == 2)
		return x * x;

	if ((n & 0x01) == 0)
		return powerWithUnsigned(powerWithUnsigned(x, n >> 1), 2);
	else
		return x * powerWithUnsigned(powerWithUnsigned(x, n >> 1), 2);
}


double power(double x, int n)
{
	if (n < 0 && dEqual(x, 0.0))
		throw new exception("Invalid input");

	bool negFlag = false;
	if (n < 0)
	{
		negFlag = true;
		n = -n;
	}

	double result = powerWithUnsigned(x, n);
	if (negFlag)
		result = 1.0 / result;
	
	return result;
}


void printMatClockwisely(int* numbers[], int cols, int rows)
{
	if (numbers == NULL || cols <= 0 || rows <= 0)
		return;

	int start = 0;
	int endX = 0;
	int endY = 0;

	while (start * 2 < cols && start * 2 < rows)
	{
		endX = cols - start - 1;
		endY = rows - start - 1;

		for (int i = start; i <= endX; ++i)
		{
			printf("%d ", numbers[i][start]);
		}

		for (int j = start + 1; j <= endY; ++j)
		{
			printf("%d ", numbers[endX][j]);
		}

		for (int k = endX - 1; k >= start; --k)
		{
			printf("%d ", numbers[k][endY]);
		}

		for (int m = endY - 1; m >= start + 1; --m)
		{
			printf("%d ", numbers[start][m]);
		}

		start++;
	}

}