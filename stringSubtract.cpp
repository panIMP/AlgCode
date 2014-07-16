#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;



void Decrease(char* input1, char* input2, char* output)
{
	char *decima1, *decima2;
	char *integ1, *integ2;

	integ1 = strtok(input1, ".");
	decima1 = strtok(NULL, ".");
	integ2 = strtok(input2, ".");
	decima2 = strtok(NULL, ".");

	string input1Str = string(integ1) + string(decima1);
	string input2Str = string(integ2) + string(decima2);
	bool negFlag = false;

	if (input1Str.size() == input2Str.size())
	{
		if (input1Str < input2Str)
		{
			negFlag = true;
			input1Str.swap(input2Str);
		}
	}
	else if (input1Str.size() < input2Str.size())
	{
		negFlag = true;
		input1Str.swap(input2Str);
	}

	int integ1Len = strlen(integ1);
	int integ2Len = strlen(integ2);
	int maxIntegLen = integ1Len > integ2Len ? integ1Len : integ2Len;
	input1Str.insert(0, maxIntegLen - integ1Len, '0');
	input2Str.insert(0, maxIntegLen - integ2Len, '0');

	int decima1Len = strlen(decima1);
	int decima2Len = strlen(decima2);
	int maxDecimaLen = decima1Len > decima2Len ? decima1Len : decima2Len;
	input1Str.append(maxDecimaLen - decima1Len, '0');
	input2Str.append(maxDecimaLen - decima2Len, '0');
	
	int maxLen = maxIntegLen + maxDecimaLen;
	string outputStr = string(maxLen, '\0');
	for (int i = maxLen-1; i >= 0; --i)
	{
		char a = input1Str[i];
		char b = input2Str[i];

		if (a >= b)
			outputStr[i] = a - b + '0';
		else
		{
			outputStr[i] = a + 10 - b + '0';

			if (i != 0)
				input1Str[i - 1]--;
		}
	}

	outputStr.insert(maxIntegLen, ".");

	char* outPtr = output;
	if (negFlag)
	{
		*outPtr++ = '-';
	}

	int startPos = outputStr.find_first_not_of("0");
	if (startPos == maxIntegLen)
		startPos--;

	int endPos = outputStr.find_last_not_of("0");
	if (endPos == maxIntegLen)
		endPos--;

	for (int i = startPos; i <= endPos; ++i)
	{
		*outPtr++ = outputStr[i];
	}
}



void stringSubtract()
{
	while (1)
	{
		char str[2048] = { '\0' };
		char outStr[2048] = { '\0' };

		gets(str);

		char* input1 = strtok(str, "-");
		char* input2 = strtok(NULL, "-");

		if (input1 == NULL || input2 == NULL)
			return;

		Decrease(input1, input2, outStr);

		puts(outStr);

		getchar();
	}

	return;
}