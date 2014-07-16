#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int yuanyinCmp(const void* a, const void* b)
{
    char aValue = *((char*)a);
    char bValue = *((char*)b);

    if (aValue > bValue)
    {
        if (aValue >= 'a' && bValue < 'a')
            return -1;
        else
            return 1;
    }
    else if (aValue < bValue)
    {
        if (aValue < 'a' && bValue >= 'a')
            return 1;
        else
            return -1;
    }
    else
        return 0;
}


void sortVowel(char* input, char* output)
{
   int len = strlen(input);

   char* outPtr = output;
   for (int i = 0; i < len; ++i)
   {
       char tmp = input[i];

       if (tmp == 'a' || tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u'||
       tmp == 'A' || tmp == 'E' || tmp == 'I' || tmp == 'O' || tmp == 'U')
       {
           *outPtr++ = tmp;
       }
   }

   *outPtr = '\0';

   qsort(output, strlen(output), sizeof(char), yuanyinCmp);
}


int aeiou()
{
    char str[1024] = {'\0'};
    char outStr[1024] = {'\0'};

    gets_s(str, 1024);
    sortVowel(str, outStr);

    puts(outStr);

    return 0;
}
