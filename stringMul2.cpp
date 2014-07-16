#include <deque>
#include <stdio.h>
#include <stdlib.h>


using namespace std;



int stringMul(int argc, char* argv[])
{
    deque<char> A;
    A.push_front(2);

    int num = 0;
    if (scanf("%d", &num) < 1)
        return -1;

    if (num == 1)
    {
        printf("2");
        return 0;
    }

    int tmp = 0;
    int stepFlag = 0;
    int size = 0;
    for (int i = 1; i < num; ++i)
    {
        tmp = 0;
        stepFlag = 0;
        size = A.size();

		tmp = A.back();
        tmp = 2 * tmp + 2;
        if (tmp > 9)
        {
            stepFlag = 1;
            tmp = tmp - 10;
        }
        A.at(size-1) = tmp;

        for (int j = size-2; j >= 0; --j)
        {
            tmp = A.at(j);
            tmp = 2 * tmp + 1 * stepFlag;
            if (tmp > 9)
            {
                stepFlag = 1;
                tmp = tmp - 10;
            }
            else
            {
                stepFlag = 0;
            }
            A.at(j) = tmp;
        }

        if (stepFlag == 1)
        {
            A.push_front(1);
        }
    }

    for (unsigned int i = 0; i < A.size(); ++i)
    {
        printf("%d",A.at(i));
    }

	system("pause");

    return 0;
}
