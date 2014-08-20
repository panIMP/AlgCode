#include <stdio.h>
#include <string.h>




void convert(char* input, char* output)
{
	int flag = 1;

	int len = strlen(input);
	output[0] = (input[0] + 1 - 'a') % 26 + 'a';

	for (int i = 1; i < len; ++i)
	{
		if (input[i] == input[i - 1])
			flag = (flag + 1) % 2;

		if (flag == 1)
		{
			output[i] = (input[i] + 1 - 'a') % 26 + 'a';
		}
		else if (flag == 0)
		{
			output[i] = (input[i] + 2 - 'a') % 26 + 'a';
		}
	}
}


int stringTrans()
{
	char str[1024] = { '\0' };
	char outStr[1024] = { '\0' };

	gets(str);

	convert(str, outStr);
	
	puts(outStr);

	getchar();

	return 0;
}
