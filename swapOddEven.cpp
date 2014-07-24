#include <stdio.h>
#include <exception>


using namespace std;



void reorderOddEven(int* pData, int len)
{
	if (pData == NULL || len <= 0)
		throw new exception("Invalid input for reorderOddEven");

	int* pre = pData;
	int* post = pData + len - 1;

	while (pre < post)
	{
		while ((pre < post) && (((*pre) & 0x01) != 0))
		{
			pre++;
		}

		while ((pre < post) && (((*post) & 0x01) == 0))
		{
			post--;
		}

		if (pre < post)
		{
			int tmp = *pre;
			*pre = *post;
			*post = tmp;
		}
	}
}


void reorder(int* pData, int len, bool(*func)(int))
{
	if (pData == NULL || len <= 0)
		throw new exception("Invalid input for reorderOddEven");

	int* pre = pData;
	int* post = pData + len - 1;

	while (pre < post)
	{
		while (pre < post && !func(*pre))
		{
			pre++;
		}

		while (pre < post && func(*post))
		{
			post--;
		}

		if (pre < post)
		{
			int tmp = *pre;
			*pre = *post;
			*post = tmp;
		}
	}
}


bool isEven(int value)
{
	return ((value & 0x01) == 0);
}

bool isPosi(int value)
{
	return value > 0;
}


int swapOddEven(int argc, char* argv[])
{
	int array[] = { 0, -1, 2, 0, 3, -7, 8, -9, -2, -1, 4 };

	reorder(array, sizeof(array) / sizeof(int), isEven);

	return 0;
}