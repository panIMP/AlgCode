#include <stdio.h>

int normalMethod(int argc, char* argv[])
{
	int flag = 1;
	int num = 0;

	scanf("%d", &num);

	int count = 0;
	while (flag)
	{
		if (num & flag)
			count++;
		flag = flag << 1;
	}


	return 0;
}


int magicMethod(int argc, char* argv[])
{
	int num = 0;

	scanf("%d", &num);

	int count = 0;
	while (num)
	{
		num = (num - 1) & num;
		count++;
	}

	return 0;
}