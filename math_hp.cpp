#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <utility>
#include <stdexcept>
#include <new>
#include <typeinfo>
#include <iostream>


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
        throw new exception();

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


pair<int, int> findNumsAppearOnce(int data[], int len)
{
    if (data == nullptr || len <= 0)
        throw runtime_error("Invalid input");

    int xorSum = 0;
    for (int i = 0; i < len; ++i)
        xorSum ^= data[i];

    int index = 0;
    while ((xorSum & 1) == 0 && index < (sizeof(int) * 8)) {
        index ++;
        xorSum = xorSum >> 1;
    }

    int maskVal = 1 << index;
    int num1 = 0;
    int num2 = 0;

    for (int i = 0; i < len; ++i)
    {
        int val = data[i];

        if ((val & maskVal) == 0)
            num1 ^= val;
        else
            num2 ^= val;
    }

    return make_pair(num1, num2);
}


bool findNumbersWithSum(int data[], int len, int sum, pair<int, int>& result)
{
    if (data == nullptr || len <= 0)
        return false;

    int* head = (int*)data;
    int* tail = (int*)(data + len - 1);

    while (head < tail)
    {
        long long curSum = *head + *tail;

        if(curSum == sum)
        {
            result.first = *head;
            result.second = *tail;

            return true;
        }
        else if (curSum > sum)
        {
            --tail;
        }
        else
        {
            ++head;
        }
    }

    return false;
}


bool findContinueNumbersWithSum(int data[], int len, int& start, int& end)
{
    if (data == nullptr || len <= 0)
        return false;

    start = 0;
    end = 1;

    while (start <= end && start >= 0 && end < len)
    {




    }
}









































































