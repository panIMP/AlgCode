#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>


using namespace std;



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

    num = (num - 1) & num;
    while (num)
    {
        num = (num - 1) & num;
        count++;
    }

    return 0;
}


int numOfWholeNine(int len)
{
    if (len <= 0)
        return 0;

    if (len == 1)
        return 1;

    if (len >= 2)
        return (10 * numOfWholeNine(len - 1) + pow(10, len - 1));
}


int countNum(char* str)
{
    if (str == NULL)
        return 0;

    int len = strlen(str);
    if (len <= 0)
        return 0;

    if (len == 1)
        return ((*str - '0') + 1);

    if (len >= 2)
        return (pow(10, len - 1) * (*str - '0') + countNum(++str));
}


int numOfOneFromNail2Value(char* str)
{
    if (str == NULL)
        return 0;

    int len = strlen(str);

    if (len < 1)
        return 0;
    else if (len == 1 && *str != '0')
        return 1;
    else if (len == 1 && *str == '0')
        return 0;
    else if (len >= 2)
    {
        if (*str != '1')
            return (((*str) - '1') * numOfWholeNine(len - 1) + pow(10, len - 1) + 2 * numOfOneFromNail2Value(str+1));
        else if (*str == '1')
            return (numOfWholeNine(len - 1) + countNum(str+1) + numOfOneFromNail2Value(str+1));
    }
}































