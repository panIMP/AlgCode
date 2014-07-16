#include <stdio.h>
#include <string.h>


int alpha(int argc, char* argv[])
{
    char str[1024] = {'\0'};
    int hist[128] = {0};
    int len = 0;
    int i = 0;
    int count = 0;


    if (gets_s(str, 1024) == NULL)
        return -1;

    len = strlen(str);
    for (i = 0; i < len; ++i)
    {
        hist[str[i]]++;
    }

    for (i = 0; i < 128; ++i)
    {
        if (hist[i] != 0)
            count++;
    }

    printf("%d", count);



    return 0;
}
