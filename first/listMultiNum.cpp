#include <stdio.h>
#include <stdlib.h>



typedef struct T_BIT
{
	unsigned char value : 4;
}tBit, *pTbit;



void printNum(pTbit num, int len)
{
	int i = 0;
	while (i < len && num[i].value == 0)
	{
		++i;
	}

	if (i == len)
		printf("0 ");
	else
	{
		pTbit start = num + i;
		pTbit end = num + len;
		while (start != end)
		{
			printf("%d", start->value);
			++start;
		}
		printf(" ");
	}
}


void printRecursive(pTbit integ, int len, int pos)
{
	if (pos == len - 1)
	{
		for (int i = 0; i < 10; ++i)
		{
			integ[pos].value = i;
			printNum(integ, len);
		}
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		integ[pos].value = i;
		printRecursive(integ, len, pos + 1);
	}
}
