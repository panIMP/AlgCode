#include "fibonacci.h"
#include <iostream>

int 
fibonacci(int n)
{
	if (n <= 0)
	{
		return -1;
	}
	else if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 1;
	}
	else
	{
		int value1 = 1;
		int value2 = 1;
		int value;
		for (int i = 2; i < n; ++i)
		{	
			value = value1 + value2;
			value1 = value2;
			value2 = value;
		}

		return value;
	}
}


