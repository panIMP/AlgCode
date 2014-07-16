#include <stdio.h>
#include <string.h>

int intRever(int argc, char* argv[])
{
    char str[1024] = {'\0'};

    if (gets_s(str, 1024) == NULL)
        return -1;

    _strrev(str);

    puts(str);

    return 0;
}
