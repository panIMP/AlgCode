#include <stdio.h>



int min3(const int& a, const int& b, const int& c)
{
    int min = a < b ? a : b;

    min = a < c ? a : c;

    return min;
}



int getUglyNumber(int index)
{
    if (index < 0)
        return 0;

    int* pUglyNumber = new int[index];
    pUglyNumber[0] = 1;

    int nextUglyIndex = 1;

    int* pUglyNumberM2 = pUglyNumber;
    int* pUglyNumberM3 = pUglyNumber;
    int* pUglyNumberM5 = pUglyNumber;

    while (nextUglyIndex < index)
    {
        int min = min3((*pUglyNumberM2) * 2, (*pUglyNumberM3) * 3, (*pUglyNumberM5) * 5);
        pUglyNumber[nextUglyIndex] = min;

        while (*pUglyNumberM2 * 2 <= pUglyNumber[nextUglyIndex])
            pUglyNumberM2++;

        while (*pUglyNumberM3 * 3 <= pUglyNumber[nextUglyIndex])
            pUglyNumberM3++;

        while (*pUglyNumberM5 * 5 <= pUglyNumber[nextUglyIndex])
            pUglyNumberM5++;

        ++nextUglyIndex;
    }

    int ugly = pUglyNumber[nextUglyIndex - 1];

    delete[] pUglyNumber;
    return ugly;
}
