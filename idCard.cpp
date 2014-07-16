#include <stdio.h>
#include <string.h>
#include <ctype.h>


int verifyIDCard(char* input)
{
	int len = strlen(input);

	if (len != 18)
		return 1;

	for (int i = 0; i < 17; ++i)
	{
		if (!isdigit(input[i]))
			return 2;
	}

	if (!isdigit(input[17]) && input[17] != 'x')
		return 3;

	int year = 0;
	int month = 0;
	int day = 0;
	sscanf(input + 6, "%4d", &year);
	sscanf(input + 10, "%2d", &month);
	sscanf(input + 12, "%2d", &day);

	if (year > 2010 || year < 1900)
		return 4;

	if (month > 12 || month < 1)
		return 5;

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day > 31 || day < 1)
			return 6;
	}

	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30 || day < 1)
			return 6;
	}

	if (month == 2)
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		{
			if (day > 29 || day < 1)
				return 6;
		}
		else
		{
			if (day > 28 || day < 1)
				return 6;
		}
	}


    return 0;
}



int idCard()
{
	while (1)
	{
		char str[1024] = { '\0' };
		char tmpStr[1024] = { '\0' };

		gets(str);

		int retVal = verifyIDCard(str);

		printf("%d", retVal);
		getchar();
	}

	return 0;
}
