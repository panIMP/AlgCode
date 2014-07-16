#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "stringHp.h"


double 
str2Num(char* str)
{
	if (str == nullptr)
	{
		exit(-1);
	}

	char* strHead = str;
	double positive = 1;
	double number = 0;
	double dotValue = '.' - '0';
	int dotPoint = strlen(str) - 1;

	if (*str == '-')
	{
		positive = -1;
		number = 0;
		++str;
	}
	else if (*str == '+')
	{
		positive = 1;
		number = 0;
		++str;
	}

	while (*str != 0)
	{
		int curNum = *str - '0';
		if (curNum > 9 || curNum < 0) 
		{
			if (curNum == dotValue) 
			{
				static int dotTimes = 0;
				
				++dotTimes;

				if (dotTimes == 1)
				{
					dotPoint = str - strHead;

					++str;

					continue;
				}
			}

			printf("Non number character exists in the input string!\n");
			getchar();
			exit(-1);
		}
		else 
		{
			number = number * 10 + curNum;
		}

		if (number < 0) 
		{
			printf("Input string has the value beyond maximum range(-2^63, 2^63-1)");
			exit(-1);
		}

		++str;
	}

	dotPoint = str - strHead - dotPoint - 1;

	return (number * positive / pow(10, dotPoint));
}