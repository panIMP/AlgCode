#include <stdio.h>
#include <string.h>

using namespace std;

int wordReverse(int argc, char* argv[])
{
    char str[1024] = {'\0'};
    char str2[100] = {'\0'};
    int i,len;
    char value;

    if (gets(str) == NULL)
        return -1;

    len = strlen(str);

    for (i = 0; i < len; ++i)
    {
        value = str[i];

        if (value == '.' || value == ',' || value == '?' || value == '!' || value == ' ')
        {
            printf("%c", value);
        }
        else
        {
            sscanf(str + i, "%[^.,?! ]s", str2);
            i += strlen(str2) - 1;
            //printf("%s", _strrev(str2));
            memset(str2, 0, strlen(str2));
        }
    }

    return 0;
}
