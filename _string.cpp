#include <string.h>
#include "_string.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>




/* Str operations */
char* createStr() {
    static char str[11] = "0123456789";

    puts(str);

    return str;
}


void strReverse(char* str) {
    int len = strlen(str);

    int halfLen = len / 2;
    int i;
    char tmp;

    for (i = 0; i < halfLen; ++i) {
        tmp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = tmp;
    }
 }


void permutation(char* const pStr, char* pBegin)
{
    if (pStr == NULL || pBegin == NULL)
        return;

    int len = strlen(pBegin);
    if (len < 0)
        return;

    if (*pBegin == '\0')
        printf("%s", pStr);
    else
    {
        for (char* pCur = pBegin; *pCur != '\0'; ++pCur)
        {
            char tmp = *pBegin;
            *pBegin = *pCur;
            *pCur = tmp;

            permutation(pStr, pBegin + 1);

            tmp = *pBegin;
            *pBegin = *pCur;
            *pCur = tmp;
        }
    }
}


char* g_strCombine1 = new char[200 + 1];
char* g_strCombine2 = new char[200 + 1];

int minStrCmp (const void* aStr, const void* bStr)
{
    strcpy(g_strCombine1, *((const char**)aStr));
    strcat(g_strCombine1, *((const char**)bStr));

    strcpy(g_strCombine2, *((const char**)bStr));
    strcat(g_strCombine2, *((const char**)aStr));

    return strcmp(g_strCombine1, g_strCombine2);
}

void sortMinStr(int* numbers, int len)
{
    if (numbers == NULL || len <= 0)
        return;

    char** numbersStr = (char**)malloc(sizeof(char*) * len);
    for (int i = 0; i < len; ++i)
    {
        numbersStr[i] = (char*) malloc(sizeof(100));
        sprintf(numbersStr[i], "%d", numbers[i]);
    }

    qsort(numbersStr, len, sizeof(char*), minStrCmp);

    for (int i = 0; i < len; ++i)
        printf("%s", numbersStr[i]);
}






































