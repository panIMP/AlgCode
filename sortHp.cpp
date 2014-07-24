#include <stdio.h>
#include <exception>
#include <algorithm>


using namespace std;



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
		throw new exception("Invalid params in partition");

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
	gets(str);
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
		throw new exception("Invalid input");

	int start = 0;
	int end = len - 1;
	int mid = (start + end) / 2;

	if (list[start] < list[end])
		throw new exception("Invalid input");

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

