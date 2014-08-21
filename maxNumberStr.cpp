#include <stdio.h>
#include <string.h>


int maxNumberStr(int argc, char* argv[])
{
	char str[1024] = { '\0' };
    fgets(str, 1024, stdin);

	if (str == NULL)
		return -1;

	char* strPtr = str;

	char nonNumStr[1024] = { '\0' };
	char numStr[1024] = { '\0' };
	int maxLen = 0;
	int curLen = 0;
	char* p;

	while (*strPtr != '\0')
	{
		memset(nonNumStr, 0, strlen(nonNumStr));
		sscanf(strPtr, "%[^0-9]", nonNumStr);
		strPtr += strlen(nonNumStr);

		memset(numStr, 0, strlen(numStr));
		sscanf(strPtr, "%[0-9]", numStr);
		curLen = strlen(numStr);
		if (curLen > maxLen)
		{
			maxLen = curLen;
			p = strPtr;
		}
		strPtr += strlen(numStr);
	}

	if (maxLen != 0)
	{
		*(p + maxLen) = '\0';
		printf("%s,%d", p, maxLen);
	}
	else
	{
		printf("0");
	}


	return 0;
}
