#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int cmp(const void* a, const void* b)
{
    if (*((int*)a) > *((int*)b))
        return 1;
    else if (*((int*)a) < *((int*)b))
        return -1;
    else
        return 0;
}


int humpSort(int argc, char* argv[])
{
    char str[1024] = {'\0'};
    int value[1024] = {0};
	char* p;

    gets_s(str, 1024);
    int i = 0;
    int j = 0;
    char* tmp = strtok_s(str, " ", &p);
    while (tmp != NULL) {
        value[i] = atoi(tmp);
        i ++;
        tmp = strtok_s(NULL, " ", &p);
    }

    int len = i;
    int tmpValue = 0;

    /*// bubble sort
    for (i = 0; i < len -1; ++i)
    {
        for (j = 0; j < len - i - 1; ++j)
        {
            if (value[j] > value[j + 1])
            {
                tmpValue = value[j];
                value[j] = value[j + 1];
                value[j + 1] = tmpValue;
            }
        }
    }*/

    /*// insert sort
    for (i = 1; i < len; ++i)
    {
        int tmpValue = value[i];
        for (j = i - 1; j >= 0 && tmpValue < value[j]; j--)
        {
            value[j + 1] = value[j];
        }
        value[j + 1] = tmpValue;
    }*/

    /*// shell sort
    for (int step = len / 2; step > 0; step /= 2)
    {
        for (i = step; i < len; ++i)
        {
            tmpValue = value[i];

            for (j = i - step; j >= 0 && tmpValue < value[j]; j-= step)
                value[j + step] = value[j];
            value[j + step] = tmpValue;
        }
    }*/

    // Binary insert sort
    /*for (i = 1; i < len; ++i)
    {
        int tmpValue = value[i];

        // find the insert index
        int left = 0;
        int right = i-1;
        int middle = 0;
        while (right >= left) {
            middle = (right + left) / 2;
            if (tmpValue < value[middle])
                right = middle - 1;
            else
                left = middle + 1;
        }

        for (j = i - 1; j >= left; j--)
            value[j + 1] = value[j];

        value[left] = tmpValue;
    }*/

    // choose sort
    /*for (i = 0; i < len - 1; ++i)
    {
        int minValue = value[i];
        int index = i;

        for (j = i + 1; j < len; ++j)
        {
            if (value[j] < minValue)
            {
                minValue = value[j];
                index = j;
            }
        }

        value[index] = value[i];
        value[i] = minValue;
    }*/

    /*// quick sort -- 1
    qsort(value, len, sizeof(int), cmp);*/

    // quick sort -- 2



    if (len % 2 == 0)
    {
        for (i = 0; i < len - 1; i += 2)
            printf("%d ", value[i]);

        for (i = len - 1; i >= 1; i -= 2)
            printf("%d ", value[i]);
    }
    else
    {
        for (i = 1; i < len - 1; i += 2)
            printf("%d ", value[i]);

        for (i = len - 1; i >= 0; i -= 2)
            printf("%d ", value[i]);
    }

    return 0;
}
