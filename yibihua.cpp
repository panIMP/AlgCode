#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>


using namespace std;


int yibihua(int argc, char* argv[])
{
	int lineNum = 0;
	scanf("%d", &lineNum);

	multimap<int, int> lines;
	set<int> points;
	int a, b;
	for (int i = 0; i < lineNum; ++i)
	{
		if (scanf("%d %d", &a, &b) == 2)
		{
			lines.insert(std::make_pair(a, b));
			lines.insert(std::make_pair(b, a));

			points.insert(a);
			points.insert(b);
		}
		else
			return -1;
	}
	
	int oddCount = 0;
	int appearTimes = 0;
	set<int>::iterator pos;
	for (pos = points.begin(); pos != points.end(); ++pos)
	{
		appearTimes = lines.count(*pos);
		if (appearTimes % 2 != 0)
			oddCount++;
	}

	if (oddCount == 0)
		printf("true");
	else if (oddCount == 2)
		printf("true");
	else if (oddCount > 2)
		printf("false");


	return 0;
}


