#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <myClass/myString.h>

using namespace std;


int findMaxShareStr(const char strA[], const char strB[], int n)
{
    if (strA == nullptr || strB == nullptr)
        return -1;

    int** table = new int*[n + 1];
    for(int i = 0; i <= n; ++i)
    {
        table[i] = new int[n + 1];
        memset(table[i], 0, sizeof(int) * (n + 1));
    }

    int maxLen = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(strA[i] == strB[j])
            {
                table[i+1][j+1] = table[i][j] + 1;
            }
            else
            {
                table[i+1][j+1] = max(table[i][j+1], table[i+1][j]);
            }

            if (maxLen < table[i+1][j+1])
                maxLen = table[i+1][j+1];
        }
    }

    for (int i = 0; i <= n; ++i)
        delete[] table[i];
    delete[] table;

    return maxLen;
}


int findMinInsertDP(const char str[], int n)
{
    int ret = 0;

    int** table = new int*[n + 1];
    for(int i = 0; i <= n; ++i)
    {
        table[i] = new int[n + 1];
        memset(table[i], 0, sizeof(int) * (n + 1));
    }

    for (int i = 0; i < n; ++i)
    {
        table[i][i] = 0;
    }

    for (int i = 1; i < n; ++i)
    {
        table[i][i+1] = (str[i] == str[i+1] ? 0 : 1);
    }

    for (int step = 2; step < n; ++step)
    {
        for (int i = 0, j = step; j < n; ++i, ++j)
        {
            if (str[i] == str[j])
                table[i][j] = table[i+1][j-1];
            else
                table[i][j] = 1 + min(table[i+1][j], table[i][j-1]);
        }
    }

    ret = table[0][n-1];

    for (int i = 0; i <= n; ++i)
        delete[] table[i];
    delete[] table;

    return ret;
}






















