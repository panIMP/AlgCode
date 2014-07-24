#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <ctype.h>
#include <algorithm>


using namespace std;


int calculator(int argc, char* argv[])
{

	char str[1024];
	gets(str);

	int len = strlen(str);

	stack<float> center;
	stack<float> back;
	stack<float> interm;

	center.push(0.0);

	char* tmp = strtok(str, " ");
	while (tmp != NULL)
	{
		float value = (float)atof(tmp);
		if (value == '+' || value == '-' || value == '*' || value == '%')
		{
			if (value > center.top())
			{
				center.push(value);
			}
			else if (value <= center.top())
			{
				while (center.top() >= value && !center.empty())
				{
					interm.push(center.top());
					center.pop();
				}
			}
		}
		else if (value == '(')
		{
			center.push('(');
		}
	}


	system("pause");

	return 0;
}