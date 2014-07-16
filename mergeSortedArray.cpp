#include "mergeSortedArray.h"
#include <cstdlib>
#include <cstring>



int
mergeSortedArray(int* A, int lenOfA, int* B, int lenOfB)
{
	int indexOfA = lenOfA - 1;
	int indexOfB = lenOfB - 1;
	int maxMergeLen = lenOfA + lenOfB;
	int indexOfMerge = 0;

	int* merge = A;
	int* arrMerge = merge + maxMergeLen - 1;

	int* arrA = A + indexOfA;
	int* arrB = B + indexOfB;;

	int valueA = *arrA;
	int valueB = *arrB;

	while (indexOfA >= 0 && indexOfB >= 0)
	{
		if (valueB > valueA)
		{
			*arrMerge = valueB;
			--indexOfB;
			valueB = *(--arrB);
		}
		else if (valueB == valueA)
		{
			*arrMerge = valueB;
			--indexOfB;
			--indexOfA;
			valueA = *(--arrA);
			valueB = *(--arrB);
		}
		else 
		{
			*arrMerge = valueA;
			--indexOfA;
			valueA = *(--arrA);
		}
		--arrMerge;
		++indexOfMerge;
	}

	if (indexOfA >= 0)
	{
		arrMerge -= indexOfA;
		indexOfMerge += (indexOfA + 1);
		memmove(arrMerge, A, (indexOfA + 1) * sizeof(int));
	}
	else if (indexOfB >= 0)
	{
		arrMerge -= indexOfB;
		indexOfMerge += (indexOfB + 1);
		memmove(arrMerge, B, (indexOfB + 1) * sizeof(int));
	}

	memmove(A, arrMerge, indexOfMerge * sizeof(int));
	memset(A + indexOfMerge, '\0', (maxMergeLen - indexOfMerge) * sizeof(int));

	return 0;
}