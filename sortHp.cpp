#include <stdio.h>
#include <exception>
#include <algorithm>
#include <string.h>
#include <set>
#include <iostream>


using namespace std;


typedef multiset<int, greater<int>> intSet;
typedef multiset<int, greater<int>>::iterator intSetIter;


static inline void swap(void* a,  void* b)
{
	int aVal = *((int*)a);
	int bVal = *((int*)b);

	*((int*)a) = bVal;
	*((int*)b) = aVal;
}


int partition(int* list, int low, int high)
{
	if (list == NULL || low < 0 || high < 0 || high < low)
        throw new exception();

	int pivot = *(list + low);

	while (low < high)
	{
		while (low < high && list[high] >= pivot)
			high--;
		swap(list + low, list + high);

		while (low < high && list[low] < pivot)
			low++;
		swap(list + low, list + high);	
	}

	return low;
}


void qsort(int* list, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(list, low, high);

		qsort(list, low, pivot - 1);
		qsort(list, pivot + 1, high);
	}
}


int qsortClassic(int argc, char* argv[])
{
	char str[1024] = { '\0' };
    fgets(str, 1024, stdin);
	int list[1024] = { 0 };
	int* listPtr = list;

	char* tmp = strtok(str, " ");
	while (tmp != NULL)
	{
		*listPtr++ = atoi(tmp);
		tmp = strtok(NULL, " ");
	}
	int len = listPtr - list;

	qsort(list, 0, len - 1);

	for (int i = 0; i < len; ++i)
		printf("%d", list[i]);

	return 0;
}


void sortKthMin(int* list, int k, int len)
{
	int pivot = partition(list, 0, len - 1);

	while (pivot != k - 1)
	{
		if (pivot > k - 1)
			pivot = partition(list, 0, pivot - 1);
		else if (pivot < k - 1)
			pivot = partition(list, pivot + 1, len - 1);
	}
}


int minReverseVal(int* list, int len)
{
	if (list == NULL || len < 0)
        throw new exception();

	int start = 0;
	int end = len - 1;
	int mid = (start + end) / 2;

	if (list[start] < list[end])
        throw new exception();

	while (list[start] >= list[end])
	{
		if (end - start == 1)
			return list[end];

		mid = (start + end) / 2;

		if (list[mid] > list[start])
		{
			start = mid;
		}
		else if (list[mid] < list[start])
		{
			end = mid;
		}
		else if (list[mid] == list[start])
		{
			for (int i = start; i <= mid; ++i)
			{
				if (list[i] < list[start])
					return list[i];
			}
		}
	}

	return list[start];
}



int halfMoreAppearNum(int* list, int len)
{
    if (list == NULL && len <= 0)
        throw new exception();

    int start = 0;
    int end = len - 1;
    int mid = len / 2;
    int index = partition(list, start, end);

    while (index != mid)
    {
        if (index > mid)
        {
            end = index - 1;
            index = partition(list, start, end);
        }
        else
        {
            start = index + 1;
            index = partition(list, start, end);
        }
    }

    int result = list[mid];

    return result;
}


int halfMoreAppearNum2(int* list, int len)
{
    if (list == NULL || len <= 0)
        throw new exception();

    int value = list[0];
    int times = 1;

    for (int i = 1; i < len; ++i)
    {
        if (times == 0)
        {
            value = list[i];
            times = 1;
        }

        else if (list[i] == value)
            times++;
        else
            times--;
    }

    int dupTimes = 0;
    for (int i = 0; i < len; ++i)
    {
        if (list[i] == value)
            dupTimes++;
    }

    if (dupTimes * 2 <= len)
        throw new exception();

    return value;
}


void minKnum(int* list, int len, int k)
{
    if (list == NULL || len <= 0 || k > len || k <=0)
        return;

    int start = 0;
    int end = len - 1;
    int index = 0;

    while(index != k - 1)
    {
        index = partition(list, start, end);

        if (index < k-1)
            start = index + 1;

        else if (index > k-1)
            end = index - 1;
    }

    for (int i = 0; i < k; ++i)
        printf("%d", list[i]);
}


void minKnum2(const vector<int>& data, intSet& leastNumbers, int k)
{
    leastNumbers.clear();

    if (k < 1 || data.size() < k)
        return;

    vector<int>::const_iterator iter = data.begin();
    for (; iter != data.end(); ++iter)
    {
        if (leastNumbers.size() < k)
            leastNumbers.insert(*iter);

        else
        {
            intSetIter iterGreat = leastNumbers.begin();

            if (*iter < *(leastNumbers.begin()))
            {
                leastNumbers.erase(iterGreat);
                leastNumbers.insert(*iter);
            }
        }
    }

    intSetIter iterGreat = leastNumbers.begin();

    for (; iterGreat != leastNumbers.end(); ++iterGreat)
        cout << *iterGreat << " ";

}


int maxSumOfSubArray(int* list, int len)
{
    int thisSum, maxSum, j;

    maxSum = list[0];
    thisSum = 0;

    for (j = 0; j < len; ++j)
    {
        thisSum += list[j];

        if (thisSum > maxSum)
        {
            maxSum = thisSum;
        }

        if (thisSum < 0)
        {
            thisSum = 0;
        }
    }

    return maxSum;
}






















