#include "replaceBlank.h"

//"abcd 34 298 df";
int
replaceBlank(char inputString[], int maxLength)
{
	if (inputString == nullptr || maxLength <= 0)
		return -1;

	int originalLength = 0;
	int numOfBlank = 0;
	int i = 0;
	int value;

	while ((value = inputString[i]) != '\0')
	{
		++originalLength;

		if (value == ' ')
			++numOfBlank;

		++i;
	}

	int newLength = originalLength + numOfBlank * 2;
	if (newLength > maxLength)
		return -1;

	int indexOfNew = newLength;
	int indexOfOriginal = originalLength;

	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (inputString[indexOfOriginal] == ' ')
		{
			inputString[indexOfNew--] = '0';
			inputString[indexOfNew--] = '2';
			inputString[indexOfNew--] = '%';
		}
		else
		{
			inputString[indexOfNew--] = inputString[indexOfOriginal];
		}

		--indexOfOriginal;
	}
	
	return 1;
}
