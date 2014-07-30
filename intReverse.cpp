#include <stdio.h>
#include <string.h>

int intRever(int argc, char* argv[])
{
    char str[1024] = {'\0'};

    if (fgets(str, 1024, stdin) == NULL)
        return -1;

    puts(str);

    return 0;
}
