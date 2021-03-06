#include <stdio.h>
#include <string.h>


int isLegalCoord(char* str, int* num, char* direct)
{
    int len = strlen(str);

    if (sscanf(str,"%c%d", direct, num) < 2)
        return 0;

    if (*direct != 'A' && *direct != 'D' && *direct != 'W' && *direct != 'S')
        return 0;

    if (len == 2 && str[1] >= '0' && str[1] <= '9')
        return 1;

    if (len == 3 && str[1] >= '0' && str[1] <= '9' && str[2] >= '0' && str[2] <= '9')
        return 1;

    return 0;
}


int coordinate()
{
    char str[1024] = {'\0'};
    char* tmpStr;
    int num = 0;
    char direct = '\0';
    int x = 0;
    int y = 0;

    memset(str, 0, strlen(str));
    if (fgets(str, 1024, stdin) == NULL)
        return -1;

    tmpStr = strtok(str, ";");
    while (tmpStr != NULL) {
        if (isLegalCoord(tmpStr, &num, &direct))
        {
            if (direct == 'A')
                x -= num;
            else if (direct == 'D')
                x += num;
            else if (direct == 'W')
                y += num;
            else if (direct == 'S')
                y -= num;
        }

        tmpStr = strtok(NULL, ";");
    }

    printf("%d,%d", x, y);

    return 0;
}
