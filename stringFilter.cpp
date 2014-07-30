#include <stdio.h>
#include <string.h>


using namespace std;



void stringFilter(const char* pInputStr, long lInputLen, char* pOutputStr)
{
	int alphaExist[26] = { 0 };

	int len = strlen(pInputStr);
	int j = 0;
	for (int i = 0; i < len; ++i)
	{
		int seq = pInputStr[i] - 'a';
		if (alphaExist[seq] == 1)
			continue;
		else
		{
			alphaExist[seq] = 1;
			pOutputStr[j] = pInputStr[i];
			j++;
		}
	}
	pOutputStr[j] = '\0';
	
}


int stringSubMult(int argc, char* argv[])
{
	char str[1024] = { '\0' };
	char outStr[1024] = { '\0' };

    fgets(str, 1024, stdin);

	stringFilter(str, strlen(str), outStr);

	puts(outStr);

	return 0;
}
