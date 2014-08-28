#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>


using namespace std;


bool isAllDigit(char* str)
{
	int len = strlen(str);

	for (int i = 0; i < len; ++i)
	{
		if (!isdigit(str[i]))
		{
			return false;
		}
	}
	
	return true;
}


int stringMul(int argc, char* argv[])
{
	char strArr[2048] = { '\0' };
	char strBrr[2048] = { '\0' };
	char strRrr[4096] = { '\0' };

    fgets(strArr, 2048, stdin);
    fgets(strBrr, 2048, stdin);

	char* strA = strArr;
	char* strB = strBrr;
	char* strR = strRrr;

	char* integA = NULL;
	bool negFlagA = false;
	integA = strtok(strA, ".");
	if (integA == NULL)
		return -1;

	if (*strA == '-')
	{
		negFlagA = true;
		strA++;
		integA++;
	}
	if (!isAllDigit(strA))
		return -1;

	char* decimaA = NULL;
	decimaA = strtok(NULL, "\n");
	if (decimaA != NULL && (!isAllDigit(decimaA)))
		return -1;
	if (decimaA == NULL)
		decimaA = "0";

	char* integB = NULL;
	bool negFlagB = false;
	integB = strtok(strB, ".");
	if (integB == NULL)
		return -1;

	if (*strB == '-')
	{
		negFlagB = true;
		strB++;
		integB++;
	}
	if (!isAllDigit(strB))
		return -1;

	char* decimaB = NULL;
	decimaB = strtok(NULL, "\n");
	if (decimaB != NULL && (!isAllDigit(decimaB)))
		return -1;
	if (decimaB == NULL)
		decimaB = "0";

	string inputAStr = string(integA) + string(decimaA);
	string inputBStr = string(integB) + string(decimaB);

	int integALen = strlen(integA);
	int integBLen = strlen(integB);

	int decimaALen = strlen(decimaA);
	int decimaBLen = strlen(decimaB);

	int totalALen = integALen + decimaALen;
	int totalBLen = integBLen + decimaBLen;
	int mulLen = totalALen + totalBLen;
	int mulDecimaLen = decimaALen + decimaBLen;
	string outputStr = string(mulLen, '\0');

	int value = 0;
	int step = 0;
	for (int i = totalALen - 1; i >= 0; --i)
	{
		for (int j = totalBLen - 1; j >= 0; --j)
		{
			value = (inputAStr[i] - '0') * (inputBStr[j] - '0') + step + outputStr[j + i + 1];
			step = value / 10;
			value = value - step * 10;
			outputStr[j + i + 1] = value;
		}
		outputStr[i] = step;
		step = 0;
	}
	if (step > 0)
	{
		outputStr.insert(0, "0");
		outputStr[0] = step + '0';
	}
	
	int dotPos = outputStr.size() - mulDecimaLen;
	outputStr.insert(dotPos, 1, '.' - '0');

	if ((negFlagA == true && negFlagA == false) || (negFlagA == false && negFlagB == true))
	{
		*strR++ = '-';
	}

	int startPos = outputStr.find_first_not_of('\0');
	if (outputStr[startPos] == '.' - '0')
		startPos--;

	int endPos = outputStr.find_last_not_of('\0');
	if (outputStr[endPos] == '.' - '0')
		endPos--;

	for (int i = startPos; i <= endPos; ++i)
	{
		*strR++ = outputStr[i] + '0';
	}
		
	puts(strRrr);

	system("pause");

	return 0;
}
