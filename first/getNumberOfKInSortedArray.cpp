#include <stdio.h>
#include <exception>

using namespace std;


int getFirstPosOfK(int* list, int k, int start, int end)
{
    if (start > end)
        return -1;

    if (list == NULL)
        return -1;

    while (start <= end)
    {
        int middle = (start + end) / 2;

        if (list[middle] > k)
            end = middle - 1;
        else if (list[middle] < k)
            start = middle + 1;
        else
        {
            if (middle == 0)
                return middle;
            else if (middle > 0)
            {
                if (list[middle - 1] != k)
                    return middle;
                else
                    return getFirstPosOfK(list, k, 0, middle -1);
            }
        }
    }

    return -1;
}


int getLastPosOfK(int* list, int len, int k, int start, int end)
{
    if (start > end)
        return -1;

    if (list == NULL || len <= 0)
        return -1;

    while (start <= end)
    {
        int middle = (start + end) / 2;

        if (list[middle] > k)
            end = middle - 1;
        else if (list[middle] < k)
            start = middle + 1;
        else
        {
            if (middle == len - 1)
                return middle;
            else if (middle < len - 1)
            {
                if (list[middle + 1] != k)
                    return middle;
                else
                    return getLastPosOfK(list, len, k, middle + 1, end);
            }
        }
    }

    return -1;
}


int getNumberOfK(int* list, int len, int k)
{
    int number = 0;

    if (list == NULL || len <= 0)
        return 0;

    int firstPos = getFirstPosOfK(list, k, 0, len - 1);
    int lastPos = getLastPosOfK(list, len, k, 0, len - 1);

    if (firstPos >= 0 && lastPos >=0 && firstPos < len && lastPos < len)
        number = lastPos - firstPos + 1;

    return number;
}


