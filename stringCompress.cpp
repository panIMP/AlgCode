#include <stdio.h>
#include <string.h>




void stringZip(const char* pInputStr, long lInputLen, char* pOutputStr)
{
	char curValue = 0;
	char value = pInputStr[0];
	char count = 1;
	char* ptr = pOutputStr;
	for (int i = 1; i <= lInputLen; ++i)
	{
		curValue = pInputStr[i];
		if (curValue == value)
			count++;
		else
		{
			if (count == 1)
			{
				*ptr++ = value;
			}
			else
			{
				*ptr++ = count + '0';
				*ptr++ = value;
			}

			value = curValue;
			count = 1;
		}
	}

	*ptr = '\0';
}


int stringCompress(int argc, char* argv[])
{
	char str[1024] = { '\0' };
	char outStr[1024] = { '\0' };

	gets(str);

	stringZip(str, strlen(str), outStr);

	puts(outStr);

	return 0;
}