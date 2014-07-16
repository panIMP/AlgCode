#include <stdio.h>
#include <string.h>
#include <string>


using namespace std;



int dna(int argc, char* argv[])
{
	char str[2048] = { '\0' };
	int subLen = 0;

	gets(str);
	string str2 = string(str);
	int len = strlen(str);

	scanf("%d", &subLen);

	if (subLen > len)
		return -1;

	if (subLen == len)
	{
		puts(str);
		return 0;
	}

	if (subLen == 0)
		return -1;

	if (len == 0)
		return -1;

	for (int i = 0; i < len; ++i)
	{
		if (str[i] == 'A' || str[i] == 'T')
			str[i] = 0;
		else if (str[i] == 'G' || str[i] == 'C')
			str[i] = 1;
	}

	long long strInt[2048] = { 0 };
	strInt[0] = str[0];
	for (int i = 1; i < len; ++i)
	{
		strInt[i] = strInt[i - 1] + str[i];
	}

	double maxFreq = 0.0;
	long long sum = 0;
	double freq = 0.0;

	int iEnd = len - subLen;
	int startPos = 0;
	int realSubLen = 0;
	for (int i = 0; i <= iEnd; ++i)
	{
		for (int j = i + subLen - 1; j < len; ++j)
		{
			sum = strInt[j] - strInt[i] + str[i];
			freq = (double)((double)sum / (double)(j - i + 1));
			if (freq > maxFreq)
			{
				maxFreq = freq;
				startPos = i;
				realSubLen = j - i + 1;
			}
		}
	}

	puts(str2.substr(startPos, realSubLen).c_str());

	return 0;
}